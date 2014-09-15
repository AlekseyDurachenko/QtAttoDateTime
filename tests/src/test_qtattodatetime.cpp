// Copyright (C) 2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
#include "test_qtattodatetime.h"
#include <QtAttoDateTime>
#include <QDebug>


TestQtAttoDateTime::TestQtAttoDateTime(QObject *parent) :
    QObject(parent)
{
}

void TestQtAttoDateTime::constructor_001()
{
    QtAttoDateTime dateTime_001(0, 0);
    QVERIFY(dateTime_001.unixSeconds() == 0
            && dateTime_001.attoPrecision() == 0);

    QtAttoDateTime dateTime_002(13, 44);
    QVERIFY(dateTime_002.unixSeconds() == 13
            && dateTime_002.attoPrecision() == 44);

    QtAttoDateTime dateTime_004(123456789, 999999999999999999LL);
    QVERIFY(dateTime_004.unixSeconds() == 123456789
            && dateTime_004.attoPrecision() == 999999999999999999LL);
}

void TestQtAttoDateTime::constructor_002()
{
    QtAttoDateTime dateTime_001(QDateTime(QDate(1970, 1, 1),
                                          QTime(0, 0, 0, 0), Qt::UTC));
    QVERIFY(dateTime_001.unixSeconds() == 0
            && dateTime_001.attoPrecision() == 0);

    QtAttoDateTime dateTime_002(QDateTime(QDate(1970, 1, 2),
                                          QTime(0, 0, 0, 0), Qt::UTC));
    QVERIFY(dateTime_002.unixSeconds() == 86400
            && dateTime_002.attoPrecision() == 0);

    QtAttoDateTime dateTime_003(QDateTime(QDate(1970, 1, 2),
                                          QTime(0, 0, 1, 999), Qt::UTC));
    QVERIFY(dateTime_003.unixSeconds() == 86401
            && dateTime_003.attoPrecision() == 999000000000000000LL);
}

void TestQtAttoDateTime::constructor_003()
{
    QtAttoDateTime dateTime_001(QDate(1970, 1, 1), QTime(0, 0, 0, 0));
    QVERIFY(dateTime_001.unixSeconds() == 0
            && dateTime_001.attoPrecision() == 0);

    QtAttoDateTime dateTime_002(QDate(1970, 1, 2), QTime(0, 0, 0, 0));
    QVERIFY(dateTime_002.unixSeconds() == 86400
            && dateTime_002.attoPrecision() == 0);

    QtAttoDateTime dateTime_003(QDate(1970, 1, 2), QTime(0, 0, 1, 999));
    QVERIFY(dateTime_003.unixSeconds() == 86401
            && dateTime_003.attoPrecision() == 999000000000000000LL);
}

void TestQtAttoDateTime::constructor_004()
{
    QtAttoDateTime dateTime_001(1970, 1, 1, 0, 0, 0, 0);
    QVERIFY(dateTime_001.unixSeconds() == 0
            && dateTime_001.attoPrecision() == 0);

    QtAttoDateTime dateTime_002(1970, 1, 2, 0, 0, 0, 0);
    QVERIFY(dateTime_002.unixSeconds() == 86400
            && dateTime_002.attoPrecision() == 0);

    QtAttoDateTime dateTime_003(1970, 1, 2, 0, 0, 1, 999000000000000999LL);
    QVERIFY(dateTime_003.unixSeconds() == 86401
            && dateTime_003.attoPrecision() == 999000000000000999LL);
}

void TestQtAttoDateTime::toDate()
{
    QtAttoDateTime dateTime_001(QDate(1970, 1, 1), QTime(0, 0, 0, 0));
    QVERIFY(dateTime_001.toDate() == QDate(1970, 1, 1));

    QtAttoDateTime dateTime_002(QDate(2010, 10, 11), QTime(23, 59, 59, 999));
    QVERIFY(dateTime_002.toDate() == QDate(2010, 10, 11));

    QtAttoDateTime dateTime_003(QDate(2000, 1, 1), QTime(10, 10, 10, 10));
    QVERIFY(dateTime_003.toDate() == QDate(2000, 1, 1));
}

void TestQtAttoDateTime::toTime()
{
    QtAttoDateTime dateTime_001(QDate(1970, 1, 1), QTime(0, 0, 0, 0));
    QVERIFY(dateTime_001.toTime() == QTime(0, 0, 0, 0));

    QtAttoDateTime dateTime_002(QDate(2010, 10, 11), QTime(23, 59, 59, 999));
    QVERIFY(dateTime_002.toTime() == QTime(23, 59, 59, 999));

    QtAttoDateTime dateTime_003(QDate(2000, 1, 1), QTime(10, 10, 10, 10));
    QVERIFY(dateTime_003.toTime() == QTime(10, 10, 10, 10));
}

void TestQtAttoDateTime::toDateTime()
{
    QtAttoDateTime dateTime_001(QDate(1970, 1, 1), QTime(0, 0, 0, 0));
    QVERIFY(dateTime_001.toDateTime()
            == QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0, 0), Qt::UTC));

    QtAttoDateTime dateTime_002(QDate(2010, 10, 11), QTime(23, 59, 59, 999));
    QVERIFY(dateTime_002.toDateTime()
            == QDateTime(QDate(2010, 10, 11), QTime(23, 59, 59, 999), Qt::UTC));

    QtAttoDateTime dateTime_003(QDate(2000, 1, 1), QTime(10, 10, 10, 10));
    QVERIFY(dateTime_003.toDateTime()
            == QDateTime(QDate(2000, 1, 1), QTime(10, 10, 10, 10), Qt::UTC));
}

void TestQtAttoDateTime::setDate()
{
    QtAttoDateTime dateTime_001(QDate(2000, 1, 1), QTime(0, 0, 0, 0));
    dateTime_001.setDate(QDate(1970, 1, 1));
    QVERIFY(dateTime_001.toDateTime()
            == QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0, 0), Qt::UTC));

    QtAttoDateTime dateTime_002(QDate(1970, 1, 1), QTime(23, 59, 59, 999));
    dateTime_002.setDate(QDate(2010, 10, 11));
    QVERIFY(dateTime_002.toDateTime()
            == QDateTime(QDate(2010, 10, 11), QTime(23, 59, 59, 999), Qt::UTC));

    QtAttoDateTime dateTime_003(QDate(1970, 1, 1), QTime(10, 10, 10, 10));
    dateTime_003.setDate(QDate(2000, 1, 1));
    QVERIFY(dateTime_003.toDateTime()
            == QDateTime(QDate(2000, 1, 1), QTime(10, 10, 10, 10), Qt::UTC));
}

void TestQtAttoDateTime::setTime()
{
    QtAttoDateTime dateTime_001(QDate(1970, 1, 1), QTime(10, 10, 10, 10));
    dateTime_001.setTime(QTime(0, 0, 0, 0));
    QVERIFY(dateTime_001.toDateTime()
            == QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0, 0), Qt::UTC));

    QtAttoDateTime dateTime_002(QDate(2010, 10, 11), QTime(0, 0, 0, 0));
    dateTime_002.setTime(QTime(23, 59, 59, 999));
    QVERIFY(dateTime_002.toDateTime()
            == QDateTime(QDate(2010, 10, 11), QTime(23, 59, 59, 999), Qt::UTC));

    QtAttoDateTime dateTime_003(QDate(2000, 1, 1), QTime(0, 0, 0, 0));
    dateTime_003.setTime(QTime(10, 10, 10, 10));
    QVERIFY(dateTime_003.toDateTime()
            == QDateTime(QDate(2000, 1, 1), QTime(10, 10, 10, 10), Qt::UTC));
}

void TestQtAttoDateTime::setDateTime()
{
    QtAttoDateTime dateTime_001(QDate(1974, 3, 11), QTime(40, 3, 2, 1));
    dateTime_001.setDateTime(QDateTime(QDate(1970, 1, 1),
                                       QTime(0, 0, 0, 0), Qt::UTC));
    QVERIFY(dateTime_001.toDateTime()
            == QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0, 0), Qt::UTC));

    QtAttoDateTime dateTime_002(QDate(1974, 3, 11), QTime(40, 3, 2, 1));
    dateTime_002.setDateTime(QDateTime(QDate(2010, 10, 11),
                                       QTime(23, 59, 59, 999), Qt::UTC));
    QVERIFY(dateTime_002.toDateTime()
            == QDateTime(QDate(2010, 10, 11), QTime(23, 59, 59, 999), Qt::UTC));

    QtAttoDateTime dateTime_003(QDate(1974, 3, 11), QTime(40, 3, 2, 1));
    dateTime_003.setDateTime(QDateTime(QDate(2000, 1, 1),
                                       QTime(10, 10, 10, 10), Qt::UTC));
    QVERIFY(dateTime_003.toDateTime()
            == QDateTime(QDate(2000, 1, 1), QTime(10, 10, 10, 10), Qt::UTC));
}
