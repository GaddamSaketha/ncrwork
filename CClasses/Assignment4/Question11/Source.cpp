#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
#include <malloc.h>
char* my_strtok(char* s, char delm)
{
	static int currIndex = 0;

	if (!s || !delm || s[currIndex] == '\0')
		return NULL;
	if(currIndex!=0)
		currIndex++;
	char *W = (char *)malloc(sizeof(char) * 100);
	int i = currIndex, k = 0;
	while (s[i] != '\0') 
	{
		if (s[i] != delm)
		{
			W[k] = s[i];
			i++;
			k++;
		}
		else
			break;
	}
	W[k] = '\0';
	currIndex = i;
	/*while (s[i] != '\0') {
		j = 0;
		while (delm[j] != '\0') {
			if (s[i] != delm[j])
				W[k] = s[i];
			else goto It;
			j++;
		}

		i++;
		k++;
	}
It:
	W[i] = 0;
	currIndex = i + 1;
	*/
	return W;
}

int main(void)
{
	char s[100];
	printf("enter string");
	scanf("%[^\n]s", s);
	char *str = my_strtok(s, '-');

	while (str!=NULL) {
		printf("%s", str);
		str = my_strtok(s, '-');
	}

	return 0;
}
