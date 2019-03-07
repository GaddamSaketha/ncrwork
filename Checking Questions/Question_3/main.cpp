#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *strrev1(char *string);
char* strcpy1(char* destination, char* source);
char *strcat1(char *dest, char *src);
int strcmp1(char *s1, char *s2);
int main()
{
	printf("enetr choice 1 for strrev, 2 for strcpy, 3 for strcat, 4 for strcmp");
	int choice;
	scanf("%d", &choice);
	char* input_string1 = (char*)malloc(100 * sizeof(char));
	char* input_string2 = (char*)malloc(100 * sizeof(char));
	char*output_string;
	int length, return_value;
	switch (choice)
	{
	case 1:printf("enter string");
		scanf("%s", input_string1);
		strrev1(input_string1);
		printf("%s", input_string1);
		break;
	case 2:printf("enter string");
		scanf("%s", input_string1);
		length = strlen(input_string1);
		output_string = (char*)malloc((length + 1) * sizeof(char));
		output_string = strcpy1(output_string, input_string1);
		printf("%s", output_string);
		break;
	case 3: printf("enter string1");
		scanf("%s", input_string1);
		printf("enter string2");
		scanf("%s", input_string2);
		output_string = strcat1(input_string1, input_string2);
		printf("%s", input_string2);
		break;
	case 4: printf("enter string1");
		scanf("%s", input_string1);
		printf("enter string2");
		scanf("%s", input_string2);
		return_value = strcmp1(input_string1, input_string2);
		printf("%d", return_value); break;
	default: printf("enter valid no"); break;
	}
	return 0;

}
char *strrev1(char *str)
{
	char temp;
	char* pointer1 = str;
	char* pointer2 = str;
	for (pointer1 = str, pointer2 = (str + (strlen(str) - 1)); pointer1 < pointer2; pointer1++, pointer2--)
	{
		temp = *pointer1;
		*pointer1 = *pointer2;
		*pointer2 = temp;
	}
	return str;
}
char* strcpy1(char* destination, char* source)
{
	int i = 0;
	while ((destination[i] = source[i]) != '\0')
		i++;
	return destination;
}
char *strcat1(char *destination, char *source)
{
	destination = (char*)realloc(destination, strlen(destination) + strlen(source) + 1);
	char* pointer1 = destination;
	char* pointer2 = source;
	while (*pointer1 != '\0')
		pointer1++;
	while ((*pointer1++ = *pointer2++) != '\0');
	return destination;
}
int strcmp1(char *string1, char *string2)
{
	while (*string1 == *string2)
	{
		if (*string1 == '\0')
			return 0;
		string1++;
		string2++;
	}
	if ((*string1 - *string2) > 0)
		return 1;
	else
		return -1;
}