#ifndef _WIFLY_H_
#define _WIFLY_H_
#include "serial.h"
class WiFly : public Serial1
{
public:
    WiFly();
    void showNetworks();
    void commandMode();
    void setPhrase(const char *);
    void join(const char *);
    void addToBuffer(char);
private:
    const char *phrase;
    const char *ssid;
};
#endif


