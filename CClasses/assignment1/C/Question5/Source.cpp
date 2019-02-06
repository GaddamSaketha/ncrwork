#include<stdio.h>
int main()
{
	long int n,n1, m=0,r;
	int i,f=0;
	scanf("%ld",&n);
	n1 = n;
	while (n != 0)
	{
		r = n % 10;
		m = m * 10 + r;
		n = n / 10;
	}
	if (n1 == m)
		printf("palindrome");
	else
		printf("not a palindrome");
	return 0;
}