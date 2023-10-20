#include <iostream>
using namespace std;


int main()
{
	int a[100];
	int n;
	cout << "Input n: ";
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cout << "a[" << i << "]" << ": ";
		cin >> a[i];
	}
	
}