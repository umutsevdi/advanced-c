# Definition

A makefile automates the compiling process for the programming languages such as
C, C++ and Java. It is used to speed up the development time.

It checks source and object files and automatically recompiles if any of the watched
files are changed.

# Experiment

In this example our goal is to generate a `Makefile` with multiple functions.
These functions are:

- **build**: Controls the change in the object files. Builds the binary.
- **compile**: Compiles to the source codes while linking th header.
- **clean**: Clears the object files and the binary.

# How to run

Execute the Makefile. 

```sh
# Run any of the followings
make clean
make test
make build
make
```
