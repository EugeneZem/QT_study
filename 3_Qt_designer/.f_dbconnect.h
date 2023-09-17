#ifndef F_DBCONNECT_H
#define F_DBCONNECT_H

#include <QWidget>

namespace Ui {
class f_DBconnect;
}

class f_DBconnect : public QWidget
{
    Q_OBJECT

public:
    explicit f_DBconnect(QWidget *parent = nullptr);
    ~f_DBconnect();

private:
    Ui::f_DBconnect *ui;
};

#endif // F_DBCONNECT_H
