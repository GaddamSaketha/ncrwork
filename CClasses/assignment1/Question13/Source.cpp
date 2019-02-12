#include<stdio.h>
int invertponwards(int number, int position, int bits)
{
	int r = 0;
	int bin[64] = { 0 }, i = 0;
	while (number > 0)
	{
		bin[i] = number % 2;
		number >>= 1;
		i++;
	}
	i--;
	int k = i - position;
	for (int temp = 0; temp < bits; temp++, k--)
	{
		bin[k] = ((bin[k] == 1) ? 0 : 1);
	}
	int j = 0;
	while (i >= 0)
	{
		r = r * 2 + bin[i];
		j++; i--;
	}
	return r;
}
int main()
{
	int n;
	printf("Enter any number\n");
	scanf("%d", &n);
	int p, b;
	printf("Enter the position to invert\n");
	scanf("%d", &p);
	printf("Enter the number of bits to invert\n");
	scanf("%d", &b);
	int res = invertponwards(n, p - 1, b);
	printf("%d\n", res);
	
	
	return 0;
}