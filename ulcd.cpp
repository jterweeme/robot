#include "ulcd.h"
#include "misc.h"
uLCD::uLCD()
{
    init();
}

void uLCD::init()
{
    
}

void uLCD::puts(const char *s)
{
    Serial3::puts(sjprintf(s));
}


