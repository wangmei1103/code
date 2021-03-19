#include<stdio.h>
#include<iostream>
using namespace std;








/*
void test()
{
	int* p = NULL;//预处理，宏替换：int* p=0
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
	//范围for：当前数据：循环的范围
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

inline int add(int a, int b)//定义add为内联函数
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
	//ra是一个引用，是a的别名，指向和a相同的实体。
	int& ra = a;
}
//做参数
void swap(int& a, int& b)//这里的引用是外部变量的别名
{
	int tmp = a;
	a = b;
	b = tmp;
}
//做返回值
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
double add(double a,double b)//类型
{
	return a + b;
}
int add(int a, int b, int c)//参数个数
{
	return a + b + c;
}
int add(int a, double b)
{
	return a + b;
}
int add(double b, int a)//顺序
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


//普通的命名空间
namespace N1
{
	int a = 0;
	void fun1()
	{
		printf("N1:fun1()\n");
	}
	//嵌套
	namespace N2
	{
		int a = 1;
		void fun1()
		{
			printf("N1:N2:fun1()\n");
		}
	}
}
//分段定义
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
	//全局的a
	printf("a: %d\n", a);
	//命名空间中的成员访问形式
	//命名空间+::+成员
	printf("N1::a: %d\n", N1::a);
	//using 命名空间::成员
	using N1::b;
	printf("N1::b %d\n", b);
	//展开命名空间：using namespace 命名空间  
	//不建议，命名空间下所有成员全部暴露在全局作用域中，会和全局域中的成员发生混淆
	using namespace N1;
	fun2();
	printf("N1::b: %d\n", b);
}
int main()
{
	test();
	return 0;
}
//全缺省
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
//半缺省:部分参数设置默认值
//设置的默认值必须从右向左依次连续，中间不能有间隔
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