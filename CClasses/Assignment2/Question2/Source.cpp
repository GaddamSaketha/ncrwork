#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int  r, h=0,n,l,j=0;
	char bin[1000];
	printf("enter binary num");
	scanf("%s", &bin);
	l = strlen(bin);

	
	for (int i = 0; i < l; i++)
	{
		bin[i] = bin[i] - 48;
	}
	l = l / 4;
	char *hex = (char*)malloc((l+1)*sizeof(char));
	while (bin!= 0)
	{
		n = bin % 10000;
		int i = 0;
		h = 0;
		while (n != 0)
		{
			r = n % 10;
			h = h + r*pow(2, i);
			i++;
			n = n / 10;
		}
		if (h <= 9)
			hex[j] = h + 48;
		else
			hex[j] = h + 55;
		j++;
		bin = bin / 10000;
	}
	for (j = l-1; j >=0; j--)
		printf("%c", hex[j]);
    

	return 0;
}