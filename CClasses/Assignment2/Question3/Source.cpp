#include<stdio.h>
int fact(int);
int main()
{
	int num;
	printf("enter num");
	scanf("%d", &num);
	int res = fact(num);
	printf("fact is %d", res);
	return 0;
}
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n*fact(n - 1);
}