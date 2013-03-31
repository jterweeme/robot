#ifndef _MOTOR_H_
#define _MOTOR_H_

class Motor
{
public:
    virtual void linksVooruit() = 0;
    virtual void linksAchteruit() = 0;
    virtual void rechtsAchteruit() = 0;
    virtual void rechtsVooruit() = 0;
    virtual void linksStop() = 0;
    virtual void rechtsStop() = 0;
};

class PWMMotor : public Motor
{
public:
    PWMMotor();
    void linksVooruit();
    void linksAchteruit();
    void rechtsAchteruit();
    void rechtsVooruit();
    void linksStop();
    void rechtsStop();
};

class PWMPLLMotor : public Motor
{
public:
    PWMPLLMotor();
    void linksVooruit();
    void linksAchteruit();
    void rechtsAchteruit();
    void rechtsVooruit();
    void linksStop();
    void rechtsStop();
};
#endif

