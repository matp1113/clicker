#ifndef TIMER_H
#define TIMER_H

#include <QObject>

enum timeDigits{
    seconds1 = 0,
    seconds2 = 1,
    minutes1 = 2,
    minutes2 = 3,
    hours1 = 4,
    hours2 = 5
};

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);
    QString toString();

public slots:
    void changeTime();

signals:
    void timeChanged(QString);

private:
    int _time[5] = {0, 0, 0, 0, 0};
    int _timeLimit[5] = {10, 6, 10, 6, 10};
    QString _timeString;

};

#endif // TIMER_H
