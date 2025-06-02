#include "device.h"

Device::Device()
{
    portname="COM8";
    portserie= new QSerialPort;
    data="";
}

/*Device::~Device()
{
    delete portserie;
}*/

int Device::Port_Config()
{
    portserie->setPortName(portname);
    if (portserie->open(QSerialPort::ReadWrite))
    {
        portserie->setBaudRate(QSerialPort::Baud115200);
        portserie->setDataBits(QSerialPort::Data8);
        portserie->setParity(QSerialPort::NoParity);
        portserie->setStopBits(QSerialPort::OneStop);
        portserie->setFlowControl(QSerialPort::NoFlowControl);
        return 0;
    }
    else
    {
        return -1;
    }
}

void Device::write_To_Stm(QByteArray d)
    {
        if (portserie-> isWritable())
        {
            // Si le port est disponible, les donnÃ©es 'd' sont envoyÃ©es Ã  la carte STM32 via le port sÃ©rie.
                   portserie->write(d);
        }
        else
        {
            // Si le port n'est pas disponible, un message d'erreur est affichÃ© dans la console pour le dÃ©bogage.
            qDebug() << "couldn't write to stm";
        }
    }


QByteArray Device::read_from_Stm()
{
    if(portserie->isReadable())
    {
        data = portserie->readAll();
        qDebug() << " les valeurs sont:"<<data;
    }
    return data;
}

QSerialPort* Device::getSerial()
{
    return portserie;
}


