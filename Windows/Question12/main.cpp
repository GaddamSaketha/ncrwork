#include<stdio.h>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI  Function_Thread(LPVOID lpParameter)
{
	_tprintf(_T("In thread function\n"));
	printf("hello hii\n");
	return 0;
}
int main(int argc, TCHAR *argv[])
{
	HANDLE hThread_handle;
	DWORD dwThread_Id;
	hThread_handle = CreateThread(NULL, 0, Function_Thread, NULL, 0, &dwThread_Id);
	if (NULL == hThread_handle)
	{
		printf("error in creating thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread created successfully\n");
	}

	printf("waiting for thread to terminate\n");
	WaitForSingleObject(hThread_handle,INFINITE);
	return 0;
}