#ifndef _SERIAL_H_
#define _SERIAL_H_
class Serial
{
public:
    virtual void puts(const char *) = 0;
};

class Serial0 : public Serial
{
public:
    Serial0();
    void puts(const char *);
    void putcee(char);
};

class Serial1 : public Serial
{
public:
    Serial1();
    void puts(const char *);
    void putcee(char);
    void bogus();
};


#endif


