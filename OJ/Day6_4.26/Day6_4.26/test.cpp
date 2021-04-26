#include<iostream>
#include<string>
using namespace std;

#include<iostream>
using namespace std;
int Fibonacci(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	//return Fibonacci(n - 2) + Fibonacci(n - 1);
	int fn1 = 1;
	int fn2 = 1;
	int ret = 0;
	for (int i = 3; i <= n; i++)
	{
		ret = fn2 + fn1;
		fn1 = fn2;
		fn2 = ret;
	}
	return ret;
}
int main()
{
	int N;
	int ret;
	cin >> N;
	int min = N;
	if (N <= 21)
	{
		for (int i = 0; i < N + 6; i++)
		{
			ret = abs(Fibonacci(i) - N);
			if (min > ret)
			{
				min = ret;
			}
		}
	}
	else {
		for (int i = 9; i < N / 2; i++)
		{
			ret = abs(Fibonacci(i) - N);
			if (min > ret)
			{
				min = ret;
			}
			else
			{
				break;
			}
		}
	}
	cout << min;
	return 0;
}


//bool chkParenthesis(string A, int n) {
//	if (n % 2 != 0)
//	{
//		return false;
//	}
//	int count = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		if (A[i] == '(')
//		{
//			count++;
//		}
//		if (A[i] == ')')
//		{
//			count--;
//		}
//		if(A[i] != '(' && A[i] != ')')
//		{
//			return false;
//		}
//	}
//	return count == 0;
//}
//int main()
//{
//	string str = "()(())";
//	chkParenthesis(str, 6);
//	return 0;
//}

//int Fibonacci(int n)
//{
//	if (n <= 0)
//	{
//		return 0;
//	}
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	//return Fibonacci(n - 2) + Fibonacci(n - 1);
//	int fn1 = 1;
//	int fn2 = 1;
//	int ret = 0;
//	for (int i = 3; i <= n; i++)
//	{
//		ret = fn2 + fn1;
//		fn1 = fn2;
//		fn2 = ret;
//	}
//	return ret;
//}
//int main()
//{
//	int N;
//	int ret;
//	cin >> N;
//	int min = N;
//	for (int i = 0; i < N + 6; i++)
//	{
//		ret = abs(Fibonacci(i) - N);
//		if (min > ret)
//		{
//			min = ret;
//		}
//		else
//		{
//			break;
//		}
//	}
//	cout << min;
//	return 0;
//}


//template<class T>
//class Big
//{
//	long n;
//public:
//	Big(T i)
//		:n(i){}
//	Big operator+(Big b)
//	{
//		return Big(n + b, n);
//	}
//};
//int main()
//{
//	return 0;
//
//}
//int main()
//{
//	int aa = 4, bb = 5;
//	int a = aa--;
//	int b = a * bb;
//	cout << a << " " << b << endl;
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2, c = 3, d = 0;
//	int m = a;
//	int n = b++;
//	if(m && n)
//	if (b != 2 || c-- != 3)
//	{
//		printf("%d,%d,%d\n", a, b, c);
//	}
//	else
//		printf("%d,%d,%d\n", a, b, c);
//	else
//		printf("%d,%d,%d\n", a, b, c);
//	return 0;
//
//}

//int main()
//{
//	int p[][4] = { {1},{3,2},{4,5,6},{0} };
//	cout << p[1][2] << endl;
//	return 0;
//}
//class parent
//{
//	int i = 0;
//protected:
//	int x;
//public:
//	parent()
//	{
//		x = 0; 
//		i = 0;
//	}
//	void change()
//	{
//		x++; 
//		i++;
//	}
//	void display();
//};
//class son : public parent
//{
//public:
//	void modify();
//};
//void parent::display()
//{
//	cout << "x=" << x << endl;
//}
//void son::modify()
//{
//	x++;
//}
//int main()
//{
//	son A;
//	parent B;
//	A.display();
//	A.change();
//	A.modify();
//	A.display();
//	B.change();
//	B.display();
//	return 0;
//}

//void test()
//{
//	int a = 1, b = 0, c = -1, d = 0;
//	d = ++a || ++b && ++c;
//	cout << d << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

//class A
//{
//	friend long fun(A s)
//	{
//		if (s.x < 3)
//		{
//			return 1;
//		}
//		return s.x + fun(A(s.x - 1));
//	}
//public:
//	A(long a)
//	{
//		x = a--;
//	}
//private:
//	long x;
//};
//int main()
//{
//	int sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		sum += fun(A(i));
//	}
//	cout << sum;
//}