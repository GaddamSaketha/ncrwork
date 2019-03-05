#include<stdio.h>
#include<windows.h>
#include<tchar.h>
CRITICAL_SECTION c_s;
int counter = 0;
DWORD WINAPI  Secondary_Thread(LPVOID lpParameter)
{
	EnterCriticalSection(&c_s);
	for (int i = 0; i < 100; i++)
	{
		printf("in p2\n");
		counter++;
	}
	LeaveCriticalSection(&c_s);
	return 0;
}
DWORD WINAPI  Primary_Thread(LPVOID lpParameter)
{
	EnterCriticalSection(&c_s);
	for (int i = 0; i < 100; i++)
	{
		printf("in p1\n");
		counter++;
	}	
	LeaveCriticalSection(&c_s);
	return 0;
}
int main(int argc, TCHAR *argv[])
{
	HANDLE hThread_handle[2];
	DWORD dwThread_Id, sec_Thread_Id;
	InitializeCriticalSection(&c_s);
	hThread_handle[0] = CreateThread(NULL, 0, Primary_Thread, NULL, 0, &dwThread_Id);
	if (NULL == hThread_handle[0])
	{
		printf("error in creating primary thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("primary thread created successfully\n");
	}

	
	hThread_handle[1] = CreateThread(NULL, 0, Secondary_Thread, NULL, 0, &sec_Thread_Id);
	if (NULL == hThread_handle[1])
	{
		printf("error in creating secondary thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("secondary thread created successfully\n");
	}
	//WaitForMultipleObjects(2, hThread_handle, TRUE, INFINITE);
	WaitForSingleObject(hThread_handle[0], INFINITE);
	WaitForSingleObject(hThread_handle[1], INFINITE);
    printf("counter value: %d\n", counter);
	DeleteCriticalSection(&c_s);
	return 0;
}