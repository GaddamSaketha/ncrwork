#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class student
{
	char studentName[30];
	int m1;
	int m2;
	int m3;
	int avg;
	char grade;
public:
	void set_Data(const char* n,int marks1, int marks2, int mark3)
	{
		strcpy(studentName, n);
		m1 = marks1;
		m2 = marks2;
		m3 = mark3;

	}
	void calculateAverage()
	{
		avg = (m1 + m2 + m3) / 3;
	}
	void ComputeGrade()
	{
		if(m1<40 ||m2<40||m3<40)
			grade = 'F';
		else if (avg > 60)
			grade = 'A';
		else if (50 < avg && avg < 60)
			grade = 'B';
		else if (40 < avg && avg < 50)
			grade = 'C';
		else
			grade = 'F';
	}
	void display()
	{
		cout << "name : " << studentName << endl;
		cout << "marks1 : " << m1 << endl;
		cout << "marks2 : " << m2 << endl;
		cout << "marks3 : " << m3 << endl;
		cout << "average : " << avg << endl;
		if (grade == 'A')
			cout << "First class" << endl;
		else if(grade=='B')
			cout << "Second class" << endl;
		else if(grade=='C')
			cout << "Third class" << endl;
		else
			cout << "Fail" << endl;

	}
};
int main()
{
	student s;
	s.set_Data("ravi", 30, 20, 50);
	s.calculateAverage();
	s.ComputeGrade();
	s.display();
	return 0;
}