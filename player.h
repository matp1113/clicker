#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);

public:
    void setName(QString);
    void setTime(QString);
    void setSupport(int);
    void save();

private:
    QString _name = "defaultName";
    QString _time = "";
    int _support = 0;

};

#endif // PLAYER_H
