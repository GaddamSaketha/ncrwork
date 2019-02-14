#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class Distance2;
class Distance1
{
	int meters;
	int centimeters;
public:
	Distance1(int x, int y)
	{
		meters = x;
		centimeters = y;
	}
	friend void add_distances(Distance1, Distance2);
};
class Distance2
{
	int inches;
	int feet;
public:
	Distance2(int x, int y)
	{
		feet= x;
		inches = y;
	}
	friend void add_distances(Distance1, Distance2);
};
void add_distances(Distance1 d1, Distance2 d2)
{
		int m = d2.feet * 0.3048+d1.meters;
		int c = d2.inches * 2.54+d1.centimeters;
		m = m + c % 100;
		c = c / 100;
		cout << "sum id meters: " << m << " centimeters: " << c << endl;
	
}
int main()
{
	Distance1 d1(10, 45);
	Distance2 d2(5, 2);
	add_distances(d1, d2);

	return 0;
}