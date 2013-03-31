#include <avr/io.h>
#include "motor.h"
Motor::Motor()
{
    DDRE |= (1<<3);
    DDRG |= (1<<5);
    DDRH |= (1<<3) | (1<<4);
}

void Motor::linksAchteruit()
{
    PORTE |= (1<<3);
    PORTG |= (1<<5);
}

void Motor::linksVooruit()
{
    PORTE |= (1<<3);
}

void Motor::rechtsAchteruit()
{
    PORTH |= (1<<3) | (1<<4);
}

void Motor::rechtsVooruit()
{
    PORTH |= (1<<3);
}

void Motor::linksStop()
{
    PORTE &= ~(1<<3);
}

void Motor::rechtsStop()
{
    PORTH &= ~(1<<3);
}


