#include <avr/io.h>
#include "motor.h"
PWMPLLMotor::PWMPLLMotor()
{
    DDRE |= (1<<3);
    DDRG |= (1<<5);
    DDRH |= (1<<3) | (1<<4);
}

void PWMPLLMotor::linksAchteruit()
{
    PORTE |= (1<<3);
    PORTG |= (1<<5);
}

void PWMPLLMotor::linksVooruit()
{
    PORTE |= (1<<3);
}

void PWMPLLMotor::rechtsAchteruit()
{
    PORTH |= (1<<3) | (1<<4);
}

void PWMPLLMotor::rechtsVooruit()
{
    PORTH |= (1<<3);
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
    //ICR4 = 10000;
    TCNT3 = 0;
    TCCR3A = (1<<COM3A1);
    TCCR4A = (1<<COM4A1) | (1<<WGM40);
    TCCR3B = (1<<WGM33) | (1<<CS32);
    TCCR4B = (1<<CS42) | (1<<WGM42);
}

void PWMMotor::linksAchteruit()
{
    PORTG |= (1<<5);
    OCR3A = 1;
}

void PWMMotor::linksVooruit()
{
    PORTG &= ~(1<<5);
    OCR3A = 1;
}

void PWMMotor::rechtsAchteruit()
{
    PORTH |= (1<<4);
    OCR4A = 1;
}

void PWMMotor::rechtsVooruit()
{
    PORTH &= ~(1<<4);
    OCR4A = 30000;
}

void PWMMotor::linksStop()
{
    OCR3A = 0;
}

void PWMMotor::rechtsStop()
{
    OCR4A = 0;
}



