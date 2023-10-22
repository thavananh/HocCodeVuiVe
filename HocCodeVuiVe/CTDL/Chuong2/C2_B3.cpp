#include <iostream>
using namespace std;


class M1C
{
private:
	int _numberOfElement;
	int _a[100];
public:
	M1C(int numberOfElement = 0, int array[] = {});
	M1C(const M1C& m1c);
	~M1C();
	void input();
	void output();
	int getNumberOfElement();
	int getArrayValue(int index);
	void removeArrayValue(int x);
	void printKeyPostionValue(int iKey);
	void binarySearch(int key, int start, int end);
};

M1C::M1C(int numberOfElement, int a[])
{
	this->_numberOfElement = numberOfElement;
	for (size_t i = 0; i < numberOfElement; i++)
	{
		this->_a[i] = a[i];
	}
}
M1C::M1C(const M1C& m1c)
{
	this->_numberOfElement = m1c._numberOfElement;
	for (size_t i = 0; i < m1c._numberOfElement; i++)
	{
		this->_numberOfElement = m1c._numberOfElement;
	}
}
M1C::~M1C() {}

int M1C::getNumberOfElement()
{
	return _numberOfElement;
}

int M1C::getArrayValue(int index)
{
	return _a[index];
}


void M1C::input()
{
	cout << "Input n: ";
	cin >> _numberOfElement;
	for (size_t i = 0; i < _numberOfElement; i++)
	{
		cout << "a[" << i << "]" << ": ";
		cin >> _a[i];
	}
}

void M1C::output()
{
	for (size_t i = 0; i < _numberOfElement; i++)
	{
		cout << _a[i] << " ";
	}
}

void M1C::removeArrayValue(int iX)
{
	int iTmp[100];
	int j = 0;
	for (size_t i = 0; i < _numberOfElement; i++)
	{
		if (_a[i] != iX)
		{
			iTmp[j] = _a[i];
			j++;
		}
		else
		{
			_a[i] = 0;
		}
	}
	_numberOfElement = j;
	for (size_t i = 0; i < j; i++)
	{
		_a[i] = iTmp[i];
	}
}

void M1C::printKeyPostionValue(int iKey)
{
	for (size_t i = 0; i < _numberOfElement; i++)
	{
		if (_a[i] == iKey)
		{
			cout << i << " ";
		}
	}
}

void M1C::binarySearch(int key, int start, int end)
{
	int mid = (start + end) / 2;
	if (_a[mid] > key)
	{
		return binarySearch(key, start, mid - 1);
	}
	if (_a[mid] < key)
	{
		return binarySearch(key, mid + 1, start);
	}
	if (_a[mid] == key)
	{
		cout << "found value at " << mid << endl;
	}
}


int main()
{
	M1C a;
	int iX;
	a.input();
	cout << "Input x: ";
	cin >> iX;
	a.binarySearch(iX, 0, a.getNumberOfElement() - 1);
}