#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
	int empno;
	char* name;
	int salary;
public:
	Employee()
	{
		empno = 0;
		name = NULL;
		salary = 0;
	}
	Employee(int no, char* s, int sal)
	{
		empno = no;
		int len = strlen(s);
		name = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(name, s);
		salary = sal;
	}
	Employee(const Employee &e)
	{
		empno = e.empno;
		int len = strlen(e.name);
		name = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(name, e.name);
		salary = e.salary;
	}
	~Employee()
	{
		if (name != NULL)
			free(name);
	}
	void set_data(int no, char* s, int sal)
	{
		empno = no;
		int len = strlen(s);
		name = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(name, s);
		salary = sal;
	}
	void get_data()
	{
		cout << "empno: " << empno << endl;
		cout << "name: " << name << endl;
		cout << "salary: " << salary << endl;
	}
	friend istream& operator >> (istream& cin, Employee &s);
};
istream& operator >> (istream& cin, Employee &s)
{
	char n[50];
	cin >> s.empno;
	cin >>n;
	int len = strlen(n);
	s.name = (char*)malloc(sizeof(char)*(len + 1));
	strcpy(s.name, n);
	cin >> s.salary;
	return cin;
}
int main()
{
	Employee e[5];
	for (int i=0;i<5;i++)
	{
		cout << "enter emp details" << endl;
		cin >> e[i];
	}
	cout << "entered emp details are" << endl;
	for (int i = 0; i<5; i++)
	{
		e[i].get_data();
	}
	return 0;
}