#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

char (*pdaytab)[13] = daytab;

    int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 0; i < month; i++)
        day += *(*(pdaytab + leap) + i);
        // day += daytab[leap][i];

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = i; yearday > daytab[leap][i]; i++)
        yearday -= *(*(pdaytab + leap) + i);
        // yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    return (n < 1 || n > 12) ? name[0] : name[n];
}


int main(int argc, char const *argv[])
{
    printf("%d\n", day_of_year(2023, 11, 27));
    return 0;
}
