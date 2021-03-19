/*
#include<iostream>
using namespace std;
class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0))
		{
			day +=1;
		}
		return day;
	}
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 1 || month < 1 || month > 12 || day < 1 || day > GetMonthDay(year, month))
		{
			cout << "日期无效" << endl;
		}
		else 
		{
			_year = year;
			_month = month;
			_day = day;
			cout << _year << "-" << _month << "-" << _day << endl;
		}
	}
	// 拷贝构造函数
    // d2(d1)
	Date(const Date& d)
	{
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	// 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}
	// 析构函数
	~Date()
	{}
	// 日期+=天数
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	// 日期+天数
	Date operator+(int day)
	{
		Date copy(*this);
		copy += day;
		return copy;
	}
	// 日期-天数
	Date operator-(int day)
	{
		Date copy(*this);
		copy -= day;
		return copy;
	}
	// 日期-=天数
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	// 前置++
	Date& operator++()
	{
		return *this += 1;
	}
	// 后置++
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;
		return copy;
	}
	// 后置--
	Date operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}
	// 前置--
	Date& operator--()
	{
		return *this -= 1;
	}
	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if(_year==d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
		}
		return false;
	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		return (*this > d) || (*this == d);
	}
	// <运算符重载
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}
	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}
	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (max < min)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++min;
			++day;
		}
		return flag * day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d1(2020, 2, 2);
	Date d2(2020, 3, 3);
	//拷贝构造函数
	Date copy(d1);
	d1.display();
	//+=
	d1 += 69;
	d1.display();
	//-=
	d1 -= 69;
	d1.display();
	//++
	d1++;
	d1.display();
	++d2;
	d2.display();
	//--
	d1--;
	d1.display();
	--d2;
	d2.display();
	bool ret1 = d1 == d1;
	bool ret2 = d1 != d1;
	bool ret3 = d1 > d2;
	bool ret4 = d1 < d2;
	bool ret5 = d2 >= d1;
	bool ret6 = d2 <= d1;
}
int main()
{
	test();
	return 0;
}*/