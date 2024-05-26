#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		int Monthday[] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			Monthday[2] = 29;
		return Monthday[month];
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{}

	// 赋值运算符重载
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

	// 析构函数
	~Date()
	{}

	// 日期+=天数
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

	// 日期+天数
	Date operator+(int day)
	{
		Date tmp = *this;
		tmp += day;
		return tmp;
	}

	// 日期-天数
	Date operator-(int day)
	{
		Date tmp = *this;
		tmp -= day;
		return tmp;
	}

	// 日期-=天数
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

	// 前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}

	// 后置--
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	// 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		return _year > d._year 
			|| (_year == d._year && _month > d._month) 
			|| (_year == d._year && _month == d._month && _day > d._day);
	}

	// ==运算符重载
	bool operator==(const Date& d)
	{
		return !(*this > d) && !(*this < d);
	}

	// >=运算符重载
	bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	// <运算符重载
	bool operator < (const Date& d)
	{
		return _year < d._year
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day);
	}

	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return *this < d || *this == d;
	}

	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// 日期-日期 返回天数
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