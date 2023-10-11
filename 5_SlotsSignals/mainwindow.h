#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPair<int, int> last_round();

signals:
    void SigStart();
    void SigStop();
    void SigReset();


private slots:
    void on_pb_StartStop_clicked();
    void UpdeteIndicator();
    void on_pb_Round_clicked();
    void on_pb_Clear_clicked();

private:
    void StartStopwatch();
    void StopStopwatch();
    Ui::MainWindow *ui;
    Stopwatch* stopwatch;
    int rounds = 0;
    QPair<int, int> _last_round;
};
#endif // MAINWINDOW_H
