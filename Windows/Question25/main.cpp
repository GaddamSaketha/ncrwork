#include<stdio.h>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI  Function_Thread_one(LPVOID lpParameter)
{
	_tprintf(_T("In thread one function\n"));
	Sleep(4000);
	//Sleep(2000);
	return 0;
}
DWORD WINAPI  Function_Thread_two(LPVOID lpParameter)
{
	_tprintf(_T("In thread two function\n"));
	Sleep(3000);
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread_handle[2];
	DWORD dwThread_Id, dw;
	int choice;
	printf("1)bWaitAll = TRUE and timeout interval INFINITE\n");
	printf("2)bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(4000) and thread2 Sleep(3000)\n");
	printf("3)bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(2000) and thread2 Sleep(3000)\n");
	printf("4)bWaitAll = FALSE and timeout interval 2000, thread1 Sleep(4000) and thread2 Sleep(3000)\n");
	scanf("%d", &choice);
	hThread_handle[0] = CreateThread(NULL, 0, Function_Thread_one, NULL, 0, &dwThread_Id);
	if (NULL == hThread_handle)
	{
		printf("error in creating thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread created successfully\n");
	}


	hThread_handle[1] = CreateThread(NULL, 0, Function_Thread_two, NULL, 0, &dwThread_Id);
	if (NULL == hThread_handle)
	{
		printf("error in creating thread: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread created successfully\n");
	}


	switch (choice)
	{
	case 1: dw=WaitForMultipleObjects(2, hThread_handle, TRUE, INFINITE);
		break;
	case 2: dw = WaitForMultipleObjects(2, hThread_handle, FALSE, INFINITE);
		break;
	case 3 : dw = WaitForMultipleObjects(2, hThread_handle, FALSE, INFINITE);
		break;
	case 4 : dw = WaitForMultipleObjects(2, hThread_handle, FALSE, 2000);
		break;
	default : printf("entered invalid choice\n");
		break;
	}
	switch (dw)
	{
	case WAIT_OBJECT_0+0: printf("Thread 1 terminated\n");
		break;
	case WAIT_OBJECT_0 + 1: printf("Thread 2 terminated\n");
		break;
	case WAIT_TIMEOUT: printf("Timeout");
		break;
	case WAIT_FAILED: printf("wait failed\n");
		break;
	default: printf("returned value %ld", dw);
		break;
	}
	return 0;
}