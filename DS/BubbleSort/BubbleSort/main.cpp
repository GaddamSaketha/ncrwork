#include<iostream>
using namespace std;
int main()
{
	int n, i, j,f=0;
	cout << "enter no of elems" << endl;
	cin >> n;
	int* a= new int[n];
	cout << "enter values";
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
	{
		f = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				f = 1;
			}
		}
		if (f == 0)
			break;
	}
	cout << "sorted list is" << endl;
	for (i = 0; i < n; i++)
		cout<<a[i];
	return 0;
}