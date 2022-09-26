#include <stdio.h>
#include <stdlib.h>

struct DATA {
  int id;
  char tag[12];
  int eol;
};

void int_arr_print(int *arr, int size) {
  int i = 0, *c = arr;
  while (i++ < size)
    printf("%d ", *(c++));
  printf("\n");
}

int main(int argc, char *argv[]) {

  // Arrays
  int arr[10] = {[0] = 2, [1] = 4, [2] = 10, [3] = 21};
  int arr_desig[10] = {[0 ... 5] = 2, [9] = 21};
  int_arr_print(arr, 10);
  int_arr_print(arr_desig, 10);

  // Structs
  struct DATA d = {.id = 10, .tag = "txt", .eol = 42};
  struct DATA d_unnamed = {11, "txt", 0};
  struct DATA d_gnu = {id : 5, tag : "ignore_eol"}; // only works with GNU
  return 0;
}
