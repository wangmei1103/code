#include<stdio.h>
#include<iostream>
using namespace std;








/*
void test()
{
	int* p = NULL;//Ԥ�������滻��int* p=0
	int* p2 = 0;
}
void test()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//��Χfor����ǰ���ݣ�ѭ���ķ�Χ
	for (int e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}

inline int add(int a, int b)//����addΪ��������
{
	return a + b;
}
void test()
{
	int c = add(1, 2);
}
int main()
{
	test();
	return 0;
}

void test()
{
	int a = 1;
	//ra��һ�����ã���a�ı�����ָ���a��ͬ��ʵ�塣
	int& ra = a;
}
//������
void swap(int& a, int& b)//������������ⲿ�����ı���
{
	int tmp = a;
	a = b;
	b = tmp;
}
//������ֵ
int& count()
{
	static int n = 0;
	n++;
	return n;
}


int add(int a, int b)
{
	return a + b;
}
double add(double a,double b)//����
{
	return a + b;
}
int add(int a, int b, int c)//��������
{
	return a + b + c;
}
int add(int a, double b)
{
	return a + b;
}
int add(double b, int a)//˳��
{
	return a + b;
}
int main()
{
	add(1, 2);
	add(1.2, 2.2);
	add(1, 2, 3);
	add(1, 2.2);
	add(1.2, 2);
	return 0;
}


void test()
{
	int a, b, c, d, e;
	//std::cin >> a;
	//std::cout << a;
	cin >> a >> b >> c >> d >> e;
	cout << a << b << c << d << e << endl;

}
int main()
{
	test();
	return 0;
}


//��ͨ�������ռ�
namespace N1
{
	int a = 0;
	void fun1()
	{
		printf("N1:fun1()\n");
	}
	//Ƕ��
	namespace N2
	{
		int a = 1;
		void fun1()
		{
			printf("N1:N2:fun1()\n");
		}
	}
}
//�ֶζ���
namespace N1
{
	int b = 3;
	void fun2()
	{
		printf("N1:fun2()\n");
	}
}
int a = 10;
void fun1()
{
	printf("fun1()\n");

}
void test()
{
	//ȫ�ֵ�a
	printf("a: %d\n", a);
	//�����ռ��еĳ�Ա������ʽ
	//�����ռ�+::+��Ա
	printf("N1::a: %d\n", N1::a);
	//using �����ռ�::��Ա
	using N1::b;
	printf("N1::b %d\n", b);
	//չ�������ռ䣺using namespace �����ռ�  
	//�����飬�����ռ������г�Աȫ����¶��ȫ���������У����ȫ�����еĳ�Ա��������
	using namespace N1;
	fun2();
	printf("N1::b: %d\n", b);
}
int main()
{
	test();
	return 0;
}
//ȫȱʡ
void fun1(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}
void test()
{
	fun1();
	fun1(10);
	fun1(10, 20);
	fun1(10, 20, 30);
}*/
//��ȱʡ:���ֲ�������Ĭ��ֵ
//���õ�Ĭ��ֵ����������������������м䲻���м��
void fun2(int a, int b, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}
void test()
{
	fun2(1, 2);
	fun2(1, 2, 4);
}
int main()
{
	test();
	return 0;
}