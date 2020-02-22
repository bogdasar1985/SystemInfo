/***
Назначение класса:
Данный класс является моделью для передачи следующей инфорации в QML:
1.Процессор:
1.1 Имя процессора
1.2
*/
#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H
#include <QObject>
#include <QString>

class SystemInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cpuName READ getCpuName)
    Q_PROPERTY(double cpuMHz READ getCpuMHz NOTIFY cpuMHzChanged)
    Q_PROPERTY(int cacheSize READ getCacheSize)
    Q_PROPERTY(QString flags READ getFlags)

public:
    explicit SystemInfo(QObject *parent = nullptr);
    QString getCpuName();
    double getCpuMHz();
    int getCacheSize();
    QString getFlags();

signals:
    void cpuMHzChanged();
};

#endif // SYSTEMINFO_H
