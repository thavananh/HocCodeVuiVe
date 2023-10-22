#include <iostream>
using namespace std;

void swapTwoNums(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void quicksort(int a[], int n, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int  pivot = (0 + n - 1) / 2;
	swapTwoNums(a[pivot], a[end]);
	int i = start, j = end;
	while (i <= j)
	{
		if (a[i] < a[pivot])
		{
			i++;
		}
		if (a[j] > a[pivot])
		{
			j--;
		}
		if (a[i] > a[pivot] && a[j] < a[pivot])
		{
			swapTwoNums(a[i], a[j]);
			i++;
			j--;
		}
	}
	swap(a[i], a[pivot]);
	quicksort(a, n, start, pivot);
	quicksort(a, n, pivot, end);

}

int main()
{
	int a[100];
	int n = 5;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quicksort(a, n, 0, n - 1);
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}