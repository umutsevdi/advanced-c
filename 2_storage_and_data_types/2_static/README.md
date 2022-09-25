# Definition

Different variable types define different scope.

## static 

Static keeps the value of a variable and prevents it from being reinitialized.

# Experiment

In this example we have a function that has a local `static` variable. This
variable is increased every time the function is called.
Without the `static` keyword this main function would loop forever.

However because of that it breaks the loop after 10 times.
# How to run
Run following command.

```sh
gcc -o main main.c
```
