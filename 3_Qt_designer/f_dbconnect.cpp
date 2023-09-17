#include "f_dbconnect.h"
#include "ui_f_dbconnect.h"

f_dbconnect::f_dbconnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::f_dbconnect)
{
    ui->setupUi(this);
}

f_dbconnect::~f_dbconnect()
{
    delete ui;
}
