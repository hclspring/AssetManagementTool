#include "util.h"

Util::Util()
{}


QString Util::genColumnNumber(int number)
{
    int n = number + 1;
    if (n <= 0) return "#NEGATIVE";
    QString res;
    while (n) {
        int residue = (n-1) % 26; // A,n=1,r=0; Z,n=26,r=25; AA,n=27,r=0
        res.push_front('A' + residue);
        n = (n - residue) / 26;
    }
    //qDebug() << number << res;
    return res;
}

QVector<QString> Util::genColumnNumbers(int count)
{
    QVector<QString> res;
    for (int i = 0; i < count; ++i) {
        res.push_back(genColumnNumber(i));
    }
    return res;
}




