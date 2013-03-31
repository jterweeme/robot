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
    OCR3A = 750;
    ICR1 = 10000;
    TCNT3 = 0;
    TCCR3A = (1<<COM3A1) | (1<<COM3B1);
    TCCR3B = (1<<WGM33) | (1<<CS11);
}

void PWMMotor::linksAchteruit()
{
    PORTE |= (1<<3);
    PORTG |= (1<<5);
}

void PWMMotor::linksVooruit()
{
    PORTE |= (1<<3);
}

void PWMMotor::rechtsAchteruit()
{
    PORTH |= (1<<3) | (1<<4);
}

void PWMMotor::rechtsVooruit()
{
    PORTH |= (1<<3);
}

void PWMMotor::linksStop()
{
    PORTE &= ~(1<<3);
}

void PWMMotor::rechtsStop()
{
    PORTH &= ~(1<<3);
}



