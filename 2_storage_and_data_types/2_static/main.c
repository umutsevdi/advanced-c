#include <stdio.h>

int inc() {
  static int x = 0;
  return ++x;
}

int main(int argc, char *argv[]) {
  int i = 0;
  while ((i = inc()) && i < 10)
    printf("%d\n", i);
  return 0;
}
