#ifndef _MOTOR_H_
#define _MOTOR_H_

class PWMMotor
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

class PWMPLLMotor
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

