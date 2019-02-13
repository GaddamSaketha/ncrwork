#include<stdio.h>
void count(FILE* fp)
{
	int alp = 0, dig = 0, sp = 0, sc = 0, i = 0;
	char c;
	//int read=fopen_s(&fp, "f2.txt", "r");
	//printf("\n %d", read);
	c = fgetc(fp);
	//perror("error");
	//fscanf(fp,"%c",&c);
	//printf("\n %c", c);
	while (!feof(fp))
	{
		//printf("\n %c", c);
		if (((c -'a'>=0) && (c-'a'<=26)) || ((c-'A'>=0) && (c-'A'<=26)))
		{
			alp++;
		}
		else if ((c - '0' >= 0) && (c - '0' <= 9))
		{
			dig++;
		}
		else if (c == ' ')
		{
			sp++;
		}
		else
			sc++;
		c = fgetc(fp);
	}
	printf(" \n count of \n alphabets : %d \n digits: %d \n spaces : %d \n special chars: %d \n", alp, dig, sp, sc);
	
}