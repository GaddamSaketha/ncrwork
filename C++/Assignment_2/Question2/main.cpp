#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class student
{
	char* studentName;
	int m1;
	int m2;
	int m3;
	int total;
	char grade;
public:
	student()
	{
		studentName = NULL;
		m1 = 0;
		m2 = 0;
		m3 = 0;
		total = 0;
		grade = 'F';
	}
	student(const char* s, int marks1, int marks2, int mark3,int t)
	{
		int len = strlen(s);
		studentName = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(studentName, s);
		m1 = marks1;
		m2 = marks2;
		m3 = mark3;
		total = 0;
		grade = 'F';
	}
	
	friend void generate_results(student* s, int n);
	friend ostream& operator<<(ostream& cout, student c);
	friend istream& operator >> (istream& cin, student &c);
};
void generate_results(student* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		int avg = (s[i].m1 + s[i].m2 + s[i].m3) / 3;
		cout << avg << endl;
		s[i].total= (s[i].m1 + s[i].m2 + s[i].m3);
		cout << s[i].total <<endl;
		if (s[i].m1<40 || s[i].m2<40 || s[i].m3<40)
			s[i].grade = 'F';
		else if (avg > 60)
			s[i].grade = 'A';
		else if (50 < avg && avg < 60)
			s[i].grade = 'B';
		else if (40 < avg && avg < 50)
			s[i].grade = 'C';
		else
			s[i].grade = 'F';
	}
}
ostream& operator<<(ostream& cout, student c)
{
	cout << "name: " << c.studentName<<endl;
	cout << "marks1: " << c.m1<<endl;
	cout << "marks2: " << c.m2 << endl;
	cout << "marks3: " << c.m3 << endl;
	cout << "total: " <<c.total << endl;
	cout << "grade: " << c.grade << endl;
	return cout;
}

istream& operator >> (istream& cin, student &c)
{
	char s[50];
	cin >> s;
	int len = strlen(s);
	c.studentName = (char*)malloc(sizeof(char)*(len + 1));
	strcpy(c.studentName, s);
	cin >> c.m1;
	cin >> c.m2;
	cin >> c.m3;
	return cin;
}
int main()
{
	int n;
	cout << "enter no of students" << endl;
	cin >> n;
	student* s;
	s = new student[n];
	
	for (int i = 0; i<n; i++)
	{
		cout << "enter student details" << endl;
		cin >> s[i];
	}
	generate_results(s, n);
	cout << "entered student details are" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << s[i];
	}
	return 0;
}