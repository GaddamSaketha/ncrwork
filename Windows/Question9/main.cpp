#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO startup_info;
	PROCESS_INFORMATION process_info;
	BOOL Return_value;
	ZeroMemory(&startup_info, sizeof(startup_info));
	startup_info.cb = sizeof(startup_info);
	ZeroMemory(&process_info, sizeof(process_info));
	Return_value = CreateProcess(
		NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&startup_info,
		&process_info);
	if (0 == Return_value)
	{
		_tprintf(_T("cant create process: Error(%d)\n"), GetLastError());
		return -1;
	}
	printf("process created successfully\n");
	printf("current process id - %d", GetCurrentProcessId());
	printf("current thread id - %d", GetCurrentThreadId());
	printf("process id (%d)\n\n", GetProcessId(process_info.hProcess));
	printf("thread id - %d", GetThreadId(process_info.hThread));
	printf("process id  of thread - %d", GetProcessIdOfThread(process_info.hThread));
	CloseHandle(process_info.hProcess);
	CloseHandle(process_info.hThread);
	return 0;
}