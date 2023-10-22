#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class SinhVien
{
private:
	string _strMaSinhVien, _strHoTen, _strNgaySinh;
	int _iSoMonHoc;
	string _strMaMon[100];
	string _strTenMon[100];
	int _iSoTinChi[100];
	double _dSoDiem[100];
public:
	SinhVien(string strMaSinhVien = "", string strHoTen = "", string strNgaySinh = "", int iSoMonHoc = 0, string strMaMon[] = {}, string strTenMon[] = {}, int iSoTinChi[] = {}, double dSoDiem[] = {});
	SinhVien(const SinhVien& sinhvien);
	~SinhVien();
	void input();
	void output();
	string getMaSinhVien();
	string getHoTen();
	string getTen();
	string getNgaySinh();
	int getNamSinh();
	void setMaSinhVien(string strMaSinhVien);
	void setHoTen(string strHoTen);
	void setNgaySinh(string strNgaySinh);
	string getValueFromMaMon(int index);
	string getValueFromTenMon(int index);
	int getValueFromSoTinChi(int index);
	double getValueFromSoDiem(int index);
	double getDiemTrungBinh();
	bool datDieuKienHocBong();
	friend void swapSinhVien(SinhVien& sv1, SinhVien& sv2);
	friend void insertionSort(SinhVien sv[], int n);
	friend void binarySearch(SinhVien sv[], int& n, int start, int end, SinhVien key);
	friend void removeElement(SinhVien sv[], int start, int& n);
	friend void selectionSort(SinhVien sv[], int n);
	friend void quickSort(SinhVien sv[], int n, int low, int high);
	friend int partition(SinhVien sv[], int low, int high);
};

SinhVien::SinhVien(string strMaSinhVien, string strHoTen, string strNgaySinh, int iSoMonHoc, string strMaMon[], string strTenMon[], int iSoTinChi[], double dSoDiem[])
{
	this->_strMaSinhVien = strMaSinhVien;
	this->_strHoTen = strHoTen;
	this->_strNgaySinh = strNgaySinh;
	this->_iSoMonHoc = iSoMonHoc;
	for (size_t i = 0; i < iSoMonHoc; i++)
	{
		this->_strMaMon[i] = strMaMon[i];
		this->_strTenMon[i] = strTenMon[i];
		this->_iSoTinChi[i] = iSoTinChi[i];
		this->_dSoDiem[i] = dSoDiem[i];
	}
}

SinhVien::SinhVien(const SinhVien& sinhvien)
{
	_strMaSinhVien = sinhvien._strMaSinhVien;
	_strHoTen = sinhvien._strHoTen;
	_strNgaySinh = sinhvien._strNgaySinh;
	_iSoMonHoc = sinhvien._iSoMonHoc;
	for (size_t i = 0; i < _iSoMonHoc; i++)
	{
		_strMaMon[i] = sinhvien._strMaMon[i];
		_strTenMon[i] = sinhvien._strTenMon[i];
		_iSoTinChi[i] = sinhvien._iSoTinChi[i];
		_dSoDiem[i] = sinhvien._dSoDiem[i];
	}
}

SinhVien::~SinhVien() {}


//câu a
void SinhVien::input()
{
	cout << "Nhap Ma Sinh Vien: ";
	cin >> _strMaSinhVien;
	cin.ignore();
	cout << "Nhap Ho Ten: ";
	getline(cin, _strHoTen);
	cout << "Nhap Ngay Sinh: ";
	cin >> _strNgaySinh;
	cout << "Nhap So Mon Hoc: ";
	cin >> _iSoMonHoc;
	cout << "Nhap Theo Thu Tu: Ma Mon - Ten Mon - So Tin Chi - Diem" << endl;
	for (size_t i = 0; i < _iSoMonHoc; i++)
	{
		cin >> _strMaMon[i];
		cin.ignore();
		getline(cin, _strTenMon[i]);
		cin >> _iSoTinChi[i] >> _dSoDiem[i];
	}
}

void SinhVien::output()
{
	cout << "Thong Tin Ca Nhan" << endl;
	cout << setfill(' ');
	vector<string>vHeader = { "Ma Sinh Vien", "Ho Ten", "Ngay Sinh" };
	for (auto it : vHeader)
	{
		cout << "| " << left << setw(20) << it << " ";
	}
	cout << "|" << endl;
	for (size_t i = 0; i < vHeader.size(); i++)
	{
		cout << "+" << setfill('-') << setw(20 + 2) << "-";
	}
	cout << "+" << endl;
	cout << setfill(' ');
	cout << "| " << left << setw(20) << _strMaSinhVien << " ";
	cout << "| " << left << setw(20) << _strHoTen << " ";
	cout << "| " << left << setw(20) << _strNgaySinh << " |" << endl;
	for (size_t i = 0; i < vHeader.size(); i++)
	{
		cout << "+" << setfill('-') << setw(20 + 2) << "-";
	}
	cout << "+" << endl;
	cout << "Thong Tin Mon Hoc" << endl;
	vector<string>vHeader1 = { "Ma Mon", "Ten Mon", "So Tin Chi", "Diem" };
	for (auto it : vHeader1)
	{
		cout << setfill(' ');
		cout << "| " << left << setw(20) << it << " ";
	}
	cout << "|" << endl;
	for (size_t i = 0; i < vHeader1.size(); i++)
	{
		cout << "+" << setfill('-') << setw(20 + 2) << "-";
	}
	cout << "+" << endl;
	for (size_t i = 0; i < _iSoMonHoc; i++)
	{
		cout << setfill(' ');
		cout << "| " << left << setw(20) << _strMaMon[i] << " ";
		cout << "| " << left << setw(20) << _strTenMon[i] << " ";
		cout << "| " << left << setw(20) << _iSoTinChi[i] << " ";
		cout << "| " << left << setw(20) << _dSoDiem[i] << " ";
		cout << "|" << endl;
		for (size_t i = 0; i < vHeader1.size(); i++)
		{
			cout << "+" << setfill('-') << setw(20 + 2) << "-";
		}
		cout << "+" << endl;
	}
	/*for (size_t i = 0; i < vHeader1.size(); i++)
	{
		cout << "+" << setfill('-') << setw(20 + 2) << "-";
	}
	cout << "+" << endl;*/
}

string SinhVien::getMaSinhVien()
{
	return _strMaSinhVien;
}
string SinhVien::getHoTen()
{
	return _strHoTen;
}
string SinhVien::getNgaySinh()
{
	return _strNgaySinh;
}
void SinhVien::setMaSinhVien(string strMaSinhVien)
{
	this->_strMaSinhVien = strMaSinhVien;
}
void SinhVien::setHoTen(string strHoTen)
{
	this->_strHoTen = strHoTen;
}
void SinhVien::setNgaySinh(string strNgaySinh)
{
	this->_strNgaySinh = strNgaySinh;
}
string SinhVien::getValueFromMaMon(int index)
{
	return _strMaMon[index];
}
string SinhVien::getValueFromTenMon(int index)
{
	return _strTenMon[index];
}
int SinhVien::getValueFromSoTinChi(int index)
{
	return _iSoTinChi[index];
}
double SinhVien::getValueFromSoDiem(int index)
{
	return _dSoDiem[index];
}
string SinhVien::getTen()
{
	stringstream ss(_strHoTen);
	string strTmp;
	while (ss >> strTmp)
	{

	}
	return strTmp;
}

void swapSinhVien(SinhVien& sv1, SinhVien& sv2)
{
	SinhVien tmp = sv1;
	sv1 = sv2;
	sv2 = tmp;
}

long convertStringToInt(string strParameter)
{
	long rs = 0;
	for (size_t i = 0; i < strParameter.length(); i++)
	{
		if (strParameter[i] == ' ')
		{
			continue;
		}
		rs += (int)strParameter[i];
	}
	return rs;
}

void insertionSort(SinhVien sv[], int n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (convertStringToInt(sv[i].getHoTen()) > (int)sv[j].getTen()[0])
			{
				swapSinhVien(sv[i], sv[j]);
			}
		}
	}
}

void binarySearch(SinhVien sv[], int& n, int start, int end, SinhVien key)
{
	int mid = (start + end) / 2;
	if (convertStringToInt(sv[mid].getHoTen()) > convertStringToInt(key.getHoTen()))
	{
		binarySearch(sv, n, start, mid - 1, key);
	}
	if (convertStringToInt(sv[mid].getHoTen()) < convertStringToInt(key.getHoTen()))
	{
		binarySearch(sv, n, mid + 1, end, key);
	}
	if (convertStringToInt(sv[mid].getHoTen()) == convertStringToInt(key.getHoTen()))
	{
		removeElement(sv, mid, n);
	}
}

void removeElement(SinhVien sv[], int start, int& n)
{
	for (size_t i = start; i < n - 1; i++)
	{
		sv[i] = sv[i + 1];
	}
	n -= 1;
}

bool SinhVien::datDieuKienHocBong()
{
	if (SinhVien::getDiemTrungBinh() >= 7)
	{
		for (size_t i = 0; i < _iSoMonHoc; i++)
		{
			if (_dSoDiem[i] < 5)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

double SinhVien::getDiemTrungBinh()
{
	double sum = 0;
	for (size_t i = 0; i < _iSoMonHoc; i++)
	{
		sum += _dSoDiem[i];
	}
	return sum /= _iSoMonHoc;
}

void selectionSort(SinhVien sv[], int n)
{
	size_t j;
	double x;
	SinhVien tmp;
	for (size_t i = 1; i < n; i++)
	{
		double x = sv[i].getDiemTrungBinh();
		tmp = sv[i];
		for (j = i; j > 0 && sv[j - 1].getDiemTrungBinh() > x; j--)
		{
			sv[j] = sv[j - 1];
		}
		sv[j] = tmp;
	}
}

int SinhVien::getNamSinh()
{
	istringstream iss(_strNgaySinh);
	string strTmp;
	while (getline(iss, strTmp, '/'))
	{
		if (!iss.eof())
		{
			strTmp = "";
		}
	}
	return stoi(strTmp);
}

int partition(SinhVien sv[], int low, int high)
{
	int pivot = sv[high].getNamSinh();
	int i = low - 1;
	for (size_t j = low; j < high; j++)
	{
		if (sv[j].getNamSinh() <= pivot)
		{
			i++;
			swap(sv[i], sv[j]);
		}
	}
	swap(sv[i + 1], sv[high]);
	return i + 1;
}

void quickSort(SinhVien sv[], int low, int high)
{
	if (low < high)
	{
		int pivotIndex = partition(sv, low, high);
		quickSort(sv, low, pivotIndex - 1);
		quickSort(sv, pivotIndex + 1, high);
	}
}

int main()
{
	SinhVien sv[10];
	int n;
	cout << "Nhap So Luong Sinh Vien: ";
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		sv[i].input();
	}
	//string strMaSinhVienX, strMaSinhVienY;
	//cout << "Nhap Ma Sinh Vien X: ";
	//cin >> strMaSinhVienX;
	//cout << "Nhap Ma Sinh Vien Y: ";
	//cin >> strMaSinhVienY;
	//// câu b
	//for (size_t i = 0; i < n; i++)
	//{
	//	if (sv[i].getMaSinhVien() == strMaSinhVienX)
	//	{
	//		sv[i].setMaSinhVien(strMaSinhVienY);
	//	}
	//}
	// Câu c
	//insertionSort(sv, n);
	/*for (size_t i = 0; i < n; i++)
	{
		sv[i].output();
	}*/
	//Câu d
	/*cout << "Nhap Ten Sinh Vien Can Tim" << endl;
	SinhVien key;
	key.input();
	binarySearch(sv, n, 0, n - 1, key);*/
	/*for (size_t i = 0; i < n; i++)
	{
		sv[i].output();
	}*/
	// Câu e
	/*selectionSort(sv, n);
	for (size_t i = 0; i < n; i++)
	{
		sv[i].output();
	}*/
	// câu f
	/*cout << "Cac Sinh Vien Dat Hoc Bong" << endl;
	for (size_t i = 0; i < n; i++)
	{
		if (sv[i].datDieuKienHocBong())
		{
			sv[i].output();
		}
	}*/
	//câu g
	/*quickSort(sv, 0, n - 1);
	for (size_t i = 0; i < n; i++)
	{
		sv[i].output();
	}*/
}