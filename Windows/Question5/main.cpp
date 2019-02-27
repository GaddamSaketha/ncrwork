#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#define BUFF_SIZE 100
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hfile;
	TCHAR buffer[]=TEXT("hii hello");
	DWORD no_of_bytes_written;
	DWORD no_of_bytes_to_write = sizeof(buffer);
	hfile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hfile)
	{
		_tprintf(_T("file doesnot exist: Error(%d)\n"), GetLastError());
		return FALSE;
	}
	_tprintf(_T("File(%s) created successful\n "), argv[1]);
	bool ret= WriteFile(hfile,buffer, no_of_bytes_to_write,&no_of_bytes_written,NULL);
	if (ret == 0)
	{
		_tprintf(_T("cant write file: Error(%d)\n"), GetLastError());
		return FALSE;
	}
	else
	{
		if (no_of_bytes_written != no_of_bytes_to_write)
		{
			_tprintf(_T("data not written properly\n"));
			return FALSE;
		}
		else
		{
			_tprintf(_T("File(%s) written successfully\n "), argv[1]);
		}
	}
	CloseHandle(hfile);
	return 0;
}