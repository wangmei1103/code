#include<iostream>
using namespace std;
#include<string>
//get?  gety
bool match(string str1, string str2)
{
	int j = 0;
	int i = 0;
	if (str1[j] != str2[i] && (str1[j] != '?' &&  str1[j] != '*'))
	{
		return false;
	}
	if (str1[j] == '?')
	{
		j++;
		i++;
	}
	else if (str1[j] == '*')
	{
		if (str1[j + 1] == str2[i] || str1[j + 1] == str2[i + 1] || str1[j] == str2[i + 1])
		{
			i++;
			j++;
		}
	}
	else if (str1[j] == str2[i])
	{
		i++;
		j++;
	}
	return true;
}
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	match(str1, str2);
	cout << match(str1, str2) << endl;
	return 0;
}

//int count(int month)
//{
//	if (month == 1)
//		return 1;
//	if (month == 2)
//		return 1;
//	if (month > 2)
//		return count(month - 1) + count(month - 2);
//}
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		int ret = count(month);
//		cout << ret << endl;
//	}
//	return 0;
//}

//int f(int n)
//{
//	static int i = 1;
//	if(n>=5)
//		return n;
//	n = n + i; i++;
//	return f(n);
//}
//int main()
//{
//	int n = 1;
//	cout << f(n);
//	return 0;
//}

//#define N 9
//void fun(int a[], int n)
//{

//	int i, j, max, min, px, pn, t;
//	for (i = 0; i < n - 1; i += 2)
//	{
//		max = min = a[i];
//		px = pn = i;
//		for (j = i + 1; j < n; j++)
//		{
//			if (max < a[j])
//			{
//				max = a[j];
//				px = j;
//			}
//			if (min > a[j])
//			{
//				min = a[j];
//				pn = j;
//			}
//		}
//		if (pn != i)
//		{
//			t = a[i];
//			a[i] = min;
//			a[pn] = t;
//			if (px == i)
//				px = pn;
//		}
//		if (px != i + 1)
//		{
//			t = a[i + 1];
//			a[i + 1] = max;
//			a[px] = t;
//		}
//	}
//}
//int main()
//{
//	int b[N] = { 9,1,4,2,3,6,5,8,7 };
//	for (int i = 0; i < N; i++)
//	{
//		cout << b[i];
//	}
//	cout << endl;
//	fun(b, N);
//	for (int i = 0; i < N; i++)
//	{
//		cout << b[i];
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	char a[] = "programing", b[] = "language";
//	char *p1, *p2;
//	p1 = a, p2 = b;
//	for (int i = 0; i < 7; i++)
//	{
//		if (*(p1 + i) == *(p2 + i))
//			printf("%c", *(p1 + i));
//	}
//	return 0;
//}