#include <stdio.h>
#include "wifly.h"
WiFly::WiFly()
{
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


