#include<iostream>
using namespace std;
int main()
{
	long long int arr[81] = { 0 };   //ǰ80λ쳲��������е�����  Ϊ�˲����±�任����1��ʼ����
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= 80; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int begin = 0, end = 0;
	while (cin >> begin >> end) 
	{
		long long int  sum = 0;

		for (int i = begin; i <= end; i++) 
		{   //ѭ����������ͼ���
			sum += arr[i];
		}
		cout << sum << endl;
	}
	return 0;
}

//int breakfast(int n)
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 1;
//	if (n > 2)
//		return breakfast(n - 1) + breakfast(n - 2);
//}
//int main()
//{
//	int day1, day2;
//	while (cin >> day1 >> day2)
//	{
//		long long int ret = 0;
//		for (int i = day1; i <= day2; i++)
//		{
//			ret = ret + breakfast(i);
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<string>
//int count(string str1, string str2)
//{
//	int n = 0;
//	size_t pos = 0;
//	while ((pos = str1.find(str2, pos)) != std::string::npos)
//	{
//		pos += str2.size();
//		n++;
//	}
//	return n;
//}
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		cout << count(str1, str2) << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//int main()
//{
//	std::string s, t;
//	while (std::cin >> s >> t)
//	{
//		int res = 0;
//		size_t pos = 0;
//		//������ s �в��� t ���ɣ�ֱ����Ҳ�Ҳ��� t
//		while ((pos = s.find(t, pos)) != std::string::npos)
//		{
//			pos += t.size(); //����t������ĳ���
//			++res; //����
//		}
//		std::cout << res << std::endl;
//	}
//	return 0;
//}

