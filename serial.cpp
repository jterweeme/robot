#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include "serial.h"
Serial0::Serial0()
{
    UBRR0L = 25;
    UCSR0A &= ~(1<<U2X0);
    UCSR0B = (1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0);
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
    sei();
}

Serial1::Serial1()
{
    UBRR1L = 103;
    UCSR1A &= ~(1<<U2X1);
    UCSR1B = (1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0);
    UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);
    sei();
}

void Serial0::puts(const char *s)
{
    for (int i = 0; i < strlen(s); ++i)
        putcee(s[i]);
}

void Serial1::puts(const char *s)
{
    for (int i = 0; i < strlen(s); ++i)
        putcee(s[i]);
}

void Serial0::putcee(char c)
{
    while (!(UCSR0A & (1<<UDRE0))) {
    }

    UDR0 = c;
}

void Serial1::putcee(char c)
{
    while (!(UCSR1A & (1<<UDRE1))) {
    }

    UDR1 = c;
}

void Serial1::bogus()
{
    puts("onzin\r");
}



