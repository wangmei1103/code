#include<iostream>
using namespace std;
#include<string>
#include<vector>


int count(string str)
{
	int len = str.length();
	int grade = 0;
	if (len <= 4)
		grade = 5;
	if (len >= 5 && len <= 7)
		grade = 10;
	if (len > 8)
		grade = 25;
	int num = 0;
	int Bletter = 0;
	int Sletter = 0;
	int letter = 0;
	int sign = 0;
	int add = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			Sletter = 1;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			Bletter = 1;
		}
		if (Sletter == 1 && Bletter == 1)
		{
			letter = grade + 25;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			num++;
		}
		if (str[i]<'0' || (str[i] > '9' && str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
		{
			sign++;
		}
		if ((Bletter == 1 || Sletter == 1) && num != 0)
		{
			add = 2;
			if (sign != 0)
			{
				add = 3;
			}
			if (letter != 0)
			{
				add = 5;
			}
		}

	}
	cout << grade << endl;
	if(Sletter == 1 || Bletter == 1)
		grade += 10;
	if (letter != 0)
		grade = letter;
	cout << grade << endl;
	if (num == 0)
		grade += 0;
	if (num == 1)
		grade += 10;
	if (num > 1)
		grade += 20;
	cout << grade << endl;
	if (sign == 0)
		grade += 0;
	if (sign == 1)
		grade += 10;
	if (sign > 1)
		grade += 25;
	cout << grade << endl;
	if (add != 0)
		grade += add;
	cout << grade << endl;
	return grade;
}
int main()
{
	string str;
	cin >> str;
	int ret = count(str);
	if (ret >= 90)
	{
		cout << "VERY_SECURE" << endl;
	}
	if (ret >= 80 && ret < 90)
	{
		cout << "SECURE" << endl;
	}
	if (ret >= 70 && ret < 80)
	{
		cout << "VERY_STRONG" << endl;
	}
	if (ret >= 60 && ret < 70)
	{
		cout << "STRONG" << endl;
	}
	if (ret >= 50 && ret < 60)
	{
		cout << "AVERAGE" << endl;
	}
	if (ret >= 25 && ret < 50)
	{
		cout << "WEAK" << endl;
	}
	if (ret >= 0 && ret < 25)
	{
		cout << "VERY_WEAK" << endl;
	}
	return 0;
}


//bool checkWon(vector<vector<int>> board) {
//	int n = sqrt(board.size());
//	for (int i = 0; i < n; i++)
//	{
//		int count1 = 0;
//		int count2 = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (board[i][j] == 1)
//			{
//				count1++;
//				if (count1 == n)
//				{
//					return true;
//				}
//			}
//			if (board[j][i] == 1)
//			{
//				count2++;
//				if (count2 == n)
//				{
//					return true;
//				}
//			}
//		}
//	}
//	int count3 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if ((i == j || (n - i) == j) && (board[i][j] == 1))
//			{
//				count3++;
//				if (count3 == n)
//				{
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//int main()
//{
//	vector<vector<int>> board;
//	board = { {0,0,1},{1,-1,1},{1,-1,1} };
//	int ret = checkWon(board);
//	cout << ret << endl;
//	return 0;
//}

//template<class T>
//class Foo
//{
//	T tval;
//public:
//	Foo(T t):tval(t)
//	{}
//};
//template<class>
//class FooD :public Foo<T>
//{
//
//};
//int main()
//{
//	FooD<int> d(5);
//	return 0;
//}

//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);
//		cout << x << endl;
//	}
//	return count;
//}
//int main()
//{
//	int ret = func(9999);
//	cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	if (i <= 0)
//	{
//		printf("****\n");
//	}
//	else
//		printf("%%%%\n");
//	return 0;
//}

//struct A
//{
//	void foo()
//	{
//		printf("foo");
//	}
//	virtual void bar()
//	{
//		printf("bar");
//	}
//};
//struct B :A
//{
//	void foo()
//	{
//		printf("_foo");
//	}
//	void bar()
//	{
//		printf("_bar");
//	}
//};
//int main()
//{
//	A *p= new B;
//	p->foo();
//	p->bar();
//	return 0;
//}

//class Printer {
//public:
//	Printer(string name) {
//		cout << name << endl;;
//	}
//};
//class Container
//{
//public:
//	Container():b("b"),a("a"){}
//	Printer a;
//	Printer b;
//};
//int main()
//{
//	Container c;
//	return 0;
//}

//int fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * fun(n + 1);
//}
//int main()
//{
//	int ret;
//	ret = fun(2);
//	cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	char **a[3][4];
//	cout << sizeof(a) << endl;
//	return 0;
//}