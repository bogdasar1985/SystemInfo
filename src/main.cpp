//Сделать обновление данных через QEventLoop
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSysInfo>
#include "cpuinfo.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<CpuInfo>("CpuInfo", 1, 0, "CpuInfo");

    engine.load(url);

    return app.exec();
}
