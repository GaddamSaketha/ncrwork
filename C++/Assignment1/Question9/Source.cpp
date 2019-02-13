#include<iostream>
using namespace std;
void swap_value(int a, int b);
void swap_reference(int &a, int &b);
int main()
{
	int a = 10, b = 20,i;
	cout << "enter 1 to use swap by value 2 to use swap by reference";
	cin >> i;
	switch (i)
	{
	case 1 : swap_value(a, b);
		cout << "after swap by value" << endl;
		cout << "a is " << a << endl;
		cout << "b is " << b << endl;
		break;
	case 2 : swap_reference(a, b);
		cout << "after swap by reference" << endl;
		cout << "a is " << a << endl;
		cout << "b is " << b << endl;
		break;
	default: cout << "enter valid no";
	}
	
	return 0;
}
void swap_value(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap_reference(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}