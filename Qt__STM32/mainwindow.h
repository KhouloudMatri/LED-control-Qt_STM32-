#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "device.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: //slot is a function that is waiting for event from user
    void on_pushButtonOn_clicked();

    void on_pushButtonOff_clicked();
    void Display_Info();

private:
    Ui::MainWindow *ui;
    Device dv;
    QByteArray d_read;
};
#endif // MAINWINDOW_H
