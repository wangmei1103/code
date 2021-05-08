#include<iostream>
using namespace std;
#include<cmath>

bool prime(int n)
{
	int a = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			a++;
		}
	}
	if (a == 0)
		return true;
	return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int mid = n / 2;
		for (int i = mid; i < n; i++)
		{
			if (prime(i) == 1)
			{
				for (int j = mid; j > 0; j--)
				{
					if (prime(j) == 1 && i + j == n)
					{
						cout << j << endl;
						cout << i << endl;
						i = n;
						break;
					}
				}
			}
		}
	}
	return 0;
}


//int binInsert(int n, int m, int j, int i)
//{
//	int m1 = m << j;
//	int ret = n | m1;
//	cout <<ret <<endl;
//	return ret;
//}
//int main()
//{
//	int n, m, j, i;
//	cin >> n >> m >> j >> i;
//	binInsert(n, m, j, i);
//	return 0;
//}


//int a[2][2] = { {1},2,3 };
//int a[2][2] = { {1},{2} };
//int a[][2] = { 1,2,3,4 };


//#define SQR(A) A*A
//int main()
//{
//	int x = 6, y = 3, z = 2;
//	x /= SQR(y + z) / SQR(y + z);
//	cout << x << endl;
//	return 0;
//}

//int main()
//{
//	int n[][3] = { 10,20,30,40,50,60 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2] << endl;
//	return 0;
//}

//class Base
//{
//public:
//	int Bar(char x)
//	{
//		return (int)(x);
//	}
//	virtual int Bar(int x)
//	{
//		return (2 * x);
//	}
//};
//class Derived : public Base
//{
//public:
//	int Bar(char x)
//	{
//		return (int)(-x);
//	}
//	int Bar(int x)
//	{
//		return (x / 2);
//	}
//};
//int main()
//{
//	Derived obj;
//	Base *pobj = &obj;
//	printf("%d", pobj->Bar((char)(100)));
//	printf(" %d", pobj->Bar(100));
//	return 0;
//}

//struct st_task
//{
//	uint16_t id;
//	uint32_t value;
//	uint64_t timestamp;
//};
//int main()
//{
//	st_task task = {};
//	uint64_t a = 0x00010001;
//	memcpy(&task, &a, sizeof(uint64_t));
//	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
//	return 0;
//}

//class A
//{
//public: 
//	virtual void x()
//	{
//		cout << "A::x" << endl;
//	}
//};
//class B : public A
//{
//public: 
//	void x()
//	{
//		cout << "B::x" << endl;
//	}
//};
//int main()
//{
//	B b;
//	b.x();
//	return 0;
//}

//void fun(const int& v1,const int& v2)
//{
//	cout << v1 << ' ';
//	cout << v2 << ' ';
//}
//int main()
//{
//	int i = 0;
//	fun(++i, i++);
//	return 0;
//}