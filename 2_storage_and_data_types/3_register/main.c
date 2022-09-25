#include <stdio.h>
#include <stdlib.h>

int sum(int *arr, int size) {
  int sum = 0, i = 0;
  while (i < size)
    sum += arr[i++];
  return sum;
}

int main(int argc, char *argv[]) {
  int i = 0, size = 0;
  scanf("%d", &size);
  register int *arr = (int *)malloc(sizeof(int) * size);

  for (i = 0; i < size; i++)
    scanf("%d ", &arr[i]);
  printf("\nRESULT = %4d\n", sum(arr, size));
  return 0;
}
