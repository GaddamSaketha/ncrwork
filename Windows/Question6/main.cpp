#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si1, si2;//instances of STARTUPINFO structure
    PROCESS_INFORMATION pi1, pi2;//instances of PROCESS_INFORMATION structure
	BOOL Return_p1, Return_p2;//retrun values of process creation
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
    ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));
	if (argc != 3)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		return -1;
	}
	Return_p1= CreateProcess(
		NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si1,
		&pi1);
	if (0 == Return_p1)
	{
		_tprintf(_T("cant create process: Error(%d)\n"), GetLastError());
		return -1;
	}
	printf("process 1 created successfully\n");
    printf("current process id - %d", GetCurrentProcessId());
	printf("current thread id - %d", GetCurrentThreadId());
	printf("process id (%d)\n\n", GetProcessId(pi1.hProcess));
	CloseHandle(pi1.hProcess);
	CloseHandle(pi1.hThread);
	Return_p2 = CreateProcess(
		NULL,
		argv[2],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si2,
		&pi2);
	if (0 == Return_p2)
	{
		_tprintf(_T("cant create process: Error(%d)\n"), GetLastError());
		return -1;
	}
	printf("process 2 created successfully\n");
	printf("current process id - %d", GetCurrentProcessId());
	printf("current thread id - %d", GetCurrentThreadId());
	printf("process id (%d)\n\n", GetProcessId(pi1.hProcess));
	CloseHandle(pi1.hProcess);
	CloseHandle(pi1.hThread);
	return 0;
}