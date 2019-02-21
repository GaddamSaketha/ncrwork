#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * fp,*fp1;
	fp = fopen("f1.txt", "r");
	fp1= fopen("f2.txt", "w");
	while (!feof(fp))
	{
		char c = fgetc(fp);
		fputc(c,fp1);
		printf("%c",c);
	}
	fclose(fp1);
	fclose(fp);
	fp = fopen("f1.txt", "w");
	fp1 = fopen("f2.txt", "r");
	while (!feof(fp1))
	{
		char c = fgetc(fp1);
		printf("%c", ~c);
		fputc(~c, fp);
	}
	
	fclose(fp1);
	fclose(fp);

	return 0;
}