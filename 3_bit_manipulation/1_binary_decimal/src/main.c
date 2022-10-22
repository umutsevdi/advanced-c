#include "bin_util.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("%d\n", bin2dec(10001));
  printf("%d\n", bin2dec(10010));
  printf("%d\n", bin2dec(10011));
  printf("%d\n", bin2dec(10100));

  printf("%lld\n", dec2bin(456));
  printf("%d\n", digit_at(456, 2));
  return 0;
}
