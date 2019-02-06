#include<stdio.h>
int main()
{
	long int sal,gross;
	printf("enter sal");
	scanf("%ld", &sal);
	if (sal <= 0)
		return 0;
	if (sal > 0 && sal <= 4000)
	{
		gross = sal + (sal / 10) + (sal / 2);
	}
	else if (sal > 4000 && sal <= 8000)
	{
		gross = sal + (sal / 5) + ((3*sal) / 5);
	}
	else if (sal > 8000 && sal < 12000)
	{
		gross = sal + (sal / 4) + ((7 * sal) / 10);
	}
	else
		gross = sal + ((3*sal) / 10) + ((4 * sal) / 5);
	printf("gross sal is %ld", gross);

	return 0;
}