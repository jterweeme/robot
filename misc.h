#ifndef _MISC_H_
#define _MISC_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
extern "C" void __cxa_pure_virtual();
/*
{
    while (true) {
    }
}*/

inline void * operator new (size_t size)
{
    return malloc(size);
}

inline const char *sjprintf(const char *s, ...)
{
    va_list arg;
    va_start(arg, s);
    static char onzin[100];
    vsprintf(onzin, s, arg);
    va_end(arg);
    return onzin;
}


#endif

