#ifndef _ULCD_H_
#define _ULCD_H_
#include "serial.h"
class uLCD : public Serial3
{
public:
    uLCD();
    void init();
    void puts(const char *);
};
#endif


