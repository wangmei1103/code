#include<iostream>
using namespace std;
#include<string>

//class Solution {
//public:
//	bool NotNumber(char input) {
//		if (input < '0' || input > '9')
//			return true;
//		else
//			return false;
//	}
//	int StrToInt(string str) {
//		int len = str.size();
//		if (!len)
//			return 0;
//		if (str[0] != '+' && str[0] != '-' && NotNumber(str[0]))
//			return 0;
//		int result = 0;
//		int sign = 1;
//		int i = 0;
//		if (str[0] == '-') {
//			sign = -1;
//			i = 1;
//		}
//
//		if (str[0] == '+')
//			i = 1;
//		for (; i < len; i++) {
//			if (NotNumber(str[i]))
//				return 0;
//			result = result * 10 + str[i] - '0';
//		}
//		return result * sign;
//	}
//};
//bool NotNumber(char ch)
//{
//	if (ch < '0' || ch > '9')
//		return true;
//	else
//		return false;
//}
//int StrToInt(string str)
//{
//	int length = str.size();
//	int flag = 1;
//	if (!length)
//	{
//
//		flag = 0;
//		//cout << "0" << endl;
//	}
//	if (str[0] != '+' && str[0] != '-' && NotNumber(str[0]))
//	{
//		flag = 0;
//		//cout << "0" << endl;
//	}
//	int ret = 0;
//	
//	int i = 0;
//	if (str[0] == '+')
//	{
//		flag = 1;
//		i = 1;
//	}
//	if (str[0] == '-')
//	{
//		flag = -1;
//		i = 1;
//	}
//	for (; i < length; i++)
//	{
//		if (NotNumber(str[i]))
//		{
//
//			flag = 0;
//			break;
//		}
//		else
//		{
//			ret = ret * 10 + str[i] - '0';
//		}
//	}
//	cout << ret * flag << endl;
//	return 0;
//}
//
//int main()
//{
//	string str;
//	StrToInt(str);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int W, H;
//	cin >> W >> H;
//	int count = 0;
//	if (W % 4 == 0 || H % 4 == 0)
//	{
//		count = (W * H) / 2;
//	}
//	else {
//		count = (W * H) / 2 + 1;
//	}
//	cout << count << endl;
//	return 0;
//}


//int main()
//{
//	int i = 100;
//	printf("%o\n", i);
//	return 0;
//}

//int f(int n)
//{
//	if (n == 1)
//		return 1;
//	else
//		return (f(n - 1) + n * n*n);
//}
//int main()
//{
//	int s = f(3);
//	cout << s << endl;
//	return 0;
//}

//int main()
//{
//	char a = 0, ch;
//	while((ch=getchar())!='\n')
//	{
//		if (a % 2 != 0 && (ch >= 'a' && ch <= 'z'))
//			ch = ch - 'a' + 'A';
//		a++;
//		putchar(ch);
//	}
//	cout << endl;
//}

struct A
{
	long a1;
	short a2;
	int a3;
	int *a4;
};
int main()
{
	cout << sizeof(A) << endl;
	return 0;
}

//char fun(char x, char y)
//{
//	if (x < y)
//		return x;
//	return y;
//}
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}

//int main()
//{
//	int m = 0123, n = 123; //0123是八进制
//	printf("%o %o\n", m, n); //%o以八进制输出
//	return 0;
//}