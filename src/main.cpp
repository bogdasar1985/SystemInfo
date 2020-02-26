//Сделать обновление данных через QEventLoop
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSysInfo>
#include "systeminfo.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<SystemInfo>("SystemInfo", 1, 0, "SystemInfo");

    engine.load(url);

    return app.exec();
}
