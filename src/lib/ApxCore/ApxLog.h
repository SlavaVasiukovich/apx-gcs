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
#ifndef ApxLog_H
#define ApxLog_H
#include <QtCore>
#include <QLoggingCategory>
#include <QMessageLogger>
#include <QMessageLogContext>
//=============================================================================
Q_DECLARE_LOGGING_CATEGORY(AppLog)
Q_DECLARE_LOGGING_CATEGORY(ConsoleLog)

#define APX_LOGGING_CATEGORY(name, ...) Q_LOGGING_CATEGORY(name, __VA_ARGS__)

#ifndef APX_LOGGING_STREAM_MOD
#define APX_LOGGING_STREAM_MOD .noquote()
#endif

#define apxDebug() qDebug() APX_LOGGING_STREAM_MOD

#define apxMsg() \
    QMessageLogger(QT_MESSAGELOG_FILE, \
                   QT_MESSAGELOG_LINE, \
                   QT_MESSAGELOG_FUNC, \
                   AppLog().categoryName()) \
        .info() APX_LOGGING_STREAM_MOD

#define apxMsgW() \
    QMessageLogger(QT_MESSAGELOG_FILE, \
                   QT_MESSAGELOG_LINE, \
                   QT_MESSAGELOG_FUNC, \
                   AppLog().categoryName()) \
        .warning() APX_LOGGING_STREAM_MOD

#define apxConsole() \
    QMessageLogger(QT_MESSAGELOG_FILE, \
                   QT_MESSAGELOG_LINE, \
                   QT_MESSAGELOG_FUNC, \
                   ConsoleLog().categoryName()) \
        .info() APX_LOGGING_STREAM_MOD

#define apxConsoleW() \
    QMessageLogger(QT_MESSAGELOG_FILE, \
                   QT_MESSAGELOG_LINE, \
                   QT_MESSAGELOG_FUNC, \
                   ConsoleLog().categoryName()) \
        .warning() APX_LOGGING_STREAM_MOD

class ApxLog : public QObject
{
    Q_OBJECT
public:
    explicit ApxLog(QObject *parent = nullptr);
    ~ApxLog();

    static void add(const QString &categoryName, const QString &fileName, bool debug);

    static void message(QtMsgType type, const QMessageLogContext &context, const QString &message);

    static bool display(const QMessageLogContext &context);

private:
    static ApxLog *_instance;
    static QMutex _mutex;
    QMap<QString, QTextStream *> streams; //category -> file
    QList<QTextStream *> debugStreams;    //no print to global log

    QTextStream *logStream;
};

//block standard behavior
//#undef qDebug
//#undef qWarning
//#define qWarning(...)   warning("Use apxDebug instead")

//#undef qDebug
//#define qDebug(...)   warning("Use apxDebug instead")

//=============================================================================
#endif
