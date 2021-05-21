#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

int distance(string str1, string str2) 
{
	if (str1.empty() || str2.empty()) 
	{
		return max(str1.size(), str2.size());
	}
	int len1 = str1.size();
	int len2 = str2.size();
	vector<vector<int>>  f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i)
	{
		f[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i) 
	{
		f[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j) 
		{       
			if (str1[i - 1] == str2[j - 1]) 
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else 
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];
}

int main() {
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << distance(str1, str2) << endl;
	}
	return 0;
}


//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		sort(gifts.begin(), gifts.end());
//		int mid = gifts[n / 2];
//		int count = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (gifts[i] == mid)
//			{
//				count++;
//			}
//		}
//		if (count > n / 2)
//			return mid;
//		else
//			return 0;
//	}
//};


//int main()
//{
//	int m = 5;
//	if (m++ > 5)
//		cout << m << endl;
//	else
//		cout << --m;
//	return 0;
//}

//struct Data
//{
//	char a;
//	int b;
//	int64_t c;
//	char d;
//};
//int main()
//{
//	Data data[2][10];
//	cout << sizeof(Data) << endl;
//	printf("%p", data[1][5].c);
//	return 0;
//}