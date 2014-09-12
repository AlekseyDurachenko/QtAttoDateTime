// Copyright (C) 2013-2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
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
#ifndef QTATTODATETIME_H
#define QTATTODATETIME_H

#include "qtattotimedelta.h"
#include <QDateTime>
#include <QHash>
class QDebug;


class QtAttoDateTime
{
public:
    explicit QtAttoDateTime(qint64 seconds = 0, qint64 atto = 0);
    explicit QtAttoDateTime(const QDateTime &datetime);
    explicit QtAttoDateTime(const QDate &toDate, const QTime &toTime = QTime());
    QtAttoDateTime(int year, int month, int day, int hour, int minute, int second, qint64 atto);

    // Converting from/to Qt datatypes
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

    // Precision
    qint64 deciPrecision() const;
    qint64 centiPrecision() const;
    qint64 milliPrecision() const;
    qint64 microPrecision() const;
    qint64 nanoPrecision() const;
    qint64 picoPrecision() const;
    qint64 femtoPrecision() const;
    qint64 attoPrecision() const;
    void setDeciPrecision(qint64 deciSeconds);
    void setCentiPrecision(qint64 centiSeconds);
    void setMilliPrecision(qint64 milliSeconds);
    void setMicroPrecision(qint64 microSeconds);
    void setNanoPrecision(qint64 nanoSeconds);
    void setPicoPrecision(qint64 picoSeconds);
    void setFemtoPrecision(qint64 femtoSeconds);
    void setAttoPrecision(qint64 attoSeconds);

    // Operators
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
private:
    // The QtAttoDateTime representation
    // Seconds, since 1 Jan 1970 (it is unixtime)
    qint64 m_sec;
    // Attoseconds, value in range [0..999 999 999 999 999 999]
    qint64 m_ats;
};
Q_DECLARE_METATYPE(QtAttoDateTime)


inline bool operator == (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return ((a.m_sec == b.m_sec) && (a.m_ats == b.m_ats));
}

inline bool operator > (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return ((a.m_sec > b.m_sec)
            || (((a.m_sec == b.m_sec) && (a.m_ats > b.m_ats))));
}

inline bool operator < (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return ((a.m_sec < b.m_sec)
            || (((a.m_sec == b.m_sec) && (a.m_ats < b.m_ats))));
}

inline bool operator >= (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return ((a.m_sec > b.m_sec)
            || (((a.m_sec == b.m_sec) && (a.m_ats >= b.m_ats))));
}

inline bool operator <= (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return ((a.m_sec < b.m_sec)
            || (((a.m_sec == b.m_sec) && (a.m_ats <= b.m_ats))));
}

inline bool operator != (const QtAttoDateTime &a, const QtAttoDateTime &b)
{
    return ((a.m_sec != b.m_sec) || (a.m_ats != b.m_ats));
}


QtAttoDateTime operator + (const QtAttoDateTime &a, const QtAttoTimeDelta &b);
QtAttoDateTime operator - (const QtAttoDateTime &a, const QtAttoTimeDelta &b);
QtAttoDateTime &operator += (QtAttoDateTime &a, const QtAttoTimeDelta &b);
QtAttoDateTime &operator -= (QtAttoDateTime &a, const QtAttoTimeDelta &b);


QDebug operator << (QDebug dbg, const QtAttoDateTime &dt);
//QDataStream &operator << (QDataStream &out, const QgeDateTime &dt);
//QDataStream &operator >> (QDataStream &out, const QgeDateTime &dt);


inline uint qHash(const QtAttoDateTime &key)
{
    return qHash(key.unixSeconds()) ^ qHash(key.attoPrecision());
}


#endif
