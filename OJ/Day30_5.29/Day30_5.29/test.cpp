#include<iostream>
#include<string>
using namespace std;

bool prime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int factor(int n)
{
	int count = 0;
	int m = 0;
	int tmp = 1;
	if (prime(n) == 1)
		return 1;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0 && prime(i) == 1)
		{
			if (m != i)
			{
				m = i;
				count++;
			}
			tmp *= i;
			if (tmp == n)
				return count;
		}
	}
	//return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << factor(n) << endl;
	}
	return 0;
}

//string code(string str)
//{
//	for (int i = 0; i < str.size(); i++)
//	{
//		char ch = str[i];
//		if (ch - 'A' >= 0)
//			ch = ch > 'E' ? (ch - 5) : (ch + 21);
//		str[i] = ch;
//	}
//	return str;
//}
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		cout << code(str) << endl;
//	}
//	return 0;
//}