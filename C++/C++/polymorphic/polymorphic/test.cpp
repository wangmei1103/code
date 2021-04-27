#include<iostream>
using namespace std;

//多态场景：
//1.从对象中获取虚表指针
//2. 通过虚表指针找到虚表
//3.从虚表中找到虚函数得地址
//4.执行虚函数得指令

//子类会继承父类的虚表
//子类重写的虚函数，对应得重写得虚函数会覆盖掉续编中对应得虚表指针
//虚表没有存放在对象中，虚表存放在代码段


////抽象类：包含纯虚函数
////抽象类不能实例化
//class A
//{
//public:
//	virtual void fun() = 0; //纯虚函数：函数接口=0，无函数体
//};
//class B :public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//};
//class C :public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "C::fun()" << endl;
//	}
//};
//class D:public A
//{};
//void test()
//{
//	//A a1;不能实例化
//	//D a2;
//	B a3;//可以实例化，重写了虚函数
//	C a4;
//}
//int main()
//{
//	test();
//	return 0;
//}

//修饰类，表示该类不能被继承
//class A1 final
//{};
//class B1 : public A1 //不能将final类类型作为基类
//{};


//实现多态：
//0.前提：继承
//1.虚函数
//2.调用虚函数的类型必须是指针或引用
//3.虚函数需要被重写
//4.一般是通过父类的指针或引用调用

//class A{};
//class B : public A {};
//class Person
//{
//public:
//	//虚函数
//	virtual void buyTicket()
//	{
//		cout << "全价" << endl;
//	}
//	virtual A* Hongbao()
//	{
//		cout << "一毛钱" << endl;
//		return new A;
//	}
//	//一般把析构函数定义成虚函数，产生多态行为，保证资源被正常释放
//	virtual ~Person()
//	{
//		cout << "~Person" << endl;
//	}
//	//final修饰虚函数，表示该虚函数不能被子类重写
//	virtual void fun()final 
//	{}
//};
//class Student : public Person
//{
//public:
//	//虚函数重写：
//	//函数名，参数列表，返回值和父类虚函数完全相同
//	//override：检查函数是否重写了父类的某一个虚函数，强制重写
//	//override：体现接口（返回值、函数名、参数列表）继承，不继承实现，重写实现
//	virtual void buyTicket() override
//	{
//		cout << "半价" << endl;
//	}
//	//协变：返回值可以不是同一个类型，但是必须是有继承关系的指针或者引用
//	virtual B* Hongbao()
//	{
//		cout << "100元" << endl;
//		return new B;
//	}
//	virtual ~Student()
//	{
//		if (_name)
//		{
//			delete[] _name;
//			cout << "delete[] _name" << endl;
//		}
//		cout << "~Student" << endl;
//	}
//	//无法重写final函数
//	/*virtual void fun()
//	{}*/
//private:
//	char* _name = new char[100];
//};
//
//
//void test()
//{
//	Person* ps = new Student;
//	delete ps;
//	Person* ps2 = new Person;
//	delete ps2;
//}
//int main()
//{
//	test();
//	return 0;
//}

//void fun(Person& rp)
//{
//	rp.buyTicket();
//}
////多态：看对象
//void fun1(Person& rp)
//{
//	rp.Hongbao();
//}
////非多态：看类型
//void fun0(Person rp)
//{
//	rp.buyTicket();
//}
//void test()
//{
//	Person p;
//	Student stu;
//	fun(p);
//	fun(stu);
//	fun1(p);
//	fun1(stu);
//	fun0(p);
//	fun0(stu);
//}
//int main()
//{
//	test();
//	return 0;
//}