#include <stdio.h>

int odd_ones(unsigned int x) 
{
    int bits = 0; //começa com 0 par 
    unsigned int pegar_ultimo = 1;
    for (int i = 0; i < 32; ++i)
    {
        if ((x & pegar_ultimo) == 1) //acho q da para usar ^ 
        {
            bits = !bits; 
        }

        x = x>>1;

    }
    return bits;

}

int main() {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}