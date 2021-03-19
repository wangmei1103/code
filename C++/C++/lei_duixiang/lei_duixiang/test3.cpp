
#include<iostream>
using namespace std;
class A
{
	//友元类声明
	friend class C;
	//内部类，作用类似于友元类
	//相比友元类，在内部类中可以直接访问外部类的static成员
	class B
	{
	public:
		void setA(A& a)
		{
			a._a = _b;
			_sa = 100;
		}
	private:
		int _b = 2;
	};
private:
	int _a = 1;
	static int _sa;
};
int A::_sa = 10;
class C {
public:
	void setA(A& a)
	{
		a._a = _c;
		a._sa = 20;
		A::_sa = 30; 
	}
private:
	int _c = 3;
};
int main()
{
	return 0;
}
/*
#include"test.h"
//友元关系是单向的
class Date;
	Time::Time(int hour, int minute, int second) :_hour(hour), _minute(minute), _second(second)
	{
	}
	void Time::fun(Date& d)
	{
		cout << d._year << d._month << d._day;
	}
class Time;
	Date::Date(int year, int month, int day) :_year(year), _month(month), _day(day) {}
	void Date::SetTimeOfDate(int hour, int minute, int second)
	{
		//直接访问时间类私有成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
void test()
{
	Date d;
	d.SetTimeOfDate(1, 1, 1);
	Time t;
	t.fun(d);
}
int main()
{
	test();
	return 0;
}*/
/*
class Date
{
	//友元函数的声明：此函数可以访问当前类的私有成员
	//此函数是一个普通函数，不使用类的成员函数
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin,  Date& d);
public:
	Date(int year,int month,int day):_year(year),_month(month),_day(day){}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
void test()
{
	Date d(2021, 3, 8);
	//简写形式
	cout << d;
	//完整形式
	operator<<(cout, d);
	//连续输出
	cout << d << endl;
	operator<<(cout, d) << endl;

	Date d1(2021, 3, 8);
	//输入
	cin >> d1 >> d1 >> d1;
}
int main()
{
	test();
	return 0;
}*/
/*
class A {
public:
	A()
	{
		++_count;
	}
	A(const A&())
	{
		++_count;
	}
	//static成员函数不包含this指针
	static int getcount()
	{
		//fun();//静态成员函数不可以调用非静态成员函数，缺少this指针
		return _count;
	}
	//普通成员函数包含this指针
	void fun()
	{
		this->getcount();//非静态成员函数可以调用类的静态成员函数
		cout << "fun" << endl;
	}
//private:
	//static成员是所有对象共享
	//static成员变量，必须在类外初始化
	static int _count;
};
int A::_count = 0;
A funA(A a)
{
	return a;
}
void test()
{
	cout << A::_count << endl;
	cout << A::getcount() << endl;
	A a1;
	A a2;
	A a3 = funA(a1);
	cout << a1.getcount() << endl;
	cout << a2.getcount() << endl;
	cout << a3.getcount() << endl;
	cout << A::getcount() << endl;
	//static成员的访问形式
	//1.对象.static成员
	cout << a1._count << endl;
	//2.类型+::+static成员
	cout << A::_count << endl;
}
int main()
{
	test();
	return 0;
}*/
/*
class Date {
public:
	Date(int year)
		:_year(year)
	{}
	explicit Date(int year)
		:_year(year)
	{}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d1(2021);
	//d1 = 2021; //用explicit修饰构造函数，将会禁止单参构造函数的隐式转换
	//若无explicit修饰的构造函数，则可以用一个整型变量给日期类型对象赋值
	//实际编译器背后会用2021构造一个无名对象，最后用无名对象给d1对象进行赋值
}*/
/*
class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)  //先初始化_a2(_a1为随机值)，再初始化_a1（a为1）
	{}
	void display()
	{
		cout << _a1 << " " << _a2 << endl;
	}
private:
	//初始化以此为顺序
	//成员变量声明的地方
	int _a2;
	int _a1;
};
void test()
{
	A aa(1);
	aa.display();
}
int main()
{
	test();
	return 0;
}*/

/*
class A
{
public:
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};
class B
{
public:
	B(int a, int ref)
		:_aobj(a)
		,_ref(ref)
		,_n(10)
	{}
private:
	int _aobj; //自定义成员变量，没有默认构造函数
	int& _ref; //引用
	const int _n; //const
};*/
/*
class Date
{
public:
	//初始化列表
	Date(int year, int month, int day)
		:_year(year) 
		,_month(month)
		,_day(day)
	{}
private:
	int _year;
	int _month;
	int _day;

};*/
/*
class Date
{
public:
	Date(int year, int month, int day) :_year(year), _month(month), _day(day)
	{
		//_year = year;
		//_month = month;
		//_day = day;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

};
class Time {
public:
	Time(int hour = 1, int minute = 1, int second = 1) :_hour(hour), _minute(minute), _second(second)
	{

	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date {
public:
	Date()
		:_time(9, 21, 12){}
private:
	Time _time;
};
void test()
{
	//Date d1(2021, 3, 3);
}
*/
/*
class A
{
public:
	A()
	{
		++_count;
	}
	A(const A& a)
	{
		++_count;
	}
	int getcount()
	{
		return _count;
	}
private:
	static int _count;
};
int A::_count = 0;
A funA(A a)
{
	return a;
}
void test()
{
	A a1;
	A a2;
	A a3 = funA(a1);
	cout << a1.getcount() << endl;
	cout << a2.getcount() << endl;
	cout << a3.getcount() << endl;
}

int main()
{
	test();
	return 0;
}*/