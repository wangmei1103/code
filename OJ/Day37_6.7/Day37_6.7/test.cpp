//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>
//
//int main() 
//{
//
//	int n = 0;
//	while (cin >> n) {
//
//		vector<string> vec;
//		vec.resize(n);
//		getchar();
//		int sum = 0;
//		int count = 0;
//
//		//把数据请求读进来
//		for (int i = 0; i < n; ++i) 
//		{
//			getline(cin, vec[i]);
//
//			if (vec[i].find("disconnect", 1) != string::npos)
//			{
//				//断开请求
//				count--;
//			}
//			else 
//			{
//				//连接请求
//				count++;
//				if (count > sum) 
//				{
//					sum = count;
//				}
//			}
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsZi(string s1, string s2)
{
	if (s1[1] == s2[1])
	{
		s2 = s2.substr(0, s1.size());
		if (s1 == s2)
			return true;
	}
	return false;
}
void Mkdir(vector<string> v)
{
	string mk = "mkdir -p ";
	int i = 0;
	while (i < v.size() - 1)
	{
		//前一个是后一个的子串，且后一个子串的下一个位置为 /
		if (IsZi(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/')
			v.erase(v.begin() + i);
		else
			i++;
	}
	for (auto &e : v)
		cout << mk << e << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string s1;
			cin >> s1;
			v.push_back(s1);
		}
		sort(v.begin(), v.end());
		Mkdir(v);
		cout << endl;
	}
	return 0;
}
