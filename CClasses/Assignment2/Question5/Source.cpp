#include<stdio.h>
#include<math.h>
int main()
{
	int n, m = 0, r;
	scanf("%d", &n);
	int len = log10(n) + 1;
	while (n != 0)
	{
		r = n % 10;
		m = (r*pow(10, len-1)) + m;
		len--;
		n = n / 10;
	}
	printf("reverce of input is %d", m);

	return 0;
}