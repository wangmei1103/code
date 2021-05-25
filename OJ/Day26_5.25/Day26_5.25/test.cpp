#include<iostream>
using namespace std;

bool test(double n, double r)
{
	double C = 6.28*r;
	if (C >= n)
		return true;
	else
		return false;
}
int main()
{
	double n, r;
	int ret;
	while (cin >> n >> r)
	{
		ret = test(n, r);
		if (ret == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}


//int main()
//{
//	int n;
//	int ret;
//	while (cin >> n)
//	{
//		ret = pow(2,n-1);
//		cout << ret << endl;
//	}
//	return 0;
//}