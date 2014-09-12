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
#include "qtattotimedelta.h"
#include <math.h>
#include <QDebug>
using namespace attodatetime;


QtAttoTimeDelta::QtAttoTimeDelta(qint64 seconds, qint64 atto)
{
    setDelta(seconds, atto);
}

void QtAttoTimeDelta::setDelta(qint64 seconds, qint64 atto)
{
    m_sec = seconds;
    m_ats = qAbs(atto) % AttoPrefix;
}

void QtAttoTimeDelta::incDelta(qint64 seconds, qint64 atto)
{
    m_sec += seconds;
    incAttoSeconds(atto);
}

QtAttoTimeDelta QtAttoTimeDelta::addDelta(qint64 seconds, qint64 atto) const
{
    QtAttoTimeDelta result(m_sec + seconds, atto);
    result.incAttoSeconds(atto);
    return result;
}

qint64 QtAttoTimeDelta::days() const
{
    return m_sec / 86400;
}

qint64 QtAttoTimeDelta::hours() const
{
    return m_sec / 3600;
}

qint64 QtAttoTimeDelta::minutes() const
{
    return m_sec / 60;
}

void QtAttoTimeDelta::setDays(qint64 days)
{
    m_sec = days * 86400;
}

void QtAttoTimeDelta::setHours(qint64 hours)
{
    m_sec = hours * 3600;
}

void QtAttoTimeDelta::setMinutes(qint64 minutes)
{
    m_sec = minutes * 60;
}

QtAttoTimeDelta QtAttoTimeDelta::addDays(qint64 day) const
{
    return QtAttoTimeDelta(m_sec + day*86400, m_ats);
}

QtAttoTimeDelta QtAttoTimeDelta::addHours(qint64 hour) const
{
    return QtAttoTimeDelta(m_sec + hour*3600, m_ats);
}

QtAttoTimeDelta QtAttoTimeDelta::addMinutes(qint64 minute) const
{
    return QtAttoTimeDelta(m_sec + minute*60, m_ats);
}

void QtAttoTimeDelta::incDays(qint64 day)
{
    m_sec += day * 86400;
}

void QtAttoTimeDelta::incHours(qint64 hour)
{
    m_sec += hour * 3600;
}

void QtAttoTimeDelta::incMinutes(qint64 minute)
{
    m_sec += minute * 60;
}

void QtAttoTimeDelta::setSeconds(qint64 seconds)
{
    m_sec = seconds;
    m_ats = 0;
}

qint64 QtAttoTimeDelta::seconds() const
{
    return m_sec;
}

double QtAttoTimeDelta::secondsDouble() const
{
    return static_cast<double>(m_sec) + static_cast<double>(m_ats) / AttoPrefix;
}

qint64 QtAttoTimeDelta::deciSeconds() const
{
    return m_sec * DeciPrefix + m_ats / DeciMul;
}

qint64 QtAttoTimeDelta::centiSeconds() const
{
    return m_sec * CentiPrefix + m_ats / CentiMul;
}

qint64 QtAttoTimeDelta::milliSeconds() const
{
    return m_sec * MilliPrefix + m_ats / MilliMul;
}

qint64 QtAttoTimeDelta::microSeconds() const
{
    return m_sec * MicroPrefix + m_ats / MicroMul;
}

qint64 QtAttoTimeDelta::nanoSeconds() const
{
    return m_sec * NanoPrefix + m_ats / NanoMul;
}

qint64 QtAttoTimeDelta::picoSeconds() const
{
    return m_sec * FemtoPrefix + m_ats / FemtoMul;
}

qint64 QtAttoTimeDelta::femtoSeconds() const
{
    return m_sec * FemtoPrefix + m_ats / FemtoMul;
}

qint64 QtAttoTimeDelta::attoSeconds() const
{
    return m_sec * AttoPrefix + m_ats;
}

void QtAttoTimeDelta::setDeciSeconds(qint64 deciSeconds)
{
    m_sec = m_ats = 0;
    incDeciSeconds(deciSeconds);
}

void QtAttoTimeDelta::setCentiSeconds(qint64 centiSeconds)
{
    m_sec = m_ats = 0;
    incCentiSeconds(centiSeconds);
}

void QtAttoTimeDelta::setMilliSeconds(qint64 milliSeconds)
{
    m_sec = m_ats = 0;
    incMilliSeconds(milliSeconds);
}

void QtAttoTimeDelta::setMicroSeconds(qint64 microSeconds)
{
    m_sec = m_ats = 0;
    incMicroSeconds(microSeconds);
}

void QtAttoTimeDelta::setNanoSeconds(qint64 nanoSeconds)
{
    m_sec = m_ats = 0;
    incNanoSeconds(nanoSeconds);
}

void QtAttoTimeDelta::setPicoSeconds(qint64 picoSeconds)
{
    m_sec = m_ats = 0;
    incPicoSeconds(picoSeconds);
}

void QtAttoTimeDelta::setFemtoSeconds(qint64 femtoSeconds)
{
    m_sec = m_ats = 0;
    incFemtoSeconds(femtoSeconds);
}

void QtAttoTimeDelta::setAttoSeconds(qint64 attoSeconds)
{
    m_sec = m_ats = 0;
    incAttoSeconds(attoSeconds);
}

QtAttoTimeDelta QtAttoTimeDelta::addSeconds(qint64 seconds) const
{
    return QtAttoTimeDelta(m_sec+seconds, m_ats);
}

QtAttoTimeDelta QtAttoTimeDelta::addSecondsDouble(double seconds) const
{
    double fractpart, intpart;
    fractpart = modf (seconds , &intpart);
    return addSeconds(static_cast<qint64>(intpart))
            .addAttoSeconds(static_cast<qint64>(fractpart*AttoPrefix));
}

QtAttoTimeDelta QtAttoTimeDelta::addDeciSeconds(qint64 deciSeconds) const
{
    QtAttoTimeDelta result = *this;
    result.incDeciSeconds(deciSeconds);
    return result;
}

QtAttoTimeDelta QtAttoTimeDelta::addCentiSeconds(qint64 centiSeconds) const
{
    QtAttoTimeDelta result = *this;
    result.incCentiSeconds(centiSeconds);
    return result;
}

QtAttoTimeDelta QtAttoTimeDelta::addMilliSeconds(qint64 milliSeconds) const
{
    QtAttoTimeDelta result = *this;
    result.incMilliSeconds(milliSeconds);
    return result;
}

QtAttoTimeDelta QtAttoTimeDelta::addMicroSeconds(qint64 microSeconds) const
{
    QtAttoTimeDelta result = *this;
    result.incMicroSeconds(microSeconds);
    return result;
}

QtAttoTimeDelta QtAttoTimeDelta::addNanoSeconds(qint64 nanoSeconds) const
{
    QtAttoTimeDelta result = *this;
    result.incNanoSeconds(nanoSeconds);
    return result;
}

QtAttoTimeDelta QtAttoTimeDelta::addPicoSeconds(qint64 picoSeconds) const
{
    QtAttoTimeDelta result = *this;
    result.incPicoSeconds(picoSeconds);
    return result;
}

QtAttoTimeDelta QtAttoTimeDelta::addFemtoSeconds(qint64 femtoSeconds) const
{
    QtAttoTimeDelta result = *this;
    result.incFemtoSeconds(femtoSeconds);
    return result;
}

QtAttoTimeDelta QtAttoTimeDelta::addAttoSeconds(qint64 attoSeconds) const
{
    QtAttoTimeDelta result = *this;
    result.incAttoSeconds(attoSeconds);
    return result;
}

void QtAttoTimeDelta::incDeciSeconds(qint64 deciSeconds)
{
    m_sec += deciSeconds / DeciPrefix;
    incAttoSeconds((deciSeconds%DeciPrefix)*DeciMul);
}

void QtAttoTimeDelta::incCentiSeconds(qint64 centiSeconds)
{
    m_sec += centiSeconds / CentiPrefix;
    incAttoSeconds((centiSeconds%CentiPrefix)*CentiMul);
}

void QtAttoTimeDelta::incMilliSeconds(qint64 milliSeconds)
{
    m_sec += milliSeconds / MilliPrefix;
    incAttoSeconds((milliSeconds%MilliPrefix)*MilliMul);
}

void QtAttoTimeDelta::incMicroSeconds(qint64 microSeconds)
{
    m_sec += microSeconds / MicroPrefix;
    incAttoSeconds((microSeconds%MicroPrefix)*MicroMul);
}

void QtAttoTimeDelta::incNanoSeconds(qint64 nanoSeconds)
{
    m_sec += nanoSeconds / NanoPrefix;
    incAttoSeconds((nanoSeconds%NanoPrefix)*NanoMul);
}

void QtAttoTimeDelta::incPicoSeconds(qint64 picoSeconds)
{
    m_sec += picoSeconds / PicoPrefix;
    incAttoSeconds((picoSeconds%PicoPrefix)*PicoMul);
}

void QtAttoTimeDelta::incFemtoSeconds(qint64 femtoSeconds)
{
    m_sec += femtoSeconds / FemtoPrefix;
    incAttoSeconds((femtoSeconds%FemtoPrefix)*FemtoMul);
}

void QtAttoTimeDelta::incAttoSeconds(qint64 attoSeconds)
{
    m_ats += attoSeconds;
    if (m_ats > 0)
    {
        m_sec += m_ats / AttoPrefix;
        m_ats %= AttoPrefix;
    }
    else if (m_ats < 0)
    {
        m_sec -= qAbs(m_ats)/AttoPrefix;
        m_ats  = qAbs(m_ats)%AttoPrefix;
        if (m_ats > 0)
        {
            m_sec -= 1;
            m_ats  = AttoPrefix - m_ats;
        }
    }
}

qint64 QtAttoTimeDelta::deciPrecision() const
{
    return m_ats / DeciMul;
}

qint64 QtAttoTimeDelta::centiPrecision() const
{
    return m_ats / CentiMul;
}

qint64 QtAttoTimeDelta::milliPrecision() const
{
    return m_ats / MilliMul;
}

qint64 QtAttoTimeDelta::microPrecision() const
{
    return m_ats / MicroMul;
}

qint64 QtAttoTimeDelta::nanoPrecision() const
{
    return m_ats / NanoMul;
}

qint64 QtAttoTimeDelta::picoPrecision() const
{
    return m_ats / PicoMul;
}

qint64 QtAttoTimeDelta::femtoPrecision() const
{
    return m_ats / FemtoMul;
}

qint64 QtAttoTimeDelta::attoPrecision() const
{
    return m_ats;
}

void QtAttoTimeDelta::setDeciPrecision(qint64 deciSeconds)
{
    m_ats = (deciSeconds*DeciMul) % AttoPrefix;
}

void QtAttoTimeDelta::setCentiPrecision(qint64 centiSeconds)
{
    m_ats = (centiSeconds*CentiMul) % AttoPrefix;
}

void QtAttoTimeDelta::setMilliPrecision(qint64 milliSeconds)
{
    m_ats = (milliSeconds*MilliMul) % AttoPrefix;
}

void QtAttoTimeDelta::setMicroPrecision(qint64 microSeconds)
{
    m_ats = (microSeconds*MicroMul) % AttoPrefix;
}

void QtAttoTimeDelta::setNanoPrecision(qint64 nanoSeconds)
{
    m_ats = (nanoSeconds*NanoMul) % AttoPrefix;
}

void QtAttoTimeDelta::setPicoPrecision(qint64 picoSeconds)
{
    m_ats = (picoSeconds*PicoMul) % AttoPrefix;
}

void QtAttoTimeDelta::setFemtoPrecision(qint64 femtoSeconds)
{
    m_ats = (femtoSeconds*FemtoMul) % AttoPrefix;
}

void QtAttoTimeDelta::setAttoPrecision(qint64 attoSeconds)
{
    m_ats = attoSeconds % AttoPrefix;
}

QtAttoTimeDelta &QtAttoTimeDelta::operator = (const QtAttoTimeDelta &other)
{
    if (this == &other)
        return *this;

    this->m_sec = other.m_sec;
    this->m_ats = other.m_ats;

    return *this;
}

QtAttoTimeDelta operator + (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    QtAttoTimeDelta result(a.m_sec + b.m_sec, a.m_ats);
    result.incAttoSeconds(b.m_ats);
    return result;
}

QtAttoTimeDelta operator - (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    QtAttoTimeDelta result(a.m_sec - b.m_sec, a.m_ats);
    result.incAttoSeconds(-b.m_ats);
    return result;
}

QtAttoTimeDelta &operator += (QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    a.m_sec += b.m_sec;
    a.incAttoSeconds(b.m_ats);
    return a;
}

QtAttoTimeDelta &operator -= (QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    a.m_sec -= b.m_sec;
    a.incAttoSeconds(-b.m_ats);
    return a;
}

QDebug operator << (QDebug dbg, const QtAttoTimeDelta &dt)
{
    return dbg.nospace() << "(Sec = " << dt.m_sec
                         << ", AttoPersision = " << dt.m_ats << ")";
}
