#ifndef BIN_UTIL
#define BIN_UTIL

#define DIGIT_AT_IN_DEC(dec, d)                                                \
  /* Returns the digit at given position, from right to left                   \
   * DIGIT_AT_IN_DEC(1234,100)->2                                              \
   */ (dec % (d * 10) - dec % d) / d

/** Returns the number at given digit
 * @param dec the decimal to search
 * @param d digit number, counts from right at left starting from 0
 * @return single digit at line
 *
 * example:
 * * digit_at(123456, 3) -> 3
 *
 * * digit_at(123456, 0) -> 6
 *
 */
short digit_at(long long dec, int digit);

/**
 * Returns decimal representation of given binary number
 * @param bin binary number
 * @return  result binary number in decimal format
 */
int bin2dec(long long bin);

/**
 * Returns binary representation of given decimal number
 * @param dec decimal number
 * @return result in binary format
 */
long long dec2bin(int dec);

#endif
