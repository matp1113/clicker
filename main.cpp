#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QLocale>
#include <QTranslator>
#include <QQuickItem>
#include <QQuickView>
#include <QMetaObject>
#include <QDir>
#include <QVariant>
#include <memory>
#include <utility>

#include "movingPoint.h"
#include "game.h"
#include "appRoot.h"
#include "mainwindow.h"
#include "settings.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "clicker_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();

    AppRoot root(&app, engine);

    QQmlContext *rootContext = engine->rootContext();
    rootContext->setContextProperty("myAppRoot", QVariant::fromValue(&root));

    return app.exec();
}
