#include<iostream>
using namespace std;
#include<string>

//1. �߼������|| && 
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
//2. λ�����
void test2()
{
	int i = 3;
	int j = 5;
	int ret = i & j; //ת�ɶ����ƣ���0Ϊ0����0Ϊ1
	cout << ret << endl; //0011 & 0101  ->0001  ->1
	ret = i | j; //���а�λ�����㣬��1Ϊ1����1Ϊ0
	cout << ret << endl;  //0011 | 0101 ->0111  ->7
	ret = i ^ j; //���а�λ�����ͬΪ0������Ϊ1
	cout << ret << endl;  //0011 ^ 0101 ->0110  ->6
	ret = ~i; //ȡ��,����λ���䣬��ֵλȡ��
	cout << ret << endl; //~0011 -> 0100  ->4
	//���ƺ����Ƶ�λ�����ܴ������ݳ��ȣ�����С��0
	ret = i << 2; //����
	cout << ret << endl; //0011<<2  ->1100  ->12
	ret = j << 2; //����
	cout << ret << endl; //000101>>2  ->010100  ->20
}

//3. ++��--������
void test3()
{
	int i = 0;
	int j = (i++, i++, i++);//���ű��ʽ��i������ÿ�����ź���Ϊ�����㵥λ�Ѿ�����
	cout << j << endl; //2

	int n = 0;
	int m = (++n, ++n, ++n); //ǰ��++��
	cout << m << endl; //3

	int x;
	int k = 3;
	x = (++k, k++, k +10); //����++��kΪ5����10���Ϊ15
	cout << x << endl; //15

	int p = 3;
	//p���������ԼӺ�Ϊ6��3��6���Ϊ18
	int ret = (++p) + (++p) + (++p);
	cout << ret << endl; //18
	int ret2 = (p++) + (p++) + (p++);
	cout << ret2 << endl; //18

	/*for (i = 0, printf("first=%d", i); i < 10, printf("seconf=%d", i); i++, printf("third=%d", i))
	{
		printf("Fourth=%d", i);
	}*/

	//̰�ķ�
	int a = 0;
	int b = 1;
	cout << a++ + b << endl; //����Ϊa���üӼӺ󣬼���b

	cout << 2 / (-2) << endl; //-1 ��
	cout << 2 % (-2) << endl; //0  ȡģ��������
} 

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}