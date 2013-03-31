#ifndef _MISC_H_
#define _MISC_H_
extern "C" void __cxa_pure_virtual()
{
    while (true) {
    }
}

void * operator new (size_t size)
{
    return malloc(size);
}

#endif

