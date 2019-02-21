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
	int* a = new int[n];
	cout << "enter values";
	for (i = 0; i < n; i++)
		cin >> a[i];
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