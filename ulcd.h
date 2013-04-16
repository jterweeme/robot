#ifndef _ULCD_H_
#define _ULCD_H_
#include "serial.h"
#include <stdint.h>
class uLCD : public Serial2
{
public:
    uLCD();
    void init();
    int puts(const char *);
    int clear();
    int landscape();
    void setResponse(uint8_t);
    int fetchResponse();
    int setBackground(unsigned int);
private:
    uint8_t response;
    static const int WHITE = 0xffff;
};
#endif


