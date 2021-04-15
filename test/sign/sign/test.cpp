#include<iostream>
using namespace std;
#include<string>

//1. Âß¼­ÔËËã·û|| && 
void test1()
{
	int i = 0;
	int j = 0;
	if(++i || ++j)
	{
		cout << i << " " << j << endl; //1 0
	}
	if (++i && ++j)
	{
		cout << i << " " << j << endl; //2 1
	}
}
//2. Î»ÔËËã·û
int main()
{
	test1();
	return 0;
}