//删除公共字符串  https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&tqId=29868&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2F2017test%2Fquestion-ranking&tab=answerKey
//
//#include<iostream>
//using namespace std;
//#include<string>
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int hash[256] = { 0 };
//	for (int i = 0; i < str2.size(); i++)
//	{
//		hash[str2[i]]++;
//	}
//	string ret = "";
//	for (int i = 0; i < str1.size(); i++)
//	{
//		if (hash[str1[i]] == 0)
//		{
//			ret += str1[i];
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}
//
////此答案用例只通过75%
////#include<iostream>
//using namespace std;
//#include<string>
//int main()
//{
//	string str, str2;
//	getline(cin, str);
//	getline(cin, str2);
//	string::iterator it2 = str2.begin();
//	while (it2 != str2.end())
//	{
//		string::iterator it = str.begin();
//
//		 while (it != str.end())
//		{
//			if (*it == *it2)
//			{
//				str.erase(it);
//			}
//			it++;
//		}
//		++it2;
//	} 
//	for (auto& e : str)
//	{
//		cout << e;
//	}
//	return 0;
//}


//组队竞赛  https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//int main()
//{
//	int n;
//	//cin >> n;
//	//循环输入
//	while (cin >> n)
//	{
//		long long sum = 0;
//		vector<int> a;
//		a.resize(3 * n);
//		for (int i = 0; i < 3 * n; i++)
//		{
//			cin >> a[i];
//		}
//		sort(a.begin(), a.end());
//		for (int i = 0; i < n; i++)
//		{
//			sum = sum + a[a.size() - 2 * (i + 1)];
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string>
//#include<algorithm>
//void test()
//{
//	int n; //定义n为组数
//	cin >> n;//输入n，
//	vector<int> v(3 * n);
//	for (int i = 0; i < n * 3; i++)
//	{
//		cin >> v[i]; //输入水平值
//	}
//	sort(v.begin(), v.end()); //给所有水平值排序：从小到大
//
//	long long count = 0;
//	//贪心算法：局部最优解：三个数中取第二个
//	//总体：将最小的n个数去掉，在剩余的2n个数中，从小向大取，每隔一个数取出一个，即为组水平值
//	//例如：1 2 3 4 5 8
//	//去掉1 2 两个数，剩余的数中取出3 5 ，即代表两个队各自的水平值
//	for (int i = n; i <= (3 * n) - 2; i += 2)
//	{
//		count += v[i]; //取出的所有水平值相加
//	}
//	cout << count << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//int main()
//{
//	string str("they are student haha");
//
//	cout << str.size() << endl;
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	double b = 3.14;
//	cout << 'A' + a + b;
//	return 0;
//}