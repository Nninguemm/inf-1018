#include <stdio.h>

void dump(void*pont, int num)
{
    char* ponteiro = pont;
    for (int i =0; i<num;++i)
    {
        printf("%p : %0x : %d : \n", ponteiro, *ponteiro, *ponteiro);
        ++ponteiro;
    }
    return;
}

int main(void)
{
  signed char sc = -1;
  unsigned int ui = sc;
  dump(&ui, sizeof(ui));
  return 0;
}