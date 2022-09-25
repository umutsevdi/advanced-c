# Definition

Enumeration is a user defined datatype in C language. It is used to assign names
to the integral constants which makes a program easy to read and maintain.
The keyword “enum” is used to declare an enumeration.

```c
enum DT_MONTH {
  DT_M_JANUARY = 1,
  DT_M_FEBRUARY,
  DT_M_MARCH,
  DT_M_APRIL,
  DT_M_MAY,
  DT_M_JUNE,
  DT_M_JULY,
  DT_M_AUGUST,
  DT_M_SEPTEMBER,
  DT_M_OCTOBER,
  DT_M_NOVEMBER,
  DT_M_DECEMBER
};

typedef struct DATE {
  int day;
  enum DT_MONTH month;
  int year;
} date;

date *dt_new(int dat, enum DT_MONTH month, int year);

/**
 * returns the number of days in the given month
 * @param DT_MONTH month - month
 * @param year - year (only checked for the leap years)
 * @return number of days in the month
 */
int dt_nod(enum DT_MONTH month, int year);
```

# Experiment

In this example we have a date library that contains both days and months as enums.

# How to run

Execute the Makefile.

```sh
# Run any of the followings
make clean
make install 
make build
make
```
