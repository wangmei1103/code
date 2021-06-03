#include<iostream>
#include<string>
#include<vector>
using namespace std;
//int main() 
//{
//	int n;
//	while (cin >> n) 
//	{
//		if (n == 0) 
//		{
//			continue;
//		}
//		getchar();
//		vector<string> str(n);
//		for (int i = 0; i < n; ++i) {
//			getline(cin, str[i]);
//			if (str[i].find(",") != -1 || str[i].find(" ") != -1) {
//				str[i].insert(0, "\"");
//				str[i].insert(str[i].size(), "\"");
//			}
//		}
//		for (int i = 0; i < n; ++i) 
//		{
//			cout << str[i];
//			if (i < n - 1) {
//				cout << ", ";
//			}
//			else 
//			{
//				cout << endl;
//			}
//		}
//	}
//	return 0;
//}

#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long arr[91] = { 0 };
		arr[1] = 1;
		arr[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		cout << arr[n] << endl;
	}
	return 0;
}

//int rabbit(int n)
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 2;
//	if (n > 2)
//		return rabbit(n - 1) + rabbit(n - 2);
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << rabbit(n) << endl;
//	}
//	return 0;
//}