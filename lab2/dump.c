#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  char c[] = "A \n$";
  int i = 10000;
  char a = 'a';
  short int i2 = 10000;
  long int i3 = 10000;
  dump(&c, sizeof(c));
  dump(&a, sizeof(a));
  dump(&i2, sizeof(i2));
  dump(&i3, sizeof(i3));
  dump(&i, sizeof(i));
  return 0;
}