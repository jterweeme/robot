#ifndef _SERIAL_H_
#define _SERIAL_H_
class Serial
{
public:
    void puts(const char *);
    virtual void putcee(char) = 0;
};

class Serial0 : public Serial
{
public:
    Serial0();
    //void puts(const char *);
    void putcee(char);
};

class Serial1 : public Serial
{
public:
    Serial1();
    void putcee(char);
    //void puts(const char *);
};

class Serial2 : public Serial
{
public:
    Serial2();
    void putcee(char);
    //void puts(const char *);

};

class Serial3 : public Serial
{
public:
    Serial3();
    void putcee(char);
    //void puts(const char *);

};

#endif


