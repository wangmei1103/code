#include<iostream>
using namespace std;
bool fun(int n)
{
	int sum = 0;
	for (int i = 1; n > sum; i = i + 2)
	{
		sum = sum + i;
	}
	return (n == sum);
}
int main()
{
	cout << fun(484) << endl;
	return 0;
}