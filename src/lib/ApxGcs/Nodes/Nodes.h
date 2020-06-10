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
#pragma once

#include "LookupConfigs.h"
#include "NodeItem.h"

#include <Protocols/ProtocolNodes.h>
#include <Protocols/ProtocolViewBase.h>

class Vehicle;

class Nodes : public ProtocolViewBase<ProtocolNodes>
{
    Q_OBJECT

public:
    explicit Nodes(Vehicle *vehicle, ProtocolNodes *protocol);

    Vehicle *vehicle;

    Fact *f_upload;
    Fact *f_search;
    Fact *f_stop;
    Fact *f_reload;
    Fact *f_clear;
    Fact *f_status;

    Fact *f_save;

    LookupConfigs *f_lookup;
    //NodesShare *f_share;

    NodeItem *node(const QString &sn) { return m_sn_map.value(sn, nullptr); }
    QList<NodeItem *> nodes() { return m_sn_map.values(); }

    NodeItem *add(ProtocolNode *protocol);

    Q_INVOKABLE void shell(QStringList commands);

private:
    QMap<QString, NodeItem *> m_sn_map;
    QDateTime m_syncTimestamp;

private slots:
    void updateActions();

    void search();
    void clear();
    void reload();
    void upload();
    void stop();

    void nodeNotify(ProtocolNode *protocol);
    void syncDone();

public slots:
    void save();
};
