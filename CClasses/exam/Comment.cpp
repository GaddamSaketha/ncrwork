#include<stdio.h>
void comment(FILE* fp)
{
	FILE* fp1 = fopen("text2", "w");
	char c = fgetc(fp);
	while (!feof(fp))
	{
		if (c == '/')
		{
			c = fgetc(fp);
			if (c == '/')
			{
				c = fgetc(fp);
				while (c != '\n')
				{
					c = fgetc(fp);
				}
			}
			else if (c == '*')
			{
				c = fgetc(fp);
				while (c != '*')
				{
					c = fgetc(fp);
				}
				c = fgetc(fp);
				if (c == '/')
				{
					c = fgetc(fp);
				}

			}
			else
			{
				fputc(c, fp1);
			}

		}
		else
			fputc(c, fp1);
		c = fgetc(fp);
	}
	fp1 = fopen("text2", "r");
	while (!feof(fp1))
	{
		c = fgetc(fp1);
		fputc(c,fp);
	}
	fclose(fp);
	fclose(fp1);
}