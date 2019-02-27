#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int arr_len, arr1_len;
	char c = 'A';
	wchar_t c1 = L'A';
	CHAR C = 'B';
	WCHAR C1 = L'B';
	printf("enter length of char array\n");
	scanf("%d", &arr_len);
	PSTR ARR = (PSTR)malloc(sizeof(CHAR)*arr_len);
	printf("enter char array\n");
	scanf("%s", ARR);
	printf("enter wide char array length\n");
	scanf("%d", &arr1_len);
	PWSTR ARR1 = (PWSTR)malloc(sizeof(WCHAR)*arr1_len);
	printf("enter wide char array\n");
	scanf("%S", ARR1);
	printf("is ARR an unicode: %d\n", IsTextUnicode(ARR, strlen(ARR)+1, NULL));
	printf("is ARR1 an unicode: %d\n", IsTextUnicode(ARR1, wcslen(ARR1)+1, NULL));
	int res = MultiByteToWideChar(CP_UTF8,0,ARR, strlen(ARR),NULL,0);
	if (0==res)
	{
		printf("Error is: %d",GetLastError());
		return -1;
	}
	PWSTR RES_ARR = (PWSTR)malloc(sizeof(WCHAR)*res);
	MultiByteToWideChar(CP_UTF8, 0, ARR, strlen(ARR) , RES_ARR, res);
	printf("%s \n", RES_ARR);
	printf("%S ", RES_ARR);
	printf("\n");
	res = WideCharToMultiByte(CP_UTF8, 0, ARR1, wcslen(ARR1), NULL, 0,NULL,NULL);
	if (0==res )
	{
		printf("Error is: %d", GetLastError());
		return -1;
	}
	PSTR RES_ARR1 = (PSTR)malloc(sizeof(CHAR)*res);
	WideCharToMultiByte(CP_UTF8, 0, ARR1, wcslen(ARR1)+1, RES_ARR1, strlen(RES_ARR1), NULL, NULL);
	printf("%s \n", RES_ARR1);
	//TCHAR char1 = TEXT(C);
	//TCHAR char2 = TEXT(C1);
	//printf("size of char1: %d\n", sizeof(char1));
	//printf("size of char2: %d\n", sizeof(char2));
	/*free(ARR);
	free(ARR1);
	free(RES_ARR);
	free(RES_ARR1);*/
	return 0;
}