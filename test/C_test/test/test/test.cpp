#include<iostream>
using namespace std;

////�˷��ھ���
//void test()
//{
//	int i, j;
//	int ret = 1;
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			ret = i * j;
//			cout << i << "*" << j << "=" << ret << " ";
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}

//�����ֵ
//void test()
//{
//	int a[10] = { 0 };
//	int Max;
//	for (int i = 0; i < 10; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		if (a[i] > a[i + 1])
//		{
//			Max = a[i];
//			a[i + 1] = a[i];
//		}
//		else {
//			Max = a[i + 1];
//		}
//	}
//	cout<<Max<<endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

////��1-1/2+1/3-1/4+1/5-...-1/100��ֵ
//void test()
//{
//	double i = 1;
//	for (int n = 2; n < 100; n += 2)
//	{
//		i = i - (1.0) / (n*(n + 1));
//	}
//	i = i - 1.0 / 100;
//	cout << i << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}

////��1-100֮��9�ĸ���
//void test()
//{
//	int count = 0;
//	for (int i = 1; i < 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

////��ӡ����
//void test()
//{
//	for (int i = 101; i < 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (0 == i % j)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			cout << i << " ";
//		}
//	}
//	cout << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

////��ӡ1000�굽2000��֮�������
//void test()
//{
//	for (int year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0) )|| (year % 400 == 0))
//		{
//			cout<<year<<" ";
//		}
//	}
//	cout << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

////���Լ��
//void test()
//{
//	int a, b;
//	cin >> a >> b;
//	int c = 0;
//	//���磺24 18
//	//6=24 % 18
//	//0=18 % 6
//	//���磺 9 7
//	//2 = 9 % 7
//	//1 = 7 % 2
//	//0 = 2 % 1
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	cout << b << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//��ӡ3�ı�������
//void test()
//{
//	int count = 0;
//
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			cout << i << " ";
//			count++;
//		}
//	}
//	cout << endl;
//	cout << count << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//�������Ӵ�С�������
//void test()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	cout << a << " "<< b << " " << c << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}



//int Max(int a, int b)
//{
//	return a > b ? a : b;
//}
//����������Ľϴ���
//void test()
//{
//	int a, b;
//	cin >> a >> b;
//	int ret = a > b ? a : b;
//	cout << ret << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}