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
#pragma once

#include "ProtocolNode.h"

#include <QtCore>

class ProtocolVehicle;

class ProtocolNodes : public ProtocolBase
{
    Q_OBJECT
public:
    explicit ProtocolNodes(ProtocolVehicle *vehicle);

    friend class ProtocolNodeRequest;

    ProtocolNodeRequest *request(xbus::pid_t pid,
                                 const QString &sn,
                                 int timeout_ms,
                                 int retry_cnt = -1);

    ProtocolNode *getNode(QString sn, bool createNew = true);

    ProtocolNodeRequest *acknowledgeRequest(xbus::node::crc_t crc);
    ProtocolNodeRequest *acknowledgeRequest(ProtocolStreamReader &stream);
    ProtocolNodeRequest *extendRequest(xbus::node::crc_t crc, int timeout_ms);

    // called by vehicle
    void downlink(xbus::pid_t pid, ProtocolStreamReader &stream);

private:
    ProtocolVehicle *vehicle;

    QList<ProtocolNodeRequest *> pool;
    QTimer timer;
    quint32 activeCount;
    QElapsedTimer reqTime;
    QTimer finishedTimer;
    bool remove(ProtocolNodeRequest *request);
    void schedule(ProtocolNodeRequest *request);

    QHash<QString, ProtocolNode *> nodes;

    void reset();

private slots:
    void doNextRequest();
    void sendRequest(ProtocolNodeRequest *request);
    void requestFinished(ProtocolNodeRequest *request);
    void checkFinished();

public slots:
    void stop();

signals:
    void next();
    void stopRequested();
    void dataExchangeFinished();

    //export signals and slots
public slots:
    //nodes dict sync
    void requestSearch();

    void clearNodes();

signals:
    void nodeFound(ProtocolNode *protocol);
    void requestTimeout(ProtocolNodeRequest *request, ProtocolNode *node);
};
