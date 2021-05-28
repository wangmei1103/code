#include<iostream>
using namespace std;
#include <vector>
using namespace std;

class Solution {
public:
	int getFirstUnFormedNum(vector<int> arr, int len) {
		int sum = 0, min = arr[0];
		for (int i = 0; i < len; ++i)
		{
			sum += arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < len; ++i)
		{
			for (int j = sum; j >= arr[i]; --j)
			{
				if (dp[j - arr[i]] + arr[i] > dp[j])
				{
					dp[j] = dp[j - arr[i]] + arr[i];
				}
			}
		}

		for (int i = min; i <= sum; ++i)
		{
			if (i != dp[i])
				return i;
		}
		return sum + 1;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		Solution s;
		cout << s.getFirstUnFormedNum(a, n) << endl;
	}
	return 0;
}


//int count(double n)
//{
//	int sum = 0;
//	while (n != 1)
//	{
//		sum++;
//		n = n / 2;
//	}
//	return sum;
//}
//int main()
//{
//	double n;
//	while (cin >> n)
//	{
//		if (n == 0)
//			return 0;
//		else if (n == 1)
//			cout << "0" << endl;
//		else
//			cout << count(n) << endl;
//	}
//	return 0;
//}
