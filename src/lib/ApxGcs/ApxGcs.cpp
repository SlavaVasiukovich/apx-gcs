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
#include "ApxGcs.h"
#include <Shortcuts/AppShortcuts.h>
#include <ApxDirs.h>
#include <ApxLog.h>
#include <QFileDialog>
//=============================================================================
ApxGcs *ApxGcs::_instance = nullptr;
ApxGcs::ApxGcs(int &argc, char **argv, const QString &name, const QUrl &url)
    : ApxApp(argc, argv, name, url)
{
    _instance = this;
}
//=============================================================================
void ApxGcs::loadServices()
{
    ApxApp::loadServices();

    protocol = new ApxProtocol(f_app);

    new Database(f_app);
    Vehicles *vehicles = new Vehicles(f_app, protocol->vehicles);
    //new Spark(f_app,protocol->vehicles->firmware);

    new AppShortcuts(f_app->f_settings->f_interface);

    //datalink
    f_datalink = new Datalink(f_app);
    QObject::connect(f_datalink, &Datalink::packetReceived, protocol, &ApxProtocol::unpack);
    QObject::connect(protocol, &ApxProtocol::sendUplink, f_datalink, &Datalink::sendPacket);
    QObject::connect(f_datalink,
                     &Datalink::heartbeat,
                     protocol->vehicles,
                     &ProtocolVehicles::sendHeartbeat);

    vehicles->move(f_app->size());

    jsync(f_app);
}
//=============================================================================
void ApxGcs::openFile(ApxGcs::FileType type)
{
    QString title;
    QString ftype;
    QDir defaultDir;
    switch (type) {
    default:
        title = tr("Import");
        defaultDir = ApxDirs::user();
        break;
    case TelemetryFile:
        title = tr("Import telemetry data");
        ftype = "telemetry";
        defaultDir = ApxDirs::user();
        break;
    case ConfigFile:
        title = tr("Import configuration");
        ftype = "nodes";
        defaultDir = ApxDirs::configs();
        break;
    case FirmwareFile:
        title = tr("Firmware");
        ftype = "apxfw";
        defaultDir = ApxDirs::user();
        break;
    }
    QString settingName = QString("SharePath_%1")
                              .arg(QMetaEnum::fromType<FileType>().valueToKey(type));
    if (!defaultDir.exists())
        defaultDir.mkpath(".");
    QDir dir = QDir(QSettings().value(settingName, defaultDir.canonicalPath()).toString());
    if (!dir.exists())
        dir = defaultDir;
    QFileDialog dlg(nullptr, title, dir.canonicalPath());
    dlg.setAcceptMode(QFileDialog::AcceptOpen);
    dlg.setFileMode(QFileDialog::ExistingFiles);
    dlg.setViewMode(QFileDialog::Detail);
    QStringList filters;
    filters << tr("All supported types") + " (*.telemetry,*.nodes,*.apxfw)"
            << tr("Telemetry") + " (*.telemetry)" << tr("Configuration") + " (*.nodes)"
            << tr("Firmware") + " (*.apxfw)" << tr("Any files") + " (*)";
    dlg.setNameFilters(filters);
    dlg.setDefaultSuffix(ftype);
    if (!ftype.isEmpty())
        dlg.selectNameFilter("*." + ftype);
    if (!(dlg.exec() && dlg.selectedFiles().size() >= 1))
        return;
    QSettings().setValue(settingName, dlg.directory().absolutePath());

    foreach (QString fname, dlg.selectedFiles()) {
        emit fileOpenRequest(fname);
    }
}
//=============================================================================
//=============================================================================
