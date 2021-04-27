#include<iostream>
using namespace std;
#include<vector>
#include<string>
bool lexicographically(vector<string> str)
{
	int n = str.size() - 1;
	for (int i = 0; i < n; i++)
	{
		if (str[i] > str[i + 1])
		{
			return false;
		}
		else
			return true;
	}
}
bool length(vector<string> str)
{
	int n = str.size() - 1;
	for (int i = 0; i < n; i++)
	{
		if (str[i].size() > str[i + 1].size())
		{
			return false;
		}
		else
			return true;
	}
}
int main()
{
	int n;
	cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; i++)
	{
		cin.get();
		getline(cin, str[i]);
	}
	if (lexicographically(str) && length(str))
	{
		cout << "both" << endl;
	}
	else if (lexicographically(str) && !length(str))
	{
		cout << "lexicographically" << endl;
	}
	else if (!lexicographically(str) && length(str))
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	return 0;
}

//class A
//{
//public:
//	A()
//		:m_ival(0)
//	{
//		test();
//	}
//	virtual void func()
//	{
//		cout << m_ival << ' ';
//	}
//	void test()
//	{
//		func();
//	}
//public:
//	int m_ival;
//};
//class B : public A
//{
//public:
//	B()
//	{
//		test();
//	}
//	virtual void func()
//	{
//		++m_ival;
//		cout << m_ival << ' ';
//	}
//};
//int main()
//{
//	A* p = new B;
//	p->test();
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	int j = 1;
//	const int * p1;
//	int const *p2 = &i;
//	p2 = &j;
//	int *const p3 = &i;
//	*p3 = 20;
//	//表达式必须是可修改的左值
//	//*p2 = 30;
//	//p3 = &j;
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int *ptr = (int*)(&a + 1);
//	printf("%d", *(ptr - 1));
//	return 0;
//}

//void counting(char a[], int n)
//{
//	int count[26] = {}, i, kind = 0;
//	for (i = 0; i < n; i++)
//	{
//		++count['Z'-a[i]];
//	}
//	for (i = 0; i < 26; i++)
//	{
//		if (++kind > 1)
//			putchar(';');
//		printf("%c=%d", 'Z'-i, count[i]);
//	}
//}
//int main()
//{
//	char a[] = "qhcfoeFUGUjio";
//	int n = sizeof(a) / sizeof(a[0]);
//	counting(a,n);
//	return 0;
//}

//class A {
//	static int n;
//public:
//	A() { n++; }
//	~A() { n--; }
//	static int get_n() { return n; }
//};
//int A::n = 0;
//int main()
//{
//	A *p = new A;
//	delete p;
//	cout << "n=" << A::get_n() << endl;
//	return 0;
//}