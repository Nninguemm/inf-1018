#include <stdio.h>

int odd_ones(unsigned int x) 
{
    // par -> impar -> par
    x = x>>24;
    int bits = 0;
    for (int i = 0; i < 3; ++i)
    {
        x = x>>1;

    }
    //0000 0000 0000 01010



}


int main() {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}