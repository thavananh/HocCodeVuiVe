#include <iostream>
#include <string>
using namespace std;

struct DATEARRAY
{
	string ngay, thang, nam;
};

istream& operator >> (istream& is, DATEARRAY& datearray)
{
	is >> datearray.ngay >> datearray.thang >> datearray.nam;
	return is;
}

ostream& operator << (ostream& os, DATEARRAY& datearray)
{
	os << datearray.ngay << '/' << datearray.thang << '/' << datearray.nam;
	return os;
}

string convertNgayThangNamSangThu(DATEARRAY da)
{
	int ngay = stoi(da.ngay);
	int thang = stoi(da.thang);
	int nam = stoi(da.nam);
	int n = (ngay + 2 * thang + (3 * (thang + 1)) / 5 + nam + (nam / 4)) % 7;
	switch (n)
	{
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	default:
		break;
	}
	return "";
}

struct M1C
{
	int n;
	DATEARRAY da[100];
};

istream& operator >> (istream& is, M1C& m1c)
{
	is >> m1c.n;
	for (size_t i = 0; i < m1c.n; i++)
	{
		is >> m1c.da[i];
	}
	return is;
}

ostream& operator << (ostream& os, M1C m1c)
{
	for (size_t i = 0; i < m1c.n; i++)
	{
		os << m1c.da[i] << endl;
	}
	return os;
}

bool operator == (M1C m1, M1C m2)
{
	if (m1.n != m2.n)
	{
		return false;
	}
	for (size_t i = 0; i < m1.n; i++)
	{
		if (convertNgayThangNamSangThu(m1.da[i]) != convertNgayThangNamSangThu(m2.da[i]))
		{
			return false;
		}
	}
	return true;
}

bool operator < (M1C m1, M1C m2)
{
	if (m1.n != m2.n)
	{
		return false;
	}
	for (size_t i = 0; i < m1.n; i++)
	{
		if (stoi(m1.da[i].ngay) >= stoi(m2.da[i].ngay))
		{
			return false;
		}
	}
	return true;
}

M1C operator + (M1C m1, M1C m2)
{
	M1C rs;
	rs.n = m1.n + m2.n;
	for (size_t i = 0; i < m1.n; i++)
	{
		rs.da[i] = m1.da[i];
	}
	for (size_t i = m2.n, j = 0; i < rs.n; i++, j++)
	{
		rs.da[i] = m2.da[j];
	}
	return rs;
}


int main()
{
	M1C m1, m2;
	cin >> m1 >> m2;
//	cout << m1 << m2;
	cout << m1 + m2;

}