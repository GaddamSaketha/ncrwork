#include<stdio.h>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI  Function_Threadb(LPVOID lpParameter)
{
	_tprintf(_T("In thread function\n"));
	printf("hello hii\n");
	for (int i = 0; i < 50; i++)
	{
		printf("%d\t", i);
		if (i == 10)
			Sleep(2000);
	}
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread_handle;
	DWORD dwThread_Id, dw;
	int choice;
	printf("enter time interval 1. infinite 2.1000");

	scanf("%d", &choice);
	hThread_handle = CreateThread(NULL, 0, Function_Threadb, NULL, 0, &dwThread_Id);
	if (NULL == hThread_handle)
	{
		printf("error in creating thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread created successfully\n");
	}

	
	if (choice == 1)
	{
		dw = WaitForSingleObject(hThread_handle, INFINITE);
	}
	else if (choice == 2)
	{
		dw = WaitForSingleObject(hThread_handle, 1000);
	}
	else
	{
		printf("entered wrong choice");
		return -1;
	}
	switch (dw)
	{
	case WAIT_OBJECT_0: printf("Thread executed successfully\n");
		break;
	case WAIT_TIMEOUT: printf("Timeout\n");
		break;
	case WAIT_FAILED: printf("wait failed\n");
		break;
	default: printf("returned value %ld", dw);
		break;
	}
	return 0;
}