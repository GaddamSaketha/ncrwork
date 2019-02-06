#include<stdio.h>
long int mul(int a, int b);
float div(int a, int b);
int res = -1;
long int res1 = -1;
float res2 = -1;
int main()
{
	int a, b, res;
	char c;
	printf("enter operands\n");
	scanf("%d%d", &a, &b);
	printf("enter operation\n");
	scanf(" %c", &c);
	switch (c)
	{
	case '+': res = add(a, b); printf("output is %d", res); break;
	case '-': res = sub(a, b); printf("output is %d", res); break;
	case '*': res1 = mul(a, b); printf("output is %d", res1); break;
	case '/': res2 = div(a, b); printf("output is %d", res2); break;
	default: printf("wrong operator");

	}
	
	return 0;
}