#include<iostream>
#include<string>
using namespace  std;

//组合
//class Tire 
//{
//protected:
//	string _brand = "Michelin";
//	size_t _size = 17;
//};
//class Car
//{
//protected:
//	string _color = "white";
//	string _num = "陕AB5678";
//	Tire _t;
//};

//继承
//class Car
//{
//protected:
//	string _color = "white";
//	string _num = "陕AB5678";
//};
//class BMW : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "好开-操控" << endl;
//	}
//};
//class Benz : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "好坐-舒适" << endl;
//	}
//};

//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
//{
//public:
//	int _b;
//};
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//void test()
//{
//	D d;
//	d.B::_a = 1;
//	d._b = 2;
//	d.C::_a = 3;
//	d._c = 4;
//	d._d = 5;
//}
//int main()
//{
//	test();
//	return 0;

//}

////菱形虚拟继承
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student :virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher :virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void test()
//{
//	cout << sizeof(Person) << endl;//28
//	cout << sizeof(Student) << endl;//32
//	cout << sizeof(Teacher) << endl;//32
//	cout << sizeof(Assistant) << endl;//92
//	Assistant a;
//	a._name = "peter"; 
//}
//int main()
//{
//	test();
//	return 0;
//}


////菱形继承
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//}; 
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void test()
//{
//	cout << sizeof(Person) << endl;//28
//	cout << sizeof(Student) << endl;//32
//	cout << sizeof(Teacher) << endl;//32
//	cout << sizeof(Assistant) << endl;//92
//	//菱形继承问题：数据冗余，二义性---通过菱形虚拟继承解决
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";  成员混淆，占了一定空间
//	a.Student::_name = "1";
//	a.Teacher::_name = "2";
//
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
//int main()
//{
//	test();
//	return 0;
//}

////基类的static成员在整个继承体中，被所有对象共享
//class A
//{
//public:
//	A()
//	{
//		++_a;
//	}
//public:
//	static int _a;
//};
//int A::_a = 0;
//class B :public A
//{};
//class C :public B
//{};
//void test()
//{
//	A a;
//	B b;
//	C c;
//	cout << a._a << endl;
//	cout << b._a << endl;
//	cout << c._a << endl;
//	cout << &a._a << endl;
//	cout << &b._a << endl;
//	cout << &c._a << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

/*
//成员初始化顺序，一定先初始化父类成员，后初始化子类成员
class Person
{
public:
	//构造函数
	//Person(int id=1, int age=16)
	//	:_id(id)
	//	, _age(age)
	//{
	//	cout << "Person(int, int)" << endl;
	//}

	//无缺省值
	Person(int id, int age)
		:_id(id)
		, _age(age)
	{
		cout << "Person(int, int)" << endl;
	}

	//拷贝构造
	Person(const Person& p)
		:_id(p._id)
		,_age(p._age)
	{
		cout << "Person(const Person&)" << endl;
	}

	//赋值运算符
	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_id = p._id;
			_age = p._age;
		}
		cout << "Person& operator=(const Person& p)" << endl;
		return *this;
	}

	//析构函数
	~Person() {
		cout << "~Person()" << endl;
	}
protected:
	int _id;
	int _age;
};
class Student :public Person
{
public:
	//不能在子类的初始化列表中直接初始化父类的成员
	//如果父类有默认构造，初始化列表可以不用显式调用父类的构造函数，编译器会自动调用父类构造
	//如果父类没有默认构造，必须显式调用父类的一个构造函数
	//Student(int id,int age,int stuId)
	//	:_stuId(stuId)
	//{
	//	Person(id, age);
	//	cout << "Student(int, int, int)" << endl;
	//}

	//父类无缺省值时
	Student(int id, int age, int stuId)
		:Person(id, age)
		, _stuId(stuId)
	{
		cout << "Student(int, int, int)" << endl;
	}
	//拷贝构造的初始化列表中可以调用普通的父类构造函数
	//也可以调用拷贝构造
	Student(const Student& stu)
		:Person(stu)
		,_stuId(stu._stuId)
	{
		cout << "Student(const Student&)" << endl;
	}

	Student& operator=(const Student& stu)
	{
		if (this != &stu)
		{
			//父类的赋值和子类的赋值运算符构成同名隐藏，需要加上父类作用域
			Person::operator=(stu);
			//operator=(stu);递归调用自己，同名隐藏，直到栈溢出才停止
			_id = stu._id;
			_age = stu._age;
			_stuId = stu._stuId;
		}
		cout << "Student& operator=(const Student& stu)" << endl;
		return *this;
	}
	//析构
	//编译器在任何情况下，都会自动调用父类的析构，所以不需要显式调用父类析构
	~Student()
	{
		//~Person();子类析构和父类析构构成同名隐藏，析构函数底层的函数名：destruct
		//Person::~Person();
		cout << "~Student()" << endl;
	}
	
private:
	int _stuId;
};
void test()
{
	//子类的默认构造会自动调用父类的构造函数
	//先父类后子类
	//Student stu;
	//Student stu(1, 2, 3);
	//子类默认的拷贝构造会自动调用父类的拷贝构造
	//如果子类显式定义了拷贝构造，子类的拷贝构造会自动调用父类的默认构造
	//Student copy(stu);
	//赋值：子类的默认赋值运算符会自动调用父类的赋值运算符
	//子类定义的赋值运算符不会自动调用父类的赋值运算符，除非显式调用
	//stu = copy;

	//析构：子类默认的析构/显式调用都会自动调用父类的析构
	//先子类后父类
	Student stu1(1, 2, 3);
}
int main()
{
	test();
	return 0;
}
*/
/*
class A
{
public:
	void fun(int a)
	{
		cout << "A::fun()" << endl;
	}
protected:
	int _a = 1;
};
//同名隐藏：无论是成员变量还是成员函数，只要成员名称相同，就会构成同名隐藏
class B :public A
{
public:
	void fun()
	{
		cout << "B::fun()" << endl;
	}
	void printB()
	{
		cout << _a << endl; //打印新定义的_a  100，继承的_a在子类中隐藏，即同名隐藏
		cout << A::_a << endl;//同名隐藏的父类成员变量，可以通过加上父类的作用域访问
	}
private:
	int _a = 100;

};

void test()
{
	B b;
	b.printB();
	//父类和子类中，如果有名称相同的函数，就会构成同名隐藏
	//调用的新定义的fun函数，同名函数隐藏
	//如果需要访问父类的同名函数，需要加上父类作用域
	b.fun();
	b.A::fun(10);
}
int main()
{
	test();
	return 0;
}
*/
/*
//父类/基类
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter";
	int _age = 18;
private:
	int _id = 201811010212;
};
//子类继承父类
//父类成员在子类中的访问权限（除过父类中的私有成员）：min（原有权限，继承方式）

//父类的私有成员被子类继承，但是子类不能访问父类的私有成员
//class定义的类，默认的继承方式是private
//公有继承：除过父类的私有成员不可见，其他的成员权限不会发生变化
//class Student : public Person
//保护继承：除过父类的private成员不可见，public会变成protected
//class Student : protected Person
//私有继承：父类的所有成员，除过父类的private成员不可见，其他成员的访问权限在类外都是不会发生变化
//class Student : Person
class Student : public Person
{
public:
	void PrintStu()
	{
		//私有成员_id不可访问，
		//受保护成员在子类中可见
		//cout << _name << _age << _id << endl;
		cout << _name << _age << endl;
	}
//private:
	int _stuid = 20;
};
void test()
{
	//基类和派生类对象赋值转换
	Student s;
	Person p;
	//切片：把属于父类的部分赋给子类
	//子类--》父类
	//子类对象、引用、指针赋给父类对应的对象、引用、指针
	p = s;
	Person& rs = s;
	Person* ps = &s;
	Student& rs2 = s;
	Student* ps2 = (Student*)ps;

	//父类--》子类
	//1. 父类对象不能赋值给子类对象，也不能进行强制类型转换
	//s = p; 不支持
	//2. 父类引用，不能直接赋值给子类的引用，但是可以通过强制类型转换赋值
	//有风险，不安全，所以不建议做强制类型转换，可能会产生访问越界的问题
	Student& rp = (Student&)rs;
	Student* pp = (Student*)&p;
	int ret = pp->_stuid; //pp为随机值，
	pp->PrintStu();
}

////struct默认public继承
//struct C :Student
//{
//	void PrintC()
//	{
//		//若Student是私有继承，则在Student中已经成为了私有成员，不可见
//		//若Student是公有继承，则在Student中可以使用
//		//cout << _name << _age << endl;
//	}
//};

//class C :public Student
//{
//	void PrintC()
//	{
//		//若Student是私有继承，则在Student中已经成为了私有成员，不可见
//		//若Student是公有继承，则在Student中可以使用
//		//cout << _name << _age << endl;
//	}
//};
//void test() 
//{
//	//子类大小和父类一样
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	Student stu;
//	//stu._age = 19;
//}
int main()
{
	test();
	return 0;
}*/