#include<iostream>
#include<string>
using namespace  std;

//���
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
//	string _num = "��AB5678";
//	Tire _t;
//};

//�̳�
//class Car
//{
//protected:
//	string _color = "white";
//	string _num = "��AB5678";
//};
//class BMW : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "�ÿ�-�ٿ�" << endl;
//	}
//};
//class Benz : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "����-����" << endl;
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

////��������̳�
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student :virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher :virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
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


////���μ̳�
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//}; 
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void test()
//{
//	cout << sizeof(Person) << endl;//28
//	cout << sizeof(Student) << endl;//32
//	cout << sizeof(Teacher) << endl;//32
//	cout << sizeof(Assistant) << endl;//92
//	//���μ̳����⣺�������࣬������---ͨ����������̳н��
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	//a._name = "peter";  ��Ա������ռ��һ���ռ�
//	a.Student::_name = "1";
//	a.Teacher::_name = "2";
//
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
//int main()
//{
//	test();
//	return 0;
//}

////�����static��Ա�������̳����У������ж�����
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
//��Ա��ʼ��˳��һ���ȳ�ʼ�������Ա�����ʼ�������Ա
class Person
{
public:
	//���캯��
	//Person(int id=1, int age=16)
	//	:_id(id)
	//	, _age(age)
	//{
	//	cout << "Person(int, int)" << endl;
	//}

	//��ȱʡֵ
	Person(int id, int age)
		:_id(id)
		, _age(age)
	{
		cout << "Person(int, int)" << endl;
	}

	//��������
	Person(const Person& p)
		:_id(p._id)
		,_age(p._age)
	{
		cout << "Person(const Person&)" << endl;
	}

	//��ֵ�����
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

	//��������
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
	//����������ĳ�ʼ���б���ֱ�ӳ�ʼ������ĳ�Ա
	//���������Ĭ�Ϲ��죬��ʼ���б���Բ�����ʽ���ø���Ĺ��캯�������������Զ����ø��๹��
	//�������û��Ĭ�Ϲ��죬������ʽ���ø����һ�����캯��
	//Student(int id,int age,int stuId)
	//	:_stuId(stuId)
	//{
	//	Person(id, age);
	//	cout << "Student(int, int, int)" << endl;
	//}

	//������ȱʡֵʱ
	Student(int id, int age, int stuId)
		:Person(id, age)
		, _stuId(stuId)
	{
		cout << "Student(int, int, int)" << endl;
	}
	//��������ĳ�ʼ���б��п��Ե�����ͨ�ĸ��๹�캯��
	//Ҳ���Ե��ÿ�������
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
			//����ĸ�ֵ������ĸ�ֵ���������ͬ�����أ���Ҫ���ϸ���������
			Person::operator=(stu);
			//operator=(stu);�ݹ�����Լ���ͬ�����أ�ֱ��ջ�����ֹͣ
			_id = stu._id;
			_age = stu._age;
			_stuId = stu._stuId;
		}
		cout << "Student& operator=(const Student& stu)" << endl;
		return *this;
	}
	//����
	//���������κ�����£������Զ����ø�������������Բ���Ҫ��ʽ���ø�������
	~Student()
	{
		//~Person();���������͸�����������ͬ�����أ����������ײ�ĺ�������destruct
		//Person::~Person();
		cout << "~Student()" << endl;
	}
	
private:
	int _stuId;
};
void test()
{
	//�����Ĭ�Ϲ�����Զ����ø���Ĺ��캯��
	//�ȸ��������
	//Student stu;
	//Student stu(1, 2, 3);
	//����Ĭ�ϵĿ���������Զ����ø���Ŀ�������
	//���������ʽ�����˿������죬����Ŀ���������Զ����ø����Ĭ�Ϲ���
	//Student copy(stu);
	//��ֵ�������Ĭ�ϸ�ֵ��������Զ����ø���ĸ�ֵ�����
	//���ඨ��ĸ�ֵ����������Զ����ø���ĸ�ֵ�������������ʽ����
	//stu = copy;

	//����������Ĭ�ϵ�����/��ʽ���ö����Զ����ø��������
	//���������
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
//ͬ�����أ������ǳ�Ա�������ǳ�Ա������ֻҪ��Ա������ͬ���ͻṹ��ͬ������
class B :public A
{
public:
	void fun()
	{
		cout << "B::fun()" << endl;
	}
	void printB()
	{
		cout << _a << endl; //��ӡ�¶����_a  100���̳е�_a�����������أ���ͬ������
		cout << A::_a << endl;//ͬ�����صĸ����Ա����������ͨ�����ϸ�������������
	}
private:
	int _a = 100;

};

void test()
{
	B b;
	b.printB();
	//����������У������������ͬ�ĺ������ͻṹ��ͬ������
	//���õ��¶����fun������ͬ����������
	//�����Ҫ���ʸ����ͬ����������Ҫ���ϸ���������
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
//����/����
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
//����̳и���
//�����Ա�������еķ���Ȩ�ޣ����������е�˽�г�Ա����min��ԭ��Ȩ�ޣ��̳з�ʽ��

//�����˽�г�Ա������̳У��������಻�ܷ��ʸ����˽�г�Ա
//class������࣬Ĭ�ϵļ̳з�ʽ��private
//���м̳У����������˽�г�Ա���ɼ��������ĳ�ԱȨ�޲��ᷢ���仯
//class Student : public Person
//�����̳У����������private��Ա���ɼ���public����protected
//class Student : protected Person
//˽�м̳У���������г�Ա�����������private��Ա���ɼ���������Ա�ķ���Ȩ�������ⶼ�ǲ��ᷢ���仯
//class Student : Person
class Student : public Person
{
public:
	void PrintStu()
	{
		//˽�г�Ա_id���ɷ��ʣ�
		//�ܱ�����Ա�������пɼ�
		//cout << _name << _age << _id << endl;
		cout << _name << _age << endl;
	}
//private:
	int _stuid = 20;
};
void test()
{
	//��������������ֵת��
	Student s;
	Person p;
	//��Ƭ�������ڸ���Ĳ��ָ�������
	//����--������
	//����������á�ָ�븳�������Ӧ�Ķ������á�ָ��
	p = s;
	Person& rs = s;
	Person* ps = &s;
	Student& rs2 = s;
	Student* ps2 = (Student*)ps;

	//����--������
	//1. ��������ܸ�ֵ���������Ҳ���ܽ���ǿ������ת��
	//s = p; ��֧��
	//2. �������ã�����ֱ�Ӹ�ֵ����������ã����ǿ���ͨ��ǿ������ת����ֵ
	//�з��գ�����ȫ�����Բ�������ǿ������ת�������ܻ��������Խ�������
	Student& rp = (Student&)rs;
	Student* pp = (Student*)&p;
	int ret = pp->_stuid; //ppΪ���ֵ��
	pp->PrintStu();
}

////structĬ��public�̳�
//struct C :Student
//{
//	void PrintC()
//	{
//		//��Student��˽�м̳У�����Student���Ѿ���Ϊ��˽�г�Ա�����ɼ�
//		//��Student�ǹ��м̳У�����Student�п���ʹ��
//		//cout << _name << _age << endl;
//	}
//};

//class C :public Student
//{
//	void PrintC()
//	{
//		//��Student��˽�м̳У�����Student���Ѿ���Ϊ��˽�г�Ա�����ɼ�
//		//��Student�ǹ��м̳У�����Student�п���ʹ��
//		//cout << _name << _age << endl;
//	}
//};
//void test() 
//{
//	//�����С�͸���һ��
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