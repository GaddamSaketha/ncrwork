#include<stdio.h>
int main()
{
	//gyhjkk
	int num,r;
	long int bin=0,i=1;
	printf("enter digit");
	scanf("%d", &num);
	if (num > 0 && num < 32)
	{
		while (num != 0)
		{
			r = num % 2;
			num = num / 2;
			bin = bin + (i*r);
			i = i * 10;
		}
		printf("bin is %ld", bin);
		return 1;
	}
	return 0;

}