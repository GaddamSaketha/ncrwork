#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	HANDLE g_hEvent;
	g_hEvent= CreateEvent(
		NULL,
		FALSE,
		FALSE,
		TEXT("MY EVENT")
	);
	if (INVALID_HANDLE_VALUE == g_hEvent)
	{
		_tprintf(_T("Error in creating handle. Error no :%d"), GetLastError());
		return -1;
	}

	//_tprintf(_T("%d\n"), g_hEvent);
//	CloseHandle(g_hEvent);
	return 0;
}