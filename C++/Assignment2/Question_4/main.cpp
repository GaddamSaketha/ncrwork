#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class complex
{
	float real;
	float img;
public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(float i)
	{
		real = img = i;
	}
	complex(float r, float i)
	{
		real = r;
		img = i;
	}
	complex(complex& c)
	{
		real = c.real;
		img = c.img;
	}
	~complex()
	{
		cout << "in destuctor" << endl;
	}
	complex operator+(complex c)
	{
		complex temp;
		temp.real = real + c.real;
		temp.img = img + c.img;
		return temp;
	}
	complex operator-()
	{
		complex c;
		c.real = -real;
		c.img = -img;
		return c;
	}
	complex operator-(complex c)
	{
		complex c1;
		c1.real = real - c.real;
		c1.img = img - c.img;
		return c1;
	}
	complex operator++()
	{
		++real;
		++img;
		return *this;
	}
	complex operator++(int x)
	{
		complex c;
		c.real = real++;
		c.img = img++;
		return c;
	}
	complex operator,(complex c)
	{
		return c;
	}
	friend ostream& operator<<(ostream& cout, complex c);
	friend istream& operator >> (istream& cin, complex& c);
};
ostream& operator<<(ostream& cout, complex c)
{
	cout << "real: " << c.real;
	cout << "img: " << c.img;
	return cout;
}
istream& operator >> (istream& cin, complex& c)
{
	cin >> c.real;
	cin >> c.img;
	return cin;
}
int main()
{
	complex c1, c2(2, 3), c3(5, 7), c4(c2), c5, c6, c7;
	c5 = c2 + c3;
	cout << "sum is: ";
	cout << c5 << endl;
	c6 = c2 - c3;
	cout << "diff is: ";
	cout << c6 << endl;
	c7 = -c4;
	cout << "-c4 is: ";
	cout << c7 << endl;
	cout << "inc of c2 is: ";
	cout << ++c2 << endl;
	c5 = c3++;
	cout << c5 << endl;
	cout << c3 << endl;
	return 0;
}