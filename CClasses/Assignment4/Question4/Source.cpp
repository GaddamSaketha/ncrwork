#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int replace(char*);
int main()
{
	char* c;
	c = (char*)malloc(50 * sizeof(char));
	printf("enter string");
	scanf("%[^\n]s", c);
	int n = replace(c);
	printf("the no of spaces are %d", n);
	return 0;
}
int replace(char* c)
{
	int i = 0, j,count=0;
	while (c[i] != '\0')
	{
		if (c[i] == ' ')
		{
			c[i] = '-';
			count++;
		}
	}
	return count;
}