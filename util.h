#ifndef UTIL_H
#define UTIL_H

#include <QVector>
#include <QString>
#include <QDebug>

class Util
{
public:
    Util();
    static QString genColumnNumber(int number);//从0开始计数，0为A，25为Z，26为AA，以此类推
    static QVector<QString> genColumnNumbers(int count);
};

#endif // UTIL_H
