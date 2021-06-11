//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>
//#include<algorithm>
//void test(string str1, string str2)
//{
//	int count = 0;
//	vector<vector<int>> v(str1.size() + 1, vector<int>(str2.size() + 1, 0));
//	for (int i = 1; i <= str1.size(); i++)
//	{
//		for (int j = 1; j <= str2.size(); j++)
//		{
//			if (str1[i - 1] == str2[j - 1])
//				v[i][j] = v[i - 1][j - 1] + 1;
//			else
//				v[i][j] = v[i - 1][j] > v[i][j - 1] ? v[i - 1][j] : v[i][j - 1];
//		}
//
//	}
//	count = v[str1.size()][str2.size()];
//	cout << count << endl;
//}
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		test(str1, str2);
//	}
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include<math.h>

int main() 
{
	//根据题中给出的例子，这个字符串只包含小写字母，不然答案就不应该是56了
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2) 
	{
		//只包含小写字母的字符串可以看成26进制的数制
		//将s1和s2补长到len2长度
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));
		vector<int> array;
		for (int i = 0; i < len2; i++) 
		{
			array.push_back(s2[i] - s1[i]);
		}
		int result = 0;
		for (int i = len1; i <= len2; i++) 
		{
			for (int k = 0; k < i; k++)
			{
				result += array[k] * pow(26, i - 1 - k);
			}
		}
		//所有字符串最后都不包含是s2自身，所以最后要减1；
		cout << result - 1 << endl;
	}
	return 0;
}