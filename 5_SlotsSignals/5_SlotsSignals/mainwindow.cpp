#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"
#include <QPair>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stopwatch = new Stopwatch(this);

    ui->pb_Round->setEnabled(false);
    ui->pb_Clear->setEnabled(false);

    ui->tl_Time->setText("0.0");

    QObject::connect(this, &MainWindow::SigStart, stopwatch, &Stopwatch::RcvStart);
    QObject::connect(this, &MainWindow::SigStop, stopwatch, &Stopwatch::RcvStop);
    QObject::connect(this, &MainWindow::SigReset, stopwatch, &Stopwatch::RcvReset);

    _last_round.first  = 0;
    _last_round.second = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

QPair<int, int> MainWindow::last_round()
{

    return _last_round;
}

void MainWindow::StartStopwatch()
{
    QObject::connect(stopwatch, &Stopwatch::SigTime, this, &MainWindow::UpdeteIndicator);
    ui->pb_Round->setEnabled(true);
    ui->pb_StartStop->setText("&Стоп");
    ui->pb_Clear->setEnabled(true);
}

void MainWindow::StopStopwatch()
{
    ui->pb_Round->setEnabled(false);
    ui->pb_StartStop->setText("&Старт");
}

void MainWindow::UpdeteIndicator()
{
    ui->tl_Time->setText(QString::number((stopwatch->time().first)) +
                         "." + QString::number((stopwatch->time().second)));

}

void MainWindow::on_pb_StartStop_clicked()
{
    if (stopwatch->launched())
        {
            emit SigStop();
            StopStopwatch();
        }
        else
        {
            emit SigStart();
            StartStopwatch();
            _last_round.first  = stopwatch->time().first;
            _last_round.second = stopwatch->time().second;
    }
}

void MainWindow::on_pb_Round_clicked()
{
    int s, ms;
    int s_p, ms_p;
    int s_d, ms_d;

        s  = stopwatch->time().first;
        ms = stopwatch->time().second;
        s_p  = _last_round.first;
        ms_p = _last_round.second;
        ms_d = ms - ms_p;
        s_d  = s - s_p;

    if (ms_d < 0)
    {
        ms_d = ms + 10 - ms_p;
        s_d = s_d - 1;
    }

    _last_round.first  = s;
    _last_round.second = ms;

    qDebug() << "Круг " << rounds << ", время: " << s - s_p << "." << ms_d;
    qDebug() << "текущее " << s << "." << ms << "предыдущее " << s_p << "." << ms_p;
    qDebug() << "______";

    rounds++;

    ui->tb_Rounds->append("Круг " + QString::number(rounds) + ", время: " +
                          QString::number(s_d) + "." +
                          QString::number(ms_d) + " сек");

    ui->pb_Clear->setEnabled(true);
}


void MainWindow::on_pb_Clear_clicked()
{
    ui->tb_Rounds->clear();
    ui->tl_Time->setText("0.0");
    rounds = 0;
    _last_round.first  = 0;
    _last_round.second = 0;
    emit SigReset();

    if (!stopwatch->launched())
    {
        ui->pb_Clear->setEnabled(false);
    }
}

