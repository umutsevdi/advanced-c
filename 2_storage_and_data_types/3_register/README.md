# Definition

Different variable types define different scope.

## register

A processor register or CPU register can hold an instruction, an address or any
type of data. `register` storage class defines the local variabe inside the CPU
register instead of the Random Access Memory. Using the register variables
allow faster access to the values.

Number of variables tagged as `register` is equal to the number of register your
CPU has. Register storage class is a hint. It may not be applied when the program
is running. If all CPU registers are being used, variable will be saved to the
memory instead.

## Experiment

Using the register storage class we can reduce time to access to the `int *arr`.

```c
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
```

## How to run

Run following command.

```sh
gcc -o main main.c
```
