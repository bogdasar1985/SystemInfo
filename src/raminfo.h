#ifndef RAMINFO_H
#define RAMINFO_H

#include <QObject>

class RamInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int totalRam READ getTotalRam)
public:
    explicit RamInfo(QObject *parent = nullptr);
    int getTotalRam();
};

#endif // RAMINFO_H
