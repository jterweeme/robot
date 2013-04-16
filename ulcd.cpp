#include "ulcd.h"
#include "misc.h"
#include <avr/io.h>
uLCD::uLCD()
{
    DDRB |= (1<<7);
    init();
}

int uLCD::fetchResponse()
{
    unsigned int timeout = 0;

    while (this->response != 6 || this->response != 0x15)
    {
        if (++timeout > 0xfffe)
        {
            break;
        }
    }

    if (this->response == 6)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void uLCD::init()
{
    Serial2::putcee('U');
    int status = fetchResponse();

    if (status >= 0)
    {
        PORTB |= (1<<7);
    }

    //status = setBackground(WHITE);
    

   
    clear();
}

int uLCD::landscape()
{
    Serial2::puts("Y\4\1");
    return 0;
}

int uLCD::setBackground(unsigned int color)
{
    Serial2::putcee('B');
    Serial2::putcee(0xff);
    Serial2::putcee(0xff);
    return fetchResponse();
}

int uLCD::clear()
{
    Serial2::putcee('E');
    return fetchResponse();
}

void uLCD::setResponse(uint8_t resp)
{
    this->response = resp;
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


