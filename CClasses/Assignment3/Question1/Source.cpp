
#include<stdio.h> 
#include<stdlib.h>

void Sum(int a[], int n, int sum)
{

	int csum = a[0], p = 0, i;


	for (i = 1; i <= n; i++)
	{

		while (csum > sum && p < i - 1)
		{
			csum = csum - a[p];
			p++;
		}


		if (csum == sum)
		{
			printf(" %d and %d", p, i - 1);
			return;
		}
	


	if (i < n)
		csum = csum + a[i];
   }


printf("0");

}


int main()
{
	int n;
	printf("no of digits");
	scanf("%d", &n);
	int * a = (int*)malloc(n * sizeof(int));
	printf("enter digits");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("enter sum");
	int sum;
	scanf("%d", &sum);
	Sum(a, n, sum);
	return 0;
}