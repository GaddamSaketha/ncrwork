#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *strrev1(char *string);
char* strcpy1(char* destination,  char* source); 
char *strcat1(char *dest,  char *src);
int strcmp1(char *s1,  char *s2);
int main()
{
	printf("enetr choice 1 for strrev, 2 for strcpy, 3 for strcat, 4 for strcmp");
	int n;
	scanf("%d", &n);
	char* c;
	char* s1= (char*)malloc(100 * sizeof(char));
	c= (char*)malloc(100 * sizeof(char));
	char*s;
	int l,r;
	switch (n)
	{
	case 1 :printf("enter string");
		scanf("%s", c);
		l = strlen(c);
		s = (char*)malloc((l + 1) * sizeof(char));
		s = strrev1(c);
		printf("%s", s);
		break;
	case 2 :printf("enter string");
		scanf("%s", c);
		l = strlen(c);
		s = (char*)malloc((l + 1) * sizeof(char));
		s = strcpy1(s,c);
		printf("%s", s);
		break;
	case 3 : printf("enter string1");
		scanf("%s", c);
		printf("enter string2");
		scanf("%s", s1);
		s=strcat1(s1, c);
		printf("%s", s1);
		break;
	case 4 : printf("enter string1");
		scanf("%s", c);
		printf("enter string2");
		scanf("%s", s1);
		r= strcmp1(s1, c);
		printf("%d", r); break;
	default: printf("enter valid no"); break;
	}
	return 0;

}
char *strrev1(char *str)
{
	char temp;
	char* p1 = str;
	char* p2 = str;
	for (p1 = str, p2 = (str + (strlen(str) - 1)); p1 < p2; p1++, p2++)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	return str;
}
char* strcpy1(char* d, char* s)
{
	while ((*d++=*s++) != '\0');
	return d;
}
char *strcat1(char *d,  char *s)
{
	d = (char*)realloc(d, strlen(d) + strlen(s) + 1);
	char* p1 = d;
	char* p2 = s;
	while (*p1 != '\0')
		p1++;
	while ((*p1++=*p2++) != '\0');
	return d;
}
int strcmp1(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	if ((*s1 - *s2) > 0)
		return 1;
	else
		return -1;
}