// Copyright 2013, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
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

// ----------------------------------------------------------------------
namespace attodatetime {
// ----------------------------------------------------------------------

const qint64 GAttoPrefix    = Q_INT64_C(1000000000000000000);
const qint64 GFemtoPrefix   = Q_INT64_C(1000000000000000);
const qint64 GPicoPrefix    = Q_INT64_C(1000000000000);
const qint64 GNanoPrefix    = Q_INT64_C(1000000000);
const qint64 GMicroPrefix   = Q_INT64_C(1000000);
const qint64 GMilliPrefix   = Q_INT64_C(1000);
const qint64 GCentiPrefix   = Q_INT64_C(100);
const qint64 GDeciPrefix    = Q_INT64_C(10);

const qint64 GAttoMul   = Q_INT64_C(1);
const qint64 GFemtoMul  = Q_INT64_C(1000);
const qint64 GPicoMul   = Q_INT64_C(1000000);
const qint64 GNanoMul   = Q_INT64_C(1000000000);
const qint64 GMicroMul  = Q_INT64_C(1000000000000);
const qint64 GMilliMul  = Q_INT64_C(1000000000000000);
const qint64 GCentiMul  = Q_INT64_C(10000000000000000);
const qint64 GDeciMul   = Q_INT64_C(100000000000000000);

// ----------------------------------------------------------------------
} // namespace attodatetime
// ----------------------------------------------------------------------

#endif // QTATTOTIMECONST_H
