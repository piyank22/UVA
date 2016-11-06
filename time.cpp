#include <cstdio>
#include <cmath>
#include <ctime>

#define PI acos(-1)

int main()
{
	tm t={0,0,0,9,8-1,2010-1900}; // sec , min , hour , date(1-31) , month(0-11) , year(starts from 1900) , week_day , day_in _year , day_light_saving_time
/*
	struct tm {
	   int tm_sec;         / seconds,  range 0 to 59          /
	   int tm_min;         / minutes, range 0 to 59           /
	   int tm_hour;        / hours, range 0 to 23             /
	   int tm_mday;        / day of the month, range 1 to 31  /
	   int tm_mon;         / month, range 0 to 11             /
	   int tm_year;        / The number of years since 1900   /
	   int tm_wday;        / day of the week, range 0 to 6    /
	   int tm_yday;        / day in the year, range 0 to 365  /
	   int tm_isdst;       / daylight saving time             /
	};

*/
	mktime(&t) ;
	printf("%d",t.tm_wday);
	return 0;
}