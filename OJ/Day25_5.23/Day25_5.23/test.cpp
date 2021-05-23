
#include <iostream>
#include <vector>
using namespace std;

int init(int n)
{
	vector<int>a = { 1, 1 };
	for (int i = 2; i <= n; i++)
	{
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
	return a[n];
}

int main()
{
	int sum, n;
	while (cin >> sum)
	{
		while (sum--)
		{
			cin >> n;
			int tmp = init(n);
			printf("%04d", tmp);
		}
		cout << endl;
	}
	return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int numRoot(int num) 
//{
//	int sum = 0;
//	while (num > 0) 
//	{
//		sum += num % 10;
//		num /= 10;
//	}
//	while (sum > 9)
//	{
//		sum = numRoot(sum);
//	}
//	return sum;
//}
//
//int main()
//{
//	string num;
//	while (cin >> num) 
//	{
//		int sum = 0;
//		for (int i = 0; i < num.size(); ++i) 
//		{
//			sum += num[i] - '0';
//		}
//		cout << numRoot(sum) << endl;;
//	}
//	return 0;
//}
