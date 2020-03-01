#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cpuinfo.h"
#include "raminfo.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<CpuInfo>("CpuInfo", 1, 0, "CpuInfo");
    qmlRegisterType<RamInfo>("RamInfo", 1, 0, "RamInfo");

    engine.load(url);

    return app.exec();
}
