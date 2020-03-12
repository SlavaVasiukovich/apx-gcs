/*
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
#include "ProtocolVehicle.h"

#include <Mandala/Mandala.h>

#include <Xbus/XbusNode.h>
#include <Xbus/XbusPacket.h>

ProtocolVehicle::ProtocolVehicle(ProtocolVehicles *vehicles,
                                 xbus::vehicle::squawk_t squawk,
                                 const xbus::vehicle::ident_s &ident,
                                 const QString &callsign)
    : ProtocolBase(vehicles, callsign)
    , vehicles(vehicles)
{
    setIcon(squawk ? "drone" : "chip");
    setDataType(Count);

    nodes = new ProtocolNodes(this);

    updateIdent(squawk, ident, callsign);
}

xbus::vehicle::squawk_t ProtocolVehicle::squawk() const
{
    return m_squawk;
}
const xbus::vehicle::ident_s &ProtocolVehicle::ident() const
{
    return m_ident;
}
void ProtocolVehicle::updateIdent(const xbus::vehicle::squawk_t &squawk,
                                  const xbus::vehicle::ident_s &ident,
                                  const QString &callsign)
{
    m_squawk = squawk;
    m_ident = ident;

    setName(callsign.toLower());
    setTitle(callsign);

    bool replay = squawk == 0 && ident.flags.bits.gcs == 1;
    setEnabled(!replay);

    emit identUpdated();
}

bool ProtocolVehicle::match(const xbus::vehicle::squawk_t &squawk) const
{
    return squawk == m_squawk;
}
bool ProtocolVehicle::match(const xbus::vehicle::uid_t &uid) const
{
    return memcmp(uid, m_ident.uid, sizeof(xbus::vehicle::uid_t)) == 0;
}
bool ProtocolVehicle::match(const xbus::vehicle::ident_s &ident) const
{
    return memcmp(&ident, &m_ident, sizeof(xbus::vehicle::ident_s)) == 0;
}

void ProtocolVehicle::downlink(ProtocolStreamReader &stream)
{
    if (stream.available() < sizeof(xbus::pid_t)) {
        qWarning() << "size" << stream.dump();
        return;
    }

    xbus::pid_t pid = stream.read<xbus::pid_t>();

    if (pid < mandala::uid_base || pid > mandala::uid_max) {
        qWarning() << "wrong pid" << pid << stream.dump();
        return;
    }

    qDebug() << QString("[%1]").arg(Mandala::meta(pid).name) << stream.available();
    //qDebug() << ident.callsign << QString::number(pid, 16);

    if (mandala::cmd::env::nmt::match(pid)) {
        nodes->downlink(pid, stream);
        return;
    }

    switch (pid) {
    default:
        emit receivedData(pid, &stream);
        break;
    case mandala::cmd::env::telemetry::data::uid:
        emit telemetryData(&stream);
        break;
    case mandala::cmd::env::vcp::rx::uid:
        if (stream.available() > 1) {
            uint8_t port_id = stream.read<uint8_t>();
            emit serialRxData(port_id, stream.payload());
        } else {
            qWarning() << "Empty serial RX data received";
        }
        break;
    case mandala::cmd::env::vcp::tx::uid:
        if (stream.available() > 1) {
            uint8_t port_id = stream.read<uint8_t>();
            emit serialTxData(port_id, stream.payload());
        } else {
            qWarning() << "Empty serial TX data received";
        }
        break;
    case mandala::cmd::env::mission::data::uid:
        break;
    case mandala::cmd::env::script::jsexec::uid:
        if (stream.available() > 2) {
            QString script = stream.payload().trimmed();
            if (!script.isEmpty()) {
                emit jsexecData(script);
                break;
            }
        }
        qWarning() << "Empty jsexec data received" << stream.dump();
        break;
    }
}

void ProtocolVehicle::send(const QByteArray packet)
{
    if (vehicles)
        vehicles->send(m_squawk, packet);
}

void ProtocolVehicle::requestTelemetry() {}
void ProtocolVehicle::vmexec(QString func)
{
    func = func.simplified().trimmed();
    if (func.isEmpty())
        return;
    ostream.reset();
    ostream.write<xbus::pid_t>(mandala::cmd::env::script::vmexec::uid);
    ostream.append(func.toUtf8());
    send(ostream.toByteArray());
}
void ProtocolVehicle::sendSerial(quint8 portID, QByteArray data)
{
    if (data.isEmpty())
        return;
    ostream.reset();
    ostream.write<xbus::pid_t>(mandala::cmd::env::vcp::tx::uid);
    ostream.write<uint8_t>(portID);
    ostream.append(data);
    send(ostream.toByteArray());
}
