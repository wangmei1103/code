#include<iostream>
using namespace std;
#include<string>

//1. 逻辑运算符|| && 
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
//2. 位运算符
void test2()
{
	int i = 3;
	int j = 5;
	int ret = i & j; //转成二进制，有0为0，无0为1
	cout << ret << endl; //0011 & 0101  ->0001  ->1
	ret = i | j; //进行按位或运算，有1为1，无1为0
	cout << ret << endl;  //0011 | 0101 ->0111  ->7
	ret = i ^ j; //进行按位异或，相同为0，相异为1
	cout << ret << endl;  //0011 ^ 0101 ->0110  ->6
	ret = ~i; //取反,符号位不变，数值位取反
	cout << ret << endl; //~0011 -> 0100  ->4
	//左移和右移的位数不能大于数据长度，不能小于0
	ret = i << 2; //左移
	cout << ret << endl; //0011<<2  ->1100  ->12
	ret = j << 2; //右移
	cout << ret << endl; //000101>>2  ->010100  ->20
}

//3. ++、--操作符
void test3()
{
	int i = 0;
	int j = (i++, i++, i++);//逗号表达式，i在遇到每个逗号后，认为本计算单位已经结束
	cout << j << endl; //2

	int n = 0;
	int m = (++n, ++n, ++n); //前置++，
	cout << m << endl; //3

	int x;
	int k = 3;
	x = (++k, k++, k +10); //两次++后k为5，加10结果为15
	cout << x << endl; //15

	int p = 3;
	//p经过三次自加后为6，3个6相加为18
	int ret = (++p) + (++p) + (++p);
	cout << ret << endl; //18
	int ret2 = (p++) + (p++) + (p++);
	cout << ret2 << endl; //18

	/*for (i = 0, printf("first=%d", i); i < 10, printf("seconf=%d", i); i++, printf("third=%d", i))
	{
		printf("Fourth=%d", i);
	}*/

	//贪心法
	int a = 0;
	int b = 1;
	cout << a++ + b << endl; //解析为a后置加加后，加上b

	cout << 2 / (-2) << endl; //-1 除
	cout << 2 % (-2) << endl; //0  取模（余数）
} 

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}