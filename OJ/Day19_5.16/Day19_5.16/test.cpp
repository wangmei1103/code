#include<iostream>
using namespace std;
#include<string>

string find(string a, string b)
{
	string str1, str2;
	str1 = a.length() >= b.length() ? b : a;
	str2 = a.length() >= b.length() ? a : b;
	for (int i = str1.length(); i > 0; i--)
	{
		for (int j = 0; j <= str1.length() - i; j++)
		{
			if (str2.find(str1.substr(j, i)) != string::npos)
			{
				return str1.substr(j, i);
			}
		}
	}
	return "";
}

int main()
{
	string a, b;
	string tmp;
	while (getline(cin, a), getline(cin, b))
	{
		tmp = find(a, b);
		for (auto e : tmp)
		{
			cout << e;
			++e;
		}
		cout << endl;
		//cout << find(a, b) << endl;
	}
	return 0;
}

//int change(int n)
//{
//	int ret = n / 3 + n % 3;
//	return ret;
//}
//int main()
//{
//	int n;
//	int ret;
//	
//	while (cin >> n)
//	{
//		int count = 0;
//		ret = change(n);
//		count = n / 3;
//		while (ret >= 3)
//		{
//			count += ret / 3;
//			ret = change(ret);
//		}
//		if (ret == 2)
//		{
//			ret = change(ret + 1);
//			count++;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}

//bool fun(int n)
//{
//	int sum = 0;
//	for (int i = 1; n > sum; i = i + 2)
//	{
//		sum = sum + i;
//	}
//	return (n == sum);
//}
//int main()
//{
//	cout << fun(484) << endl;
//	return 0;
//}