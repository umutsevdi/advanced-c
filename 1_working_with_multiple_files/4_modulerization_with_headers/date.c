#include "date.h"
#include <stdlib.h>
void dt__fetch(date *d) {
  if (d->day >= dt_nod(d->month, d->year)) {
    d->day -= dt_nod(d->month, d->year);
    d->month++;
  }
  if (d->month > 12) {
    d->month = DT_M_JANUARY;
    d->year++;
  }
}

int dt_nod(enum DT_MONTH month, int year) {
  switch (month) {
  case DT_M_JANUARY:
    return 31;
  case DT_M_FEBRUARY:
    return DT_IS_LEAP(year) ? 29 : 28;
  case DT_M_MARCH:
    return 31;
  case DT_M_APRIL:
    return 30;
  case DT_M_MAY:
    return 31;
  case DT_M_JUNE:
    return 30;
  case DT_M_JULY:
    return 31;
  case DT_M_AUGUST:
    return 31;
  case DT_M_SEPTEMBER:
    return 30;
  case DT_M_OCTOBER:
    return 31;
  case DT_M_NOVEMBER:
    return 30;
  case DT_M_DECEMBER:
    return 31;
  }
}

date *dt_new(int dat, enum DT_MONTH month, int year) {
  date *d = (date *)malloc(sizeof(date));
  d->day = dat;
  d->month = month;
  d->year = year;
  return d;
}

int dt_comp(date *d1, date *d2) {
  if (d2->year != d1->year)
    return (d1->year > d2->year) * 2 - 1;
  if (d2->month != d1->month)
    return (d1->month > d2->month) * 2 - 1;
  if (d2->day != d1->day)
    return (d1->day > d2->day) * 2 - 1;
  return 0;
}
int dt_doy(date *d);
int dt_woy(date *d);
enum DT_DAY dt_day(date *d);

void dt_plus_d(date *d, int day) {
  d->day += day;
  dt__fetch(d);
}
void dt_plus_m(date *d, int month) {
  d->month += month;
  dt__fetch(d);
}
void dt_plus_y(date *d, int year) {
  d->year += year;
  dt__fetch(d);
}
