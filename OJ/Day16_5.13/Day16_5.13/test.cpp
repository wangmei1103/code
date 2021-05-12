#include<iostream>
#include<string>
#include<vector>
using namespace std;
int count(const string &s)
{
	int n = 0, pos = 0;
	while ((pos = s.find(" ", pos)) != string::npos)
	{
		n++;
		pos += 1;
	}
	return ++n;
}

int main()
{
	string s;	//输入的字符串
	string s1, s2;
	getline(cin, s);
	s1 = s.substr(0, s.find('-'));	//左边的牌
	s2 = s.substr(s.find('-') + 1);	//右边的牌
	int n1 = count(s1);				//左边牌的数量
	int n2 = count(s2);				//右边牌的数量
	string POKER = "345678910JQKA2";
	string MAX = "joker JOKER";
	if (s1 == MAX)
		cout << s1 << endl;
	else if (s2 == MAX)
		cout << s2 << endl;
	else if (n1 == n2)
	{
		string f1, f2;
		f1 = s1.substr(0, f1.find(" "));
		cout << f1 << endl;
		f2 = s2.substr(0, f2.find(" "));
		cout << f2 << endl;
		if (POKER.find(f1) > POKER.find(f2))
			cout << s1 << endl;
		else
			cout << s2 << endl;
	}
	else if (4 == n1)
		cout << s1 << endl;
	else if (4 == n2)
		cout << s2 << endl;
	else
		cout << "ERROR" << endl;
	return 0;
}

//bool completeNum(int n)
//{
//	int sum = 0;
//	for (int i = 1; i < n; i++)
//	{
//		if (n%i == 0)
//		{
//			sum += i;
//		}
//	}
//	if (sum == n)
//		return true;
//	return false;
//	
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		for (int i = 1; i < n; i++)
//		{
//			if (completeNum(i) == 1)
//			{
//				count++;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}

//class B
//{
//public:
//	virtual int foo(int x)
//	{
//		return x * 10;
//	}
//	int foo(char x[14])
//	{
//		return sizeof(x) + 10;
//	}
//};
//class D :public B
//{
//	int foo(int x)
//	{
//		return x * 20;
//	}
//	virtual int foo(char x[10])
//	{
//		return sizeof(x) + 20;
//	}
//};
//int main()
//{
//	D st;
//	B *p = &st;
//	char x[10];
//	cout << p->foo(100) + p->foo(x) << endl;
//	return 0;
//}

//struct Test
//{
//	Test(int)
//	{}
//	Test(){}
//	void fun(){
//		cout << "**" << endl;
//	}
//};
//int main()
//{
//	Test a(1);
//	a.fun();
//	Test b();
//	//b.fun();
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	int *p = (int *)(&a);
//	*p = 20;
//	cout << "a=" << a << ",*p=" << *p << endl;
//	return 0;
//}

//class A
//{
//public:
//	void funA()
//	{
//		cout << "FAC" << endl;
//	}
//	virtual void funB()
//	{
//		cout << "FBC" << endl;
//	}
//};
//class B :public A
//{
//public:
//	void funA()
//	{
//		A::funA();
//		cout << "FABC" << endl;
//	}
//	virtual void funB()
//	{
//		cout << "FBBC" << endl;
//	}
//};
//int main()
//{
//	B b;
//	A *pa;
//	pa = &b;
//	A *pa2 = new A;
//	pa->funA();
//	pa->funB();
//	pa2->funA();
//	pa->funB();
//	delete pa2;
//	return 0;
//}

//void print(char *s)
//{
//	if (*s)
//	{
//		print(++s);
//		printf("%c", *s);
//	}
//}
//int main()
//{
//	char str[] = "Geneius";
//	print(str);
//	return 0;
//}