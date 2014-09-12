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
#ifndef QTATTOTIMEDELTA_H
#define QTATTOTIMEDELTA_H

#include "qtattotimeconst.h"
#include <QtGlobal>
#include <QMetaType>
class QDebug;
class QtAttoDateTime;


class QtAttoTimeDelta
{
public:
    // Constructors
    explicit QtAttoTimeDelta(qint64 seconds = 0, qint64 atto = 0);

    // Delta
    void setDelta(qint64 seconds, qint64 atto);
    QtAttoTimeDelta addDelta(qint64 seconds, qint64 atto) const;
    void incDelta(qint64 seconds, qint64 atto);

    // Day/Hour/Minute
    qint64 days() const;
    qint64 hours() const;
    qint64 minutes() const;
    void setDays(qint64 days);
    void setHours(qint64 hours);
    void setMinutes(qint64 minutes);
    QtAttoTimeDelta addDays(qint64 day) const;
    QtAttoTimeDelta addHours(qint64 hour) const;
    QtAttoTimeDelta addMinutes(qint64 minute) const;
    void incDays(qint64 day);
    void incHours(qint64 hour);
    void incMinutes(qint64 minute);

    // Seconds
    qint64 seconds() const;
    double secondsDouble() const;
    qint64 deciSeconds() const;
    qint64 centiSeconds() const;
    qint64 milliSeconds() const;
    qint64 microSeconds() const;
    qint64 nanoSeconds() const;
    qint64 picoSeconds() const;
    qint64 femtoSeconds() const;
    qint64 attoSeconds() const;
    void setSeconds(qint64 seconds);
    void setDeciSeconds(qint64 deciSeconds);
    void setCentiSeconds(qint64 centiSeconds);
    void setMilliSeconds(qint64 milliSeconds);
    void setMicroSeconds(qint64 microSeconds);
    void setNanoSeconds(qint64 nanoSeconds);
    void setPicoSeconds(qint64 picoSeconds);
    void setFemtoSeconds(qint64 femtoSeconds);
    void setAttoSeconds(qint64 attoSeconds);
    QtAttoTimeDelta addSeconds(qint64 seconds) const;
    QtAttoTimeDelta addSecondsDouble(double seconds) const;
    QtAttoTimeDelta addDeciSeconds(qint64 deciSeconds) const;
    QtAttoTimeDelta addCentiSeconds(qint64 centiSeconds) const;
    QtAttoTimeDelta addMilliSeconds(qint64 milliSeconds) const;
    QtAttoTimeDelta addMicroSeconds(qint64 microSeconds) const;
    QtAttoTimeDelta addNanoSeconds(qint64 nanoSeconds) const;
    QtAttoTimeDelta addPicoSeconds(qint64 picoSeconds) const;
    QtAttoTimeDelta addFemtoSeconds(qint64 femtoSeconds) const;
    QtAttoTimeDelta addAttoSeconds(qint64 attoSeconds) const;
    void incDeciSeconds(qint64 deciSeconds);
    void incCentiSeconds(qint64 centiSeconds);
    void incMilliSeconds(qint64 milliSeconds);
    void incMicroSeconds(qint64 microSeconds);
    void incNanoSeconds(qint64 nanoSeconds);
    void incPicoSeconds(qint64 picoSeconds);
    void incFemtoSeconds(qint64 femtoSeconds);
    void incAttoSeconds(qint64 attoSeconds);

    // Presision
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

    // operators
    QtAttoTimeDelta &operator = (const QtAttoTimeDelta &other);
private:
    friend inline bool operator == (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend inline bool operator != (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend inline bool operator >= (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend inline bool operator <= (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend inline bool operator >  (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend inline bool operator <  (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend QtAttoTimeDelta operator + (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend QtAttoTimeDelta operator - (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend QtAttoTimeDelta &operator += (QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend QtAttoTimeDelta &operator -= (QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
    friend QtAttoDateTime operator + (const QtAttoDateTime &a, const QtAttoTimeDelta &b);
    friend QtAttoDateTime operator - (const QtAttoDateTime &a, const QtAttoTimeDelta &b);
    friend QtAttoDateTime &operator += (QtAttoDateTime &a, const QtAttoTimeDelta &b);
    friend QtAttoDateTime &operator -= (QtAttoDateTime &a, const QtAttoTimeDelta &b);
    friend QDebug operator << (QDebug dbg, const QtAttoTimeDelta &dt);
private:
    // The QtAttoTimeDelta representation
    // Seconds, since 1 Jan 1970 (it is unixtime)
    qint64 m_sec;
    // Attoseconds, value in range [0..999 999 999 999 999 999]
    qint64 m_ats;
};
Q_DECLARE_METATYPE(QtAttoTimeDelta)


inline bool operator == (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    return ((a.m_sec == b.m_sec) && (a.m_ats == b.m_ats));
}

inline bool operator != (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    return ((a.m_sec != b.m_sec) || (a.m_ats != b.m_ats));
}

inline bool operator >= (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    return ((a.m_sec > b.m_sec)
            || (((a.m_sec == b.m_sec) && (a.m_ats >= b.m_ats))));
}

inline bool operator <= (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    return ((a.m_sec < b.m_sec)
            || (((a.m_sec == b.m_sec) && (a.m_ats <= b.m_ats))));
}

inline bool operator > (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    return ((a.m_sec > b.m_sec)
            || (((a.m_sec == b.m_sec) && (a.m_ats > b.m_ats))));
}

inline bool operator < (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    return ((a.m_sec < b.m_sec)
            || (((a.m_sec == b.m_sec) && (a.m_ats < b.m_ats))));
}


QtAttoTimeDelta operator + (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
QtAttoTimeDelta operator - (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
QtAttoTimeDelta &operator += (QtAttoTimeDelta &a, const QtAttoTimeDelta &b);
QtAttoTimeDelta &operator -= (QtAttoTimeDelta &a, const QtAttoTimeDelta &b);


QDebug operator << (QDebug dbg, const QtAttoTimeDelta &dt);
//QDataStream &operator << (QDataStream &out, const QgeTimeDelta &dt);
//QDataStream &operator >> (QDataStream &out, const QgeTimeDelta &dt);


#endif // QTATTOTIMEDELTA_H
