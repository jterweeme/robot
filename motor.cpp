/*
Jasper ter Weeme
*/

#include <avr/io.h>
#include "motor.h"
PWMPLLMotor::PWMPLLMotor()
{
    DDRE |= (1<<3);
    DDRG |= (1<<5);
    DDRH |= (1<<3) | (1<<4);
}

void PWMPLLMotor::linksAchteruit(unsigned int speed = 0)
{
    if (speed > 0)
    {
        PORTE |= (1<<3);
        PORTG |= (1<<5);
    }
    else
    {
        linksStop();
    }
}

void PWMPLLMotor::linksVooruit(unsigned int speed = 0)
{
    if (speed > 0)
    {
        PORTE |= (1<<3);
    }
    else
    {
        linksStop();
    }
}

void PWMPLLMotor::rechtsAchteruit(unsigned int speed = 0)
{
    if (speed > 0)
    {
        PORTH |= (1<<3) | (1<<4);
    }
    else
    {
        rechtsStop();
    }
}

void PWMPLLMotor::rechtsVooruit(unsigned int speed = 0)
{
    if (speed > 0)
    {
        PORTH |= (1<<3);
    }
    else
    {
        rechtsStop();
    }
}

void PWMPLLMotor::linksStop()
{
    PORTE &= ~(1<<3);
}

void PWMPLLMotor::rechtsStop()
{
    PORTH &= ~(1<<3);
}

PWMMotor::PWMMotor()
{
    DDRE = 0xff;
    DDRG = 0xff;
    DDRH = 0xff;
    ICR3 = 10000;
    ICR4 = 10000;
    TCNT3 = 0;
    TCCR3A = (1<<COM3A1);
    TCCR4A = (1<<COM4A1);
    TCCR3B = (1<<WGM33) | (1<<CS32);
    TCCR4B = (1<<CS42) | (1<<WGM43);
}

void PWMMotor::linksAchteruit(unsigned int speed)
{
    PORTG |= (1<<5);
    OCR3A = speed;
}

void PWMMotor::linksVooruit(unsigned int speed)
{
    PORTG &= ~(1<<5);
    OCR3A = speed;
}

void PWMMotor::rechtsAchteruit(unsigned int speed)
{
    PORTH |= (1<<4);
    OCR4A = speed;
}

void PWMMotor::rechtsVooruit(unsigned int speed)
{
    PORTH &= ~(1<<4);
    OCR4A = speed;
}

void PWMMotor::linksStop()
{
    OCR3A = 0;
}

void PWMMotor::rechtsStop()
{
    OCR4A = 0;
}



