#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class strings
{
	char* sptr;
	int len;
public:
	strings()
	{
		sptr = NULL;
		len = 0;
	}
	strings(const char* s)
	{
		len = strlen(s);
		sptr = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, s);
	}
	strings(const strings &temp)
	{
		len = temp.len;
		sptr = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, temp.sptr);
	}
	~strings()
	{
		if (sptr != NULL)
			free(sptr);
	}
	char& operator[](int n)
	{
		return sptr[n];
	}
	strings* operator->()
	{
		return this;
	}
	strings operator=(strings temp)
	{
		len = temp.len;
		if (sptr != NULL)
			free(sptr);
		sptr = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, temp.sptr);
		return(*this);
	}
	strings operator+(strings s)
	{
		strings temp;
		temp.len = len + s.len;
		temp.sptr = (char*)realloc(sptr, (len + 1));
		int i = 0, j = 0;
		while (*(sptr + i) != '\0')
		{
			*(temp.sptr + i) = *(sptr + i);
			i++;
		}
		while (*(sptr + j) != '\0')
		{
			*(temp.sptr + i) = *(sptr + j);
			j++;
			i++;
		}
		*(temp.sptr + i) = '\0';
		return temp;

	}
	friend ostream& operator<<(ostream& cout, strings s);
	friend istream& operator >> (istream& cin, strings &s);
};
ostream& operator<<(ostream& cout, strings s)
{
	cout << s.sptr;

	return cout;
}
istream& operator >> (istream& cin, strings &s)
{
	cin >> s.sptr;
	return cin;
}

int main()
{
	strings s1("hello"), s2(s1), s3;
	s3 = s1 + s2;
	cout << s3<<endl;
	cout << s1[3]<<endl;
	cin >> s3;
	cout << s3;
	return 0;
}