#include<iostream>
using namespace std;
int* a;
void heap_sort(int);
void build_heap(int, int);
int main()
{
	int n, i;
	cout << "enter no of elems" << endl;
	cin >> n;
	a = new int[n];
	cout << "enter values";
	for (i = 0; i < n; i++)
		cin >> a[i];
	heap_sort(n);
	cout << "sorted list is" << endl;
	for (i = 0; i < n; i++)
		cout << a[i];
	return 0;
}
void heap_sort(int n)
{
	int i,j;
	for(i = (n / 2) - 1; i >= 0; i--)
	{
		build_heap(i, n);
	}
	for (j = 1; j <= n - 1; j++)
	{
		int temp = a[0];
		a[0] = a[n - j];
		a[n - j] = temp;
		build_heap(0, n - j);
	}
}
void build_heap(int i, int n)
{
	int temp = a[i],c;
	for (; 2 * i + 1 < n; i = c)
	{
		c = 2 * i + 1;
		if (c + 1 < n && a[c + 1] > a[c])
			c++;
		if (a[c] > temp)
			a[i] = a[c];
		else
			break;
	}
	a[i] = temp;
}