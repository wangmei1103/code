#include<iostream>
using namespace std;
#pragma warning (disable:4996)

#include <iostream>
#include <vector>
#include< algorithm>
using namespace std;
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		vector<int> s;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (left[i] * right[i] == 0)
				sum += (left[i] + right[i]);
			else
				s.push_back(left[i] > right[i] ? right[i] : left[i]);
		}
		sort(s.begin(), s.end());
		for (int i = s.size() - 1; i > 0; i--) sum += s[i];
		return sum + 2;
	}
};


////5--101  
//int main()
//{
//	int n;
//	cin >> n;
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n = n / 2;
//	}
//	cout << count << endl;
//	return 0;
//}


//int main()
//{
//	char a[] = "ABCD";
//	char b[] = { 'A','B','C','D' };
//	cout << strlen(a) << " " << strlen(b) << endl;
//	cout << sizeof(a) / sizeof(a[0]) << " " << sizeof(b) / sizeof(b[0]) << endl;
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A" << endl;
//	}
//	A(int a)
//	{
//		cout << "A" << endl;
//	}
//};
//int main()
//{
//	A a();
//	A b(2);
//	A c[3];
//	A &ra = b;
//	A d = b;
//	A *pa = c;
//	A *p = new A(4);
//	return 0;
//}

//static int a = 1;
//void fun1(void)
//{
//	a = 2;
//}
//void fun2(void)
//{
//	int a = 3;
//}
//void fun3(void)
//{
//	static int a = 4;
//}
//int main()
//{
//	cout << a;
//	fun1();
//	cout << a;
//	fun2();
//	cout << a;
//	fun3();
//	cout << a;
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout <<"A ";
//	}
//	~A()
//	{
//		cout << "~A ";
//	}
//};
//class B
//{
//public:
//	B()
//	{
//		cout << "B ";
//	}
//	~B()
//	{
//		cout << "~B ";
//	}
//};
//class C :public A, public B
//{
//public:
//	C()
//	{
//		cout << "C ";
//	}
//	~C()
//	{
//		printf("~C ");
//	}
//};
//int main()
//{
//	A *a = new C();
//	delete a;
//	return 0;
//}
//int FindSubString(char* pch)
//{
//	int count = 0;
//	char *p1 = pch;
//	while (*p1 != '\n')
//	{
//		if (*p1 == p1[1] - 1)
//		{
//			p1++;
//			count++;
//		}
//		else
//			break;
//	}
//	int count2 = count;
//	while (*p1 != '\0')
//	{
//		if (*p1 == p1[1] + 1)
//		{
//			p1++;
//			count2--;
//		}
//		else
//			break;
//	}
//	if (count2 == 0)
//		return (count);
//	return 0;
//}
//void ModifyString(char *pText)
//{
//	char *p1 = pText;
//	char *p2 = p1;
//	while (*p1 != '\0')
//	{
//		int count = FindSubString(p1);
//		if (count > 0)
//		{
//			*p2++ = *p1;
//			sprintf(p2, "%i", count);
//			while (*p2 != '\0')
//			{
//				p2++;
//			}
//			p1 += count + count + 1;
//		}
//		else
//			*p2++ = *p1++;
//	}
//}
//int main()
//{
//	char text[32] = "XYBCDCBABABA";
//	ModifyString(text);
//	printf(text);
//	return 0;
//}
//class A
//{
//public:
//	void f()
//	{
//		printf("A\n");
//	}
//};
//class B : public A
//{
//public:
//	virtual void f()
//	{
//		printf("B\n");
//	}
//};
//int main()
//{
//	A *a = new B;
//	a->f(); //输出了不符合预期的A
//	delete a;
//	return 0;
//}