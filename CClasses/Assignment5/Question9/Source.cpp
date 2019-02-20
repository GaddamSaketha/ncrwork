#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i;
	FILE *fp1, *fp;
	fp1 = fopen("f.txt", "w");
	char a[50], c;
	scanf("%[^\n]s", a);

	for (i = 0; i < strlen(a); i++)
	{
		c = a[i];
		
		 if (c >= 97 && c <= 122)
		{
			c -= 32;
			fputc(c, fp1);
		}
		 else if (c >= 65 && c <= 90)
		 {
			 c += 32;
			 fputc(c, fp1);
		 }
		else
			fputc(c, fp1);

	}
	printf("Current Postion of file pointer is: %d\n", ftell(fp1));
	fseek(fp1, -1, SEEK_CUR);
	printf("Current Postion of file pointer is:%d\n", ftell(fp1));

	return 0;
}