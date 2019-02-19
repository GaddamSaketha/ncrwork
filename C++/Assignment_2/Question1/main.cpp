#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class polar
{
	int angle;
	int radius;
public:
	static int count;
	polar()
	{
		angle = 0;
		radius = 0;
		count++;
	}
	polar(int x, int y)
	{
		angle = x;
		radius = y;
		count++;
	}
	polar(const polar &p)
	{
		angle = p.angle;
		radius = p.radius;
		count++;
	}
	~polar()
	{
		count--;
	}

};
int polar::count;
int main()
{
	polar p1, p2(30, 6);
	cout << polar::count << endl;
	{
		polar p3(p2);
		cout << polar::count << endl;
	}
	cout << polar::count << endl;

	return 0;
}