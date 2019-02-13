#include<stdio.h>
#include<string.h>
void word(FILE* fp)
{
	char s[20];
	int i=0,j=0, f = 0;
	printf("enter word");
	scanf("%s", s);
	char c = fgetc(fp);
	FILE* fp1 = fp;
	char ch, ch1;;
	while (!feof(fp))
	{
		fp1 = fp;
		i = 0;
		if (c ==s[i])
		{
			
			i++;

			c = fgetc(fp);
			while (s[i] != '\0')
			{
				if (s[i] != c)
				{
					f = 1;
					break;
				}
				i++;
				c = fgetc(fp);
			}
			if (f == 0)
			{
				while (fp1 < fp)
				{
					ch = fgetc(fp1);
					ch1 = fgetc(fp);
					fputc(ch1, fp1);
					fputc(ch, fp1);

				}
				fseek(fp1, 1, SEEK_CUR);
				fseek(fp, -1, SEEK_CUR);
				
			}

		}
		fseek(fp, fp-fp1, SEEK_CUR);
		c = fgetc(fp);
	}
}