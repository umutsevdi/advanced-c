#include "static.h"
#include <stdio.h>

int public_variable;
static int private_variable;

int inc() {
  static int x = 0;
  return ++x;
}

int main(int argc, char *argv[]) {
    set();
  int i = 0;
  while ((i = inc()) && i < 10)
    printf("%d\n", i);

  public_function();
  /* This function is not accessable*/
  /* private_function(); */
  printf("Public Variable: %2d (is updated by set())\n", public_variable);
  printf("Private Variable: %2d (is not updated)\n", private_variable);

  return 0;
}
