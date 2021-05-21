#include<iostream>
#include<string>
#include<vector>
using namespace std;
char FirstNotRepeatingChar(string str) {
	int hash[256] = { 0 };
	for (auto c : str) {  // 遍历一次，复杂度为O(n) 
		hash[c] ++;
	}
	char ch;
	for (int i = 0; i < str.size(); i++) {
		if (hash[str[i]] == 1) {
			//return i;
			return str[i];
		}
	}
	return '\0'; // if(str.size() == 0) return '\0';
}
int main()
{
	string str;
	while (cin >> str)
	{
		char ret = FirstNotRepeatingChar(str);
		if (ret == '\0')
			cout << "-1" << endl;
		else
			cout << ret << endl;
	}
	return 0;
}



////获取最大公约数
//int GetConventionNum(int b, int c) {
//	int ret = 0;
//	for (int i = 1; i <= b; ++i) {
//		if (b % i == 0 && c % i == 0)
//			ret = i;
//	}
//	return ret;
//}
//
//int main() {
//	int n, a;
//	while (cin >> n >> a) {
//		vector<int> v(n);
//		for (size_t i = 0; i < v.size(); ++i) {
//			cin >> v[i];
//		}
//
//		for (size_t i = 0; i < v.size(); ++i) {
//			if (a > v[i])
//				a += v[i];
//			else
//				a += GetConventionNum(v[i], a);
//		}
//		cout << a << endl;
//	}
//	return 0;
//}
