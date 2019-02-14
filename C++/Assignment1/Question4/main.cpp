#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

inline int add(int x, int y)
{
	return(x + y);
}
inline int sub(int x, int y)
{
	return(x - y);
}
inline long mul(int x, int y)
{
	return (x*y);
}
inline int division(int x, int y)
{
	if (y == 0)
		return -1;
	else
		return(x / y);
}
inline int mod(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}
int main()
{
	int a, b;
	cout << "enter numbers" << endl;
	cin >> a >> b;
	cout << "sum of nos: " << add(a, b) << endl;
	cout << "diff of nos: " << sub(a, b) << endl;
	cout << "product of nos: " << mul(a, b) << endl;
	cout << " division of nos: " << division(a, b) << endl;
	cout << "modulus of " <<a<<" is: "<< mod(a) << endl;
	cout << "modulus of " << b << " is: " << mod(b) << endl;

	return 0;
}