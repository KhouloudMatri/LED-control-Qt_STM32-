#ifndef DEVICE_H
#define DEVICE_H

#include  <QtSerialPort/QSerialPort>
#include <QDebug>


class Device
{
private:
    QString portname;
    QSerialPort *portserie;
    QByteArray data;

public:
    Device();
    //~Device();
    int Port_Config();
    void write_To_Stm(QByteArray d);
    QByteArray read_from_Stm();
    QSerialPort *getSerial();
};

#endif // DEVICE_H
