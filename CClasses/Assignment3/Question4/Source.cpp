#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	printf("Enter a hexadecimal number\n");
	unsigned int h;
	scanf("%x", &h);
	while (1)
	{
		printf("1. Display the hexadecimal equivalent of the one's complement\n");
		printf("2. Carry out a masking operation and then display the hexadecimal equivalent of the result\n");
		printf("3. Carry out a bit shifting operation and then display the hexadecimal equivalent of the result\n");
		printf("4. Exit\n");
		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1: printf("hexadecimal equivalent of the one’s equivalent is 0x%x\n\n", ~h);
			break;
		case 2: prompt_func(number);
			break;
		case 3: 
			printf("enter 1 for left shift and 2 for right shift");
			int x;
			scanf("%d", &x);
			printf("enter no of bits to shift");
			int y;
			scanf("%d", &y);
			if(x==1)
				printf("value after shift is 0x%x\n", (h << y));
			else
				printf("value after shift is 0x%x\n", (h >> y));

			break;
		case 4:
			exit(0);
		}
	}

	return 0;
}