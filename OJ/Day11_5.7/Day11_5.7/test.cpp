#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int k = 0;
		for (k = 0; n != 0; k++)
		{
			n = n & (n << 1);
		}
		cout << k << endl;
	}
	return 0;
}


//int getLCA(int a, int b)
//{
//	int ret;
//	if (a < b)
//	{
//		b = b / 2;
//		while (a != b)
//		{
//			if (b > a)
//			{
//				b = b / 2;
//			}
//			if (a > b)
//			{
//				a = a / 2;
//			}
//			ret = a;
//		}
//	}
//	if (a > b)
//	{
//		a = a / 2;
//		while (a != b)
//		{
//			if (a > b)
//			{
//				a = a / 2;
//			}
//			if (a < b)
//			{
//				b = b / 2;
//			}
//			ret = a;
//		}
//	}
//	if (a == b)
//	{
//		ret = a;
//	}
//	return ret;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int ret = getLCA(a, b);
//	//cout << ret << endl;
//	return 0;
//}

//#pragma pack 4
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//struct B
//{
//	int a;
//	short b;
//	char c;
//	int d;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	return 0;
//}

//class A
//{
//public:
//	void foo()
//	{
//		printf("1");
//	}
//	virtual void fun()
//	{
//		printf("2");
//	}
//};
//class B : public A
//{
//public:
//	void foo()
//	{
//		printf("3");
//	}
//	void fun()
//	{
//		printf("4");
//	}
//};
//int main()
//{
//	A a;
//	B b;
//	A *p = &a;
//	p->foo();
//	p->fun();
//	p = &b;
//	p->foo();
//	p->fun();
//	A *ptr = (A*)&b;
//	ptr->foo();
//	ptr->fun();
//	return 0;
//}

//int foo(int n)
//{
//	if (n < 2)
//		return n;
//	else
//		return 2 * foo(n - 1) + foo(n - 2);
//}
//int main()
//{
//	int n = foo(5);
//	cout << n << endl;
//	return 0;
//}

//class A
//{
//public:
//	virtual void fun(int val = 1)
//	{
//		cout << "A->" << val << endl;
//	}
//	virtual void test()
//	{
//		fun();
//	}
//};
//class B : public A
//{
//public: 
//	void fun(int val = 0)
//	{
//		cout << "B->" << val << endl;
//	}
//};
//int main()
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}

//int main()
//{
//	int x = 3, y = 3;
//	switch (x % 2)
//	{
//	case 1:
//		switch(y)
//		{
//		case 0:cout << "first";
//		case 1:cout << "second"; break;
//		default:
//			cout << "hello";
//		}
//	case 2: cout << "third";
//	}
//	return 0;
//}

//#define N 9
//int x[N];
//
//void dump()
//{
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{
//		printf("%d", x[i]);
//	}
//	printf("\n");
//}
//void swap(int a, int b)
//{
//	int t = x[a];
//	x[a] = x[b];
//	x[b] = t;
//}
////int count = 0;
//int run(int n)
//{
//	int i;
//	int count = 0;
//	if (N - 1 == n)
//	{
//		dump();
//		count++;
//		return count;
//	}
//	for (i = n; i < N; i++)
//	{
//		swap(n, i);
//		run(n + 1);
//		swap(n+1, i);
//	}
//}
//int main()
//{
//	int i;
//	for (i = 0; i < N; i++)
//	{
//		x[i] = i + 1;
//	}
//	int count = run(0);
//	printf("*Total:%d\n", count);
//	return 0;
//}