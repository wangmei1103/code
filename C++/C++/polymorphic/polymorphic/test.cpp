#include<iostream>
using namespace std;

//��̬������
//1.�Ӷ����л�ȡ���ָ��
//2. ͨ�����ָ���ҵ����
//3.��������ҵ��麯���õ�ַ
//4.ִ���麯����ָ��

//�����̳и�������
//������д���麯������Ӧ����д���麯���Ḳ�ǵ������ж�Ӧ�����ָ��
//���û�д���ڶ����У�������ڴ����


////�����ࣺ�������麯��
////�����಻��ʵ����
//class A
//{
//public:
//	virtual void fun() = 0; //���麯���������ӿ�=0���޺�����
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
//	//A a1;����ʵ����
//	//D a2;
//	B a3;//����ʵ��������д���麯��
//	C a4;
//}
//int main()
//{
//	test();
//	return 0;
//}

//�����࣬��ʾ���಻�ܱ��̳�
//class A1 final
//{};
//class B1 : public A1 //���ܽ�final��������Ϊ����
//{};


//ʵ�ֶ�̬��
//0.ǰ�᣺�̳�
//1.�麯��
//2.�����麯�������ͱ�����ָ�������
//3.�麯����Ҫ����д
//4.һ����ͨ�������ָ������õ���

//class A{};
//class B : public A {};
//class Person
//{
//public:
//	//�麯��
//	virtual void buyTicket()
//	{
//		cout << "ȫ��" << endl;
//	}
//	virtual A* Hongbao()
//	{
//		cout << "һëǮ" << endl;
//		return new A;
//	}
//	//һ�����������������麯����������̬��Ϊ����֤��Դ�������ͷ�
//	virtual ~Person()
//	{
//		cout << "~Person" << endl;
//	}
//	//final�����麯������ʾ���麯�����ܱ�������д
//	virtual void fun()final 
//	{}
//};
//class Student : public Person
//{
//public:
//	//�麯����д��
//	//�������������б�����ֵ�͸����麯����ȫ��ͬ
//	//override����麯���Ƿ���д�˸����ĳһ���麯����ǿ����д
//	//override�����ֽӿڣ�����ֵ���������������б��̳У����̳�ʵ�֣���дʵ��
//	virtual void buyTicket() override
//	{
//		cout << "���" << endl;
//	}
//	//Э�䣺����ֵ���Բ���ͬһ�����ͣ����Ǳ������м̳й�ϵ��ָ���������
//	virtual B* Hongbao()
//	{
//		cout << "100Ԫ" << endl;
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
//	//�޷���дfinal����
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
////��̬��������
//void fun1(Person& rp)
//{
//	rp.Hongbao();
//}
////�Ƕ�̬��������
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