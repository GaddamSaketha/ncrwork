#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp = NULL;
	char c;
	fp = fopen("file1.txt", "r");
	while (!feof(fp))
	{
		c = fgetc(fp);
		printf("%c", c);
	} 
	fclose(fp);
	return 0;
}