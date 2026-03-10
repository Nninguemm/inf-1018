#include <stdio.h>
#include <stdlib.h>

int is_little()
{
    int i = 123;
    unsigned char* p = (unsigned char*)&i; //utilizar char para verificar de cada byte // n entendi isso
    if (*p > 0)
    {
        printf("1");
        return 1;
    }
    else
        return 0;
    //for (int n = 0; n<4;++n)
    //{
        //printf("%d ",*p);
        //++p;
    //}
}

void num2string(char *s, int num, int base)
{
    char* string;
    int num2 = num;
    for(int n; n<base; ++n)
    {
       //
    }
}

int main(void)
{

    is_little();
    return 0;
}