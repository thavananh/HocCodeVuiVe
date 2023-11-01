#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(0));
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << rand() % 98 + 1 << " ";
		}
		cout << endl;
	}
}