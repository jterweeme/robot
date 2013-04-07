/*
Jasper ter Weeme
*/

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
#include "ulcd.h"

extern "C" void __vector_25() __attribute__ ((signal, used, externally_visible));
extern "C" void __vector_36() __attribute__ ((signal, used, externally_visible));
extern "C" void __vector_51() __attribute__ ((signal, used, externally_visible));

class Robot
{
public:
    Robot();
    static void command(const char *);
};

Robot::Robot()
{
    DDRB |= (1<<7);
}

Motor *motor;
Serial0 *debugPort;
WiFly *wifly;
Robot *robot;
uLCD *ulcd;

void Robot::command(const char *cmd)
{
    //debugPort->puts(sjprintf("%02x", cmd));
    debugPort->puts(cmd);

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

    if (strcmp(commando, "US") == 0)
    {
        //sonic->requestDistance();
        //debugPort->puts(sjprintf("%dcm\n", sonic->getDistance()));
    }
        
}



void __vector_25()
{
    char data = UDR0;
    wifly->putcee(data);
}


void __vector_36()
{
    char data = UDR1;

    if (wifly->addToBuffer(data) == 1)
        Robot::command(wifly->getBuffer());
}

void __vector_51()
{
    char data = UDR2;
}

int main()
{
    motor = new PWMMotor();
    robot = new Robot();
    debugPort = new Serial0();
    wifly = new WiFly();
    ulcd = new uLCD();

    ulcd->puts("Beware of the mighty Stendor robot");

    while (true) {
    }

    return 0;
}


