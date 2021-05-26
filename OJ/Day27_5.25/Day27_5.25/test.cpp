#include<iostream>
using namespace std;
bool triangle(int a, int b, int c)
{
	if (a + b > c && abs(a - b) < c)
		return true;
	else
		return false;
}
int main()
{
	int a, b, c;
	int ret;
	while (cin >> a >> b >> c)
	{
		ret = triangle(a, b, c);
		if (ret == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}