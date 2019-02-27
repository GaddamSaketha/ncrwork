#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#define BUFF_SIZE 100
int _tmain(int argc,LPTSTR argv[])
{
	HANDLE hfile;
	TCHAR buffer[BUFF_SIZE];
	DWORD no_of_bytes_read;
	hfile = CreateFile(argv[1], GENERIC_READ,0,NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,NULL);
	if (INVALID_HANDLE_VALUE == hfile)
	{
		_tprintf(_T("file doesnot exist: Error(%d)\n"),GetLastError());
		return FALSE;
	}
	_tprintf(_T("File(%s) opened successful\n "),argv[1]);
	while (1)
	{
		ZeroMemory(buffer, BUFF_SIZE);
		bool ret = ReadFile(hfile, buffer,BUFF_SIZE,&no_of_bytes_read,NULL);
		if (ret == 0)
		{
			_tprintf(_T("cant read file: Error(%d)\n"), GetLastError());
			return FALSE;
		}
		if (ret && no_of_bytes_read == 0)
		{
			_tprintf(_T("Reached end of the file \n"));
			break;
		}
		_tprintf(_T("%S\n"),buffer);
	}
	CloseHandle(hfile);
	return 0;
}