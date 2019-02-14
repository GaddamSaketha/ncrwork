#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class point
{
	int x;
	int y;
	
public:
	point()
	{
		x = 0;
		y = 0;
	}
	point(int val)
	{
		x = val;
		y = val;
	}
	point(int val1,int val2)
	{
		x = val1;
		y = val2;
	}

	friend float calculate_distance(point &p1, point &p2);

};
float calculate_distance(point &p1, point &p2)
{
	float d;
	int a = p1.x - p2.x;
	int b = p1.y - p2.y;
	d = sqrt(a*a + b*b);
	return d;
}
int main()
{
	point p1(5), p2(3, 7);
	float d= calculate_distance(p1, p2);
	cout << "the distance between two points is: " << d << endl;
	return 0;
}