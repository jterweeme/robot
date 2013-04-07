#ifndef _ULCD_H_
#define _ULCD_H_
#include "serial.h"
class uLCD : public Serial2
{
public:
    uLCD();
    void init();
    int puts(const char *);
    int clear();
    int landscape();
};
#endif


