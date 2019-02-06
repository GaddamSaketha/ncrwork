#include<stdio.h>
int main()
{
	int min=9999,max=-1,avg=0,count=0,n;
	do {
		scanf("%d", &n);
		if (n <= 0)
			break;
		count++;
		if (n > max)
			max = n;
		if (n < min)
			min = n;
		avg = avg + n;
	} while (n > 0);
	avg = avg / count;
	printf("\n min is %d", min);
	printf("\n max is %d", max);
	printf("\n avg is %d", avg);
	printf("\n count is %d", count);

	return 0;
}