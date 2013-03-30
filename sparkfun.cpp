#include "sparkfun.h"
Sparkfun::Sparkfun()
{
    bufferPtr = 0;
}

void Sparkfun::tokenize(const char *s)
{
    if (strcmp(s, "192") == 0)
        debugPort->puts("niks");
}

void Sparkfun::addToBuffer(char c)
{
    buffer[bufferPtr] = c;

    if (c == '\r')
    {
        buffer[c] = 0;  // terminate
        //debugPort->puts(buffer);
        //debugPort->putcee('\r');
        bufferPtr = 0;
        //tokenize(buffer);
    }

    bufferPtr++;

/*
    if (bufferPtr > 100)
    {
        bufferPtr = 0;
    }*/
}

void Sparkfun::startServer(unsigned int port)
{
    char foo[40];
    sprintf(foo, "at+nstcp=%d\r", port);
    puts(foo);
}

void Sparkfun::showNetworks()
{
    puts("at+ws\r");
}

void Sparkfun::setWPA(const char *phrase)
{
    char foo[40];
    sprintf(foo, "at+wwpa=%s\r", phrase);
    puts(foo);
}

void Sparkfun::setSSID(const char *ssid)
{
    char foo[40];
    sprintf(foo, "at+wa=%s\r", ssid);
    puts(foo);
}



