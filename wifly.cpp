#include <stdio.h>
#include "wifly.h"
WiFly::WiFly()
{
    buffer_ptr = 0;
    last_buffer_ptr = 0;
}

void WiFly::showNetworks()
{
    puts("scan\r");
}

void WiFly::commandMode()
{
    puts("$$$\r");

    for (volatile unsigned long int i = 0; i < 0xfffff; i++) {
    }
}

void WiFly::setPhrase(const char *phrase)
{
    this->phrase = phrase;
    char onzin[100];
    sprintf(onzin, "set wlan phrase %s\r", phrase);
    puts(onzin);

    for (unsigned volatile long int i = 0; i < 0xfffff; i++) {
    }
}

void WiFly::join(const char *ssid)
{
    this->ssid = ssid;
    char onzin[100];
    sprintf(onzin, "set wlan ssid %s\r", ssid);
    puts(onzin);

    for (unsigned volatile long int i = 0; i < 0xfffff; i++) {
    }

    puts("join\r");
}

const char *WiFly::getBuffer()
{
    return buffer;
}

int WiFly::addToBuffer(char c)
{
    if (c == '\r')
    {
        buffer[buffer_ptr] = 0;
        last_buffer_ptr = buffer_ptr;
        buffer_ptr = 0;
        return 1;
    }

    buffer[buffer_ptr] = c;
    buffer_ptr++;
    return 0;
    
}

