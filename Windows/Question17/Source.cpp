#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int counter = 0;
DWORD WINAPI  Secondary_Thread(LPVOID lpParameter)
{
	counter++;
	return 0;
}
DWORD WINAPI  Primary_Thread(LPVOID lpParameter)
{
	counter++;
	return 0;
}
int main(int argc, TCHAR *argv[])
{
	HANDLE hThread_handle, sec_Thread_handle;
	DWORD dwThread_Id, sec_Thread_Id;
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
	sec_Thread_handle = CreateThread(NULL, 0, Secondary_Thread, NULL, 0, &sec_Thread_Id);
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
	if (counter != 2)
		printf("counter value is inconsistent\n");
	else
		printf("counter value: %d\n",counter);
	return 0;
}