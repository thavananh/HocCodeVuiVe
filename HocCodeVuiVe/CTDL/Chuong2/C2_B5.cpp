#include <iostream>
#include <string>
using namespace std;

long convertStringToInt(string strInput)
{
	long rs = 0;
	for (size_t i = 0; i < strInput.length(); i++)
	{
		if (strInput[i] == ' ')
		{
			continue;
		}
		rs += (int)strInput[i];
	}
	return rs;
}

class QLISACH
{
private:
	string _strMaSach, _strTieuDeSach;
	int _iNamXuatBan;
	double _dGia;
public:
	QLISACH(string _strMaSach = "", string _strTieuDeSach = "", int iNamXuatBan = 0, double dGia = 0.0);
	QLISACH(const QLISACH& qlisach);
	~QLISACH();
	friend istream& operator >> (istream& is, QLISACH& qlisach);
	friend ostream& operator << (ostream& os, QLISACH qlisach);
	string getMaSach()
	{
		return _strMaSach;
	}
	string getTieuDeSach()
	{
		return _strTieuDeSach;
	}
	int getNamXuatBan()
	{
		return _iNamXuatBan;
	}
	double getGia()
	{
		return _dGia;
	}
	void setTieuDeSach(string strInput)
	{
		this->_strTieuDeSach = strInput;
	}
	void setGia(double dGia)
	{
		this->_dGia = dGia;
	}
};

QLISACH::QLISACH(string strMaSach, string strTieuDeSach, int iNamXuatBan, double dGia)
{
	this->_strMaSach = strMaSach;
	this->_strTieuDeSach = strTieuDeSach;
	this->_iNamXuatBan = iNamXuatBan;
	this->_dGia = dGia;
}

QLISACH::QLISACH(const QLISACH& qlisach)
{
	this->_strMaSach = qlisach._strMaSach;
	this->_strTieuDeSach = qlisach._strTieuDeSach;
	this->_iNamXuatBan = qlisach._iNamXuatBan;
	this->_dGia = qlisach._dGia;
}

QLISACH::~QLISACH() {}

istream& operator >> (istream& is, QLISACH& qlisach)
{
	cout << "Nhap Ma Sach: ";
	is >> qlisach._strMaSach;
	is.ignore();
	cout << "Nhap Tieu De Sach: ";
	getline(is, qlisach._strTieuDeSach);
	cout << "Nhap Nam Xuat Ban: ";
	is >> qlisach._iNamXuatBan;
	cout << "Nhap Gia Ban: ";
	is >> qlisach._dGia;
	return is;
}

ostream& operator << (ostream& os, QLISACH qlisach)
{
	os << "Ma Sach: " << qlisach._strMaSach << endl;
	os << "Tieu De Sach: " << qlisach._strTieuDeSach << endl;
	os << "Nam Xuat Ban: " << qlisach._iNamXuatBan << endl;
	os << "Gia Ban: " << qlisach._dGia << endl;
	return os;
}

class M1C
{
	QLISACH _a[100];
	int _iNumberOfElement;
public:
	M1C(int iNumberOfElement = 0, QLISACH a[] = {});
	M1C(const M1C& m1c);
	~M1C();
	void inputArr();
	void outputArr();
	int getNumberOfElement()
	{
		return _iNumberOfElement;
	}
	void timKiemRoiThay(string xstrX, double dGiaY);
	void binarySearch(int start, int end, string key);
	void removeElementFromArr(int index);
	void selectionSort();
	void insertionSort();
	void bubbleSort();
	void quicksort();
	double partition(int low, int high)
	{
		double pivot = _a[high].getGia();
		int i = low - 1;
		for (size_t j = low; j < high; j++)
		{
			if (_a[j].getGia() <= pivot)
			{
				i++;
				swap(_a[i], _a[j]);
			}
		}
		swap(_a[i + 1], _a[high]);
		return i + 1;
	}

	void quickSort(int low, int high)
	{
		if (low < high)
		{
			int pivotIndex = partition(low, high);
			quickSort(low, pivotIndex - 1);
			quickSort(pivotIndex + 1, high);
		}
	}

};

M1C::M1C(int iNumberOfElement, QLISACH a[])
{
	this->_iNumberOfElement = iNumberOfElement;
	for (size_t i = 0; i < iNumberOfElement; i++)
	{
		this->_a[i] = a[i];
	}
}

M1C::M1C(const M1C& m1c)
{
	this->_iNumberOfElement = m1c._iNumberOfElement;
	for (size_t i = 0; i < _iNumberOfElement; i++)
	{
		this->_a[i] = m1c._a[i];
	}
}

M1C::~M1C() {}

void M1C::inputArr()
{
	cout << "Nhap So Phan Tu: ";
	cin >> _iNumberOfElement;
	for (size_t i = 0; i < _iNumberOfElement; i++)
	{
		cin >> _a[i];
	}
}

void M1C::outputArr()
{
	cout << endl;
	for (size_t i = 0; i < _iNumberOfElement; i++)
	{
		cout << _a[i] << endl;
	}
}

void M1C::removeElementFromArr(int index)
{
	_iNumberOfElement -= 1;
	for (size_t i = index; i < _iNumberOfElement; i++)
	{
		_a[i] = _a[i + 1];
	}
}

void M1C::binarySearch(int start, int end, string key)
{
	if (start > end)
	{
		return;
	}
	int mid = (start + end) / 2;
	if (convertStringToInt(_a[mid].getMaSach()) > convertStringToInt(key))
	{
		binarySearch(start, mid - 1, key);
	}
	if (convertStringToInt(_a[mid].getMaSach()) < convertStringToInt(key))
	{
		binarySearch(mid + 1, end, key);
	}
	if (convertStringToInt(_a[mid].getMaSach()) == convertStringToInt(key))
	{
		removeElementFromArr(mid);
	}
}

void M1C::timKiemRoiThay(string strX, double dGiaY)
{
	bool thayKhong = false;
	for (size_t i = 0; i < _iNumberOfElement; i++)
	{
		if (_a[i].getTieuDeSach() == strX)
		{
			thayKhong = true;
			_a[i].setGia(dGiaY);
		}
	}
	if (thayKhong)
	{
		cout << "Quyen Sach Khong Ton Tai" << endl;
	}
}

void M1C::selectionSort()
{
	int min;
	for (size_t i = 0; i < _iNumberOfElement - 1; i++)
	{
		min = i;
		for (size_t j = i + 1; j < _iNumberOfElement; j++)
		{
			if (convertStringToInt(_a[j].getMaSach()) < convertStringToInt(_a[min].getMaSach()))
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(_a[min], _a[i]);
		}
	}
}

void M1C::insertionSort()
{
	int pos, x;
	QLISACH tmp;
	for (size_t i = 0; i < _iNumberOfElement; i++)
	{
		x = _a[i].getNamXuatBan();
		tmp = _a[i];
		for (pos = i; pos > 0 && _a[pos - 1].getNamXuatBan() < x; pos--)
		{
			_a[pos] = _a[pos - 1];
		}
		_a[pos] = tmp;
	}
}

void M1C::bubbleSort()
{
	for (size_t i = 0; i < _iNumberOfElement - 1; i++)
	{
		for (size_t j = _iNumberOfElement - 1; j > i; j--)
		{
			if (convertStringToInt(_a[j].getTieuDeSach()) < convertStringToInt(_a[j - 1].getTieuDeSach()))
			{
				swap(_a[j], _a[j - 1]);
			}
		}
	}
}


int main()
{
	M1C  m1c;
	// câu a;
	m1c.inputArr();
	// câu b;
	//m1c.timKiemRoiThay("Trai Hoa Vang", 500000);
	// câu c;
	//m1c.binarySearch(0, m1c.getNumberOfElement() - 1, "SACH001");
	// câu d;
	//m1c.selectionSort();
	// câu e;
	//m1c.insertionSort();
	// câu f;
	//m1c.bubbleSort();
	// câu g;
	//m1c.quickSort(0, m1c.getNumberOfElement() - 1);
	m1c.outputArr();
}


