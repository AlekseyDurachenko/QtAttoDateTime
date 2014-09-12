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
#include "qtattodatetime.h"
#include <QDebug>
#include <math.h>
using namespace attodatetime;


QtAttoDateTime::QtAttoDateTime(qint64 seconds, qint64 atto)
{
    m_sec = seconds;
    m_ats = qAbs(atto)%AttoPrefix;
}

QtAttoDateTime::QtAttoDateTime(const QDateTime &dateTime)
{
    setDateTime(dateTime);
}

QtAttoDateTime::QtAttoDateTime(const QDate &date, const QTime &time)
{
    setDateTime(QDateTime(date, time, Qt::UTC));
}

QtAttoDateTime::QtAttoDateTime(int year, int month, int day,
        int hour, int minute, int second, qint64 atto)
{
    setDateTime(QDateTime(QDate(year, month, day),
                          QTime(hour, minute, second),
                          Qt::UTC));
    incAttoSeconds(atto);
}

QDate QtAttoDateTime::toDate() const
{
    return toDateTime().date();
}

QTime QtAttoDateTime::toTime() const
{
    return toDateTime().time();
}

QDateTime QtAttoDateTime::toDateTime() const
{
    return QDateTime::fromMSecsSinceEpoch(unixMilliSeconds()).toUTC();
}

void QtAttoDateTime::setDate(const QDate &date)
{
    qint64 days = QDate(1970, 1, 1).daysTo(date);
    m_sec = m_sec%86400 + days*86400;
}

void QtAttoDateTime::setTime(const QTime &time)
{
    setDateTime(QDateTime(toDate(), time, Qt::UTC));
}

void QtAttoDateTime::setDateTime(const QDateTime &dateTime)
{
    setUnixSeconds(dateTime.toTime_t());
    incMilliSeconds(dateTime.time().msec());
}

int QtAttoDateTime::year() const
{
    return toDate().year();
}

int QtAttoDateTime::month() const
{
    return toDate().month();
}

int QtAttoDateTime::day() const
{
    return toDate().day();
}

int QtAttoDateTime::dayOfYear() const
{
    return toDate().dayOfYear();
}

int QtAttoDateTime::hour() const
{
    return toTime().hour();
}

int QtAttoDateTime::minute() const
{
    return toTime().minute();
}

int QtAttoDateTime::second() const
{
    return toTime().second();
}

void QtAttoDateTime::setYear(int year)
{
    setDate(year, month(), day());
}

void QtAttoDateTime::setMonth(int month)
{
    setDate(year(), month, day());
}

void QtAttoDateTime::setDay(int day)
{
    setDate(year(), month(), day);
}

void QtAttoDateTime::setDayOfYear(int doy)
{
    setDate(QDate(year(), 1, 1).addDays(doy));
}

void QtAttoDateTime::setDate(int year, int month, int day)
{
    setDate(QDate(year, month, day));
}

void QtAttoDateTime::setDate(int year, int doy)
{
    setDate(QDate(year, 1, 1).addDays(doy));
}

void QtAttoDateTime::setHour(int hour)
{
    setTime(hour, minute(), second());
}

void QtAttoDateTime::setMinute(int minute)
{
    setTime(hour(), minute, second());
}

void QtAttoDateTime::setSecond(int second)
{
    setTime(hour(), minute(), second);
}

void QtAttoDateTime::setTime(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}

qint64 QtAttoDateTime::days() const
{
    return m_sec/86400;
}

qint64 QtAttoDateTime::hours() const
{
    return m_sec/3600;
}

qint64 QtAttoDateTime::minutes() const
{
    return m_sec/60;
}

void QtAttoDateTime::setDays(qint64 days)
{
    m_sec = days*86400;
}

void QtAttoDateTime::setHours(qint64 hours)
{
    m_sec = hours*3600;
}

void QtAttoDateTime::setMinutes(qint64 minutes)
{
    m_sec = minutes*60;
}

QtAttoDateTime QtAttoDateTime::addDays(qint64 day) const
{
    return QtAttoDateTime(m_sec + day*86400, m_ats);
}

QtAttoDateTime QtAttoDateTime::addHours(qint64 hour) const
{
    return QtAttoDateTime(m_sec + hour*3600, m_ats);
}

QtAttoDateTime QtAttoDateTime::addMinutes(qint64 minute) const
{
    return QtAttoDateTime(m_sec + minute*60, m_ats);
}

void QtAttoDateTime::incDays(qint64 day)
{
    m_sec += day*86400;
}

void QtAttoDateTime::incHours(qint64 hour)
{
    m_sec += hour*3600;
}

void QtAttoDateTime::incMinutes(qint64 minute)
{
    m_sec += minute*60;
}

qint64 QtAttoDateTime::unixSeconds() const
{
    return m_sec;
}

double QtAttoDateTime::unixSecondsDouble() const
{
    return static_cast<double>(m_sec) + static_cast<double>(m_ats)/AttoPrefix;
}

qint64 QtAttoDateTime::unixDeciSeconds() const
{
    return m_sec*DeciPrefix + m_ats/DeciMul;
}

qint64 QtAttoDateTime::unixCentiSeconds() const
{
    return m_sec*CentiPrefix + m_ats/CentiMul;
}

qint64 QtAttoDateTime::unixMilliSeconds() const
{
    return m_sec*MilliPrefix + m_ats/MilliMul;
}

qint64 QtAttoDateTime::unixMicroSeconds() const
{
    return m_sec*MicroPrefix + m_ats/MicroMul;
}

qint64 QtAttoDateTime::unixNanoSeconds() const
{
    return m_sec*NanoPrefix + m_ats/NanoMul;
}

qint64 QtAttoDateTime::unixPicoSeconds() const
{
    return m_sec*FemtoPrefix + m_ats/FemtoMul;
}

qint64 QtAttoDateTime::unixFemtoSeconds() const
{
    return m_sec*FemtoPrefix + m_ats/FemtoMul;
}

qint64 QtAttoDateTime::unixAttoSeconds() const
{
    return m_sec*AttoPrefix + m_ats;
}

void QtAttoDateTime::setUnixSeconds(qint64 seconds)
{
    m_sec = seconds;
    m_ats = 0;
}

void QtAttoDateTime::setUnixDeciSeconds(qint64 deciSeconds)
{
    m_sec = m_ats = 0;
    incDeciSeconds(deciSeconds);
}

void QtAttoDateTime::setUnixCentiSeconds(qint64 centiSeconds)
{
    m_sec = m_ats = 0;
    incCentiSeconds(centiSeconds);
}

void QtAttoDateTime::setUnixMilliSeconds(qint64 milliSeconds)
{
    m_sec = m_ats = 0;
    incMilliSeconds(milliSeconds);
}

void QtAttoDateTime::setUnixMicroSeconds(qint64 microSeconds)
{
    m_sec = m_ats = 0;
    incMicroSeconds(microSeconds);
}

void QtAttoDateTime::setUnixNanoSeconds(qint64 nanoSeconds)
{
    m_sec = m_ats = 0;
    incNanoSeconds(nanoSeconds);
}

void QtAttoDateTime::setUnixPicoSeconds(qint64 picoSeconds)
{
    m_sec = m_ats = 0;
    incPicoSeconds(picoSeconds);
}

void QtAttoDateTime::setUnixFemtoSeconds(qint64 femtoSeconds)
{
    m_sec = m_ats = 0;
    incFemtoSeconds(femtoSeconds);
}

void QtAttoDateTime::setUnixAttoSeconds(qint64 attoSeconds)
{
    m_sec = m_ats = 0;
    incAttoSeconds(attoSeconds);
}

QtAttoDateTime QtAttoDateTime::addSeconds(qint64 seconds) const
{
    return QtAttoDateTime(m_sec + seconds, m_ats);
}

QtAttoDateTime QtAttoDateTime::addSecondsDouble(double seconds) const
{
    double fractpart, intpart;
    fractpart = modf (seconds , &intpart);
    return addSeconds(static_cast<qint64>(intpart))
            .addAttoSeconds(static_cast<qint64>(fractpart*AttoPrefix));
}

QtAttoDateTime QtAttoDateTime::addDeciSeconds(qint64 deciSeconds) const
{
    QtAttoDateTime result = *this;
    result.incDeciSeconds(deciSeconds);
    return result;
}

QtAttoDateTime QtAttoDateTime::addCentiSeconds(qint64 centiSeconds) const
{
    QtAttoDateTime result = *this;
    result.incCentiSeconds(centiSeconds);
    return result;
}

QtAttoDateTime QtAttoDateTime::addMilliSeconds(qint64 milliSeconds) const
{
    QtAttoDateTime result = *this;
    result.incMilliSeconds(milliSeconds);
    return result;
}

QtAttoDateTime QtAttoDateTime::addMicroSeconds(qint64 microSeconds) const
{
    QtAttoDateTime result = *this;
    result.incMicroSeconds(microSeconds);
    return result;
}

QtAttoDateTime QtAttoDateTime::addNanoSeconds(qint64 nanoSeconds) const
{
    QtAttoDateTime result = *this;
    result.incNanoSeconds(nanoSeconds);
    return result;
}

QtAttoDateTime QtAttoDateTime::addPicoSeconds(qint64 picoSeconds) const
{
    QtAttoDateTime result = *this;
    result.incPicoSeconds(picoSeconds);
    return result;
}

QtAttoDateTime QtAttoDateTime::addFemtoSeconds(qint64 femtoSeconds) const
{
    QtAttoDateTime result = *this;
    result.incFemtoSeconds(femtoSeconds);
    return result;
}

QtAttoDateTime QtAttoDateTime::addAttoSeconds(qint64 attoSeconds) const
{
    QtAttoDateTime result = *this;
    result.incAttoSeconds(attoSeconds);
    return result;
}

void QtAttoDateTime::incDeciSeconds(qint64 deciSeconds)
{
    m_sec += deciSeconds/DeciPrefix;
    incAttoSeconds((deciSeconds%DeciPrefix)*DeciMul);
}

void QtAttoDateTime::incCentiSeconds(qint64 centiSeconds)
{
    m_sec += centiSeconds/CentiPrefix;
    incAttoSeconds((centiSeconds%CentiPrefix)*CentiMul);
}

void QtAttoDateTime::incMilliSeconds(qint64 milliSeconds)
{
    m_sec += milliSeconds/MilliPrefix;
    incAttoSeconds((milliSeconds%MilliPrefix)*MilliMul);
}

void QtAttoDateTime::incMicroSeconds(qint64 microSeconds)
{
    m_sec += microSeconds/MicroPrefix;
    incAttoSeconds((microSeconds%MicroPrefix)*MicroMul);
}

void QtAttoDateTime::incNanoSeconds(qint64 nanoSeconds)
{
    m_sec += nanoSeconds/NanoPrefix;
    incAttoSeconds((nanoSeconds%NanoPrefix)*NanoMul);
}

void QtAttoDateTime::incPicoSeconds(qint64 picoSeconds)
{
    m_sec += picoSeconds/PicoPrefix;
    incAttoSeconds((picoSeconds%PicoPrefix)*PicoMul);
}

void QtAttoDateTime::incFemtoSeconds(qint64 femtoSeconds)
{
    m_sec += femtoSeconds/FemtoPrefix;
    incAttoSeconds((femtoSeconds%FemtoPrefix)*FemtoMul);
}

void QtAttoDateTime::incAttoSeconds(qint64 attoSeconds)
{
    m_ats += attoSeconds;
    if (m_ats > 0)
    {
        m_sec += m_ats/AttoPrefix;
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

qint64 QtAttoDateTime::deciPrecision() const
{
    return m_ats/DeciMul;
}

qint64 QtAttoDateTime::centiPrecision() const
{
    return m_ats/CentiMul;
}

qint64 QtAttoDateTime::milliPrecision() const
{
    return m_ats/MilliMul;
}

qint64 QtAttoDateTime::microPrecision() const
{
    return m_ats/MicroMul;
}

qint64 QtAttoDateTime::nanoPrecision() const
{
    return m_ats/NanoMul;
}

qint64 QtAttoDateTime::picoPrecision() const
{
    return m_ats/PicoMul;
}

qint64 QtAttoDateTime::femtoPrecision() const
{
    return m_ats/FemtoMul;
}

qint64 QtAttoDateTime::attoPrecision() const
{
    return m_ats;
}

void QtAttoDateTime::setDeciPrecision(qint64 deciSeconds)
{
    m_ats = (deciSeconds*DeciMul)%AttoPrefix;
}

void QtAttoDateTime::setCentiPrecision(qint64 centiSeconds)
{
    m_ats = (centiSeconds*CentiMul)%AttoPrefix;
}

void QtAttoDateTime::setMilliPrecision(qint64 milliSeconds)
{
    m_ats = (milliSeconds*MilliMul)%AttoPrefix;
}

void QtAttoDateTime::setMicroPrecision(qint64 microSeconds)
{
    m_ats = (microSeconds*MicroMul)%AttoPrefix;
}

void QtAttoDateTime::setNanoPrecision(qint64 nanoSeconds)
{
    m_ats = (nanoSeconds*NanoMul)%AttoPrefix;
}

void QtAttoDateTime::setPicoPrecision(qint64 picoSeconds)
{
    m_ats = (picoSeconds*PicoMul)%AttoPrefix;
}

void QtAttoDateTime::setFemtoPrecision(qint64 femtoSeconds)
{
    m_ats = (femtoSeconds*FemtoMul)%AttoPrefix;
}

void QtAttoDateTime::setAttoPrecision(qint64 attoSeconds)
{
    m_ats = attoSeconds%AttoPrefix;
}

QtAttoDateTime &QtAttoDateTime::operator = (const QtAttoDateTime &other)
{
    if (this == &other)
        return *this;

    this->m_sec = other.m_sec;
    this->m_ats = other.m_ats;

    return *this;
}

QString QtAttoDateTime::toString(const QString &format) const
{
    return toDateTime().toString(format);
}

qint64 QtAttoDateTime::attoFromDeci(qint64 deciSeconds)
{
    return deciSeconds*DeciMul;
}

qint64 QtAttoDateTime::attoFromCenti(qint64 centiSeconds)
{
    return centiSeconds*CentiMul;
}

qint64 QtAttoDateTime::attoFromMilli(qint64 milliSeconds)
{
    return milliSeconds*MilliMul;
}

qint64 QtAttoDateTime::attoFromMicro(qint64 microSeconds)
{
    return microSeconds*MicroMul;
}

qint64 QtAttoDateTime::attoFromNano(qint64 nanoSeconds)
{
    return nanoSeconds*NanoMul;
}

qint64 QtAttoDateTime::attoFromPico(qint64 picoSeconds)
{
    return picoSeconds*PicoMul;
}

qint64 QtAttoDateTime::attoFromFemto(qint64 femtoSeconds)
{
    return femtoSeconds*FemtoMul;
}

qint64 QtAttoDateTime::deciFromAtto(qint64 attoSeconds)
{
    return attoSeconds/DeciMul;
}

qint64 QtAttoDateTime::centiFromAtto(qint64 attoSeconds)
{
    return attoSeconds/CentiMul;
}

qint64 QtAttoDateTime::milliFromAtto(qint64 attoSeconds)
{
    return attoSeconds/MilliMul;
}

qint64 QtAttoDateTime::microFromAtto(qint64 attoSeconds)
{
    return attoSeconds/MicroMul;
}

qint64 QtAttoDateTime::nanoFromAtto(qint64 attoSeconds)
{
    return attoSeconds/NanoMul;
}

qint64 QtAttoDateTime::picoFromAtto(qint64 attoSeconds)
{
    return attoSeconds/PicoMul;
}

qint64 QtAttoDateTime::femtoFromAtto(qint64 attoSeconds)
{
    return attoSeconds/FemtoMul;
}

QtAttoDateTime QtAttoDateTime::fromUnixSeconds(qint64 seconds)
{
    return QtAttoDateTime(seconds, 0);
}

QtAttoDateTime QtAttoDateTime::fromUnixDeciSeconds(qint64 deciSeconds)
{
    return QtAttoDateTime(deciSeconds/DeciPrefix, deciSeconds%DeciPrefix*DeciMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixCentiSeconds(qint64 centiSeconds)
{
    return QtAttoDateTime(centiSeconds/CentiPrefix,
                          centiSeconds%CentiPrefix*CentiMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixMilliSeconds(qint64 milliSeconds)
{
    return QtAttoDateTime(milliSeconds/MilliPrefix,
                          milliSeconds%MilliPrefix*MilliMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixMicroSeconds(qint64 microSeconds)
{
    return QtAttoDateTime(microSeconds/MicroPrefix,
                          microSeconds%MicroPrefix*MicroMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixNanoSeconds(qint64 nanoSeconds)
{
    return QtAttoDateTime(nanoSeconds/NanoPrefix,
                          nanoSeconds%NanoPrefix*NanoMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixPicoSeconds(qint64 picoSeconds)
{
    return QtAttoDateTime(picoSeconds/PicoPrefix,
                          picoSeconds%PicoPrefix*PicoMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixFemtoSeconds(qint64 femtoSeconds)
{
    return QtAttoDateTime(femtoSeconds/FemtoPrefix,
                          femtoSeconds%FemtoPrefix*FemtoMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixAttoSeconds(qint64 attoSeconds)
{
    return QtAttoDateTime(attoSeconds/AttoPrefix,
                          attoSeconds%AttoPrefix*AttoMul);
}

QtAttoDateTime QtAttoDateTime::fromDateTime(const QDateTime &dateTime)
{
    QtAttoDateTime dt;
    dt.setDateTime(dateTime);
    return dt;
}

QtAttoDateTime QtAttoDateTime::currentDateTime()
{
    return QtAttoDateTime::fromDateTime(QDateTime::currentDateTime());
}

QtAttoDateTime QtAttoDateTime::fromString(const QString &string,
        const QString &format)
{
    return QtAttoDateTime::fromDateTime(QDateTime::fromString(string, format));
}

QtAttoDateTime operator + (const QtAttoDateTime &a, const QtAttoTimeDelta &b)
{
    QtAttoDateTime result(a.m_sec + b.m_sec, a.m_ats);
    result.incAttoSeconds(b.m_ats);
    return result;
}

QtAttoDateTime operator - (const QtAttoDateTime &a, const QtAttoTimeDelta &b)
{
    QtAttoDateTime result(a.m_sec - b.m_sec, a.m_ats);
    result.incAttoSeconds(-b.m_ats);
    return result;
}

QtAttoDateTime &operator += (QtAttoDateTime &a, const QtAttoTimeDelta &b)
{
    a.m_sec += b.m_sec;
    a.incAttoSeconds(b.m_ats);
    return a;
}

QtAttoDateTime &operator -= (QtAttoDateTime &a, const QtAttoTimeDelta &b)
{
    a.m_sec -= b.m_sec;
    a.incAttoSeconds(-b.m_ats);
    return a;
}

QDebug operator << (QDebug dbg, const QtAttoDateTime &dt)
{
    return dbg.nospace() << "(Sec = " << dt.m_sec
                         << ", AttoPersision = " << dt.m_ats << ")";
}
