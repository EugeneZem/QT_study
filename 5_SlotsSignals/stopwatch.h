#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <Qtime>
#include <QPair>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    bool launched();
    QPair<int, int> time();

public slots:
    void TimerSlot();
    void RcvReset();
    void RcvStart();
    void RcvStop();

signals:
    void SigTime();

private:
    QTimer *timer;
    bool _launched;
    QPair<int, int> _time;
};

#endif // STOPWATCH_H
