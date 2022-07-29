#ifndef SUPPORT_H
#define SUPPORT_H

#include <QObject>
#include <memory>
#include <utility>
#include "game.h"

class Support : public QObject
{
    Q_OBJECT
public:
    explicit Support(QObject *parent = nullptr, std::unique_ptr<QObject> it = nullptr, std::unique_ptr<Game> git = nullptr);
    ~Support();
    void invokeQml();

private:
    std::unique_ptr<QObject> _it;
    std::unique_ptr<Game> _git;

};

#endif // SUPPORT_H
