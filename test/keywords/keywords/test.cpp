#include<iostream>
using namespace std;

//1. ���壺
//����������һ������Ϊ����������һ���ڴ棬��ȡһ�����֣������������������
//һ�����������ֻ����һ���������ڣ������ڡ�ȫ�֣�������һ�Ρ�
//int i;

//2. ������
//���߱�������������Ѿ�ƥ�䵽һ���ڴ����ˣ��������Գ��ֶ��
//extern int i;
//���߱����������������Ԥ���ˣ���ĵط�������������Ϊ���������߶�������
//void fun(int i, char c); 
//��������������𣺶��崴���˶��󣬲�Ϊ������������һ���ڴ棬������û�з����ڴ�

//3. auto
//��������Ĭ��ȱʡ������£����еı�������auto��
//��Χfor�е�Ӧ��
void test1()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//��Χfor����������,���Ա���Խ�����
	for (auto& e : a)
	{
		cout << a[e] << " ";
	}
	cout << endl; //0 1 2 3 4 5 6 7 8 9
}

//4. static
//���α����ͺ���
//����ȫ�ֱ���
//�����򣺴Ӷ��崦���ļ�ĩβ
static int j;
void fun1(void)
{
	//���ξֲ�����
	//�����򣺽����ڱ�������
	static int i = 0;
	i++;
	cout << i << " ";
}
void fun2(void)
{
	j = 0;
	j++;
	cout << j << " ";
}
void test2()
{
	for (int k = 0; k < 10; k++)
	{
		fun1();//1 2 3 4 5 6 7 8 9 10
		fun2();//1 1 1 1 1 1 1 1 1 1
		cout << endl;
	}
}

//5. ��������
void test3()
{
	cout << "short:" << sizeof(short) << endl; //2
	cout << "int:" << sizeof(int) << endl; //4
	cout << "long:" << sizeof(long) << endl; //4
	cout << "float:" << sizeof(float) << endl; //4
	cout << "double:" << sizeof(double) << endl; //8
	cout << "char:" << sizeof(char) << endl; //1
}

//6. sizeof
void fun(int b[100])
{
	cout << sizeof(b) << endl; //4��ֻ��b�������й�
}
void test4()
{
	int i = 0;
	cout << "sizeof(int):" << sizeof(int) << endl; //4
	cout << "sizeof(i):" << sizeof(i) << endl; //4
	int *p = NULL;
	cout << "sizeof(p):" << sizeof(p) << endl; //4
	cout << "sizeof(*p):" << sizeof(*p) << endl; //4
	int a[100];
	cout << "sizeof(a):" << sizeof(a) << endl; //400
	cout << "sizeof(a[100]):" << sizeof(a[100]) << endl; //4
	cout << "sizeod(&a):" << sizeof(&a) << endl; //4
	cout << "sizeof(&a[0]):" << sizeof(&a[0]) << endl; //4
	int b[100];
	fun(b);
}

//7.signed��unsigned
//������Ĭ��Ϊsigned
void test5()
{
	//�����ϵͳ�У���ֵһ���ò������洢��
	//-128��char���������ܴ洢����С������
	//i��������ʱ�ᷢ����������λ���������洢��
	//��i���ӵ�256ʱ����ʼ��һ�ֵ�ѭ��...
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	cout << "a:" << strlen(a) << endl; //255
	int m = -20;
	unsigned int n = 10;
	cout << "m+n: " << m + n << endl; // 4294967286
	
	unsigned k;
	for (k = 9; k > 0; k--)
	{
		cout << k << endl; //9 8 7 6 5 4 3 2 1 
	}
	cout << endl;

	unsigned j;  //j���޷����������ܵ���0��ѭ������ֹͣ
	for (j = 9; j >= 0; j--)
	{
		//cout << j << endl; //ѭ����ӡ 4294967286  
	}
	cout << endl;	
}

//8.switch��case: �����ںܶ��֧
//case����ֻ�������ͻ��ַ��͵ĳ����������ʽ
//default�Ӿ�ֻ���ڼ��������Ĭ�����
void test6()
{
	char grade;
	cin >> grade;
	cout << "score: ";
	switch (grade)
	{
	case 'A':
		cout << "90-100" << endl;
		break;
	case 'B':
		cout << "80-90" << endl;
		break;
	case 'C':
		cout << "60-80" << endl;
		break;
	default:
		cout << "data error!" << endl;
		break;
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}