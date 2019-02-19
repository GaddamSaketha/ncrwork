#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void leapyr(int year);
int yr1; 
int yr2; 
int m1;
int m2;
int d1;
int d2;
int leap;
int main()
{
	int numdays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
	int totaldays=0; 
	int year;
	int month;
	int day;
	printf("Enter beginning date in form month/day/year: ");
	scanf("%d/%d/%d", &m1, &d1, &yr1);
	printf("Enter ending date in form month/day/year: ");
	scanf("%d/%d/%d", &m2, &d2, &yr2);
	for (year = (yr1 + 1); year < yr2; year++) 
	{
		leapyr(year);
		if (leap == 1)
			totaldays += 366;
		else totaldays += 365;
	}
	year = yr1;
	for (month = m1 + 1; month <= 12; month++) 
	{
		leapyr(year);
		if (leap == 1)
			numdays[2] = 29;
		else 
			numdays[2] = 28;
		totaldays = totaldays + numdays[month];
	}
	month = m1;
	for (day = d1; day <= numdays[month]; day++) 
	{
		leapyr(year);
		if (leap == 1)
			numdays[2] = 29;
		totaldays += 1;
	}
	year = yr2;
	for (month = m2 - 1; month >= 1; month--) 
	{
		leapyr(year);
		if (leap == 1)
			numdays[2] = 29;
		totaldays += numdays[month];
	}
	month = m2;
	for (day = d2; day > 1; --day) 
	{
		totaldays += 1; 
	}
	printf("Total number of days between two given dates is: %d days", totaldays);
	
	return 0;

}
void leapyr( int year)
{

	if (year % 4 == 0)
		leap = 1;
	else
		if (year % 100 == 0)
			leap = 0;
		else
			if (year % 400 == 0)
				leap = 1;
	
}