
#include<iostream>
using namespace std;
class A
{
	//��Ԫ������
	friend class C;
	//�ڲ��࣬������������Ԫ��
	//�����Ԫ�࣬���ڲ����п���ֱ�ӷ����ⲿ���static��Ա
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
//��Ԫ��ϵ�ǵ����
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
		//ֱ�ӷ���ʱ����˽�г�Ա����
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
	//��Ԫ�������������˺������Է��ʵ�ǰ���˽�г�Ա
	//�˺�����һ����ͨ��������ʹ����ĳ�Ա����
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
	//��д��ʽ
	cout << d;
	//������ʽ
	operator<<(cout, d);
	//�������
	cout << d << endl;
	operator<<(cout, d) << endl;

	Date d1(2021, 3, 8);
	//����
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
	//static��Ա����������thisָ��
	static int getcount()
	{
		//fun();//��̬��Ա���������Ե��÷Ǿ�̬��Ա������ȱ��thisָ��
		return _count;
	}
	//��ͨ��Ա��������thisָ��
	void fun()
	{
		this->getcount();//�Ǿ�̬��Ա�������Ե�����ľ�̬��Ա����
		cout << "fun" << endl;
	}
//private:
	//static��Ա�����ж�����
	//static��Ա�����������������ʼ��
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
	//static��Ա�ķ�����ʽ
	//1.����.static��Ա
	cout << a1._count << endl;
	//2.����+::+static��Ա
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
	//d1 = 2021; //��explicit���ι��캯���������ֹ���ι��캯������ʽת��
	//����explicit���εĹ��캯�����������һ�����ͱ������������Ͷ���ֵ
	//ʵ�ʱ������������2021����һ������������������������d1������и�ֵ
}*/
/*
class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)  //�ȳ�ʼ��_a2(_a1Ϊ���ֵ)���ٳ�ʼ��_a1��aΪ1��
	{}
	void display()
	{
		cout << _a1 << " " << _a2 << endl;
	}
private:
	//��ʼ���Դ�Ϊ˳��
	//��Ա���������ĵط�
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
	int _aobj; //�Զ����Ա������û��Ĭ�Ϲ��캯��
	int& _ref; //����
	const int _n; //const
};*/
/*
class Date
{
public:
	//��ʼ���б�
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