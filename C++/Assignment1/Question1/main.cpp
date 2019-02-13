#include<iostream>
using namespace std;
class Time
{
	int hours;
	int minutes;
	int seconds;
public:
	Time()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	Time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display()
	{
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}
	void add_time(Time t1, Time t2)
	{

		hours = 0;
		minutes = 0;
		seconds = 0;
		if (t1.seconds + t2.seconds > 59)
		{
			minutes = (t1.seconds + t2.seconds) / 60;
		}
		if (t1.minutes + t2.minutes > 59)
		{
			hours = (t1.minutes + t2.minutes) / 60;
		}
		hours = hours+t1.hours + t2.hours;
		minutes = minutes+(t1.minutes + t2.minutes)%60;
		seconds = seconds+(t1.seconds + t2.seconds)%60;
	}

};

int main()
{
	Time c1(1, 30, 40);
	Time c2(2, 50, 30);
	Time c3;
	c3.add_time(c1, c2);
	c3.display();
	return 0;
}
