//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		vector<string> a;
//		string tmp;
//		for (int i = 0; i <= str.length(); i++)
//		{
//			if (str[i] != ' ' && str[i] != '\0')
//			{
//				tmp += str[i];
//			}
//			else
//			{
//				a.push_back(tmp);
//				tmp.clear();
//			}
//		}
//		for (int i = a.size() - 1; i >= 0; i--)
//		{
//			cout << a[i] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}


#include<iostream>
using namespace std;
#include<string>
void output(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '_')
		{
			str[i + 1] -= 32;
			str.erase(i, 1);
		}
	}
	cout << str << endl;
}
int main()
{
	string str;
	while (cin >> str)
	{
		output(str);
	}
	return 0;
}