#include<stdio.h>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI  Function_Thread(LPVOID lpParameter)
{
	for(int counter=0;counter<=1000;counter++)
	printf("%d\t",counter);
	return 0;
}
int main(int argc, TCHAR *argv[])
{
	HANDLE hThread_handle;
	DWORD dwThread_Id;
	hThread_handle = CreateThread(NULL, 0, Function_Thread, NULL, CREATE_SUSPENDED, &dwThread_Id);
	if (NULL == hThread_handle)
	{
		printf("error in creating thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread created successfully\n");
	}
	printf("thread susupended\n");
	printf("resuming the thread\n");
	DWORD status = ResumeThread(hThread_handle);
	getchar();
	return 0;
}