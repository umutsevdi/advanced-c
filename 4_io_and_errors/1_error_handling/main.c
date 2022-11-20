#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define EXIT_CODE 0
jmp_buf buf;

int tst_func() {
  printf(" begin:\ttst_func()\n");
  sleep(1);
  /* exception happens */
  longjmp(buf, 10);
  printf(" exit:\ttst_func\n");
  return 0;
}

int tst_func2() {
  printf(" begin:\ttst_func2()\n");
  sleep(1);
  printf(" exit:\ttst_func2\n");
  return 0;
}

int try_catch(int function()) {
  printf(">> try\n");
  int err_code = setjmp(buf);
  if (err_code == 0) {
    int r = function();
    printf(">> ok\treturn %d\n",r);
    return r;
  }
  printf(">> catch\t%2d\n", err_code);
  return err_code;
}

int main() {
  printf("begin:\tmain\n");
  printf("exec:\ttst_func\n");
  try_catch(tst_func);
  printf("exec:\ttst_func2\n");
  try_catch(tst_func2);

  tst_func();
  tst_func2();
  printf("exit:\tmain\n");
}
