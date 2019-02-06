#include<stdio.h>
#include<math.h>
int main()
{
	int n, r, num = 0,n1;
	scanf("%d",&n);
	n1 = n;
	int l = log10(n)+1;
	while (n != 0)
	{
		r = n % 10;
		num = num + pow(r, l);
		n = n / 10;
	}
	if (n1 == num)
		printf("amstrong number");
	else
		printf("not an amstrong number");
	return 0;
}