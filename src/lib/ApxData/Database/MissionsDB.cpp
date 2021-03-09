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
#include "MissionsDB.h"
#include "Database.h"
#include <App/AppDirs.h>

MissionsDB::MissionsDB(QObject *parent, QString sessionName)
    : DatabaseSession(parent, "missions", sessionName, "v2")
{
    new DBReqMakeTable(this,
                       "Missions",
                       QStringList()
                           << "key INTEGER PRIMARY KEY NOT NULL"
                           << "hash TEXT NOT NULL UNIQUE"
                           << "time INTEGER DEFAULT 0" //access time
                           << "title TEXT"
                           << "lat REAL"
                           << "lon REAL"
                           << "siteID INTEGER"
                           << "topLeftLat REAL"
                           << "topLeftLon REAL"
                           << "bottomRightLat REAL"
                           << "bottomRightLon REAL"
                           << "distance INTEGER"
                           << "callsign TEXT"
                           << "runway TEXT"
                           << "FOREIGN KEY(siteID) REFERENCES Sites(key) ON DELETE SET NULL");
    new DBReqMakeIndex(this, "Missions", "hash", true);
    new DBReqMakeIndex(this, "Missions", "time", false);
    new DBReqMakeIndex(this, "Missions", "title", false);
    new DBReqMakeIndex(this, "Missions", "callsign", false);
    new DBReqMakeIndex(this, "Missions", "runway", false);

    new DBReqMakeTable(this,
                       "Sites",
                       QStringList() << "key INTEGER PRIMARY KEY NOT NULL"
                                     << "title TEXT NOT NULL"
                                     << "lat REAL NOT NULL"
                                     << "lon REAL NOT NULL");
    new DBReqMakeIndex(this, "Sites", "title", true);
    new DBReqMakeIndex(this, "Sites", "lat,lon", true);

    //mission elements
    new DBReqMakeTable(this,
                       "Runways",
                       QStringList() << "key INTEGER PRIMARY KEY NOT NULL"
                                     << "missionID INTEGER NOT NULL"
                                     << "num INTEGER"
                                     << "title TEXT"
                                     << "lat REAL"
                                     << "lon REAL"
                                     << "hmsl INTEGER"
                                     << "dN INTEGER"
                                     << "dE INTEGER"
                                     << "approach INTEGER"
                                     << "type TEXT"
                                     << "FOREIGN KEY(missionID) REFERENCES Missions(key) ON DELETE "
                                        "CASCADE ON UPDATE CASCADE");
    new DBReqMakeIndex(this, "Runways", "missionID", false);
    new DBReqMakeIndex(this, "Runways", "lat,lon", false);

    new DBReqMakeTable(this,
                       "Waypoints",
                       QStringList() << "key INTEGER PRIMARY KEY NOT NULL"
                                     << "missionID INTEGER NOT NULL"
                                     << "num INTEGER"
                                     << "title TEXT"
                                     << "lat REAL"
                                     << "lon REAL"
                                     << "altitude INTEGER"
                                     << "type TEXT"
                                     << "actions TEXT"
                                     << "FOREIGN KEY(missionID) REFERENCES Missions(key) ON DELETE "
                                        "CASCADE ON UPDATE CASCADE");
    new DBReqMakeIndex(this, "Waypoints", "missionID", false);
    new DBReqMakeIndex(this, "Waypoints", "lat,lon", false);

    new DBReqMakeTable(this,
                       "Taxiways",
                       QStringList() << "key INTEGER PRIMARY KEY NOT NULL"
                                     << "missionID INTEGER NOT NULL"
                                     << "num INTEGER"
                                     << "title TEXT"
                                     << "lat REAL"
                                     << "lon REAL"
                                     << "FOREIGN KEY(missionID) REFERENCES Missions(key) ON DELETE "
                                        "CASCADE ON UPDATE CASCADE");
    new DBReqMakeIndex(this, "Taxiways", "missionID", false);
    new DBReqMakeIndex(this, "Taxiways", "lat,lon", false);

    new DBReqMakeTable(this,
                       "Pois",
                       QStringList() << "key INTEGER PRIMARY KEY NOT NULL"
                                     << "missionID INTEGER NOT NULL"
                                     << "num INTEGER"
                                     << "title TEXT"
                                     << "lat REAL"
                                     << "lon REAL"
                                     << "hmsl INTEGER"
                                     << "radius INTEGER"
                                     << "loops INTEGER"
                                     << "timeout INTEGER"
                                     << "FOREIGN KEY(missionID) REFERENCES Missions(key) ON DELETE "
                                        "CASCADE ON UPDATE CASCADE");
    new DBReqMakeIndex(this, "Pois", "missionID", false);
    new DBReqMakeIndex(this, "Pois", "lat,lon", false);
}

DBReqMissions::DBReqMissions()
    : DatabaseRequest(Database::instance()->missions)
{}

bool DBReqMissionsFindSite::run(QSqlQuery &query)
{
    if (!(std::isnan(lat) || std::isnan(lon) || lat == 0.0 || lon == 0.0)) {
        query.prepare("SELECT (((?-lat)*(?-lat)*?)+((?-lon)*(?-lon))) AS dist, * FROM Sites"
                      " WHERE lat!=0 AND lon!=0 AND dist<2"
                      " ORDER BY dist ASC LIMIT 1");
        query.addBindValue(lat);
        query.addBindValue(lat);
        query.addBindValue(std::pow(std::cos(qDegreesToRadians(lat)), 2));
        query.addBindValue(lon);
        query.addBindValue(lon);
        if (!query.exec())
            return false;
        if (query.next()) {
            siteID = query.value("key").toULongLong();
            site = query.value("title").toString();
        }
    }
    emit siteFound(siteID, site);
    return true;
}
bool DBReqMissionsSaveSite::run(QSqlQuery &query)
{
    if (std::isnan(lat) || std::isnan(lon) || lat == 0.0 || lon == 0.0)
        return false;
    if (!key) {
        //create site record
        query.prepare("INSERT INTO Sites"
                      " (title,lat,lon) VALUES(?,?,?)");
        query.addBindValue(title);
        query.addBindValue(lat);
        query.addBindValue(lon);
        if (!query.exec())
            return false;
        emit siteAdded(title);
    } else {
        //update site record
        query.prepare("UPDATE Sites SET"
                      " title=?,lat=?,lon=?"
                      " WHERE key=?");
        query.addBindValue(title);
        query.addBindValue(lat);
        query.addBindValue(lon);
        query.addBindValue(key);
        if (!query.exec())
            return false;
        emit siteModified(title);
    }
    return true;
}
bool DBReqMissionsRemoveSite::run(QSqlQuery &query)
{
    query.prepare("DELETE FROM Sites WHERE key=?");
    query.addBindValue(key);
    if (!query.exec())
        return false;
    emit siteRemoved();
    return true;
}

bool DBReqMissionsSave::run(QSqlQuery &query)
{
    if (json.value("rw").toArray().isEmpty()) {
        qWarning() << "missing runways in mission";
    }

    //find siteID
    if (!reqSite.run(query))
        return false;

    QString title = json.value("title").toString().simplified();
    if (reqSite.siteID) {
        title = title.remove(reqSite.site, Qt::CaseInsensitive).simplified();
    } else {
        qDebug() << "no site";
    }

    QString callsign = json.value("callsign").toString();
    QVariant siteID = reqSite.siteID ? reqSite.siteID : QVariant();

    //find existing mission by hash
    QString hash = json.value("hash").toString();
    query.prepare("SELECT * FROM Missions WHERE hash=?");
    query.addBindValue(hash);
    if (!query.exec())
        return false;
    if (query.next()) {
        missionID = query.value(0).toULongLong();
        qDebug() << "mission exists";
        if (callsign.isEmpty())
            callsign = query.value("callsign").toString();
        //update mission access time
        query.prepare("UPDATE Missions SET time=?, title=?, siteID=?, callsign=? WHERE key=?");
        query.addBindValue(t);
        query.addBindValue(title);
        query.addBindValue(siteID);
        query.addBindValue(callsign);
        query.addBindValue(missionID);
        if (!query.exec())
            return false;
        emit missionHash(hash);
        return true;
    }

    //create new mission record
    if (!db->transaction(query))
        return false;

    QVariantMap info = filterFields("Missions", json);
    info["hash"] = hash;
    info["time"] = t;
    info["title"] = title;
    info["callsign"] = callsign;
    info["siteID"] = siteID;

    if (!recordInsertQuery(query, info, "Missions"))
        return false;
    if (!query.exec())
        return false;
    missionID = query.lastInsertId().toULongLong();

    //write items
    if (!writeItems(query, json.value("rw").toArray(), "Runways"))
        return false;
    if (!writeItems(query, json.value("wp").toArray(), "Waypoints"))
        return false;
    if (!writeItems(query, json.value("tw").toArray(), "Taxiways"))
        return false;
    if (!writeItems(query, json.value("pi").toArray(), "Pois"))
        return false;

    if (!db->commit(query))
        return false;

    emit missionHash(hash);
    return true;
}
bool DBReqMissionsSave::writeItems(QSqlQuery &query, QJsonArray json, QString tableName)
{
    DatabaseRequest::Records records;
    records.names = db->tableFields(tableName);
    records.names.removeOne("key");
    quint32 num = 0;
    for (auto j : json) {
        QJsonObject obj = j.toObject();
        QVariantList r;
        r.append(missionID);
        r.append(num++);
        for (int i = 2; i < records.names.size(); ++i) {
            QJsonValue v = obj[records.names.at(i)];
            if (v.isObject()) {
                QStringList st;
                for (auto k : v.toObject().keys()) {
                    st.append(k + "=" + v[k].toString());
                }
                r.append(st.join(','));
            } else {
                r.append(v.toVariant());
            }
        }
        records.values.append(r);
    }
    for (int i = 0; i < records.values.size(); ++i) {
        recordInsertQuery(query, records, i, tableName);
        if (!query.exec())
            return false;
    }
    return true;
}

bool DBReqMissionsLoad::run(QSqlQuery &query)
{
    query.prepare(
        "SELECT * FROM Missions"
        " LEFT JOIN (SELECT key, title AS site FROM Sites) AS Sites ON Missions.siteID=Sites.key"
        " WHERE hash=?");
    query.addBindValue(hash);
    if (!query.exec())
        return false;
    if (!query.next())
        return false;

    quint64 missionID = query.value("Missions.key").toULongLong();
    QJsonObject json = QJsonObject::fromVariantMap(filterIdValues(queryRecord(query)));

    query.prepare("SELECT * FROM Runways WHERE missionID=? ORDER BY num ASC");
    query.addBindValue(missionID);
    if (!query.exec())
        return false;
    json.insert("rw", readItems(query));

    query.prepare("SELECT * FROM Waypoints WHERE missionID=? ORDER BY num ASC");
    query.addBindValue(missionID);
    if (!query.exec())
        return false;
    json.insert("wp", readItems(query));

    query.prepare("SELECT * FROM Taxiways WHERE missionID=? ORDER BY num ASC");
    query.addBindValue(missionID);
    if (!query.exec())
        return false;
    json.insert("tw", readItems(query));

    query.prepare("SELECT * FROM Pois WHERE missionID=? ORDER BY num ASC");
    query.addBindValue(missionID);
    if (!query.exec())
        return false;
    json.insert("pi", readItems(query));

    emit loaded(json);
    return true;
}
QJsonValue DBReqMissionsLoad::readItems(QSqlQuery &query)
{
    QJsonArray array;
    while (query.next()) {
        QJsonObject obj = QJsonObject::fromVariantMap(filterIdValues(queryRecord(query)));
        obj.remove("num");
        array.append(obj);
    }
    return array.isEmpty() ? QJsonValue() : array;
}
