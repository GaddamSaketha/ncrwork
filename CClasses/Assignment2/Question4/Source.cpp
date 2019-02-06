#include<stdio.h>
int main()
{
	int n, m, i, f = 0, j;
	printf("enter 1st num");
	scanf("%d", &n);
	printf("enter 2nd num");
	scanf("%d", &m);
	for (i = n + 1; i < m; i++)
	{
		for (j = 2; j <= i / 2; j++)
		{
			if (i%j == 0)
				f = 1;
		}
		if (f == 0)
			printf("\n %d", i);
		f = 0;
	}
	return 0;
}