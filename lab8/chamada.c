#include <stdio.h>

int b (long z, int y, short x)
{
    return z + y + x;
}

int a (long x, int y, short z)
{
    int c = b(z,y,x);
    return c;
}

int main(void)
{
    printf("%d", a(1,2,3));

    return 0;
}