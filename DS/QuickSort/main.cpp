#include<iostream>
using namespace std;
int* a;
void quick_sort(int low, int high);
int main()
{
	int n, i;
	cout << "enter no of elems" << endl;
	cin >> n;
    a = new int[n];
	cout << "enter values";
	for (i = 0; i < n; i++)
		cin >> a[i];
	quick_sort(0, n - 1);
	cout << "sorted list is" << endl;
	for (i = 0; i < n; i++)
		cout << a[i];
	return 0;
}
void quick_sort(int low, int high)
{
	int pivot = a[low];
	int i, j,f;
	i = low + 1;
	j = high;
	if (low < high)
	{
		while (1)
		{
			f = 0;
			while (i < high && a[i] < pivot)
				i++;
			while (a[j] > pivot)
				j--;
			if (i < j)
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = a[i];
				f = 1;
			}
			else
				break;
		}
		int temp = a[low];
		a[low] = a[j];
		a[j] = temp;
		quick_sort(low, j - 1);
		quick_sort(j + 1, high);
	}
}