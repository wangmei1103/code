//#include<iostream>
//using namespace std;
//void result(int n)
//{
//	long long p[21] = { 0 };
//	p[1] = { 0 };
//	p[2] = { 1 };
//	for (int i = 3; i < 21; i++)
//	{
//		p[i] = (i - 1)*(p[i - 2] + p[i - 1]);
//	}
//	cout << p[n] << endl;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		result(n);
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mostlong(vector<int>& v)
{
	vector<int> arr(v.size(), 1);
	int sum = 1;
	for (size_t i = 1; i < v.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
			if (v[i] > v[j])
				arr[i] = max(arr[i], arr[j] + 1);

		sum = max(sum, arr[i]);
	}
	cout << sum << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		mostlong(v);
	}
	return 0;
}