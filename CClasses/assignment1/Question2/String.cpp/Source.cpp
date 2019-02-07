#include<stdio.h>
#include<ctype.h>
int main()
{
	int letters = 0, digits = 0, blanks = 0, tabs = 0, others = 0, i = 0;
	char c;
	char text[80];
	scanf("%[^\n]s", text);
	c = text[i];
	while (c != '\0')
	{
		if (isalpha(c))
			letters++;
		else if (isdigit(c))
			digits++;
		else if (c == 9 || c == 11)
			tabs++;
		else if (isblank(c))
			blanks++;
		else
			others++;
		i++;
		c = text[i];
	}
	printf("letters=%d, digits=%d, blanks=%d, tabs=%d,others=%d", letters, digits, blanks, tabs, others);
	scanf("%d", &i);

	return 0;
}