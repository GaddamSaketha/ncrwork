#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct time {
	int hr, min, sec;
};
int main()
{
	struct time t;
	printf("Enter the time in hrs mins and seconds : ");
	scanf("%d %d %d", &t.hr, &t.min, &t.sec);
	printf("Time is : %d:%d:%d\n", t.hr, t.min, t.sec);
	return 0;
}