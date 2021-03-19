
//#include<iostream>
//#include<string>
//using namespace std;
//#pragma warning(disable: 4996)
/*
class Date {
public:
	//this:Date* const
	Date* operator&() //&d:d.operator&()
	{
		return this; //返回d对象本身的值
	}
	//构成重载
	//this:const Date* const
	const Date* operator&()const    
	{
		return this; 
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	const Date d;
	const Date* ptr1 = d.operator&();
	const Date* ptr2 = &d;
}*/

/*
class A
{
public:
	int setI(int i) //在函数内部可以修改成员变量的值
	{
		_i = i;
		getI();//非const成员函数内可以调用其他的const成员函数
	}
	//const修饰this指针：this指针指向的对象内容不能变
	int getI()const //防止在函数内部修改成员变量的值，函数后可加上const关键字
	{
		//setI(10);//const成员函数内不可以调用其他的非const成员函数
		return _i;
	}
private:
	int _i;
};
void test()
{
	//非const对象可以调用const成员函数
	A a;
	a.setI(10);
	a.getI();
	//const对象不能调用const成员函数
	const A b;//b的内容不能改
	//b.setI(10);
	b.getI();
}*/
////const只修饰成员函数
//void fun(int a)const
//{
//	a = 100;
//}
/*
class Date
{
public:
	void display()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};*/
/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1) //定义有参数的构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
	~Date(){}  //定义析构函数
	//拷贝构造函数必须使用引用传参，且参数只有一个
	//使用传值方式，会引发无穷递归调用
	//如果不显式定义拷贝构造，编译器会自动生成拷贝构造
	Date(const Date& d) //拷贝构造：同上面构造函数构成重载
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d(2021, 2, 22);
	d.display();
	//调用拷贝构造，创建copy对象，内容和d完全相同
	Date copy(d);
	d.display();
}
int main()
{
	test();
	return 0;
}*/
/*
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d(2021, 2, 2);
}*/

/*
class Date
{
public:
	//没有显式定义构造函数，编译器自动生成一个无参的默认构造函数
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d;//没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
}
int main()
{
	test();
	return 0;
}*/

/*
class Date
{
public:
	// 1.无参构造函数
	Date()
	{}

	// 2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d1;//调用无参构造函数
	Date d2(2021, 2, 22);//调用带参的构造函数
}
int main()
{
	test();
	return 0;
}
*/

//class Date
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	void SetDate(int year, int month, int day)
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void test()
//{
//	Date d1, d2;
//	d1.SetDate(2021, 2, 22);
//	d1.Display();
//	d2.SetDate(2020, 2, 20);
//	d2.Display();
//}

//class A
//{
//public:
//	int _a;
//};
//class B  //成员函数不占对象的空间
//{
//public:
//	int fun1(int a, int b)
//	{
//		return a + b;
//	}
//public:
//	int _a;
//};
//class C  //不包含成员变量，大小类似与空类的大小
//{
//public:
//	int fun1(int a, int b)
//	{
//		return a + b;
//	}
//};
//class D  //空类  1字节
//{
//
//};
//void test()
//{
//	cout << "A: " << sizeof(A) << endl;
//	cout << "B: " << sizeof(B) << endl;
//	cout << "C: " << sizeof(C) << endl;
//	cout << "D: " << sizeof(D) << endl;
//}


//class A {
//public:
//	int setI(int i)
//	{
//		_i = i;
//	}
//	//const修饰this指针：this指针指向的对象内容不能变
//	int getI()const
//	{
//		
//		return _i;
//	}
//private:
//	int _i;
//};
//
//
//class className 
//{
//	//类体：由成员函数和成员变量组成
//};




//inline int add(int a, int b)
//{
//	return a + b;
//}
//
//inline int fun1(int n)
//{
//	for (int i = 1; i < n; ++i)
//		n += i * n / (i + 1) + i * n;
//	return n;
//}
//inline int fun2(int n)
//{
//	if (n <= 1)
//		return 1;
//	return fun2(n - 1)*n;
//}
//void test()
//{
//	int a = add(10, 20);//a=10+20;
//	cout << a << endl;
//	int n = 1000;
//	n = fun1(n);
//}
//
////范围for
//void test()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	//范围for：当前的数据：循环的范围
//	for (const int& e : arr) {
//		cout << e << "";
//	}
//	cout << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

/*
struct Student
{
	//成员函数
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	//成员变量/属性
	char _name[20];
	char _gender[3];
	int _age;
};
*/
//C++中常用的定义类方式 class  类名  {所有成员}；
//class Student
//{
//public:
//	//成员函数
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	//成员变量
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//void test()
//{
//	Student stu;
//	stu.SetStudentInfo("acd", "男", 30);
//	stu.PrintStudentInfo();
//	cout << stu._gender << endl;
//}
/*
class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		_y = y;
		_m = m;
		_d = d;
	}
	bool isEqual(const Date& d)
	{
		return _y == d._y && _m == d._m && _d == d._d;
	}
	bool  operator==(const Date& d)
	{
		return _y == d._y && _m == d._m && _d == d._d;
	}

private:
	int _y;
	int _m;
	int _d;
};
void test()
{
	Date d1(2020, 12, 17);
	Date d2(2020, 12, 18);
	if (d1 == d2)
	{
		cout << "==" << endl;
	}
	else {
		cout << "!=" << endl;
	}
}
int main()
{
	test();
	return 0;
}*/