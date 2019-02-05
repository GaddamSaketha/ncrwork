#include<stdio.h>
long int invertponwards(long int n, int p, int b);
int c = 0;
int main()
{
	int num,r,p,b;
	long int bin,res;
	int i = 1;
	printf("enter num");
	scanf("%d",&num);
	printf("enter pos");
	scanf("%d",&p);
	printf("enter bits count");
	scanf("%d", &b);

	while (num != 0)
	{
		c++;
		r = num % 2;
		num = num / 2;
		bin = bin + (i*r);
		i = i * 10;
	}
	res = invertponwards(bin, p, b);

	return 0;
}
long int invertponwards(long int n, int p, int b)
{
	int i = 0;
	for (i = 0; i < c; i++)
	{
		if(i>=p-1)
	}
}