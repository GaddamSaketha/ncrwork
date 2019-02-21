#include<iostream>
using namespace std;
int main()
{

	int n, i, j=0, temp;
	cout << "enter no of elems" << endl;
	cin >> n;
	int* a = new int[n];
	cout << "enter values";
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
	{
		int loc = i;
		j = i + 1;
		while (j <= n - 1)
		{
			if (a[j] < a[loc])
				loc = j;
			j++;
		}
		temp = a[i];
		a[i] = a[loc];
		a[loc] = temp;
	}
	cout << "sorted list is" << endl;
	for (i = 0; i < n; i++)
		cout << a[i];
	return 0;
}