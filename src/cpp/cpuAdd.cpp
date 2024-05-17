#include "add.h"

int add(int a, int b, int device)
{
    int c;
    if (device == 0)
    {
        add_CPU(a, b, &c);
    }
    else
    {
        add_GPU(a, b, &c);
    }
    return c;
}

void add_CPU(int a, int b, int* c)
{
    *c = a + b;
}