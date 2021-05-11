#include<iostream>
using namespace std;
#include<iterator>
#include<string>
#include<vector>
#include<algorithm>

int getnum(int a[], int pos, long sum, long multi, int n)
{
	int cnt = 0;
	for (int i = pos; i < n; i++)
	{
		sum += a[i];
		multi *= a[i];
		if (sum > multi)
			cnt += 1 + getnum(a, i + 1, sum, multi, n);
		else if (a[i] == 1)
			cnt += getnum(a, i + 1, sum, multi, n);
		else
			break;
		sum = sum - a[i];
		multi = multi / a[i];
		for (; i < n - 1 && a[i] == a[i + 1]; i++);
	}
	return cnt;
}
int main()
{
	int a[] = {0};
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		cout << getnum(a, 0, 0, 1, n);
	}
	return 0;
}


//bool luck(vector<int> a, int n)
//{
//	int add = 0, sum = 1;
//	for (int i = 0; i < n; i++)
//	{
//		add += a[i];
//		sum *= a[i];
//	}
//	if (add > sum)
//		return true;
//	return false;
//}
//int count(vector<int> a, int n)
//{
//	sort(a.begin(), a.end());
//	int ret = 0;
//	for (int j = 0; j < a.size(); j++)
//	{
//		for (int i = 1; i < a.size(); i++) {
//			a[i - 1] = a[i];
//		}
//		a.shrink_to_fit();
//		if (luck(a, n) == 0)
//		{
//			ret = j;
//			break;
//		}
//	}
//	return ret+1;
//}

//int main()
//{
//	int n;
//	
//	cin >> n;
//	vector<int> a(n);
//	for (auto e : a)
//	{
//		cin >> a[e];
//	}
//	int ret = count(a, n);
//	cout << ret << endl;
//	return 0;
//}

//int Param(int year, int month, int day)
//{
//	int days = 0;
//	int monthday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	for (int i = 0; i < month; i++)
//	{
//		days += monthday[i];
//	}
//	days += day;
//	return days;
//}
//
//int main()
//{
//	int year, month, day, ret;
//	while (cin >> year, cin>>month,cin>>day)
//	{
//		ret = Param(year, month, day);
//		if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && (month > 2))
//			ret += 1;
//		cout << ret << endl;
//	}
//	return 0;
//}

/*int main()
{
	unsigned int n = 197;
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	cout << n << endl;
	char d[] = "wang\0miao";
	cout << sizeof(d) << " " << strlen(d) << endl;
	return 0;
}*/
//#pragma warning(disable:4996)
//int main()
//{
//	char ccS1[] = "IPF";
//	char ccS2[] = "NPF";
//	strcpy(ccS1, "N");
//	if (strcmp(ccS1, ccS2) == 0)
//		cout << ccS2;
//	else
//		cout << ccS1;
//	return 0;
//}

//class B
//{
//public:
//	B(int j):i(j)
//	{}
//	virtual ~B(){}
//	void fun1()
//	{
//		i *= 10;
//		fun2();
//	}
//	int getV()
//	{
//		return i;
//	}
//protected:
//	virtual void fun2()
//	{
//		i++;
//	}
//protected:
//	int i;
//};
//class C :public B
//{
//public:
//	C(int j) :B(j){}
//	void fun1()
//	{
//		i *= 100;
//		fun2();
//	}
//protected:
//	void fun2()
//	{
//		i += 2;
//	}
//};
//int main()
//{
//	B *pb = new C(1);
//	pb->fun1();
//	cout << pb->getV() << endl;
//	delete pb;
//	return 0;
//}

//void swap(int *a,int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void perm(int list[], int k, int m)
//{
//	if (k == m)
//	{
//		copy(list, list + m, ostream_iterator<int>(cout, " "));
//		cout << endl;
//		return;
//	}
//	for (int i = k; i <= m; i++)
//	{
//		swap(&list[k], &list[i]);
//		perm(list, k + 1, m);
//		swap(&list[k], &list[i]);
//	}
//}
//int main()
//{
//	int list[] = { 1,2,3,5,4,6,4 };
//	perm(list, 0, sizeof(list) / sizeof(list[0])-1);
//	return 0;
//}
//int main()
//{
//	char str[] = "glad to test something";
//	char *p = str;
//	p++;
//	int *p1 = reinterpret_cast<int *>(p);
//	p1++;
//	p = reinterpret_cast<char *>(p1);
//	printf("result is %s\n", p);
//}

//int main()
//{
//	int a = -25;
//	printf("%x", a);
//	return 0;
//}