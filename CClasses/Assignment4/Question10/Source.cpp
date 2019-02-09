#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void deletee(char*, char);
int main()
{
	char s1[1000];
	char s2;
	printf("enter string\n");
	scanf("%s", s1);
	printf("enter character\n");
	scanf(" %c",&s2);
	deletee(s1, s2);
	return 0;
}
void deletee(char* s1, char s2)
{
	
	int i = 0, j = 0;
	
	while (s1[i] != '\0')
	{
		if (s1[i]!= s2)
		{
			s1[j] = s1[i];
			j++;
		}
		i++;
	}
	s1[j] = '\0';
	printf("the output string is %s", s1);
}