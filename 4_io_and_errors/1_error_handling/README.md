# Exception Handling in C with `setjmp` and `longjmp`

`setjmp` and `longjmp` are functions that let you perform complex flow control
in C.

- `setjmp` mainly used at implementing exception handling in C for recovery
  situations. They are like `try` `catch` in languages like C++ and Java.
- `longjmp` can be used like `throw`.

## Overview

Suppose there is an error deep down in a function nested in many other
functions and error handling makes sense in the top level function.

- It may not make sense when the function returns normally.
- Using a global variable to determine the error would be bad practice.
- It behaves like `goto` with an exception. These functions can jump to
  other functions.

```c
#include <setjmp.h>
```
