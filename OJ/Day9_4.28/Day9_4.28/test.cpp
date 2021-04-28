#include<iostream>
using namespace std;
#include<vector>

int chess1(int n, int m)
{
	vector<int> v;
	v.resize(m + 1, 1);
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			v[j] += v[j - 1];
		}
	}
	return v[m];
}
int chess(int n, int m)
{
	if (n == 0 || m == 0)
	{
		return 1;
	}
	return chess(n - 1, m) + chess(n, m - 1);
}
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	int ret;
	ret = chess(n, m);
	cout << ret << endl;
	return 0;
}


//class Myclass
//{
//public:
//	Myclass(int i = 0)
//	{
//		cout << 1;
//	}
//	Myclass(const Myclass& x)
//	{
//		cout << 2;
//	}
//	Myclass& operator=(const Myclass& x)
//	{
//		cout << 3; 
//		return *this;
//	}
//	~Myclass()
//	{
//		cout << 4;
//	}
//};
//int main()
//{
//	Myclass obj1(1), obj2(2), obj3(obj1);
//	return 0;
//}

//void Func(int &val);
//int main()
//{
//	int a[] = { 0 };
//	Func(*a);
//	return 0;
//}

//int fun(int a)
//{
//	a ^= (1 << 5) - 1;
//	cout << a << endl;
//	return a;
//}
//int main()
//{
//	fun(21);
//	return 0;
//}

//int main()
//{
//	int a[2][2][2][2] = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
//	cout << ((((a + 1) + 1) + 1) + 1) << endl;
//	cout << ((a + 1) + 1 + 1 + 1) << endl;
//	cout << (((a + 1) + 1) + 1 + 1) << endl;
//	cout << *(*(*(*(a + 1) + 1) + 1) + 1) << endl;
//	return 0;
//}

//void func(const char **m)
//{
//	++m;
//	cout << *m << endl;
//}
//int main()
//{
//	static const char *a[] = { "morning","afternoon","evening" };
//	const char **p;
//	p = a;
//	func(p);
//	return 0;
//}

//class Test
//{
//public:
//	int a, b;
//	virtual void fun(){}
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	}
//	int getA()
//	{
//		return a;
//	}
//	int getB()
//	{
//		return b;
//	}
//};
//int main()
//{
//	Test obj(5, 10);
//	int * pInt = (int*)&obj;
//	*(pInt + 0) = 100;
//	*(pInt + 1) = 200;
//	cout << "a=" << obj.getA() << endl;
//	cout << "b=" << obj.getB() << endl;
//	return 0;
//}

//int main()
//{
//	int y1, y2, y3, y4, y5;
//	const int const *x1 = &y1;
//	const int* const x2 = &y2;
//	const int *x3 = &y3;
//	int const *x4 = &y4;
//	int *const x5 = &y5;
//	return 0;
//}