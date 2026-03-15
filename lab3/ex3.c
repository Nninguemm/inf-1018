#include <stdio.h>

unsigned char switch_byte(unsigned char x)
{
    unsigned char metade1;
    unsigned char metade2;
    metade1 = x<<4;
    metade2 = x>>4;
    unsigned char tudo = metade1|metade2;
    return tudo; 
}

unsigned char rotate_left(unsigned char x, int n)
{
    unsigned char voltar = 0;
    int num = (8-n);
    for (int i = 0; i<n; ++i)
    {
        voltar = voltar | (x&(0x1<<7))>>num;
        ++num;
        x = x<<1;
    }

    return (x|voltar);
}

int main(void) 
{
    unsigned char a = 0xAB;
    //printf("resultado:%02x", switch_byte(a));
        printf("resultado:%02x", rotate_left(0x61,1));
            printf("resultado:%02x", rotate_left(0x61,2));
    printf("resultado:%02x", rotate_left(0x61,7));
    return 0;
}