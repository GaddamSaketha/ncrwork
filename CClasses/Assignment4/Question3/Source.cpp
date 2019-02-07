#include<stdio.h>
#include<string.h>
int main()
{
	char  *s[6];
	s[0] = "{";
	s[1] = "ill teach you how to “;";
	s[2] = "a mountain “;";
    s[3] = "“Level a building “;";
	s[4] = "“Erase the past “;";
	s[5] = "“Make a million “; }.";
	int c = 0;
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		while (s[i][j]!= '\0')
		{
			if (s[i][j] == 'e')
				c++;
			j++;
		}
	}
	printf("count of e is %d", c);
	
	return 0;
}