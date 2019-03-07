#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int expand(char*, char*);
int is_alphabet(int alpha);
int is_same_case(int alpha1, int alpha2);
int main()
{
	char input_string[100], output_string[100];
	printf("enter string\n");
	scanf("%s", input_string);
	int return_value = expand(input_string, output_string);
	if (return_value == 0)
		printf("%s", output_string);
	else
	{
		printf("\n invalid input");
	}
	return 0;
}
int expand(char* input_string, char* output_string)
{
	int i, j, char_left, char_middle, char_right;
	i = j = 0;
	while ((char_middle = input_string[i]) != '\0')
	{
		char_right = input_string[i + 1];
		if (i != 0)
			char_left = input_string[i - 1];
		if (char_middle != '-' && !is_alphabet(char_middle) && !isdigit(char_middle))
		{
			return -1;
		}
		else if (char_middle == '-' && !is_alphabet(char_right) && !isdigit(char_right))
		{
			return -1;
		}
		else if (char_middle == '-' && char_right<char_left)
		{
			return -1;
		}
		else if (char_middle == '-' && char_right >= char_left)
		{
			if ((is_alphabet(char_left) && is_alphabet(char_right)) || (isdigit(char_left) && isdigit(char_right)))
			{
				if (is_alphabet(char_left) && is_alphabet(char_right))
				{
					int ret_val = is_same_case(char_left, char_right);
					if (ret_val == 0)
					{
						printf("wrong input\n");
						return -1;
					}
				}
				i++;
				while (char_left < char_right)
					output_string[j++] = ++char_left;
			}
			else
			{
				return -1;
			}
		}
		else
			output_string[j++] = char_middle;
		i++;
	}
	output_string[j] = '\0';
	return 0;
}
int is_alphabet(int alpha)
{
	if ((alpha >= 65 && alpha <= 90) || (alpha >= 97 && alpha <= 122))
		return 1;
	else
		return 0;
}
int is_same_case(int alpha1, int alpha2)
{
	if ((alpha1 >= 65 && alpha1 <= 90) && (alpha2 >= 65 && alpha2 <= 90))
		return 1;
	else if ((alpha1 >= 97 && alpha1 <= 122) && (alpha2 >= 97 && alpha2 <= 122))
		return 1;
	else
		return 0;
}