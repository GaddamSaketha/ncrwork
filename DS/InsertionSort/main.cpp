#include<iostream>
using namespace std;
int main()
{

	int n, i, j, f = 0, temp;
	cout << "enter no of elems" << endl;
	cin >> n;
	int* a = new int[n];
	cout << "enter values";
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		j = i - 1;
		while (temp < a[j] && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	cout << "sorted list is" << endl;
	for (i = 0; i < n; i++)
		cout << a[i];
	return 0;
}