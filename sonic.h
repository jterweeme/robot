/*
Jasper ter Weeme
 */


#ifndef _SONIC_H_
#define _SONIC_H_
class Sonic : public Serial3
{
public:
    Sonic();
    uint8_t getDistance();
    void requestDistance();
    void setDistance(uint8_t distance);
    void addToBuffer(char);
private:
    int bufferPointer;
    int header;
    int highbyte;
    int lowbyte;
    int sum;
};
#endif

