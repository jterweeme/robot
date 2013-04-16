#ifndef _SERIAL_H_
#define _SERIAL_H_
#include <stdint.h>
class Serial
{
public:
    Serial();
    void puts(const char *);
    void putcee(char);
protected:
    volatile uint8_t *UCSRXA;
    volatile uint8_t *UDRX;
};

class Serial0 : public Serial
{
public:
    Serial0();
};

class Serial1 : public Serial
{
public:
    Serial1();
};

class Serial2 : public Serial
{
public:
    Serial2();
};

class Serial3 : public Serial
{
public:
    Serial3();
};

#endif


