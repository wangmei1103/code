#include<iostream>
using namespace std;
#include<string>

#include <deque>



void getPos(deque<int> s, int count)
{
	count = count - 1;
	s.push_front(0);
	s.push_front(0);
	s.push_back(0);
	s.push_back(0);
	deque<int> temp;
	for (int i = 1; i < static_cast<int>(s.size()) - 1; i++)
	{
		int t = s.at(i - 1) + s.at(i) + s.at(i + 1);
		if (count <= 0)
		{
			if (t % 2 == 0)
			{
				cout << i << endl;
				return;
			}
		}
		temp.push_back(t);
	}
	if (count <= 0)
	{
		cout << -1 << endl;
		return;
	}
	s.clear();
	s.insert(s.begin(), temp.begin(), temp.end());
	temp.clear();
	getPos(s, count);
}

int main()
{
	deque<int> s;
	s.push_back(1);
	int n;
	while (cin >> n)
	{
		if (n == 1)
			cout << -1;
		else
		{
			--n;
			getPos(s, n);
		}
	}
	return 0;
}

//string add(string str1, string str2)
//{
//	//reverse(str1.begin(), str1.end());
//	//reverse(str2.begin(), str2.end());
//	string str;
//	int cur = 0;
//	int m = str1.size() - 1;
//	int n = str2.size() - 1;
//	while (m >= 0 || n >= 0)
//	{
//		if (m >= 0)
//		{
//			cur += (str1[m] - '0');
//		}
//		if (n >= 0)
//		{
//			cur += (str2[n] - '0');
//		}
//		str += (char)(cur % 10 + '0');
//		cur /= 10;
//		m--;
//		n--;
//	}
//	if (cur == 1)
//	{
//		str += '1';
//	}
//	return str;
//}
//int main()
//{
//	string str1, str2;
//	while (getline(cin, str1), getline(cin, str2))
//	{
//		string str = add(str1, str2);
//		string::reverse_iterator it = str.rbegin();
//		while (it != str.rend())
//		{
//			cout << *it;
//			++it;
//		}
//		cout << endl;
//	}
//	add(str1, str2);
//	return 0;
//}


//class A
//{
//public:
//	~A()
//	{
//		cout << "~A()";
//	}
//};
//class B
//{
//public:
//	virtual ~B()
//	{
//		cout << "~B()";
//	}
//};
//class C :public A, public B
//{
//public:
//	~C() {
//		cout << "~C()";
//	}
//};
//int main()
//{
//	C *c = new C;
//	B *b1 = dynamic_cast<B *> (c);
//	A *a2 = dynamic_cast<A *> (b1);
//	delete a2;
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int *p[] = { a,a + 1,a + 2,a + 3 };
//	int **q = p;
//	cout << (*(p[0] + 1) + **(q + 2)) << endl;
//	return 0;
//}

//int main()
//{
//	const char *p = "abc";
//	const char *q = "abc123";
//	while (*p == *q)
//	{
//		printf("%c %c", *p, *q);
//	}
//	return 0;
//}

//class A
//{
//public:
//	A(){}
//};
//void foo()
//{
//	throw new A;
//}
//int main()
//{
//	catch (A *x);
//	return 0;
//}

//int main()
//{
//	char* ptr;
//	char str[] = "abcdefg";
//	ptr = str;
//	ptr += 5;
//	printf("%s", ptr);
//	return 0;
//}

//#define M 5
//#define N 20
//int fun(char(*ss)[N], int *n)
//{
//	int  i, k = 0, len = N;
//	for (int i = 0; i < M; i++)
//	{
//		len = strlen(ss[i]);
//		if (i == 0)
//		{
//			*n = len;
//		}
//		if (len < *n)
//		{
//			*n = len;
//			k = i;
//		}
//	}
//	return k;
//}
//int main()
//{
//	char ss[M][N] = { "shanghai","guangzhou","beijing","tianjing","chongqing" };
//	int n, k, i;
//	for (i = 0; i < M; i++)
//	{
//		puts(ss[i]);
//	}
//	k = fun(ss, &n);
//	cout << n << endl;
//	printf("%s", ss[k]);
//	return 0;
//}	

/*class A
{
public:
	A() { p(); }
	virtual void p() { cout << "A"; }
	virtual ~A()
	{
		p();
	}
};
class B : public A
{
public:
	B() { p(); }
	void p() { cout << "B"; }
	~B()
	{
		p();
	}
};
int main()
{
	A* a = new B();
	delete a;
	return 0;
}*/

//int main()
//{
//	long long a = 1, b = 2, c = 3;
//	cout << a << b << c;
//	return 0;
//}
//template<class T>
//struct  sum
//{
//	static void foo(T op1, T op2)
//	{
//		cout << op1 << op2;
//	}
//};
//int main()
//{
//	sum<int>::foo(1, 3);
//	return 0;
//}