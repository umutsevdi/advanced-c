# Definition

Different variable types define different scope.

## extern

Extern is a type of global variable that allow access from different source files.

By initializing variables with the same name links them together.

```c
    /*--- main.c ---*/
    #include "extern.h"
    #include <stdio.h>
 ┌> int external_variable = 5;
 │  int main(void) {
 │      printf("%d\n", external_variable);
 │      intc_exvar(10);
 │      printf("%d\n", external_variable);
 │  }
 │
 /*--- extern.c ---*/
 │  #include "extern.h"
 │  #include <stdio.h>
 └>  extern int exvar;
     void inc_exvar(int amount) {
         exvar += amount;
     }
```

Extern can be used to link functions without actually including them.

# Experiment

In this example we have a variable defined at the [main](main.c) that is modified
by an external function.

# How to run

Execute the Makefile.

```sh
# Run any of the followings
make clean
make compile 
make build
make
```
