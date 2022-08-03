#ifndef SUPPORT_H
#define SUPPORT_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <memory>
#include <utility>
#include "game.h"
#include "mainwindow.h"
#include "settings.h"

enum Window{
    mainWindow = 0,
    settings = 1,
    gameWindow = 2
};

class AppRoot : public QObject
{
    Q_OBJECT
public:
    void changeWindow(Window w);
    explicit AppRoot(QObject *parent = nullptr, QQmlApplicationEngine *engine = nullptr, std::unique_ptr<Game> game = nullptr, std::unique_ptr<MainWindow> main = nullptr, std::unique_ptr<Settings> settings = nullptr);
    ~AppRoot();

public slots:
    void openSettings();
    void exitSettings();
    void enterGame();
    void setSize(int size);
    int getSize();
    void setPointSize(int size);
    int getPointSize();
    void setGameVelocity(int vel);
    int getGameVelocity();

private:
    QQmlApplicationEngine *_engine;
    std::unique_ptr<Game> _game;
    std::unique_ptr<MainWindow> _main;
    std::unique_ptr<Settings> _settings;
    int _size = 400;
    int _pointSize = 20;
};

#endif // SUPPORT_H
