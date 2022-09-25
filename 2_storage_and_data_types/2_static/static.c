#include "static.h"
static void private_function() {
  printf("This function can not be accessed.\n");
}

void public_function() { printf("This function can be accessed.\n"); }

void set() {
  private_variable = 5;
  public_variable = 5;
}
