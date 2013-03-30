#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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

Serial0 *debugPort;
WiFly *wifly;

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
    debugPort->putcee(data);
    //wifly->addToBuffer(data);

}

void * operator new (size_t size)
{
    return malloc(size);
}

int main()
{
    Motor motor;
    //motor.linksAchteruit();
    //motor.rechtsAchteruit();
    debugPort = new Serial0();
    wifly = new WiFly();   
    //wifly->commandMode();
    //wifly->setPhrase("hutspot89xyz");
    //wifly->join("ABCDEFGHIJK");

    
    while (true) {
    }
    return 0;
}


