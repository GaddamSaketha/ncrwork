#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
//class to create complex numbers
class complex
{
	double real;
	double img;
	
public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(double val)
	{
		real = val;
		img = val;
	}
	complex(double val1, double val2)
	{
		real = val1;
		img = val2;
	}
	void display()
	{
		cout << "real : " << real << endl;
		cout << "img : " << img << endl;
	}
	friend complex add(const complex &c1, const complex &c2);
	friend complex mul(const complex &c1, const complex &c2);
};
//function to add two complex numbers
complex add(const complex &c1, const complex &c2)
{
	complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	return temp;
}
//function to multiply two complex numbers
complex mul(const complex &c1, const complex &c2)
{
	complex temp;
	temp.real = c1.real * c2.real;
	temp.img = c1.img * c2.img;
	return temp;
}
int main()
{
	double real, img;
	complex complex_number1(4), complex_number2(3, 6), complex_number3,complex_number4;
	complex_number1.display();
	complex_number2.display();
	complex_number3.display();
	cout << "enter real and img values of first complex number" << endl;
	cin >> real;
	cin >> img;
	complex complex_number5(real, img);
	cout << "enter real and img values of second complex number" << endl;
	cin >> real;
	cin >> img;
	complex complex_number6(real, img);
	complex_number3=add(complex_number5, complex_number6);
	complex_number4=mul(complex_number5, complex_number6);
	cout << "sum of nos: ";
	complex_number3.display();
	cout << "product of no: ";
	complex_number4.display();


	
	return 0;
}