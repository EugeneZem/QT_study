#include "stopwatch.h"
#include <QPair>

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    _launched = false;

    timer = new QTimer(this);
    timer->setInterval(100);
    _time.first = 0;
    _time.second = 0;
}

bool Stopwatch::launched()
{
    return _launched;
}

QPair<int, int> Stopwatch::time()
{
    return _time;
}

void Stopwatch::TimerSlot()
{
    if(_time.second == 9)
    {
        _time.first++;
        _time.second = 0;
    }
    else
    {
        _time.second++;
    }
    emit SigTime();
}

void Stopwatch::RcvReset()
{
    _time.first = 0;
    _time.second = 0;
}

void Stopwatch::RcvStart()
{
    connect(timer, QTimer::timeout, this, Stopwatch::TimerSlot);
    timer->start(100);

    emit SigTime();
    _launched = true;
}

void Stopwatch::RcvStop()
{
    disconnect(timer, QTimer::timeout, this, Stopwatch::TimerSlot);
    _launched = false;
}
