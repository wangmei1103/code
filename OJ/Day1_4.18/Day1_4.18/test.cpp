#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str, str2;
	getline(cin, str);
	getline(cin, str2);
	string::iterator it2 = str2.begin();
	while (it2 != str2.end())
	{
		string::iterator it = str.begin();

		 while (it != str.end())
		{
			if (*it == *it2)
			{
				str.erase(it);
			}
			it++;
		}
		++it2;
	} 
	for (auto& e : str)
	{
		cout << e;
	}
	return 0;
}

//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string>
//#include<algorithm>
//void test()
//{
//	int n; //����nΪ����
//	cin >> n;//����n��
//	vector<int> v(3 * n);
//	for (int i = 0; i < n * 3; i++)
//	{
//		cin >> v[i]; //����ˮƽֵ
//	}
//	sort(v.begin(), v.end()); //������ˮƽֵ���򣺴�С����
//
//	long long count = 0;
//	//̰���㷨���ֲ����Ž⣺��������ȡ�ڶ���
//	//���壺����С��n����ȥ������ʣ���2n�����У���С���ȡ��ÿ��һ����ȡ��һ������Ϊ��ˮƽֵ
//	//���磺1 2 3 4 5 8
//	//ȥ��1 2 ��������ʣ�������ȡ��3 5 �������������Ӹ��Ե�ˮƽֵ
//	for (int i = n; i <= (3 * n) - 2; i += 2)
//	{
//		count += v[i]; //ȡ��������ˮƽֵ���
//	}
//	cout << count << endl;
//}
////int main()
////{
////	test();
////	return 0;
////}
//
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