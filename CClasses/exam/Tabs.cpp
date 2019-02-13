#include<stdio.h>
void tabs(FILE* fp)
{
	FILE* fp1 = fopen("text2", "w");
	char c;
	c = fgetc(fp);
	while (!feof(fp))
	{

		if ((c-9)==0)
		{
			fputc('\\', fp1);
			fputc('t', fp1);
			
		}
		else
			fputc(c, fp1);
		c = fgetc(fp);

	}
	fp1 = fopen("text2", "r");
	while (!feof(fp1))
	{
		c = fgetc(fp1);
		fputc(c, fp);
	}
	fclose(fp);
	fclose(fp1);
}