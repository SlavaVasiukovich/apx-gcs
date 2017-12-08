﻿/*
 * Copyright (C) 2011 Aliaksei Stratsilatau <sa@uavos.com>
 *
 * This file is part of the UAV Open System Project
 *  http://www.uavos.com/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301, USA.
 *
 */
#include "Vehicle.h"
#include "Vehicles.h"
#include "VehicleMandala.h"
#include "VehicleNmtManager.h"
#include "VehicleRecorder.h"
#include "VehicleWarnings.h"
#include "Nodes.h"
#include "Mandala.h"
//=============================================================================
Vehicle::Vehicle(Vehicles *parent, QString callsign, quint16 squawk, QByteArray uid, VehicleClass vclass, bool bLocal)
  : Fact(bLocal?parent:parent->f_list,callsign,callsign,"",GroupItem,NoData),
    uid(uid),
    m_squawk(squawk)
{
  setSection(parent->title());

  //requests manager
  nmtManager=new VehicleNmtManager(this);
  connect(nmtManager,&VehicleNmtManager::sendUplink,this,&Vehicle::sendUplink);
  connect(this,&Vehicle::nmtReceived,nmtManager,&VehicleNmtManager::nmtReceived);

  f_streamType=new Fact(this,"stream",tr("Stream"),tr("Current data stream type"),FactItem,ConstData);
  f_streamType->setEnumStrings(QMetaEnum::fromType<StreamType>());

  f_squawk=new Fact(this,"squawk",tr("SQUAWK"),tr("Dynamic vehicle ID"),FactItem,ConstData);
  f_squawk->setValue(QString("%1").arg((ulong)squawk,4,16,QLatin1Char('0')).toUpper());
  f_squawk->setVisible(vclass!=LOCAL);

  f_callsign=new Fact(this,"callsign",tr("Callsign"),tr("Vehicle name"),FactItem,ConstData);
  f_callsign->setValue(callsign);
  f_callsign->setVisible(vclass!=LOCAL);
  connect(f_callsign,&Fact::valueChanged,this,[=](){ setName(f_callsign->text());setTitle(f_callsign->text()); });

  f_vclass=new Fact(this,"vclass",tr("Class"),tr("Vehicle class"),FactItem,ConstData);
  f_vclass->setEnumStrings(QMetaEnum::fromType<VehicleClass>());
  f_vclass->setValue(vclass);

  connect(f_squawk,&Fact::valueChanged,this,[=](){ m_squawk=f_squawk->value().toUInt(); });

  f_selectAction=new Fact(this,"select",tr("Select"),"Make this vehicle active",FactItem,ActionData);
  connect(f_selectAction,&Fact::triggered,this,[=](){ parent->selectVehicle(this); });
  connect(parent,&Vehicles::vehicleSelected,this,[=](Vehicle *v){ f_selectAction->setEnabled(v!=this); });

  f_mandala=new VehicleMandala(this);
  f_nodes=new Nodes(this);
  f_recorder=new VehicleRecorder(this);
  f_warnings=new VehicleWarnings(this);

  //datalink
  connect(this,&Vehicle::sendUplink,this,[=](const QByteArray &ba){
    parent->vehicleSendUplink(this,ba);
    f_recorder->record_uplink(ba);
  });


  //selection action fact in separate group menu
  f_select=new Fact(parent->f_select,name(),title(),descr(),FactItem,ActionData);
  connect(this,&Vehicle::destroyed,this,[=](){ parent->f_select->removeItem(f_select); });
  connect(f_select,&Fact::triggered,this,[=](){ parent->selectVehicle(this); });

  connect(this,&Vehicle::activeChanged,this,[=](){ f_select->setActive(active()); });
  connect(parent,&Vehicles::vehicleSelected,this,[=](Vehicle *v){ setActive(v==this); });

  connect(this,&Fact::statusChanged,this,[=](){ f_select->setStatus(status()); });

  connect(f_streamType,&Fact::valueChanged,this,[=](){ f_mandala->setStatus(f_streamType->text()); });

  f_streamType->setValue(0);

  onlineTimer.setSingleShot(true);
  onlineTimer.setInterval(7000);
  connect(&onlineTimer,&QTimer::timeout,this,[=](){ f_streamType->setValue(OFFLINE); });

  connect(f_streamType,&Fact::valueChanged,this,[=](){ setStatus(f_streamType->text()); });
  f_streamType->setValue(0);

  //register JS new vehicles instantly
  connect(this,&Vehicle::nameChanged,this,[=](){FactSystem::instance()->jsSync(this);});
  FactSystem::instance()->jsSync(this);
}
//=============================================================================
bool Vehicle::isLocal() const
{
  return f_vclass->value().toInt()==LOCAL;
}
//=============================================================================
quint16 Vehicle::squawk(void) const
{
  return m_squawk;
}
//=============================================================================
//=============================================================================
void Vehicle::downlinkReceived(const QByteArray &packet)
{
  if(f_nodes->unpackService(packet)){
    emit nmtReceived(packet);
    if(telemetryTime.elapsed()>2000 && xpdrTime.elapsed()>3000)
      f_streamType->setValue(SERVICE);
  }else if(f_mandala->unpackTelemetry(packet)){
    f_streamType->setValue(TELEMETRY);
    telemetryTime.start();
  }else if(f_mandala->unpackData(packet)){
    if(telemetryTime.elapsed()>2000 && xpdrTime.elapsed()>3000)
      f_streamType->setValue(DATA);
  }else return;
  f_recorder->record_downlink(packet);
  onlineTimer.start();
}
//=============================================================================
void Vehicle::xpdrReceived(const QByteArray &data)
{
  if(f_mandala->unpackXPDR(data)){
    f_streamType->setValue(XPDR);
    xpdrTime.start();
  }else return;
  onlineTimer.start();
}
//=============================================================================
void Vehicle::vmexec(QString func)
{
  emit sendUplink(QByteArray().append((unsigned char)idx_vmexec).append(func));
}
//=============================================================================
void Vehicle::sendSerial(quint8 portID,QByteArray data)
{
  emit sendUplink(QByteArray().append((unsigned char)idx_data).append((unsigned char)portID).append(data));
}
void FactSystemJS::sleep(quint16 ms)
{
  QEventLoop loop;
  QTimer::singleShot(ms,&loop,SLOT(quit()));
  loop.exec();
}
//=============================================================================
QString Vehicle::fileTitle() const
{
  QString confName;
  foreach(NodeItem *node,f_nodes->snMap.values()){
    if(!node->title().endsWith(".shiva"))continue;
    confName=node->status().trimmed();
    if(!confName.isEmpty())break;
  }
  if(confName.isEmpty())return title();
  return confName;
}
//=============================================================================
//=============================================================================