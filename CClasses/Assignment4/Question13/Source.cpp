#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void expand(char*, char*);
int main()
{
	
	char c[100],s[100];
	printf("enter string\n");
	scanf("%s", c);
	
	expand(c, s);
	return 0;
}
void expand(char* s1, char* s2)
{
	int i, j, c;

	i = j = 0;

	while ((c = s1[i++]) != '\0')
		if (s1[i] == '-' && s1[i + 1] >= c)
		{
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;

	s2[j] = '\0';
	printf("%s", s2);

}