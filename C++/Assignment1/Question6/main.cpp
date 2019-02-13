#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class point
{
	int x;
	int y;
	float d;
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
	void display()
	{
		cout << "the distance between two points is: " << d << endl;
	}
	friend point calculate_distance(point &p1, point &p2);

};
point calculate_distance(point &p1, point &p2)
{
	point temp;
	int a = p1.x - p2.x;
	a = a*a;
	int b = p1.y - p2.y;
	b = b*b;
	temp.d = sqrt(a + b);
	return temp;
}
int main()
{
	point p1(5), p2(3, 7), p3;
	p3 = calculate_distance(p1, p2);
	p3.display();
	return 0;
}