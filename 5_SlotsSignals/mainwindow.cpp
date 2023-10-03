#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"
#include <QPair>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartStopwatch()
{
    QObject::connect(stopwatch, &Stopwatch::SigTime, this, &MainWindow::UpdeteIndicator);
    ui->pb_Round->setEnabled(true);
    ui->pb_Clear->setEnabled(true);
    ui->pb_StartStop->setText("&Стоп");

}

void MainWindow::StopStopwatch()
{
    ui->pb_Round->setEnabled(false);
//    ui->pb_Clear->setEnabled(false);
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
    }
}

void MainWindow::on_pb_Round_clicked()
{
    rounds++;
    ui->tb_Rounds->append("Круг " + QString::number(rounds) + ", время: " +
                          QString::number((stopwatch->time().first)) + "." +
                          QString::number((stopwatch->time().second)) + " сек");
}


void MainWindow::on_pb_Clear_clicked()
{
    ui->tl_Time->setText("0.0");
    ui->tb_Rounds->clear();
    ui->pb_Round->setEnabled(false);
    ui->pb_Clear->setEnabled(false);
    ui->pb_StartStop->setText("&Старт");
    emit SigStop();
    emit SigReset();
    round = 0;
}

