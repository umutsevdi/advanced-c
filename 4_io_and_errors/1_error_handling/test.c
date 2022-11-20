#include <stdio.h>
int main(int argc, char *argv[]) {
  int i, j, n = 5;
  for (i = 0, j = 0; i < n; j < n ? j++ : (j = 0, i++)) {
    printf("%d %d\n", i, j);
  }

  return 0;
}
