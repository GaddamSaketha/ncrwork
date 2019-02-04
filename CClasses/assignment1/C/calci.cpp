#include<stdio.h>
extern int mul(int a, int b);
extern int add(int a, int b);
extern int sub(int a, int b);
extern int div(int a, int b);
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
	case '+': res = add(a, b);break;
	case '-': res = sub(a, b); break;
	case '*': res = mul(a, b); break;
	case '/': res = div(a, b); break;
	default: printf("wrong operator");

	}
	printf("output is %d", res);
	return 0;
}