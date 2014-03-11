// Copyright 2013-2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef QTATTOTIMECONST_H
#define QTATTOTIMECONST_H

#include <QtGlobal>

// ----------------------------------------------------------------------
namespace attodatetime {
// ----------------------------------------------------------------------

const qint64 AttoPrefix    = Q_INT64_C(1000000000000000000);
const qint64 FemtoPrefix   = Q_INT64_C(1000000000000000);
const qint64 PicoPrefix    = Q_INT64_C(1000000000000);
const qint64 NanoPrefix    = Q_INT64_C(1000000000);
const qint64 MicroPrefix   = Q_INT64_C(1000000);
const qint64 MilliPrefix   = Q_INT64_C(1000);
const qint64 CentiPrefix   = Q_INT64_C(100);
const qint64 DeciPrefix    = Q_INT64_C(10);

const qint64 AttoMul   = Q_INT64_C(1);
const qint64 FemtoMul  = Q_INT64_C(1000);
const qint64 PicoMul   = Q_INT64_C(1000000);
const qint64 NanoMul   = Q_INT64_C(1000000000);
const qint64 MicroMul  = Q_INT64_C(1000000000000);
const qint64 MilliMul  = Q_INT64_C(1000000000000000);
const qint64 CentiMul  = Q_INT64_C(10000000000000000);
const qint64 DeciMul   = Q_INT64_C(100000000000000000);

// ----------------------------------------------------------------------
} // namespace attodatetime
// ----------------------------------------------------------------------

#endif // QTATTOTIMECONST_H
