
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
		return this; //����d�������ֵ
	}
	//��������
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
	int setI(int i) //�ں����ڲ������޸ĳ�Ա������ֵ
	{
		_i = i;
		getI();//��const��Ա�����ڿ��Ե���������const��Ա����
	}
	//const����thisָ�룺thisָ��ָ��Ķ������ݲ��ܱ�
	int getI()const //��ֹ�ں����ڲ��޸ĳ�Ա������ֵ��������ɼ���const�ؼ���
	{
		//setI(10);//const��Ա�����ڲ����Ե��������ķ�const��Ա����
		return _i;
	}
private:
	int _i;
};
void test()
{
	//��const������Ե���const��Ա����
	A a;
	a.setI(10);
	a.getI();
	//const�����ܵ���const��Ա����
	const A b;//b�����ݲ��ܸ�
	//b.setI(10);
	b.getI();
}*/
////constֻ���γ�Ա����
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
	Date(int year = 1900, int month = 1, int day = 1) //�����в����Ĺ��캯��
	{
		_year = year;
		_month = month;
		_day = day;
	}
	~Date(){}  //������������
	//�������캯������ʹ�����ô��Σ��Ҳ���ֻ��һ��
	//ʹ�ô�ֵ��ʽ������������ݹ����
	//�������ʽ���忽�����죬���������Զ����ɿ�������
	Date(const Date& d) //�������죺ͬ���湹�캯����������
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
	//���ÿ������죬����copy�������ݺ�d��ȫ��ͬ
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
	//û����ʽ���幹�캯�����������Զ�����һ���޲ε�Ĭ�Ϲ��캯��
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d;//û�ж��幹�캯��������Ҳ���Դ����ɹ�����˴˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
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
	// 1.�޲ι��캯��
	Date()
	{}

	// 2.���ι��캯��
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
	Date d1;//�����޲ι��캯��
	Date d2(2021, 2, 22);//���ô��εĹ��캯��
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
//class B  //��Ա������ռ����Ŀռ�
//{
//public:
//	int fun1(int a, int b)
//	{
//		return a + b;
//	}
//public:
//	int _a;
//};
//class C  //��������Ա��������С���������Ĵ�С
//{
//public:
//	int fun1(int a, int b)
//	{
//		return a + b;
//	}
//};
//class D  //����  1�ֽ�
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
//	//const����thisָ�룺thisָ��ָ��Ķ������ݲ��ܱ�
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
//	//���壺�ɳ�Ա�����ͳ�Ա�������
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
////��Χfor
//void test()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	//��Χfor����ǰ�����ݣ�ѭ���ķ�Χ
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
	//��Ա����
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
	//��Ա����/����
	char _name[20];
	char _gender[3];
	int _age;
};
*/
//C++�г��õĶ����෽ʽ class  ����  {���г�Ա}��
//class Student
//{
//public:
//	//��Ա����
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
//	//��Ա����
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//void test()
//{
//	Student stu;
//	stu.SetStudentInfo("acd", "��", 30);
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