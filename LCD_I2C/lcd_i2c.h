#ifndef LCD_I2C_H
#define LCD_I2C_H

#include <wiringPi.h>
#include <wiringPiI2C.h>

class LCD_I2C
{
private:
    int RS, RW, E, BACKLIGHT,D4, D5, D6, D7;
    int ID_device;
    unsigned char data;

    void setRS(int v);
    void setRW(int v);
    void setEnable(int v);
    void setD4(int v);
    void setD5(int v);
    void setD6(int v);
    void setD7(int v);

    int writeNibble(unsigned char d);
    int sendData(bool action, unsigned char d);

public:
//    LCD_I2C(int rs, int rw, int enable, int d4, int d5, int d6, int d7, int backLight);



    LCD_I2C();

    void setup(char adress,int rs, int rw, int enable, int d4, int d5, int d6, int d7, int backLight);
    int writeByte(bool,unsigned char c);
    int Putc(unsigned char c);
    int clear();
    int init();
    int gotoXY(int x,int y);
    int print(const char *str);



    int setBackLight(int v);
    int setBackLight(bool v);
};
#endif // LCD_I2C_H
