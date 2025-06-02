#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //this is instance of mainWindow
    int ret = dv.Port_Config();
    if(ret==0)
    {
        qDebug() << "Device is available and connected";
    }
    else
    {
        qDebug() << "Device is not  available and not connected";
    }
    QObject::connect(dv.getSerial(),SIGNAL(readyRead()),this,SLOT(Display_Info()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOn_clicked()
{
    dv.write_To_Stm("1");
}


void MainWindow::on_pushButtonOff_clicked()
{
    dv.write_To_Stm("0");
}

void MainWindow::Display_Info()
{
    d_read= dv.read_from_Stm();
    if("1"== d_read)
    {
        ui-> lineEdit-> setText("LED GREEN ON");
    }
    if("0"== d_read)
    {
        ui-> lineEdit-> setText("LED GREEN OFF");
    }

}

