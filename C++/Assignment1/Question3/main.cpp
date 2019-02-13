#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class complex
{
	int real;
	int img;
	
public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(int val)
	{
		real = val;
		img = val;
	}
	complex(int val1,int val2)
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
complex add(const complex &c1, const complex &c2)
{
	complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	return temp;
}
complex mul(const complex &c1, const complex &c2)
{
	complex temp;
	temp.real = c1.real * c2.real;
	temp.img = c1.img * c2.img;
	return temp;
}
int main()
{
	complex c1(4), c2(3, 6), c3,c4;
	c3=add(c1, c2);
	c4=mul(c1, c2);
	cout << "sum of nos: ";
	c3.display();
	cout << "product of no: ";
	c4.display();
	return 0;
}