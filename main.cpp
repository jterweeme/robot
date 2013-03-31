#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "serial.h"
#include "motor.h"
#include "wifly.h"

extern "C" void __cxa_pure_virtual()
{
    while (true) {
    }
}

class Wifi
{
public:
    virtual void showNetworks() = 0;
};

class Robot
{
public:
    Robot();
    void command(const char *);
};

Robot::Robot()
{
    DDRB |= (1<<7);
}

Motor *motor;
Serial0 *debugPort;

const char *sjprintf(const char *s, ...)
{
    va_list arg;
    va_start(arg, s);
    static char onzin[100];
    vsprintf(onzin, s, arg);
    va_end(arg);
    return onzin;
}

void Robot::command(const char *cmd)
{
    PORTB ^= (1<<7);


    for (int i = 0; i < strlen(cmd); i++)
        debugPort->puts(sjprintf("%02x", cmd[i]));


    if (strcmp(cmd, "\nvooruit") == 0 || strcmp(cmd, "vooruit") == 0)
    {
        motor->linksVooruit();
        motor->rechtsVooruit();
    }
    if (strcmp(cmd, "\nachteruit") == 0)
    {
        motor->linksAchteruit();
        motor->rechtsAchteruit();
    }
    if (strcmp(cmd, "\nstop") == 0)
    {
        motor->linksStop();
        motor->rechtsStop();
    }
    if (strcmp(cmd, "\nlinks") == 0)
    {
        motor->rechtsVooruit();
        motor->linksStop();
    }
    if (strcmp(cmd, "\nrechts") == 0)
    {
        motor->linksVooruit();
        motor->rechtsStop();
    }
}

WiFly *wifly;
Robot *robot;

extern "C" void __vector_25() __attribute__ ((signal, __INTR_ATTRS));
extern "C" void __vector_36() __attribute__ ((signal, __INTR_ATTRS));

void __vector_25()
{
    char data = UDR0;
    wifly->putcee(data);
}


void __vector_36()
{
    char data = UDR1;

    if (wifly->addToBuffer(data) == 1)
        robot->command(wifly->getBuffer());

}

void * operator new (size_t size)
{
    return malloc(size);
}

int main()
{
    
    motor = new Motor();
    robot = new Robot();
    debugPort = new Serial0();
    wifly = new WiFly();   

    
    while (true) {
    }
    return 0;
}


