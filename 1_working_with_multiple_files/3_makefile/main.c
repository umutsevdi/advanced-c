#include "test.h"
#include <stdio.h>

extern int k;
int main(int argc, char *argv[]) {
  printf("%d\n", get_value(10, 5));
  int y = k;
  printf("Shared K value results: %d\n", y);
  return 0;
}
