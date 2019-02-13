#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
extern void count(FILE*);
extern void comment(FILE*);
extern void word(FILE*);
extern void tabs(FILE*);
int main()
{
	int i;
	char f[20]="F.txt";
	printf("enetr file name");
	//scanf("%s",f);
	//f = "f2.txt";
	FILE* fp=fopen(f, "r");

	if (fp == NULL)
	{
		printf("\n error in opening file");
		return -1;
	}


	printf("Enter required no to perform following tasks \n 1)count no of alphabets,digits,spaces,special chars \n 2)to remove comments \n 3)to find matching word and rotate it \n 4)replace tabs with \\t");
	int n;
	scanf("%d", &n);
	switch (n)
	{
	case 1: count(fp);
		break;
	case 2 : comment(fp);
		break;
	case 3: word(fp);
		break;
	case 4 :  tabs(fp);
		break;
	default: printf("enter valid no");
	}
	fclose(fp);
	return 0;
}
