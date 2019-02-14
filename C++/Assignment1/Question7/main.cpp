#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class matrix
{
	int rows;
	int cols;
	int** ptr;
public:
	matrix()
	{
		rows = 0;
		cols = 0;
		ptr = NULL;
	}
	matrix(int x)
	{
		rows = x;
		cols = x;
		ptr = new int*[x];
		for (int i = 0; i < x; i++)
		{
			ptr[i] = new int[x];
		}
	}
	matrix(int m, int n)
	{
		rows = m;
		cols = n;
		ptr = new int*[m];
		for (int i = 0; i < m; i++)
		{
			ptr[i] = new int[n];
		}
	}
};