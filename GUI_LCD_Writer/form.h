#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include "lcd_i2c.h"

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
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    LCD_I2C lcd;

};

#endif // FORM_H
