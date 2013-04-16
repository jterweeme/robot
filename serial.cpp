#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include "serial.h"

Serial::Serial()
{
}

Serial0::Serial0()
{
    UCSRXA = (volatile uint8_t *)0xc0;
    UDRX   = (volatile uint8_t *)0xc6;
    UBRR0L = 25;
    UCSR0A &= ~(1<<U2X0);
    UCSR0B = (1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0);
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
    sei();
}

Serial1::Serial1()
{
    UCSRXA = (volatile uint8_t *)0xc8;
    UDRX   = (volatile uint8_t *)0xce;
    UBRR1L = 103;
    UCSR1A &= ~(1<<U2X1);
    UCSR1B = (1<<TXEN1) | (1<<RXEN1) | (1<<RXCIE1);
    UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);
    sei();
}

Serial2::Serial2()
{
    UCSRXA = (volatile uint8_t *)0xd0;
    UDRX   = (volatile uint8_t *)0xd6;
    UBRR2L = 103;
    UCSR2A &= ~(1<<U2X2);
    UCSR2B = (1<<TXEN2) | (1<<RXEN2) | (1<<RXCIE2);
    UCSR2C = (1<<UCSZ21) | (1<<UCSZ20);
    sei();
}

Serial3::Serial3()
{
    UBRR3L = 103;
    UCSR3A &= ~(1<<U2X2);
    UCSR3B = (1<<TXEN3) | (1<<RXEN3) | (1<<RXCIE3);
    UCSR3C = (1<<UCSZ31) | (1<<UCSZ30);
    sei();
}

void Serial::puts(const char *s)
{
    while (*s)
    {
        putcee(*s++);
    }
}

void Serial::putcee(char c)
{
    while (!(*UCSRXA & (1<<5))) {
    }

    *UDRX = c;
}


