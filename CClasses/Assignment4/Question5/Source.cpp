
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void ltou();
void utol();
int main()
{
	printf("enter 1 to convert lower to upper and 2 to convert upper to lower");
	int n;
	scanf("%d", &n);
	if (n == 1)
		ltou();
	else if (n == 2)
		utol();
	else
		printf("enter valid no\n");
	return 0;
}
void ltou()
{
	char c[50];
	printf("enter string");
	scanf("%s", c);
	int i = 0;
	while (c[i] != '\0')
	{
		if ((c[i] - 97 >= 0) && (c[i] - 97 <= 26))
		{
			c[i] = c[i] - 32;
		}
		i++;
	}
	printf("%s", c);
}
void utol()
{
	char c[50];
	printf("enter string");
	scanf("%s", c);
	int i = 0;
	while (c[i] != '\0')
	{
		if ((c[i] - 65 >= 0) && (c[i] - 65 <= 26))
		{
			c[i] = c[i] +32;
		}
		i++;
	}
	printf("%s", c);
}