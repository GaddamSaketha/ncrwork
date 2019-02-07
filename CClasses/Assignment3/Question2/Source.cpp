#include<stdio.h>
#include<stdlib.h>
void fun(int a[], int n);
void fun(int a[], int n)
{
	int j = 0, i;
	for (i = 0; i < n; i++) {
		if (a[i] < 0) {
			if (i != j)
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
     			j++;
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
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
	fun(a, n);
	return 0;
}