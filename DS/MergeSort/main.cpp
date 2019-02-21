#include<iostream>
using namespace std;
int* a;
void merge_sort(int, int);
void merge(int, int, int);
int main()
{
	int n,i;
	cout << "enter no of elems" << endl;
	cin >> n;
	a = new int[n];
	cout << "enter values";
	for (i = 0; i < n; i++)
		cin >> a[i];
	merge_sort(0, n - 1);
	cout << "sorted list is" << endl;
	for (i = 0; i < n; i++)
		cout << a[i];
	return 0;
}
void merge_sort(int low, int high)
{
	if (low < high)
	{
		int mid;
		mid = (low + high) / 2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
}
void merge(int l1s, int l1e, int l2e)
{
	int l2s = l1e + 1;
	int *l3, i, j, k;
	l3 = new int[l2e - l1s + 1];
	i = l1s;
	j = l2s;
	k = 0;
	while (i <= l1e && j <= l2e)
	{
		if (a[i] > a[j])
			l3[k++] = a[j++];
		else
			l3[k++] = a[i++];
	}
	while (i <= l1e)
		l3[k++] = a[i++];
	while (j <= l2e)
		l3[k++] = a[j++];
	while (l2e >= l1s)
		a[l2e--] = l3[--k];
	delete l3;
}