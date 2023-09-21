#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gb_radiobox->setTitle("&Радио");
    ui->rb_button1->setText("&КП 97.2 FM");
    ui->rb_button2->setText("&Звезда 95.6 FM");

    for (int i = 0; i < 10; ++i)
    {
        ui->cb_combo1->addItem("Строка " + QString::number(i + 1));
    }

    ui->b_button1->setText("&Увеличить");

    ui->pb_progress1->setMinimum(0);
    ui->pb_progress1->setMaximum(100);
    ui->pb_progress1->setValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_b_button1_clicked()
{
    if (ui->pb_progress1->value()<ui->pb_progress1->maximum())
        ui->pb_progress1->setValue(ui->pb_progress1->value()+10);
    else
        ui->pb_progress1->setValue(0);
}


void MainWindow::on_pb_progress1_valueChanged(int value)
{
    if (ui->pb_progress1->value() == ui->pb_progress1->maximum())
    {
        ui->b_button1->setText("&Сброс");

        ui->b_button1->setCheckable(true);
      if (ui->b_button1->isCheckable()) ui->gb_progress->setTitle("checkable");
    }
    else
    {
        ui->b_button1->setText("&Увеличить");
    }
}

