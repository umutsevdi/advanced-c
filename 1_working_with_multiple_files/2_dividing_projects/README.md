# Definition

In this project we divide a complex program into modules. We have a stack library
called stk.h. Which includes various helpful functions for a general purpose
stack implementation.

However instead of keeping it all in the same file we divide the project into
multiple source files. All files are then included at [header/stk.h](header/stk.h)
to remove the complexity. By including a single file, user can access the entire
library.

# Experiment

In this example we have a header files at the [header](header/) directory.

- [stk_init](header/stk_init.h) contains base functions. It is included at
  every other stk source file. However it is not added to the code multiple times
  due to the following conditional inclusion.

  ```cpp
  #ifndef STK_INIT
  #define STK_INIT
  #include "stk_init.h"
  #endif
  ```

- [stk_util](header/stk_util.h) includes various utility functions such as
  `int stk_len(stk *stack)` or `int stk_len(stk *stack)`. Much like the previous
  stk_init, it is not added to the binary multiple times thanks to a similar macro.

- [stk_mv](header/stk_mv.h) includes functions like stk_push and stk_pop. It returns
  error values such as:

  ```c
  #define STK_ERROR_ALREADY_ADDED 1
  #define STK_ERROR_INVALID_ARGUMENTS 2
  #define STK_ERROR_NO_ELEMENT_LEFT NULL
  ```

- All source files are documented using the javadoc standard.

  ```c
  /**
   * pushes given node to the stack
   * @param stk*      stack address of the stack
   * @param stk_node* address of the node
   * @return 0 if successfully pushed, any other number on error
   */
  int stk_push(stk *stack, stk_node *node) {
    if (stack == NULL || node == NULL) {
      return STK_ERROR_INVALID_ARGUMENTS;
    } else if (stack->current == node) {
      return STK_ERROR_ALREADY_ADDED;
    }
    node->next = stack->current;
    stack->current = node;
    return 0;
  }
  ```

# How to run

Execute the shell script. It will create the binary at the [build/main](build/main) directory.

```sh
echo "gcc -o build/main src/*.c -I`pwd`/header/" | sh 
```
