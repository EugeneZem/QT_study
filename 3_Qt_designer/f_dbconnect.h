#ifndef F_DBCONNECT_H
#define F_DBCONNECT_H

#include <QDialog>

namespace Ui {
class f_dbconnect;
}

class f_dbconnect : public QDialog
{
    Q_OBJECT

public:
    explicit f_dbconnect(QWidget *parent = nullptr);
    ~f_dbconnect();

private:
    Ui::f_dbconnect *ui;
};

#endif // F_DBCONNECT_H
