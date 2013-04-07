#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "misc.h"

class Motor
{
public:
    virtual void linksVooruit(unsigned int) = 0;
    virtual void linksAchteruit(unsigned int) = 0;
    virtual void rechtsAchteruit(unsigned int) = 0;
    virtual void rechtsVooruit(unsigned int) = 0;
    virtual void linksStop() = 0;
    virtual void rechtsStop() = 0;
};

class PWMMotor : public Motor
{
public:
    PWMMotor();
    void linksVooruit(unsigned int);
    void linksAchteruit(unsigned int);
    void rechtsAchteruit(unsigned int);
    void rechtsVooruit(unsigned int);
    void linksStop();
    void rechtsStop();
};

class PWMPLLMotor : public Motor
{
public:
    PWMPLLMotor();
    void linksVooruit(unsigned int);
    void linksAchteruit(unsigned int);
    void rechtsAchteruit(unsigned int);
    void rechtsVooruit(unsigned int);
    void linksStop();
    void rechtsStop();
};
#endif

