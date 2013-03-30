#ifndef _SPARKFUN_H_
#define _SPARKFUN_H_
#include <stdint.h>
class Sparkfun : public Serial1, Wifi
{
public:
    Sparkfun();
    void showNetworks();
    void setWPA(const char *);
    void setSSID(const char *);
    void startServer(unsigned int);
    void addToBuffer(char);
    void tokenize(const char *);
private:
    char buffer[200];
    uint8_t bufferPtr;
};
#endif

