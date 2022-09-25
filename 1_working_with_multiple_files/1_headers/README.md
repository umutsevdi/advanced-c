# Definition

A header file is a file with extension .h which contains C function declarations
and macro definitions to be shared between several source files. There are two
types of header files: the files that the programmer writes and the files that
comes with your compiler.

# Experiment

In this example we have a header file at [header/other.h](header/other.h) which is
included by both source files: [main](src/main.c) and [other](src/other.c).

Header defines a static `VALUE` as 5. And contains a function `other#get_num(void)`.
This function returns the `VALUE`. On the main function we access the variable by
including the header file which is implemented by the source file with the same name.

# How to run

Execute the shell script. It will create the binary at the [build/main](build/main) directory.

```sh
echo "gcc -o build/main src/*.c -I`pwd`/header/" | sh
```
