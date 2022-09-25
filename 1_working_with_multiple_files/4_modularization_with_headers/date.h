#define DT_IS_LEAP(year) !(year % 4)
enum DT_DAY {
  DT_MONDAY = 1,
  DT_TUESDAY,
  DT_WEDNESDAY,
  DT_THURSDAY,
  DT_FRIDAY,
  DT_SATURDAY,
  DT_SUNDAY
};
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

/**
 *
 * @param doy - Day of the year
 * @param dow - Day of the week
 * @param month
 * @param year
 *
 */
typedef struct DATE {
  int day;
  enum DT_MONTH month;
  int year;
} date;

date *dt_new(int dat, enum DT_MONTH month, int year);

/**
 * compares given dates
 * returns 1 if the first date is after, -1 of the second is after, 0 if they
 * are equal
 * @param d1 first date
 * @param d2 second date
 * @return comparision result
 */
int dt_comp(date *d1, date *d2);
int dt_doy(date *d);
int dt_woy(date *d);
enum DT_DAY dt_day(date *d);
void dt_plus_d(date *d, int day);
void dt_plus_m(date *d, int month);
void dt_plus_y(date *d, int year);
/**
 * returns the number of days in the given month
 * @param DT_MONTH month - month
 * @param year - year (only checked for the leap years)
 * @return number of days in the month
 */
int dt_nod(enum DT_MONTH month, int year);
