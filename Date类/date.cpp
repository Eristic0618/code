#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		int Monthday[] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			Monthday[2] = 29;
		return Monthday[month];
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	// �������캯��
	// d2(d1)
	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{}

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// ��������
	~Date()
	{}

	// ����+=����
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

	// ����+����
	Date operator+(int day)
	{
		Date tmp = *this;
		tmp += day;
		return tmp;
	}

	// ����-����
	Date operator-(int day)
	{
		Date tmp = *this;
		tmp -= day;
		return tmp;
	}

	// ����-=����
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	// ǰ��++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}

	// ����--
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	// ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >���������
	bool operator>(const Date& d)
	{
		return _year > d._year 
			|| (_year == d._year && _month > d._month) 
			|| (_year == d._year && _month == d._month && _day > d._day);
	}

	// ==���������
	bool operator==(const Date& d)
	{
		return !(*this > d) && !(*this < d);
	}

	// >=���������
	bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	// <���������
	bool operator < (const Date& d)
	{
		return _year < d._year
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day);
	}

	// <=���������
	bool operator <= (const Date& d)
	{
		return *this < d || *this == d;
	}

	// !=���������
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// ����-���� ��������
	int operator-(const Date& d)
	{
		Date great = *this;
		Date less = d;
		if (great < less)
		{
			great = d;
			less = *this;
		}
		int count = 0;
		while (great != less)
		{
			less++;
			count++;
		}
		return count;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};