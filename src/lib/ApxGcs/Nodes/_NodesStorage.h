/*
 * APX Autopilot project <http://docs.uavos.com>
 *
 * Copyright (c) 2003-2020, Aliaksei Stratsilatau <sa@uavos.com>
 * All rights reserved
 *
 * This file is part of APX Ground Control.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <Database/NodesReqDict.h>
#include <Database/NodesReqNconf.h>
#include <Database/NodesReqVehicle.h>
#include <Protocols/ProtocolNode.h>
#include <QtCore>

class Nodes;
class NodeItem;

class NodesStorage : public QObject
{
    Q_OBJECT

public:
    explicit NodesStorage(Nodes *nodes);

    QVariantMap configInfo;

    bool loading;

private:
    Nodes *nodes;
    QString loadedHash;
    bool loadDicts;

    static QString backupTitle(quint64 time, QString title);

    void newNodeDict(QVariantMap info, DictNode::Dict dict);
    void newNodeConfig(quint64 nconfID, QVariantMap info, QVariantMap values);
    int importConfigs(QList<QVariantMap> data);

public slots:
    void loadNodeInfo(NodeItem *node);
    void saveNodeInfo(NodeItem *node);
    void infoLoaded(QVariantMap info);

    void saveNodeUser(NodeItem *node);

    void loadDictCache(NodeItem *node);
    void saveDictCache(NodeItem *node, const DictNode::Dict &dict);
    void dictLoaded(QVariantMap info, DictNode::Dict dict);

    void loadNodeConfig(NodeItem *node, quint64 nconfID);
    void saveNodeConfig(NodeItem *node);
    void configLoaded(QVariantMap info, QVariantMap values);

    void restoreNodeConfig(NodeItem *node);

    void loadConfiguration(QString hash);
    void saveConfiguration(bool force = false);

private slots:
    //Configs
    void setConfigInfo(QVariantMap info);
    void loadedConfiguration(QVariantMap configInfo, QList<QVariantMap> data);
    void vehicleConfigUpdated();
    void vehicleConfigCreated();

signals:
    void configInfoUpdated();
};