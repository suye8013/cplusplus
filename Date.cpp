#include<iostream>
#include<assert.h>
#include"Data.h"

using namespace std;
Date::Date(int year, int month, int day)
:_year(year),
_month(month),
_day(day)
{
	if (!IsInvalid())
	{
		cout << "输入错误" << endl;
		assert(false);
	}
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
inline bool Date::IsInvalid()
{
	if (_year < 1900 || (_month<1 || _month>12) || _day<1 || _day>GetMonthDay(_year, _month))
	{
		return false;
	}
	return true;
}
inline bool Date::isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year && 100 == 0 && year && 400 == 0))
	{
		return true;
	}
	return false;

}
inline int Date::GetMonthDay(int year, int month)
{
	int buf[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = buf[month];
	if (isLeapYear(year) && month == 2)
	{
		day = buf[2] + 1;
	}
	return day;
}
inline bool Date::operator==(const Date& d)
{
	return _year == d._year&&_month == d._month&&_day == d._day;
}
inline bool Date::operator>(const Date& d)
{
	if (_year > d._year || (_year == d._year&&_month > d._month) || (_year == d._year&&_month == d._month&&_day > d._day))
	{
		return true;
	}
	return false;
}
inline bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
inline bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}
inline bool Date::operator<=(const Date& d)
{
	return !(*this>d);
}
inline bool Date::operator<(const Date& d)
{
	return !(*this == d) && !(*this>d);
}
Date Date::operator+(int day)
{
	if (day > 0)
	{
		Date tmp = *this;
		tmp += day;
		if (!IsInvalid())
		{
			cout << "输入错误" << endl;
			assert(false);
		}
		return tmp;
	}
	else
	{
		Date tmp = *this;
		tmp -= (-day);
		if (!IsInvalid())
		{
			cout << "输入错误" << endl;
			assert(false);
		}
		return tmp;
	}
}
Date& Date::operator+=(int day)
{
	_day = _day + day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day = _day - GetMonthDay(_year, _month);
		if (_month < 12)
		{
			_month++;
		}
		else
		{
			_year++;
		}
	}
	if (!IsInvalid())
	{
		cout << "输入错误" << endl;
		assert(false);
	}
	return *this;
}
Date Date::operator-(int day)
{
	if (day > 0)
	{
		Date tmp = *this;
		tmp -= day;
		if (!IsInvalid())
		{
			cout << "输入错误" << endl;
			assert(false);
		}
		return tmp;
	}
	else
	{
		Date tmp = *this;
		tmp += (-day);
		if (!IsInvalid())
		{
			cout << "输入错误" << endl;
			assert(false);
		}
		return tmp;
	}
}
Date& Date::operator-=(int day)
{
	_day = _day - day;
	while (_day <= 0 && _year >= 1900)
	{
		if (_month>1)
		{
			_month--;
		}
		else
		{
			_month = 12;
			_year--;
		}
		_day = _day + GetMonthDay(_year, _month);
	}
	if (!IsInvalid())
	{
		cout << "输入错误" << endl;
		assert(false);
	}
	return *this;
}
int Date::operator-(const Date& d)
{
	int day = 0;
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (max < min)
	{
		flag = -1;
		max = d;
		min = *this;
	}
	while (max._year != min._year || max._month != min._month)
	{
		if (IsInvalid())
		{
			if (max._month <= 1)
			{
				max._year--;
				max._month = 12;
			}
			else
			{
				max._month--;
			}
			day = day + GetMonthDay(max._year, max._month);
		}
		else
		{
			cout << "输入错误" << endl;
			assert(false);
		}
	}
	day = day + max._day - min._day;
		return day;
}

//++d1 
inline Date& Date::operator++() // 前置 先加后用
{
	(*this) = *this + 1;
	return *this;
}
//d1++ 
inline Date Date::operator++(int) // 后置 先用后加
{
	Date tmp = *this;
	(*this) = *this + 1;
	return tmp;
}
inline Date& Date::operator--()
{
	(*this) = *this - 1;
	if (!IsInvalid())
	{
		cout << "输入错误" << endl;
		assert(false);
	}
	return *this;
}
inline Date Date::operator--(int)
{
	Date tmp = *this;
	(*this) = *this - 1;
	if (!IsInvalid())
	{
		cout << "输入错误" << endl;
		assert(false);
	}
	return tmp;
}
inline void Date::Show()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
