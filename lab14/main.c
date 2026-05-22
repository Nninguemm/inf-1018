#include <stdio.h>

#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

typedef union { 
  float f;
  unsigned int i;
 } U;


float float2(float f)
{
    U u;

    u.f = f;

    unsigned int expoente = getexp(u.i);
    expoente = expoente + 1;

    unsigned int sinal = getsig(u.i);
    unsigned int fracao = getfrac(u.i);

    u.i = makefloat(sinal, expoente, fracao);

    return u.f;
}

float int2float(int i)
{
    if(i == 0)
        return 0.0;

    unsigned int s;
    unsigned int valor;

    if(i < 0)
    {
        s = 1;
        valor = -i;
    }
    else
    {
        s = 0;
        valor = i;
    }

    int j = 31;

    while(1)
    {
        unsigned int bit = (valor >> j) & 1;

        if(bit == 1)
            break;

        --j;
    }

    unsigned int e = j + 127;

    unsigned int frac;

    if(j <= 23)
        frac = (valor << (23 - j)) & 0x7fffff;
    else
        frac = (valor >> (j - 23)) & 0x7fffff;

    U u;

    u.i = makefloat(s, e, frac);

    return u.f;
}

int main(void)
{
    float f1 = 2.25;

    float f2 = float2(f1);

    printf("dobro de %f = %f\n", f1, f2);


    int i;

    printf("\n******** int2float ****************\n");
    i = 0;
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = 1;  
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = -1;  
    printf(" %d -> %10.4f\n", i, int2float(i));
    i = 0x7fffffff;  
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = -i;
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = 12345;
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = -12345;
    printf(" %d -> %+10.4f\n", i, int2float(i));
    return 0;

    return 0;
}