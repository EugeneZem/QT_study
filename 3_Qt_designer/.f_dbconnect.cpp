#include "f_dbconnect.h"
#include "ui_f_dbconnect.h"

f_DBconnect::f_DBconnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::f_DBconnect)
{
    ui->setupUi(this);
}

f_DBconnect::~f_DBconnect()
{
    delete ui;
}

