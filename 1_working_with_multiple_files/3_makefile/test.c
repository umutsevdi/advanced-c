#include "test.h"

#define MAX(x, y) x > 0 ? x : y
#define _ MAX

int k;
int get_value(int x, int y) {
  k = _(x, y);
  return k;
}
