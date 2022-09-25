#include <stdio.h>
#include "date.h"

int main(int argc, char *argv[])
{
    date* d = dt_new(12, DT_M_FEBRUARY, 1999);
    printf("%d\n",DT_IS_LEAP(d->year));

    return 0;
}
