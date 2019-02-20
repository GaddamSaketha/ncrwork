#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
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
		case 2: printf("enter 1-AND 2-OR 3-XOR");
			int x;
			scanf("%d", &x);
			if (x == 1)
			{
				printf("%x\n", (h & 0xf0));
			}
			else if (x == 2)
			{
				printf("%x\n", (h | 0xf0));
			}
			else
			{
				printf("%x\n", (h ^ 0xf0));
			}
			break;
		case 3: 
			printf("enter 1 for left shift and 2 for right shift");
			int z;
			scanf("%d", &z);
			printf("enter no of bits to shift");
			int y;
			scanf("%d", &y);
			if(z==1)
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