#include<iostream>
#include<string> 
using namespace std;
//int a[21][21];
//long long solve(string pre, string post, int n) 
//{
//	long long sum = 1;
//	int num = 0, k = 0, i;
//	pre.erase(pre.begin());
//	post = post.substr(0, post.length() - 1);
//	while (k < pre.length())
//	{
//		for (i = 0; i < post.length(); i++)
//		{
//			if (pre[k] == post[i])
//			{
//				sum *= solve(pre.substr(k, i - k + 1), post.substr(k, i - k + 1), n);
//				num++, k = i + 1;
//				break;
//			}
//		}
//	}
//	sum *= a[num][n];
//	return sum;
//}
//
//int main() 
//{
//	string pre;
//	string post;
//	int i, j, n;
//	a[0][1] = a[1][1] = 1;
//	for (i = 2; i < 21; i++)
//	{
//		for (a[0][i] = 1, j = 1; j <= i; j++)
//		{
//			if (i == j)
//				a[j][i] = 1;
//			else
//				a[j][i] = a[j - 1][i - 1] + a[j][i - 1];
//		}
//	}
//	while (cin >> n >> pre >> post && n)
//	{
//		cout << solve(pre, post, n) << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
long long gcd(long a, long b)
{
	return b == 0 ? abs(a) : gcd(b, a%b);
}
string deduction(long long up1, long long down1)
{
	string s;
	int flag = 0;
	long long gcdvalue = gcd(abs(up1), abs(down1));
	if (up1 == 0)
	{
		s = "0";
		return s;
	}
	if (gcdvalue)
	{
		up1 /= gcdvalue;
		down1 /= gcdvalue;
	}
	if ((up1 > 0 && down1 < 0) || (up1 < 0 && down1>0))
	{
		up1 = (-1)*(abs(up1));
		down1 = abs(down1);
		s += '(';
		s += '-';
		flag = 1;
	}
	if (abs(up1) % abs(down1) == 0)
	{
		string t;
		up1 = abs(up1);
		down1 = abs(down1);
		s += to_string(abs(up1) / abs(down1));
	}
	else if (abs(up1) < abs(down1))
	{
		s += to_string(abs(up1));
		s += '/';
		s += to_string(abs(down1));
	}
	else
	{
		s += to_string(abs(up1 / down1));
		s += ' ';
		s += to_string(abs(up1) % down1);
		s += '/';
		s += to_string(down1);
	}
	if (flag == 1) s += ')';
	return s;
}
int main()
{
	long long up1, down1, up2, down2;
	scanf_s("%lld/%lld %lld/%lld", &up1, &down1, &up2, &down2);
	cout << deduction(up1, down1) << " + " << deduction(up2, down2) << " = " << deduction(up1*down2 + up2 * down1, down1*down2) << endl;
	cout << deduction(up1, down1) << " - " << deduction(up2, down2) << " = " << deduction(up1*down2 - up2 * down1, down1*down2) << endl;
	cout << deduction(up1, down1) << " * " << deduction(up2, down2) << " = " << deduction(up1*up2, down1*down2) << endl;
	cout << deduction(up1, down1) << " / " << deduction(up2, down2) << " = ";
	if (up2 != 0 && down2 != 0) cout << deduction(up1*down2, down1*up2) << endl;
	else cout << "Inf" << endl;
	return 0;
}
