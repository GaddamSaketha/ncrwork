#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void bintohexa();
void hextobin();
int main()
{

	printf("enter 1 to convert bin to hex and 2 for hex to bin");
	int p;
	scanf("%d", &p);
	if (p == 1)
		bintohexa();
	else
		hextobin();
	
	

	return 0;
}
void bintohexa()
{
	int  r, h = 0, n, l, j = 0, i = 0, temp;
	char bin[1000];
	printf("enter binary num");
	scanf("%s", &bin);

	l = strlen(bin);


	while (bin[i] != '\0')
	{
		bin[i] = bin[i] - 48;
		i++;
	}
	j = i - 1;
	l = l / 4 + 1;
	char *hex = (char*)malloc((l + 1) * sizeof(char));
	while (j != 0)
	{
		temp = bin[j - 3] * 8 + bin[j - 2] * 4 + bin[j - 1] * 2 + bin[j];
		if (temp > 9)
			hex[h++] = temp + 55;
		else
			hex[h++] = temp + 48;
		j = j - 4;
		if (j < 3)
			break;
	}
	if (j < 3 && j >= 0)
	{
		if (j == 2)
			temp = bin[j - 2] * 4 + bin[j - 1] * 2 + bin[j] + 48;
		else if (j == 1)
			temp = bin[j - 1] * 2 + bin[j] + 48;
		else
			temp = bin[j] + 48;

	}
	for (j = l - 2; j >= 0; j--)
		printf("%c", hex[j]);

    
}
void hextobin()
{
	int  r, h = 0, n, l, j = 0, i = 0, temp=0;
	char hex[1000];
	printf("enter hexa num");
	scanf("%s", hex);

	l = strlen(hex);
	l = l *4;
	int *bin = (int*)malloc((l) * sizeof(int));
	for (i = 0; i < l; i++)
		bin[i] = 0;
	i = 0;
	while (hex[i] != '\0')
	{
		
			h = ((i+1)*4)-1;
			

		
		if ((hex[i] - 48 >= 0) && (hex[i] - 48 <= 9))
		{
			int p = 0, q = 0;
			n= hex[i] - 48;
			
			while (n != 0)
			{
				r = n % 2;
				
				bin[h--] = r;
				
				n = n / 2;
			}
			
			
	  }
		else if((hex[i]-65>=0)&&(hex[i]-65<=26))
		{
			int p = 0, q = 0;
			n = hex[i] - 55;
			
			
			while (n != 0)
			{
				r = n % 2;
				
				bin[h--] = r;
				
				n = n / 2;
			}
			
		}
		else 
		{
			int p = 0, q = 0;
			n = hex[i] - 87;
			
			while (n != 0)
			{
				r = n % 2;
				
				bin[h--] = r;
				
				n = n / 2;
			}
			
		}
		i++;
	}
	for (i = 0; i < l; i++)
		printf("%d", bin[i]);
}