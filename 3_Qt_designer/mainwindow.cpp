#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "f_dbconnect.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   f_dbconnect wind;
   wind.setModal(true);
   wind.exec();
}

