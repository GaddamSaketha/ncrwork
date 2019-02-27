#include<stdio.h>
#include<windows.h>
int main()
{
	LPWSTR * szArglist;
	int nArgs;
	szArglist = CommandLineToArgvW(GetCommandLineW(),&nArgs);
	if (NULL==szArglist)
	{
		printf("error is: ",GetLastError());
		return -1;
	}
	printf("%d", nArgs);
	for (int i = 0; i < nArgs; i++)
		printf("%ws\n", szArglist[i]);
	return 0;
	free(szArglist);
}