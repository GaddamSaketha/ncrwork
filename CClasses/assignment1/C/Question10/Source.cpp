#include<stdio.h>
int main()
{
	long int n, n1, m = 0, r;
	scanf("%ld", &n);
	n1 = n;
	while (n != 0)
	{
		r = n % 10;
		m = m + r;
		n = n / 10;
	}
	printf("sum is %d", m);
	return 0;
	
}