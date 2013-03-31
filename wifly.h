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
    int addToBuffer(char);
    const char *getBuffer();
private:
    char buffer[200];
    uint8_t buffer_ptr;
    uint8_t last_buffer_ptr;
    const char *phrase;
    const char *ssid;
};
#endif


