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
#include "qtattotimedelta.h"
#include <QDebug>

using namespace attodatetime;

QtAttoTimeDelta::QtAttoTimeDelta(qint64 seconds, qint64 atto)
{
    setDelta(seconds, atto);
}

void QtAttoTimeDelta::setDelta(qint64 seconds, qint64 atto)
{
    mSec = seconds;
    mAts = qAbs(atto) % GAttoPrefix;
}

void QtAttoTimeDelta::incDelta(qint64 seconds, qint64 atto)
{
    mSec += seconds;
    incAttoSeconds(atto);
}

QtAttoTimeDelta QtAttoTimeDelta::addDelta(qint64 seconds, qint64 atto) const
{
    QtAttoTimeDelta result(mSec + seconds, atto);
    result.incAttoSeconds(atto);
    return result;
}

qint64 QtAttoTimeDelta::days() const
{
    return mSec / 86400;
}

qint64 QtAttoTimeDelta::hours() const
{
    return mSec / 3600;
}

qint64 QtAttoTimeDelta::minutes() const
{
    return mSec / 60;
}

void QtAttoTimeDelta::setDays(qint64 days)
{
    mSec = days * 86400;
}

void QtAttoTimeDelta::setHours(qint64 hours)
{
    mSec = hours * 3600;
}

void QtAttoTimeDelta::setMinutes(qint64 minutes)
{
    mSec = minutes * 60;
}

QtAttoTimeDelta QtAttoTimeDelta::addDays(qint64 day) const
{
    return QtAttoTimeDelta(mSec + day*86400, mAts);
}

QtAttoTimeDelta QtAttoTimeDelta::addHours(qint64 hour) const
{
    return QtAttoTimeDelta(mSec + hour*3600, mAts);
}

QtAttoTimeDelta QtAttoTimeDelta::addMinutes(qint64 minute) const
{
    return QtAttoTimeDelta(mSec + minute*60, mAts);
}

void QtAttoTimeDelta::incDays(qint64 day)
{
    mSec += day * 86400;
}

void QtAttoTimeDelta::incHours(qint64 hour)
{
    mSec += hour * 3600;
}

void QtAttoTimeDelta::incMinutes(qint64 minute)
{
    mSec += minute * 60;
}

void QtAttoTimeDelta::setSeconds(qint64 seconds)
{
    mSec = seconds;
    mAts = 0;
}

qint64 QtAttoTimeDelta::seconds() const
{
    return mSec;
}

qint64 QtAttoTimeDelta::deciSeconds() const
{
    return mSec * GDeciPrefix + mAts / GDeciMul;
}

qint64 QtAttoTimeDelta::centiSeconds() const
{
    return mSec * GCentiPrefix + mAts / GCentiMul;
}

qint64 QtAttoTimeDelta::milliSeconds() const
{
    return mSec * GMilliPrefix + mAts / GMilliMul;
}

qint64 QtAttoTimeDelta::microSeconds() const
{
    return mSec * GMicroPrefix + mAts / GMicroMul;
}

qint64 QtAttoTimeDelta::nanoSeconds() const
{
    return mSec * GNanoPrefix + mAts / GNanoMul;
}

qint64 QtAttoTimeDelta::picoSeconds() const
{
    return mSec * GFemtoPrefix + mAts / GFemtoMul;
}

qint64 QtAttoTimeDelta::femtoSeconds() const
{
    return mSec * GFemtoPrefix + mAts / GFemtoMul;
}

qint64 QtAttoTimeDelta::attoSeconds() const
{
    return mSec * GAttoPrefix + mAts;
}

void QtAttoTimeDelta::setDeciSeconds(qint64 deciSeconds)
{
    mSec = mAts = 0;
    incDeciSeconds(deciSeconds);
}

void QtAttoTimeDelta::setCentiSeconds(qint64 centiSeconds)
{
    mSec = mAts = 0;
    incCentiSeconds(centiSeconds);
}

void QtAttoTimeDelta::setMilliSeconds(qint64 milliSeconds)
{
    mSec = mAts = 0;
    incMilliSeconds(milliSeconds);
}

void QtAttoTimeDelta::setMicroSeconds(qint64 microSeconds)
{
    mSec = mAts = 0;
    incMicroSeconds(microSeconds);
}

void QtAttoTimeDelta::setNanoSeconds(qint64 nanoSeconds)
{
    mSec = mAts = 0;
    incNanoSeconds(nanoSeconds);
}

void QtAttoTimeDelta::setPicoSeconds(qint64 picoSeconds)
{
    mSec = mAts = 0;
    incPicoSeconds(picoSeconds);
}

void QtAttoTimeDelta::setFemtoSeconds(qint64 femtoSeconds)
{
    mSec = mAts = 0;
    incFemtoSeconds(femtoSeconds);
}

void QtAttoTimeDelta::setAttoSeconds(qint64 attoSeconds)
{
    mSec = mAts = 0;
    incAttoSeconds(attoSeconds);
}

QtAttoTimeDelta QtAttoTimeDelta::addSeconds(qint64 seconds) const
{
    return QtAttoTimeDelta(mSec+seconds, mAts);
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
    mSec += deciSeconds / GDeciPrefix;
    incAttoSeconds((deciSeconds%GDeciPrefix)*GDeciMul);
}

void QtAttoTimeDelta::incCentiSeconds(qint64 centiSeconds)
{
    mSec += centiSeconds / GCentiPrefix;
    incAttoSeconds((centiSeconds%GCentiPrefix)*GCentiMul);
}

void QtAttoTimeDelta::incMilliSeconds(qint64 milliSeconds)
{
    mSec += milliSeconds / GMilliPrefix;
    incAttoSeconds((milliSeconds%GMilliPrefix)*GMilliMul);
}

void QtAttoTimeDelta::incMicroSeconds(qint64 microSeconds)
{
    mSec += microSeconds / GMicroPrefix;
    incAttoSeconds((microSeconds%GMicroPrefix)*GMicroMul);
}

void QtAttoTimeDelta::incNanoSeconds(qint64 nanoSeconds)
{
    mSec += nanoSeconds / GNanoPrefix;
    incAttoSeconds((nanoSeconds%GNanoPrefix)*GNanoMul);
}

void QtAttoTimeDelta::incPicoSeconds(qint64 picoSeconds)
{
    mSec += picoSeconds / GPicoPrefix;
    incAttoSeconds((picoSeconds%GPicoPrefix)*GPicoMul);
}

void QtAttoTimeDelta::incFemtoSeconds(qint64 femtoSeconds)
{
    mSec += femtoSeconds / GFemtoPrefix;
    incAttoSeconds((femtoSeconds%GFemtoPrefix)*GFemtoMul);
}

void QtAttoTimeDelta::incAttoSeconds(qint64 attoSeconds)
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

qint64 QtAttoTimeDelta::deciPersision() const
{
    return mAts / GDeciMul;
}

qint64 QtAttoTimeDelta::centiPersision() const
{
    return mAts / GCentiMul;
}

qint64 QtAttoTimeDelta::milliPersision() const
{
    return mAts / GMilliMul;
}

qint64 QtAttoTimeDelta::microPersision() const
{
    return mAts / GMicroMul;
}

qint64 QtAttoTimeDelta::nanoPersision() const
{
    return mAts / GNanoMul;
}

qint64 QtAttoTimeDelta::picoPersision() const
{
    return mAts / GPicoMul;
}

qint64 QtAttoTimeDelta::femtoPersision() const
{
    return mAts / GFemtoMul;
}

qint64 QtAttoTimeDelta::attoPersision() const
{
    return mAts;
}

void QtAttoTimeDelta::setDeciPersision(qint64 deciSeconds)
{
    mAts = (deciSeconds*GDeciMul) % GAttoPrefix;
}

void QtAttoTimeDelta::setCentiPersision(qint64 centiSeconds)
{
    mAts = (centiSeconds*GCentiMul) % GAttoPrefix;
}

void QtAttoTimeDelta::setMilliPersision(qint64 milliSeconds)
{
    mAts = (milliSeconds*GMilliMul) % GAttoPrefix;
}

void QtAttoTimeDelta::setMicroPersision(qint64 microSeconds)
{
    mAts = (microSeconds*GMicroMul) % GAttoPrefix;
}

void QtAttoTimeDelta::setNanoPersision(qint64 nanoSeconds)
{
    mAts = (nanoSeconds*GNanoMul) % GAttoPrefix;
}

void QtAttoTimeDelta::setPicoPersision(qint64 picoSeconds)
{
    mAts = (picoSeconds*GPicoMul) % GAttoPrefix;
}

void QtAttoTimeDelta::setFemtoPersision(qint64 femtoSeconds)
{
    mAts = (femtoSeconds*GFemtoMul) % GAttoPrefix;
}

void QtAttoTimeDelta::setAttoPersision(qint64 attoSeconds)
{
    mAts = attoSeconds % GAttoPrefix;
}

QtAttoTimeDelta &QtAttoTimeDelta::operator = (const QtAttoTimeDelta &other)
{
    if (this == &other)
        return *this;

    this->mSec = other.mSec;
    this->mAts = other.mAts;

    return *this;
}

QtAttoTimeDelta operator + (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    QtAttoTimeDelta result(a.mSec + b.mSec, a.mAts);
    result.incAttoSeconds(b.mAts);
    return result;
}

QtAttoTimeDelta operator - (const QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    QtAttoTimeDelta result(a.mSec - b.mSec, a.mAts);
    result.incAttoSeconds(-b.mAts);
    return result;
}

QtAttoTimeDelta &operator += (QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    a.mSec += b.mSec;
    a.incAttoSeconds(b.mAts);
    return a;
}

QtAttoTimeDelta &operator -= (QtAttoTimeDelta &a, const QtAttoTimeDelta &b)
{
    a.mSec -= b.mSec;
    a.incAttoSeconds(-b.mAts);
    return a;
}

QDebug operator << (QDebug dbg, const QtAttoTimeDelta &dt)
{
    return dbg.nospace() << "(Sec = " << dt.mSec << ", AttoPersision = " << dt.mAts << ")";
}
