#include "form.h"
#include "ui_form.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    //Iniciando com endereço expansor de portas para LCD
    ID_device = wiringPiI2CSetup (0x27);
    qDebug()<<"Dispositivo: "<<ID_device;
}

Form::~Form()
{
    delete ui;
}

unsigned char Form::makeNumber()
{
    unsigned char num = 0;

    if(this->ui->bit_7->isChecked())num |= (1<<7);
    if(this->ui->bit_6->isChecked())num |= (1<<6);
    if(this->ui->bit_5->isChecked())num |= (1<<5);
    if(this->ui->bit_4->isChecked())num |= (1<<4);
    if(this->ui->bit_3->isChecked())num |= (1<<3);
    if(this->ui->bit_2->isChecked())num |= (1<<2);
    if(this->ui->bit_1->isChecked())num |= (1<<1);
    if(this->ui->bit_0->isChecked())num |= (1<<0);
    return num;
}

void Form::on_bit_7_clicked()
{
    data = makeNumber();
    int ret = wiringPiI2CWrite (ID_device,data) ;
    qDebug()<<(int)data << ", "<<ret;
}

void Form::on_bit_6_clicked()
{
    data = makeNumber();
    int ret = wiringPiI2CWrite (ID_device,data) ;
    qDebug()<<(int)data << ", "<<ret;
}

void Form::on_bit_5_clicked()
{
    data = makeNumber();
    int ret = wiringPiI2CWrite (ID_device,data) ;
    qDebug()<<(int)data << ", "<<ret;
}

void Form::on_bit_4_clicked()
{
    data = makeNumber();
    int ret = wiringPiI2CWrite (ID_device,data) ;
    qDebug()<<(int)data << ", "<<ret;
}

void Form::on_bit_3_clicked()
{
    data = makeNumber();
    int ret = wiringPiI2CWrite (ID_device,data) ;
    qDebug()<<(int)data << ", "<<ret;
}

void Form::on_bit_2_clicked()
{
    data = makeNumber();
    int ret = wiringPiI2CWrite (ID_device,data) ;
    qDebug()<<(int)data << ", "<<ret;
}

void Form::on_bit_1_clicked()
{
    data = makeNumber();
    int ret = wiringPiI2CWrite (ID_device,data) ;
    qDebug()<<(int)data << ", "<<ret;
}

void Form::on_bit_0_clicked()
{
    data = makeNumber();
    int ret = wiringPiI2CWrite (ID_device,data) ;
    qDebug()<<(int)data << ", "<<ret;
}
