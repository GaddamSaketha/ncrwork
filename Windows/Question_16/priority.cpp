#include<stdio.h>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI  Function_Thread(LPVOID lpParameter)
{
	_tprintf(_T("In thread function\n"));
	printf("hello hii\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", i);
	}
	getchar();
	return 0;
}
int _tmain(int argc, TCHAR *argv[])
{
	getchar();
	HANDLE hProcess = GetCurrentProcess();

	BOOL ret= SetPriorityClass(hProcess, BELOW_NORMAL_PRIORITY_CLASS);
	if (0 == ret)
	{
		_tprintf(_T("cant set priority: Error(%d)\n"), GetLastError());
		return -1;
	}
	printf("priority changed\n");
	getchar();
	HANDLE hThread_handle;
	DWORD dwThread_Id;
	hThread_handle = CreateThread(NULL, 0, Function_Thread, NULL, THREAD_PRIORITY_LOWEST, &dwThread_Id);
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
	WaitForSingleObject(hThread_handle, INFINITE);
	getchar();
	CloseHandle(hThread_handle);
	return 0;
}
//check priorities in sysinternals->procexp
//for thread priority  sysinternals->procexp->right click on process ->properties->go to threads tab