#include "ulcd.h"
#include "misc.h"
#include <avr/io.h>
uLCD::uLCD()
{
    init();
}

void uLCD::init()
{
    DDRB |= (1<<6);
    PORTB &= ~(1<<6);
    Serial2::putcee('U');

    Serial2::putcee('B');
    Serial2::putcee(0xff);
    Serial2::putcee(0xff);

    Serial2::puts("Y\4\1");

    clear();
}

int uLCD::landscape()
{
    return 0;
}

int uLCD::clear()
{
    Serial2::putcee('E');
    return 0;
}

int uLCD::puts(const char *s)
{
    Serial2::putcee('s');
    Serial2::putcee(0);     // x = 0
    Serial2::putcee(0);     // y = 0
    Serial2::putcee(1);
    Serial2::putcee(0);
    Serial2::puts(s);
    Serial2::putcee(0);
    return 0;
}


