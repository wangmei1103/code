#include<iostream>
using namespace std;

class A {
public:
	A(const char *s)
	{
		cout << s << endl;
	}
	~A() {}
};
class B:virtual public A
{
public:
	B(const char *s1, const char *s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};
class C :virtual public A
{
public:
	C(const char *s1,const char *s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};
class D :public B, public C
{
public:
	D(const char *s1, const char *s2, const char *s3, const char *s4)
		:B(s1, s2)
		, C(s1, s3)
		, A(s1)
	{
		cout << s4 << endl;
	}
};
int main()
{
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}

//int main()
//{
//	int(*a)(int);
//	int(*a1)[10];
//	int(*a2[10])(int);
//	int *a3[10];
//	return 0;
//}

//ì³²¨ÄÇÆõÊýÁÐ
//int cnt = 0;
//int fib(int n)
//{
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//	
//}
//int main()
//{
//	fib(8);
//	printf("%d", cnt);
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,3,5,7,9 };
//	int *p = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(p - 1));
//	return 0;
//}