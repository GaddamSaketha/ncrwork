#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
void rev(char s[])
{
	int i, j, c;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
void itob(int n, char s[])
{
	int i = 0;
	while (n > 0)
	{
		if (n & 1)
			s[i] = '1';
		else
			s[i] = '0';
		n = n / 2;
		i++;
	}
	s[i] = '\0';
	rev(s);
	return;
}
void itoh(int n, char s[])
{
	int i = 0;
	while (n > 0)
	{
		if ((n % 16) <= 9)
			s[i] = ((n % 16) + '0');
		else
		{
			s[i] = (((n % 16) - 10) + 'A');
		}
		n = n / 16;
		i++;
	}
	s[i] = '\0';
	rev(s);
	return;
}
int main()
{
	char r1[100], r2[100];
	int n1, n2;
	printf("enter the number\n");
	scanf("%d", &n1);
	itob(n1, r1);
	printf("%s\n", r1);
	printf("enter the number\n");
	scanf("%d", &n2);
	itoh(n2, r2);
	printf("%s\n", r2);
	
	return 0;
}