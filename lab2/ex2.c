#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int n) {
  int a = 0;
  for (; *s; s++)
    a = a*10 + (*s - '0');
  return a;
}

int string2num2 (char *s, int n) {
  int a = 0;
  for (; *s; s++)
    a = a*n + (*s - '0');
  return a;
}

int string2num3 (char *s, int n) {
  int a = 0;
  for (; *s; s++)
    if isdigit(*s)
      a = a*n + (*s - '0');
    else
    {
      a = a*n + (*s - 'W');
    }
  return a;
}

int main (void) {
  printf("%d\n", string2num3("1a", 16));
  printf("%d\n", string2num3("a09b", 16));
  printf("%d\n", string2num3("z09b", 36));
  return 0;
}