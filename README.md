QtAttoDateTime
==============

About
-----

This class represents the datetime with precision up to attoseconds,
not support time zones, and compatible with the QDateTime.

Website: https://github.com/AlekseyDurachenko/QtAttoDateTime

Copyright (c) 2013-2014 Aleksey Durachenko (unless explicitly stated otherwise).

Usage
-----

Converting the QDateTime to QtAttoDatetime:
```cpp
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
```

License
-------

<a href="LICENSE">LGPLv2.1+</a>.
