# Type Qualifiers

## Definition

Type qualifiers are a type of definition similar to the storage classes. However
type qualifiers are for compiler optimization. Same type qualifier can be used multiple
times on the same variable. Redundant qualifiers are automatically ignored.

- **const**: Describes that the defined variables value will not change during it's
  lifetime. Compiler can catch an error during compile time. And the compiler
  may place the value to a read-only memory.

  ```c
    const int x = 20;
    const char* y;
    y = (char*) malloc(sizeof(char)*SIZE);

    const float* pf;            // A pointer that points to a constant float value
    float const* pf;            // Same as above
    float* const pf;            // A constant pointer that points to a float
    const float* const pf;      // A constant pointer that points to a constant float

    /**
     * @param arr immutable int array
     * @param len number of elements in the array
     */
    void display(const int* arr, int len);

    /**
     * Append the string src to the string dest, returning
     * a pointer dest.
     * @param dest destination to append
     * @param src source to copy
     * @return new char pointer
     */
    char *strcat(char *restrict dest, const char *restrict src);
  ```

- **volatile**: Volatile is the opposite of constant. It is used to notify compiler
  that the referenced value will change during runtime. Then the compiler will not
  cache the value. This type qualifier is commonly used on embedded programming and
  multi-threaded software.

  ```c
      volatile int const *p; // a constant pointer that points to an integer with
                             // a non-cached value
  ```

  - Use Cases:
    - Peripheral registers
    - Global variables modified by an interrupt
    - Global variables modified by different threads

  **Important Note:** Volatile may reduced performance depending on the use case.
  For example on the same thread let's say we have the following value.

  ```c
     int x = 24;
     int y = x;
  ```

  In this case C compiler understands that the value '24' has only 2 use cases, so
  it stores the value in the register for performance increase. Using `volatile`
  here removes this optimization. Use `volatile` only when the value x can be changed
  by an external source such as another thread, an interrupt or another process that
  has access to the value.

  - Another case with an embedded IO module where `volatile` is useful. Let's say
    we have an output port that can read our `char *outPort;` value. To pass a char
    we can write:

  ```c
    char * outPort;
    // Code to implement binding
    *outPort = 'H';
  ```

  When we write `H` character to the port it will be displayed on the screen. To
  push another value we can write:

  ```c
    *outPort = 'H';
    *outPort = 'E';
    *outPort = 'L';
    *outPort = 'L';
    *outPort = 'O';
  ```

  However in this case C compiler will assume we are not using previously assigned
  values and simply reduce the actual code to `*outPort = 'O';`. To prevent this
  unwanted optimization we can add a type qualifier to the `outPort`.

- **restrict**: Restrict type qualifier tells the compiler that the value can be
  accessed only from the mentioned variable in the existing local scope. Otherwise
  the compiler assumes the worst case.

  ```c
    // Compiler will assume both pointers will access to mutually exclusive arrays.
    int restrict *ptr;
    int restrict *ptr2;
  ```

  - In the worst case compiler will verify whether value is accessed
    by another source such as thread or not. By using restrict compiler will simply
    assume no change happened since the last access.
  - Using restrict and modifying the value from an external source causes undefined
    behaviour.
  - Restrict is not supported on C++.

    ```c
      #include <stdio.h>
      #include <stdlib.h>
      int main(void) {
          int i;
          int arr[10];
          int* restrict sole_arr = (int*) malloc(10* sizeof(int));
          int* acc_arr = arr;
          // acc_arr can not be restrict because there are more access points than
          // acc_arr.

          for(i=0; i< 10; i++) {
              printf("%d %d ->", arr[i], sole_arr[i]);
              acc_arr[i] +=1;
              sole_arr[i] += 2;
              arr[i] += 10;
              acc_arr[i] +=2;
              sole_arr[i] += 5;
              printf("%d %d\n", arr[i], sole_arr[i]);
          }
          // However while compiling the code, compiler change the code to the following
          // version.
          /*
           *  for(i=0; i< 10; i++) {
           *      acc_arr[i] +=1;
           *      sole_arr[i] += 7;
           *      arr[i] += 10;
           *      acc_arr[i] +=2;
           *   }
           */
        }
    ```
