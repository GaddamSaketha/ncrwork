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
	void matrix_initialize()
	{
		cout << "enter matrix values" << endl;
		for(int i=0;i<rows;i++)
			for (int j = 0; j <cols; j++)
			{
				cin >> *(*(ptr+i)+j);
			}
	}
	void display()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << " " << *(*(ptr + i) + j) << " ";
			}
			cout << endl;
		}
	}
	friend matrix matrix_multiplication(matrix, matrix);
};
matrix matrix_multiplication(matrix m1, matrix m2)
{
	int sum = 0, i, j, k;
	matrix m(m1.rows, m2.cols);
	if (m1.cols != m2.rows)
		cout << "matrix multiplication not possible" << endl;
	else
	{
		
		for (i = 0; i < m1.rows; i++)
		{
			for (j = 0; j < m2.cols; j++)
			{
				for (k = 0; k < m2.rows; k++)
				{
					sum = sum+(*(*(m1.ptr + i) + k) )* (*(*(m2.ptr + k) + j));
				}
				*(*(m.ptr + i) + j) = sum;
				sum = 0;
			}
			
		}
	}
	return m;
}
int main()
{
	matrix m1(2, 3), m2(3, 2), m3;
	m1.matrix_initialize();
	m2.matrix_initialize();
	m3 = matrix_multiplication(m1, m2);
	m3.display();
	return 0;
}