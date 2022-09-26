# Definition

## Designated Initializers

Standard C90 requires the elements of an initializer to appear in a fixed order,
the same as the order of the elements in the array or structure being initialized.

In ISO C99 you can give the elements in random order, specifying the array
indices or structure field names they apply to, and GNU C allows this as an
extension in C90 mode as well. This extension is not implemented in GNU C++.
To specify an array index, write ‘[index] =’ or ‘[index]’ before the element value.

```c
  int arr[5] = {[0] = 2, [1] = 4, [4] = 10}; // [2, 4, 0, 0, 10]
```

You can initialize multiple serial values.

```c
  int arr_desig[10] = {[0 ... 5] = 2, [9] = 21}; // [2, 2, 2, 2, 2, 2, 0, 0, 0, 21]
```

Structs have following Designated Initializers:

```c
  struct DATA d = {.id = 10, .tag = "txt", .eol = 42};
  struct DATA d_unnamed = {11, "txt", 0};
  struct DATA d_gnu = {id : 5, tag : "ignore_eol"}; // only works with GNU
```

## Experiment

## How to run

Run following command.

```sh
gcc -o main main.c
```
