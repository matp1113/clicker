#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QLocale>
#include <QTranslator>
#include <QQuickItem>
#include <QQuickView>
#include <QMetaObject>
#include <memory>
#include <utility>

#include "movingPoint.h"
#include "game.h"
#include "support.h"

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

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/clicker/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QQuickView view(QUrl::fromLocalFile("Users/Mateusz/Desktop/soft_int_qt/clicker/game.qml"));
    std::unique_ptr<QObject> item = std::make_unique<QObject>(view.rootObject());
    std::unique_ptr<Game> myGame = std::make_unique<Game>();

    QObject::connect(item.get(), SIGNAL(start()), myGame.get(), SLOT(start()));

    std::unique_ptr<Support> support = std::make_unique<Support>(nullptr, std::move(item), std::move(myGame));

//    QQmlContext *rootContext = engine.rootContext();
//    rootContext->setContextProperty("pointClass", QVariant::fromValue(&myGame));

    //QObject::connect(myGame, SIGNAL(sendCordinates), item, SLOT())

    return app.exec();
}
