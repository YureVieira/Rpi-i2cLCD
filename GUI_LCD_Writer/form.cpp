#include "form.h"
#include "ui_form.h"
#include <QDebug>


Form::Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    lcd.setup(0x27,0,1,2,4,5,6,7,3);
    lcd.init();
    lcd.setBackLight(1);
    lcd.print("Sistema pronto");
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QString str = this->ui->lineEdit->text();

    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print(str.toStdString().c_str());

}
