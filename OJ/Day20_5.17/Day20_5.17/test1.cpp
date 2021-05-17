#include<iostream>
#include<string>
using namespace std;

string find(string a, string b)
{
	string str1, str2;
	str1 = a.length() >= b.length() ? b : a;
	str2 = a.length() >= b.length() ? a : b;
	int ret = 0;
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
	while (cin >> a >> b)
	{
		tmp = find(a, b);

		cout << tmp.length() << endl;
	}
	return 0;
}

//void reverse(string str)
//{
//	string tmp;
//	string::reverse_iterator rit = str.rbegin();
//	while (rit != str.rend())
//	{
//		cout << *rit;
//		++rit;
//	}
//	cout << endl;
//}
//int main()
//{
//	string str, tmp;
//	while (cin >> str)
//	{
//		reverse(str);
//	}
//	return 0;
//}