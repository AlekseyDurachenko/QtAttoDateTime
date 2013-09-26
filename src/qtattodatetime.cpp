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
#include "qtattodatetime.h"
#include <QDebug>
#include <math.h>

using namespace attodatetime;

QtAttoDateTime::QtAttoDateTime(qint64 seconds, qint64 atto)
{
    mSec = seconds;
    mAts = qAbs(atto) % GAttoPrefix;
}

QtAttoDateTime::QtAttoDateTime(const QDateTime &dateTime)
{
    setDateTime(dateTime);
}

QtAttoDateTime::QtAttoDateTime(const QDate &date, const QTime &time)
{
    setDateTime(QDateTime(date, time));
}

QtAttoDateTime::QtAttoDateTime(int year, int month, int day, int hour, int minute, int second, qint64 atto)
{
    setDateTime(QDateTime(QDate(year, month, day), QTime(hour, minute, second)));
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
    mSec = mSec%86400 + days*86400;
}

void QtAttoDateTime::setTime(const QTime &time)
{
    setDateTime(QDateTime(toDate(), time));
}

void QtAttoDateTime::setDateTime(const QDateTime &dateTime)
{
    setUnixMilliSeconds(dateTime.toTime_t());
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
    return mSec / 86400;
}

qint64 QtAttoDateTime::hours() const
{
    return mSec / 3600;
}

qint64 QtAttoDateTime::minutes() const
{
    return mSec / 60;
}

void QtAttoDateTime::setDays(qint64 days)
{
    mSec = days * 86400;
}

void QtAttoDateTime::setHours(qint64 hours)
{
    mSec = hours * 3600;
}

void QtAttoDateTime::setMinutes(qint64 minutes)
{
    mSec = minutes * 60;
}

QtAttoDateTime QtAttoDateTime::addDays(qint64 day) const
{
    return QtAttoDateTime(mSec + day*86400, mAts);
}

QtAttoDateTime QtAttoDateTime::addHours(qint64 hour) const
{
    return QtAttoDateTime(mSec + hour*3600, mAts);
}

QtAttoDateTime QtAttoDateTime::addMinutes(qint64 minute) const
{
    return QtAttoDateTime(mSec + minute*60, mAts);
}

void QtAttoDateTime::incDays(qint64 day)
{
    mSec += day * 86400;
}

void QtAttoDateTime::incHours(qint64 hour)
{
    mSec += hour * 3600;
}

void QtAttoDateTime::incMinutes(qint64 minute)
{
    mSec += minute * 60;
}

qint64 QtAttoDateTime::unixSeconds() const
{
    return mSec;
}

qint64 QtAttoDateTime::unixDeciSeconds() const
{
    return mSec * GDeciPrefix + mAts / GDeciMul;
}

qint64 QtAttoDateTime::unixCentiSeconds() const
{
    return mSec * GCentiPrefix + mAts / GCentiMul;
}

qint64 QtAttoDateTime::unixMilliSeconds() const
{
    return mSec * GMilliPrefix + mAts / GMilliMul;
}

qint64 QtAttoDateTime::unixMicroSeconds() const
{
    return mSec * GMicroPrefix + mAts / GMicroMul;
}

qint64 QtAttoDateTime::unixNanoSeconds() const
{
    return mSec * GNanoPrefix + mAts / GNanoMul;
}

qint64 QtAttoDateTime::unixPicoSeconds() const
{
    return mSec * GFemtoPrefix + mAts / GFemtoMul;
}

qint64 QtAttoDateTime::unixFemtoSeconds() const
{
    return mSec * GFemtoPrefix + mAts / GFemtoMul;
}

qint64 QtAttoDateTime::unixAttoSeconds() const
{
    return mSec * GAttoPrefix + mAts;
}

void QtAttoDateTime::setUnixSeconds(qint64 seconds)
{
    mSec = seconds;
    mAts = 0;
}

void QtAttoDateTime::setUnixDeciSeconds(qint64 deciSeconds)
{
    mSec = mAts = 0;
    incDeciSeconds(deciSeconds);
}

void QtAttoDateTime::setUnixCentiSeconds(qint64 centiSeconds)
{
    mSec = mAts = 0;
    incCentiSeconds(centiSeconds);
}

void QtAttoDateTime::setUnixMilliSeconds(qint64 milliSeconds)
{
    mSec = mAts = 0;
    incMilliSeconds(milliSeconds);
}

void QtAttoDateTime::setUnixMicroSeconds(qint64 microSeconds)
{
    mSec = mAts = 0;
    incMicroSeconds(microSeconds);
}

void QtAttoDateTime::setUnixNanoSeconds(qint64 nanoSeconds)
{
    mSec = mAts = 0;
    incNanoSeconds(nanoSeconds);
}

void QtAttoDateTime::setUnixPicoSeconds(qint64 picoSeconds)
{
    mSec = mAts = 0;
    incPicoSeconds(picoSeconds);
}

void QtAttoDateTime::setUnixFemtoSeconds(qint64 femtoSeconds)
{
    mSec = mAts = 0;
    incFemtoSeconds(femtoSeconds);
}

void QtAttoDateTime::setUnixAttoSeconds(qint64 attoSeconds)
{
    mSec = mAts = 0;
    incAttoSeconds(attoSeconds);
}

QtAttoDateTime QtAttoDateTime::addSeconds(qint64 seconds) const
{
    return QtAttoDateTime(mSec+seconds, mAts);
}

QtAttoDateTime QtAttoDateTime::addSecondsDouble(double seconds) const
{
    double fractpart, intpart;
    fractpart = modf (seconds , &intpart);
    return addSeconds(static_cast<qint64>(intpart))
            .addAttoSeconds(static_cast<qint64>(fractpart*GAttoPrefix));
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
    mSec += deciSeconds / GDeciPrefix;
    incAttoSeconds((deciSeconds%GDeciPrefix)*GDeciMul);
}

void QtAttoDateTime::incCentiSeconds(qint64 centiSeconds)
{
    mSec += centiSeconds / GCentiPrefix;
    incAttoSeconds((centiSeconds%GCentiPrefix)*GCentiMul);
}

void QtAttoDateTime::incMilliSeconds(qint64 milliSeconds)
{
    mSec += milliSeconds / GMilliPrefix;
    incAttoSeconds((milliSeconds%GMilliPrefix)*GMilliMul);
}

void QtAttoDateTime::incMicroSeconds(qint64 microSeconds)
{
    mSec += microSeconds / GMicroPrefix;
    incAttoSeconds((microSeconds%GMicroPrefix)*GMicroMul);
}

void QtAttoDateTime::incNanoSeconds(qint64 nanoSeconds)
{
    mSec += nanoSeconds / GNanoPrefix;
    incAttoSeconds((nanoSeconds%GNanoPrefix)*GNanoMul);
}

void QtAttoDateTime::incPicoSeconds(qint64 picoSeconds)
{
    mSec += picoSeconds / GPicoPrefix;
    incAttoSeconds((picoSeconds%GPicoPrefix)*GPicoMul);
}

void QtAttoDateTime::incFemtoSeconds(qint64 femtoSeconds)
{
    mSec += femtoSeconds / GFemtoPrefix;
    incAttoSeconds((femtoSeconds%GFemtoPrefix)*GFemtoMul);
}

void QtAttoDateTime::incAttoSeconds(qint64 attoSeconds)
{
    mAts += attoSeconds;
    if (mAts > 0)
    {
        mSec += mAts / GAttoPrefix;
        mAts %= GAttoPrefix;
    }
    else if (mAts < 0)
    {
        mSec -= qAbs(mAts)/GAttoPrefix;
        mAts  = qAbs(mAts)%GAttoPrefix;
        if (mAts > 0)
        {
            mSec -= 1;
            mAts  = GAttoPrefix - mAts;
        }
    }
}

qint64 QtAttoDateTime::deciPersision() const
{
    return mAts / GDeciMul;
}

qint64 QtAttoDateTime::centiPersision() const
{
    return mAts / GCentiMul;
}

qint64 QtAttoDateTime::milliPersision() const
{
    return mAts / GMilliMul;
}

qint64 QtAttoDateTime::microPersision() const
{
    return mAts / GMicroMul;
}

qint64 QtAttoDateTime::nanoPersision() const
{
    return mAts / GNanoMul;
}

qint64 QtAttoDateTime::picoPersision() const
{
    return mAts / GPicoMul;
}

qint64 QtAttoDateTime::femtoPersision() const
{
    return mAts / GFemtoMul;
}

qint64 QtAttoDateTime::attoPersision() const
{
    return mAts;
}

void QtAttoDateTime::setDeciPersision(qint64 deciSeconds)
{
    mAts = (deciSeconds*GDeciMul) % GAttoPrefix;
}

void QtAttoDateTime::setCentiPersision(qint64 centiSeconds)
{
    mAts = (centiSeconds*GCentiMul) % GAttoPrefix;
}

void QtAttoDateTime::setMilliPersision(qint64 milliSeconds)
{
    mAts = (milliSeconds*GMilliMul) % GAttoPrefix;
}

void QtAttoDateTime::setMicroPersision(qint64 microSeconds)
{
    mAts = (microSeconds*GMicroMul) % GAttoPrefix;
}

void QtAttoDateTime::setNanoPersision(qint64 nanoSeconds)
{
    mAts = (nanoSeconds*GNanoMul) % GAttoPrefix;
}

void QtAttoDateTime::setPicoPersision(qint64 picoSeconds)
{
    mAts = (picoSeconds*GPicoMul) % GAttoPrefix;
}

void QtAttoDateTime::setFemtoPersision(qint64 femtoSeconds)
{
    mAts = (femtoSeconds*GFemtoMul) % GAttoPrefix;
}

void QtAttoDateTime::setAttoPersision(qint64 attoSeconds)
{
    mAts = attoSeconds % GAttoPrefix;
}

QtAttoDateTime &QtAttoDateTime::operator = (const QtAttoDateTime &other)
{
    if (this == &other)
        return *this;

    this->mSec = other.mSec;
    this->mAts = other.mAts;

    return *this;
}

QString QtAttoDateTime::toString(const QString &format) const
{
    return toDateTime().toString(format);
}

qint64 QtAttoDateTime::attoFromDeci(qint64 deciSeconds)
{
    return deciSeconds * GDeciMul;
}

qint64 QtAttoDateTime::attoFromCenti(qint64 centiSeconds)
{
    return centiSeconds * GCentiMul;
}

qint64 QtAttoDateTime::attoFromMilli(qint64 milliSeconds)
{
    return milliSeconds * GMilliMul;
}

qint64 QtAttoDateTime::attoFromMicro(qint64 microSeconds)
{
    return microSeconds * GMicroMul;
}

qint64 QtAttoDateTime::attoFromNano(qint64 nanoSeconds)
{
    return nanoSeconds * GNanoMul;
}

qint64 QtAttoDateTime::attoFromPico(qint64 picoSeconds)
{
    return picoSeconds * GPicoMul;
}

qint64 QtAttoDateTime::attoFromFemto(qint64 femtoSeconds)
{
    return femtoSeconds * GFemtoMul;
}

qint64 QtAttoDateTime::deciFromAtto(qint64 attoSeconds)
{
    return attoSeconds / GDeciMul;
}

qint64 QtAttoDateTime::centiFromAtto(qint64 attoSeconds)
{
    return attoSeconds / GCentiMul;
}

qint64 QtAttoDateTime::milliFromAtto(qint64 attoSeconds)
{
    return attoSeconds / GMilliMul;
}

qint64 QtAttoDateTime::microFromAtto(qint64 attoSeconds)
{
    return attoSeconds / GMicroMul;
}

qint64 QtAttoDateTime::nanoFromAtto(qint64 attoSeconds)
{
    return attoSeconds / GNanoMul;
}

qint64 QtAttoDateTime::picoFromAtto(qint64 attoSeconds)
{
    return attoSeconds / GPicoMul;
}

qint64 QtAttoDateTime::femtoFromAtto(qint64 attoSeconds)
{
    return attoSeconds / GFemtoMul;
}

QtAttoDateTime QtAttoDateTime::fromUnixSeconds(qint64 seconds)
{
    return QtAttoDateTime(seconds, 0);
}

QtAttoDateTime QtAttoDateTime::fromUnixDeciSeconds(qint64 deciSeconds)
{
    return QtAttoDateTime(deciSeconds/GDeciPrefix, deciSeconds%GDeciPrefix*GDeciMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixCentiSeconds(qint64 centiSeconds)
{
    return QtAttoDateTime(centiSeconds/GCentiPrefix, centiSeconds%GCentiPrefix*GCentiMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixMilliSeconds(qint64 milliSeconds)
{
    return QtAttoDateTime(milliSeconds/GMilliPrefix, milliSeconds%GMilliPrefix*GMilliMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixMicroSeconds(qint64 microSeconds)
{
    return QtAttoDateTime(microSeconds/GMicroPrefix, microSeconds%GMicroPrefix*GMicroMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixNanoSeconds(qint64 nanoSeconds)
{
    return QtAttoDateTime(nanoSeconds/GNanoPrefix, nanoSeconds%GNanoPrefix*GNanoMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixPicoSeconds(qint64 picoSeconds)
{
    return QtAttoDateTime(picoSeconds/GPicoPrefix, picoSeconds%GPicoPrefix*GPicoMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixFemtoSeconds(qint64 femtoSeconds)
{
    return QtAttoDateTime(femtoSeconds/GFemtoPrefix, femtoSeconds%GFemtoPrefix*GFemtoMul);
}

QtAttoDateTime QtAttoDateTime::fromUnixAttoSeconds(qint64 attoSeconds)
{
    return QtAttoDateTime(attoSeconds/GAttoPrefix, attoSeconds%GAttoPrefix*GAttoMul);
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

QtAttoDateTime QtAttoDateTime::fromString(const QString &string, const QString &format)
{
    return QtAttoDateTime::fromDateTime(QDateTime::fromString(string, format));
}

QtAttoDateTime operator + (const QtAttoDateTime &a, const QtAttoTimeDelta &b)
{
    QtAttoDateTime result(a.mSec + b.mSec, a.mAts);
    result.incAttoSeconds(b.mAts);
    return result;
}

QtAttoDateTime operator - (const QtAttoDateTime &a, const QtAttoTimeDelta &b)
{
    QtAttoDateTime result(a.mSec - b.mSec, a.mAts);
    result.incAttoSeconds(-b.mAts);
    return result;
}

QtAttoDateTime &operator += (QtAttoDateTime &a, const QtAttoTimeDelta &b)
{
    a.mSec += b.mSec;
    a.incAttoSeconds(b.mAts);
    return a;
}

QtAttoDateTime &operator -= (QtAttoDateTime &a, const QtAttoTimeDelta &b)
{
    a.mSec -= b.mSec;
    a.incAttoSeconds(-b.mAts);
    return a;
}

QDebug operator << (QDebug dbg, const QtAttoDateTime &dt)
{
    return dbg.nospace() << "(Sec = " << dt.mSec << ", AttoPersision = " << dt.mAts << ")";
}
