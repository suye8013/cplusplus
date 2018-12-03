#ifndef __DATA_H__
#define __DATA_H__
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);
	bool IsInvalid();
	bool isLeapYear(int year);
	int GetMonthDay(int year, int month);
	bool operator==(const Date& d);
	bool operator>(const Date& d);
	bool operator!=(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator<(const Date& d);
	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);
	Date& operator++();//++d1  前置 
	Date operator++(int); //d1++  后置
	Date& operator--();
	Date operator--(int);
	void Show();
private:
	int _year;
	int _month;
	int _day;
};

#endif
