#include "bin_util.h"

short digit_at(long long dec, int digit) {
  /* get the digit value from the digit number*/
  int d = 1;
  while (digit--)
    d *= 10;
  return DIGIT_AT_IN_DEC(dec, digit);
}

int bin2dec(long long bin) {
  // shift index
  int i = 1;
  // dib10: digit in base 10
  int dib10 = 1;
  // res: result
  int res = 0;
  while (bin) {
    short d = DIGIT_AT_IN_DEC(bin, dib10);
    bin -= d * dib10;
    /* add the digit multiplied with the shift value */
    res += d * i;
    dib10 *= 10;
    i = i << 1;
  }
  return res;
}

long long dec2bin(int dec) {
  long long bin = 0;
  int rem, i = 1;
  while (dec) {
    rem = dec % 2;
    dec /= 2;
    bin += rem * i;
    i = i * 10;
  }
  return bin;
}
