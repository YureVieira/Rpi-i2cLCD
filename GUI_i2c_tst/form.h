#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include <wiringPiI2C.h>

namespace Ui {
class Form;
}

class Form : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    
private slots:

    void on_bit_7_clicked();

    void on_bit_6_clicked();

    void on_bit_5_clicked();

    void on_bit_4_clicked();

    void on_bit_3_clicked();

    void on_bit_2_clicked();

    void on_bit_1_clicked();

    void on_bit_0_clicked();

private:
    Ui::Form *ui;
    unsigned char data;
    int ID_device;
    unsigned char makeNumber();
};

#endif // FORM_H
