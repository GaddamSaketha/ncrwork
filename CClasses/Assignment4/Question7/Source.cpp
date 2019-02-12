#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char c[100][80], temp[80];
	int i, j, n;

	printf("Enter the value of n \n");
	scanf("%d", &n);
	printf("Enter %d names n \n", n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", c[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(c[i], c[j]) > 0)
			{
				strcpy(temp, c[i]);
				strcpy(c[i], c[j]);
				strcpy(c[j], temp);
			}
		}
	}

	printf("Sorted strings are:\n");
	
	for (i = 0; i < n; i++)
	{
		printf("%s\n",  c[i]);
	}

		return 0;
}