# Definition

Different variable types define different scope.

## static

Static keeps the value of a variable and prevents it from being reinitialized.
Static variables are can not be accessed from outside the scope.

By default all functions and variables in the global scope are defined as `extern`.
Allowing access from outside. However adding `static` keyword makes them local to
the scope disabling any external acccess.

## Experiment

In this example we have a function that has a local `static` variable. This
variable is increased every time the function is called.
Without the `static` keyword this main function would loop forever.

However because of that it breaks the loop after 10 times.

## Experiment 2

In the example the following function and variables are defined.

```c
static void private_function();

void public_function();

static int private_variable;

extern int public_variable;

void set();
```

By default all functions and variables in the global scope are defined as `extern`.
Allowing access from outside. However adding `static` keyword makes them local to
the scope disabling any external acccess.

In the second experiment we can see we can access to the `public_function` and `public_variable`.
In fact we can set it using the `set` function. However private_variable is uneffected.

## How to run

Run following command.

```sh
gcc -o main main.c
```
