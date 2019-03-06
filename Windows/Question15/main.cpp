#include<stdio.h>
#include<windows.h>
#include<tchar.h>

DWORD WINAPI  Secondary_Thread(LPVOID lpParameter)
{
	_tprintf(_T("In secondary thread function\n"));
	printf("hello hii\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}
DWORD WINAPI  Primary_Thread(LPVOID lpParameter)
{
	HANDLE sec_Thread_handle;
	DWORD sec_Thread_Id;
	DWORD dwExitCode;
	sec_Thread_handle = CreateThread(NULL, 0, Secondary_Thread, NULL, CREATE_SUSPENDED, &sec_Thread_Id);
	if (NULL == sec_Thread_handle)
	{
		printf("error in creating secondary thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("secondary thread created successfully\n");
	}
	printf("waiting for secondary thread to terminate\n");
	WaitForSingleObject(sec_Thread_handle, INFINITE);
	//WaitForSingleObject(sec_Thread_handle, INFINITE);
	/*int Return_val=TerminateThread(sec_Thread_handle, 5);
	if (0 == Return_val)
	{
		printf("error in terminating secondary thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("secondary thread terminated successfully\n");
	}
	BOOL ret =GetExitCodeThread(sec_Thread_handle, &dwExitCode);
	printf("secondary thread exited with exit code %d", dwExitCode);*/
	return 0;
}
int main(int argc, TCHAR *argv[])
{
	HANDLE hThread_handle;
	DWORD dwThread_Id;
	hThread_handle = CreateThread(NULL, 0, Primary_Thread, NULL, 0, &dwThread_Id);
	if (NULL == hThread_handle)
	{
		printf("error in creating primary thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("primary thread created successfully\n");
	}

	printf("waiting for primary thread to terminate\n");
	WaitForSingleObject(hThread_handle, INFINITE);
	return 0;
}