// Copyright (C) 2013, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
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
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#ifndef QTATTODATETIME_H
#define QTATTODATETIME_H

#include <QDateTime>
#include <QHash>
#include "qtattotimedelta.h"

// ------------------------------------------------------------------------
class QDebug;

// ------------------------------------------------------------------------
class QtAttoDateTime
{
    friend inline bool operator == (const QtAttoDateTime &a, const QtAttoDateTime &b);
    friend inline bool operator > (const QtAttoDateTime &a, const QtAttoDateTime &b);
    friend inline bool operator < (const QtAttoDateTime &a, const QtAttoDateTime &b);
    friend inline bool operator >= (const QtAttoDateTime &a, const QtAttoDateTime &b);
    friend inline bool operator <= (const QtAttoDateTime &a, const QtAttoDateTime &b);
    friend inline bool operator != (const QtAttoDateTime &a, const QtAttoDateTime &b);
    friend QtAttoDateTime operator + (const QtAttoDateTime &a, const QtAttoTimeDelta &b);
    friend QtAttoDateTime operator - (const QtAttoDateTime &a, const QtAttoTimeDelta &b);
    friend QtAttoDateTime &operator += (QtAttoDateTime &a, const QtAttoTimeDelta &b);
    friend QtAttoDateTime &operator -= (QtAttoDateTime &a, const QtAttoTimeDelta &b);
    friend QDebug operator << (QDebug dbg, const QtAttoDateTime &dt);
public:
    // Constructors
    explicit QtAttoDateTime(qint64 seconds = 0, qint64 atto = 0);
    QtAttoDateTime(const QDateTime &datetime);
    explicit QtAttoDateTime(const QDate &toDate, const QTime &toTime = QTime());
    QtAttoDateTime(int year, int month, int day, int hour, int minute, int second, qint64 atto);

    // Qt
    QDate toDate() const;
    QTime toTime() const;
    QDateTime toDateTime() const;
    void setDate(const QDate &date);
    void setTime(const QTime &time);
    void setDateTime(const QDateTime &dateTime);

    // Baisc
    int year() const;
    int month() const;
    int day() const;
    int dayOfYear() const;
    int hour() const;
    int minute() const;
    int second() const;
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setDayOfYear(int doy);
    void setDate(int year, int month, int day);
    void setDate(int year, int doy);
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    void setTime(int hour, int minute, int second = 0);

    // Day/Hour/Minute
    qint64 days() const;
    qint64 hours() const;
    qint64 minutes() const;
    void setDays(qint64 days);
    void setHours(qint64 hours);
    void setMinutes(qint64 minutes);
    QtAttoDateTime addDays(qint64 day) const;
    QtAttoDateTime addHours(qint64 hour) const;
    QtAttoDateTime addMinutes(qint64 minute) const;
    void incDays(qint64 day);
    void incHours(qint64 hour);
    void incMinutes(qint64 minute);

    // Seconds
    qint64 unixSeconds() const;
    double unixSecondsDouble() const;
    qint64 unixDeciSeconds() const;
    qint64 unixCentiSeconds() const;
    qint64 unixMilliSeconds() const;
    qint64 unixMicroSeconds() const;
    qint64 unixNanoSeconds() const;
    qint64 unixPicoSeconds() const;
    qint64 unixFemtoSeconds() const;
    qint64 unixAttoSeconds() const;
    void setUnixSeconds(qint64 seconds);
    void setUnixDeciSeconds(qint64 deciSeconds);
    void setUnixCentiSeconds(qint64 centiSeconds);
    void setUnixMilliSeconds(qint64 milliSeconds);
    void setUnixMicroSeconds(qint64 microSeconds);
    void setUnixNanoSeconds(qint64 nanoSeconds);
    void setUnixPicoSeconds(qint64 picoSeconds);
    void setUnixFemtoSeconds(qint64 femtoSeconds);
    void setUnixAttoSeconds(qint64 attoSeconds);
    QtAttoDateTime addSeconds(qint64 seconds) const;
    QtAttoDateTime addSecondsDouble(double seconds) const;
    QtAttoDateTime addDeciSeconds(qint64 deciSeconds) const;
    QtAttoDateTime addCentiSeconds(qint64 centiSeconds) const;
    QtAttoDateTime addMilliSeconds(qint64 milliSeconds) const;
    QtAttoDateTime addMicroSeconds(qint64 microSeconds) const;
    QtAttoDateTime addNanoSeconds(qint64 nanoSeconds) const;
    QtAttoDateTime addPicoSeconds(qint64 picoSeconds) const;
    QtAttoDateTime addFemtoSeconds(qint64 femtoSeconds) const;
    QtAttoDateTime addAttoSeconds(qint64 attoSeconds) const;
    void incDeciSeconds(qint64 deciSeconds);
    void incCentiSeconds(qint64 centiSeconds);
    void incMilliSeconds(qint64 milliSeconds);
    void incMicroSeconds(qint64 microSeconds);
    void incNanoSeconds(qint64 nanoSeconds);
    void incPicoSeconds(qint64 picoSeconds);
    void incFemtoSeconds(qint64 femtoSeconds);
    void incAttoSeconds(qint64 attoSeconds);

    // Presision
    qint64 deciPersision() const;
    qint64 centiPersision() const;
    qint64 milliPersision() const;
    qint64 microPersision() const;
    qint64 nanoPersision() const;
    qint64 picoPersision() const;
    qint64 femtoPersision() const;
    qint64 attoPersision() const;
    void setDeciPersision(qint64 deciSeconds);
    void setCentiPersision(qint64 centiSeconds);
    void setMilliPersision(qint64 milliSeconds);
    void setMicroPersision(qint64 microSeconds);
    void setNanoPersision(qint64 nanoSeconds);
    void setPicoPersision(qint64 picoSeconds);
    void setFemtoPersision(qint64 femtoSeconds);
    void setAttoPersision(qint64 attoSeconds);

    // operators
    QtAttoDateTime &operator = (const QtAttoDateTime &other);

    // Strings
    QString toString(const QString &format) const;

public:
    // Conversion
    static qint64 attoFromDeci(qint64 deciSeconds);
    static qint64 attoFromCenti(qint64 centiSeconds);
    static qint64 attoFromMilli(qint64 milliSeconds);
    static qint64 attoFromMicro(qint64 microSeconds);
    static qint64 attoFromNano(qint64 nanoSeconds);
    static qint64 attoFromPico(qint64 picoSeconds);
    static qint64 attoFromFemto(qint64 femtoSeconds);
    static qint64 deciFromAtto(qint64 attoSeconds);
    static qint64 centiFromAtto(qint64 attoSeconds);
    static qint64 milliFromAtto(qint64 attoSeconds);
    static qint64 microFromAtto(qint64 attoSeconds);
    static qint64 nanoFromAtto(qint64 attoSeconds);
    static qint64 picoFromAtto(qint64 attoSeconds);
    static qint64 femtoFromAtto(qint64 attoSeconds);

    // Conversion
    static QtAttoDateTime fromDateTime(const QDateTime &dateTime);

    //
    static QtAttoDateTime fromUnixSeconds(qint64 seconds);
    static QtAttoDateTime fromUnixDeciSeconds(qint64 deciSeconds);
    static QtAttoDateTime fromUnixCentiSeconds(qint64 centiSeconds);
    static QtAttoDateTime fromUnixMilliSeconds(qint64 milliSeconds);
    static QtAttoDateTime fromUnixMicroSeconds(qint64 microSeconds);
    static QtAttoDateTime fromUnixNanoSeconds(qint64 nanoSeconds);
    static QtAttoDateTime fromUnixPicoSeconds(qint64 picoSeconds);
    static QtAttoDateTime fromUnixFemtoSeconds(qint64 femtoSeconds);
    static QtAttoDateTime fromUnixAttoSeconds(qint64 attoSeconds);

    // System clock
    static QtAttoDateTime currentDateTime();

    // Strings
    static QtAttoDateTime fromString(const QString &string, const QString &format);

private:
    // The QtAttoDateTime representation
    // Seconds, since 1 Jan 1970 (it is unixtime)
    qint64 mSec;
    // Attoseconds, as presision of the seconds [1..999 999 999 999 999 999]
    qint64 mAts;
};
Q_DECLARE_METATYPE(QtAttoDateTime)

// ----------------------------------------------------------------------
inline bool operator == (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return (a.mSec == b.mSec) && (a.mAts == b.mAts);
}

inline bool operator > (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return (a.mSec > b.mSec) || (((a.mSec == b.mSec) && (a.mAts > b.mAts)));
}

inline bool operator < (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return (a.mSec < b.mSec) || (((a.mSec == b.mSec) && (a.mAts < b.mAts)));
}

inline bool operator >= (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return (a.mSec > b.mSec) || (((a.mSec == b.mSec) && (a.mAts >= b.mAts)));
}

inline bool operator <= (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return (a.mSec < b.mSec) || (((a.mSec == b.mSec) && (a.mAts <= b.mAts)));
}

inline bool operator != (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return (a.mSec != b.mSec) || (a.mAts != b.mAts);
}

// ------------------------------------------------------------------------
QtAttoDateTime operator + (const QtAttoDateTime &a, const QtAttoTimeDelta &b);
QtAttoDateTime operator - (const QtAttoDateTime &a, const QtAttoTimeDelta &b);
QtAttoDateTime &operator += (QtAttoDateTime &a, const QtAttoTimeDelta &b);
QtAttoDateTime &operator -= (QtAttoDateTime &a, const QtAttoTimeDelta &b);

// ------------------------------------------------------------------------
QDebug operator << (QDebug dbg, const QtAttoDateTime &dt);

// ------------------------------------------------------------------------
//QDataStream &operator << (QDataStream &out, const QgeDateTime &dt);
//QDataStream &operator >> (QDataStream &out, const QgeDateTime &dt);

// ------------------------------------------------------------------------
inline uint qHash(const QtAttoDateTime &key)
{
    return qHash(key.unixSeconds()) ^ qHash(key.attoPersision());
}

#endif
