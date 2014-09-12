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
#include <QtAttoDateTime>
#include <iostream>

int main(int /*argc*/, char **/*argv*/)
{
    QDateTime src(QDate(2013, 02, 12), QTime(10, 11, 12, 196), Qt::UTC);
    QtAttoDateTime dest(src);
    QDateTime dest2 = dest.toDateTime();

    std::cout << "QDateTime     : "
              << src.toString("yyyy.MM.dd HH:mm:ss.zzz").toStdString()
              << std::endl;
    std::cout << "QtAttoDateTime: "
              << dest.toString("yyyy.MM.dd HH:mm:ss.zzz").toStdString()
              << std::endl;
    std::cout << "QDateTime     : "
              << dest2.toString("yyyy.MM.dd HH:mm:ss.zzz").toStdString()
              << std::endl;

    return 0;
}
