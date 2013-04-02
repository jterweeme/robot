#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "serial.h"
#include "motor.h"
#include "wifly.h"
#include "misc.h"

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

PWMMotor *motor;
Serial0 *debugPort;
WiFly *wifly;
Robot *robot;

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
    debugPort->puts(sjprintf("%02x", cmd);

    char *commando = strtok((char *)cmd, " ,.-\n");
    char *parameter = strtok(NULL, " ,.-");
    unsigned int speed = atoi(parameter);

    if (strcmp(commando, "A") == 0)
        motor->linksAchteruit(speed);
    
    if (strcmp(commando, "Q") == 0)
        motor->linksVooruit(speed);

    if (strcmp(commando, "W") == 0)
        motor->rechtsVooruit(speed);

    if (strcmp(commando, "S") == 0)
        motor->rechtsAchteruit(speed);
}


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

int main()
{
    
    motor = new PWMMotor();
    robot = new Robot();
    debugPort = new Serial0();
    wifly = new WiFly();   

    while (true) {
    }

    return 0;
}


