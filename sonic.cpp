Sonic::Sonic()
{
    bufferPointer = 0;
    header = 0;
    highbyte = 0;
    lowbyte = 0;
    sum = 0;
}

uint8_t Sonic::getDistance()
{
    return lowbyte;
}

void Sonic::requestDistance()
{
    uint8_t onzin[4] = { 0x22, 0, 0, 0x22 };

    for (int i = 0; i < 4; i++)
        this->putcee(onzin[i]);
}

void Sonic::addToBuffer(char c)
{
    bufferPointer++;

    switch (bufferPointer)
    {
    case 1:
        header = (int)c;
        break;
    case 2:
        highbyte = (int)c;
        break;
    case 3:
        lowbyte = (int)c;
        break;
    case 4:
        sum = (int)c;
        break;
    default:
        bufferPointer = 0;
        break;
    }

    debugPort->putcee(c);
    debugPort->putcee('\n');

}


