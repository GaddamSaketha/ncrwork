#include<stdio.h>
#include<math.h>
int main()
{
	int num, r,num1=0;

	long int bin = 0, i = 1,bin1=0;

	printf("enter digit");
	scanf("%d", &num);
	printf("enter bin");
	scanf("%ld", &bin1);
	while (num != 0)

		{
			r = num % 2;

			num = num / 2;

			bin = bin + (i*r);

			i = i * 10;

		}

		printf("\n bin is %ld", bin);
		i = 0;
		while (bin1 != 0)
		{
			r = bin1 % 10;
			num1 = num1 + (pow(2, i)*r);
			i++;
			bin1 = bin1 / 10;
		}


		printf("\n decimal is %ld", num1);

	
	return 0;
}