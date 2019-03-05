#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO startup_info;
	PROCESS_INFORMATION process_info;
	//SECURITY_ATTRIBUTES sec_attr;
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
		HIGH_PRIORITY_CLASS,
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
	//sec_attr.bInheritHandle = TRUE;
	return 0;
}