#include "extern.h"
#include <stdio.h>
#include <stdlib.h>
int exvar = 5;
int main(int argc, char *argv[]) {
  printf("External value is %d\n", exvar);
  inc_exvar(15);
  printf("External value is updated to %d\n", exvar);

  return 0;
}
