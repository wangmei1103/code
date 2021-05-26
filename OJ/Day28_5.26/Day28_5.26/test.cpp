#include<iostream>
using namespace std;
long long Minpeach(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n > 1)
		return pow(5, n) - 4;
}
long long OldmonkeyPeach(int n)
{
	if (n == 1)
		return 1;
	if (n > 1)
		return pow(4, n) + n - 4;
}
int main()
{
	int n;//ºï×Ó
	long long peach, monkeyPeach;
	while (cin >> n)
	{
		peach = Minpeach(n);
		if (peach == 0)
			return 0;
		monkeyPeach = OldmonkeyPeach(n);
		cout << peach << " " << monkeyPeach << endl;
	}
	return 0;
}