#include "lcd_i2c.h"
#include <QDebug>

LCD_I2C::LCD_I2C()
{
}

int LCD_I2C::Putc(unsigned char c)
{
    return sendData(1,c);
}

int LCD_I2C::clear()
{
    int ret = sendData(0,0x01);
    delay(2);
    return ret;
}

int LCD_I2C::init()
{
    setD4(0);
    setD5(0);
    setD6(0);
    setD7(0);
    setEnable(0);

    delay(15);
    if(writeNibble(0x03) == -1)return -1;          // Envia comando para inicializar o display
    delay(5);                                      // Aguarda 5ms para estabilizar o LCD
    if(writeNibble(0x03) == -1)return -1;          // Envia comando para inicializar o display
    delay(5);                                      // Aguarda 5ms para estabilizar o LCD
    if(writeNibble(0x03) == -1)return -1;          // Envia comando para inicializar o display
    delay(5);                                      // Aguarda 5ms para estabilizar o LCD
    if(writeNibble(0x02) == -1)return -1;          // CURSOR HOME - Envia comando para zerar o contador de caracteres e retornar à posição inicial (0x80).
    delay(1);                                      // Aguarda 1ms para estabilizar o LCD
    if(sendData(0,0x28) == -1)return -1;               // FUNCTION SET - Configura o LCD para 4 bits, 2 linhas, fonte 5X7.
    if(sendData(0,0x0c) == -1)return -1;               // DISPLAY CONTROL - Display ligado, sem cursor
    clear();                                       // Limpa o LCD
    if(sendData(0,0x06) == -1)return -1;               // ENTRY MODE SET - Desloca o cursor para a direita
    return 0;
}

int LCD_I2C::gotoXY(int x, int y)
{
    int pos=0;
       if(y == 1)
       {
          pos=0x80;     //Se setado linha 1, end incial 0x80
       }
       if(y == 2)
       {
          pos=0xc0;     //Se setado linha 2, end incial 0xc0
       }

    pos=pos+x;     //soma ao end inicial, o numero da coluna
    pos--;                  //subtrai 1 para corrigir posição

    return sendData(0,pos);
}

int LCD_I2C::print(const char *str)
{
    for(int i=0;str[i]!=0;i++)
    {
        if(Putc(str[i]) == -1)return -1;
    }
    return 0;
}

int LCD_I2C::setBackLight(int v)
{
    if(v) data |= (1<<BACKLIGHT);
    else data &= ~(1<<BACKLIGHT);
    if(wiringPiI2CWrite (ID_device,data) == -1)return -1;
    return 0;
}
int LCD_I2C::setBackLight(bool v)
{
    if(v) data |= (1<<BACKLIGHT);
    else data &= ~(1<<BACKLIGHT);
    if(wiringPiI2CWrite (ID_device,data) == -1)return -1;
    return 0;
}

/*****************************************************************************************************************
* Privates
******************************************************************************************************************/
/*Envia a parte baixa de um byte*/
void LCD_I2C::setup(char address,int rs, int rw, int enable, int d4, int d5, int d6, int d7, int backLight)
{
    RS = rs;
    RW = rw;
    E = enable;
    BACKLIGHT =  backLight;
    D4 = d4;
    D5 = d5;
    D6 = d6;
    D7 = d7;
    ID_device = wiringPiI2CSetup (address);
    data = 0;
}

int LCD_I2C::writeNibble(unsigned char d)
{
    setD4((0x01 & d));
    setD5((0x02 & d));
    setD6((0x04 & d));
    setD7((0x08 & d));

    if(wiringPiI2CWrite (ID_device,data) == -1)return -1;
    delay(1);
    setEnable(1);
    if(wiringPiI2CWrite (ID_device,data) == -1)return -1;

    setEnable(0);
    if(wiringPiI2CWrite (ID_device,data) == -1)return -1;

    return 0;
}

int LCD_I2C::sendData(bool action, unsigned char d)
{
    setRS((int)action);
    if(wiringPiI2CWrite (ID_device,data) == -1)return -1;

    delayMicroseconds(100);
    setEnable(0);

    if(wiringPiI2CWrite (ID_device,data) == -1)return -1;

    if(writeNibble(d>>4) == -1)return -1;

    if(writeNibble(d & 0x0f) == -1)return -1;

    delayMicroseconds(40);
    return 0;
}

void LCD_I2C::setRS(int v)
{
    if(v) data |= (1<<RS);
    else data &= ~(1<<RS);
}

void LCD_I2C::setRW(int v)
{
    if(v) data |= (1<<RW);
    else data &= ~(1<<RW);
}

void LCD_I2C::setEnable(int v)
{
    if(v) data |= (1<<E);
    else data &= ~(1<<E);
}

void LCD_I2C::setD4(int v)
{
    if(v) data |= (1<<D4);
    else data &= ~(1<<D4);
}

void LCD_I2C::setD5(int v)
{
    if(v) data |= (1<<D5);
    else data &= ~(1<<D5);
}

void LCD_I2C::setD6(int v)
{
    if(v) data |= (1<<D6);
    else data &= ~(1<<D6);
}

void LCD_I2C::setD7(int v)
{
    if(v) data |= (1<<D7);
    else data &= ~(1<<D7);
}

