#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class strings
{
	char* string_pointer;
	int length;
public:
	//constructors
	strings()
	{
		string_pointer = NULL;
		length = 0;
	}
	strings(const char* string1)
	{
		length = strlen(string1);
		string_pointer = (char*)malloc(sizeof(char)*(length + 1));
		strcpy(string_pointer, string1);
	}
	strings(const strings &string1)
	{
		length = string1.length;
		string_pointer = (char*)malloc(sizeof(char)*(length + 1));
		strcpy(string_pointer, string1.string_pointer);
	}
	//destructor
	~strings()
	{
		if (string_pointer != NULL)
			free(string_pointer);
	}
	//overloading []
	char& operator[](int index)
	{
		if (index > length)
			cout << "out of bound";
		else
			return string_pointer[index];
	}
	//overloading -> operator
	strings* operator->()
	{
		return this;
	}
	//overloading = operator
	
	strings operator=(strings temp)
	{
		length = temp.length;
		if (string_pointer != NULL)
			free(string_pointer);
		string_pointer = (char*)malloc(sizeof(char)*(length + 1));
		strcpy(string_pointer, temp.string_pointer);
		return(*this);
	}
	//overloading + operator
	strings operator+(strings string1)
	{
		strings temp;
		temp.length = length + string1.length;
		temp.string_pointer = (char*)realloc(string_pointer, (temp.length + 1));
		int i = 0, j = 0;
		while (*(string_pointer + i) != '\0')
		{
			*(temp.string_pointer + i) = *(string_pointer + i);
			i++;
		}
		while (*(string_pointer + j) != '\0')
		{
			*(temp.string_pointer + i) = *(string_pointer + j);
			j++;
			i++;
		}
		*(temp.string_pointer + i) = '\0';
		return temp;

	}
	friend ostream& operator<<(ostream& cout, strings s);
	friend istream& operator >> (istream& cin, strings &s);
};
//overloading << operator
ostream& operator<<(ostream& cout, strings s)
{
	cout << s.string_pointer;

	return cout;
}
//overloading >> operator
istream& operator >> (istream& cin, strings &s)
{
	cin >> s.string_pointer;
	return cin;
}

int main()
{
	char input_string[50];
	cout << "enter string" << endl;
	cin >> input_string;
	strings s1(input_string), s2(s1), s3;
	//strings s1("hello"), s2(s1), s3;
	s3 = s1 + s2;
	cout << s3<<endl;
	int index;
	cout << "enter index" << endl;
	cin >> index;
	cout << "value is : "<<s1[index]<<endl;
	cout << "enter string"<<endl;
	cin >> s3;
	cout << "entered string is : ";
	cout << s3;
	return 0;
}