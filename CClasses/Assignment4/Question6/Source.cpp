#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rev(char*);
int main()
{
	char c[100];
	printf("enter string\n");
	scanf("%s", c);
	//int l = strlen(c);
	//char*r = (char*)malloc((l + 1) * sizeof(char));

	rev(c);
	printf("%s", c);
	return 0;
}
void rev(char* c)
{
	static int i = 0,j=0;
	char ch;
	if (c[i] != '\0')
	{
		ch = c[i];
		i++;
		rev(c);
		
	}
	else {
		return;
	}
	c[j] = ch;
	j++;
}