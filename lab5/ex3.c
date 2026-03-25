#include <stdio.h>

struct X1 {
  char c1;
  int i;
  char c2;
};

struct X2 {
  long l;
  char c;
};

struct X3 {
  int i;
  char c1;
  char c2;
};

struct X4 {
  struct X2 x;
  char c;
};

struct X5 {
  char c1;
  char c2;
  char c3;
};

struct X6 {
  short s1;
  int i;
  char c[3];
  short s2;
};

union U1 {
  int i;
  char c[5];
};

union U2 {
  short s;
  char c[5];
};

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  struct X1 x1 = {'A', 10, 'B'};

  struct X2 x2 = {1000L, 'C'};

  struct X3 x3 = {20, 'D', 'E'};

  struct X4 x4 = {{2000L, 'F'}, 'G'};

  struct X5 x5 = {'H', 'I', 'J'};

  struct X6 x6 = {1, 30, {'K', 'L', 'M'}, 2};

  union U1 u1 = {.i = 12345};   

  union U2 u2 = {.s = 32000};   
  dump(&x1, sizeof(x1));
  printf("------------------------------");
  dump(&x2, sizeof(x1));
  printf("------------------------------");
  dump(&x3, sizeof(x1));
  printf("------------------------------");
  dump(&x4, sizeof(x1));
  printf("------------------------------");
  dump(&x5, sizeof(x1));
  printf("------------------------------");
  dump(&x6, sizeof(x1));
  printf("------------------------------");

  printf("=======================\n");
  printf("%d\n", sizeof(x1));
  printf("%d\n", sizeof(x2));
  printf("%d\n", sizeof(x3));
  printf("%d\n", sizeof(x4));
  printf("%d\n", sizeof(x5));
  printf("%d\n", sizeof(x6));
  printf("%d\n", sizeof(u1));
  printf("%d\n", sizeof(u2));
  return 0;
}