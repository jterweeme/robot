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
#include "sonic.h"

extern "C" void __vector_25() __attribute__ ((signal, __INTR_ATTRS));
extern "C" void __vector_36() __attribute__ ((signal, __INTR_ATTRS));

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
WiFly *wifly;
Robot *robot;
Sonic *sonic;
uLCD *ulcd;

Sonic::Sonic()
{
    bufferPointer = 0;
    header = 0;
    highbyte = 0;
    lowbyte = 0;
    sum = 0;
}

uint8_t Sonic::getDistance()
{
    return lowbyte;
}

void Sonic::requestDistance()
{
    uint8_t onzin[4] = { 0x22, 0, 0, 0x22 };

    for (int i = 0; i < 4; i++)
        this->putcee(onzin[i]);
}

void Sonic::addToBuffer(char c)
{
    bufferPointer++;

    switch (bufferPointer)
    {
    case 1:
        header = (int)c;
        break;
    case 2:
        highbyte = (int)c;
        break;
    case 3:
        lowbyte = (int)c;
        break;
    case 4:
        sum = (int)c;
        break;
    default:
        bufferPointer = 0;
        break;
    }

    debugPort->putcee(c);
    debugPort->putcee('\n');
    
}

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
        sonic->requestDistance();
        debugPort->puts(sjprintf("%dcm\n", sonic->getDistance()));
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
        robot->command(wifly->getBuffer());
}

int main()
{
    
    motor = new PWMPLLMotor();
    robot = new Robot();
    debugPort = new Serial0();
    wifly = new WiFly();
    ulcd = new uLCD();

    ulcd->puts("Beware of the mighty Stendor robot");

    while (true) {
    }

    return 0;
}


