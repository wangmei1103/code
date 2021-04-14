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

//9. do��while��for
void test7()
{
	//whileѭ��
	int a = 5;
	while (a)
	{
		cout << a << " ";
		a--;
	}
	cout << "end" << endl;
	//forѭ��+whileѭ��
	//ð������
	//break��ֹ����ѭ����ִ�е�breakʱ��ѭ����ֹ��
	//continue��ֹ����ѭ����ִ�е�continueʱ����ѭ����ֹ��������һ��ѭ����
	int arr[] = { 1,3,5,2,4,7,6,8,0,9 };
	int end = sizeof(arr) / sizeof(arr[0]);
	int flag = 0;
	while (end > 1)
	{
		for (int i = 1; i < end; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				int tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
				flag = 1;
			}
		}
		if (!flag)
			break;
		end--;
	}
	for (auto& e : arr)
	{
		cout << arr[e] << " ";
	}
	cout << endl; //0 1 2 3 4 5 6 7 8 9
	//do whileѭ��
	int m = 0;
	do
	{
		m++;
		cout << m << " ";
	} while (m < 8);
	cout << endl;
}

//10. const
//����ֻ��������һ����������顢ָ�롢������������������ֵ
//���Խ�ʡ�ռ䣬���ⲻ��Ҫ���ڴ���䣬���Ч��
#define M 3 //�곣��
void test8()
{
	//����ֻ�����������в��ɱ���
	//const int MAX = 10;
	//int arr[MAX]; 

	const int N = 5;//��ʱ��δ��N�����ڴ���
	int i = N;//��ʱΪN�����ڴ棬�Ժ��ٷ���
	int j = M;//Ԥ�����ڼ���к��滻�������ڴ�
	int a = N;//û���ڴ����
	int b = M;//�ٽ��к��滻����һ�η����ڴ�

	//����һ�����
	const int c = 1;
	int const d = 1;

	//��������
	const int arr1[10] = { 0 };
	int const arr2[10] = { 0 };

	//����ָ�룺�ͽ�ԭ����˭��������˭
	//const int *p; const����*p��p��ָ�룬*p��ָ��ָ��Ķ��󣬲��ɱ�
	//int const *p; const����*p��p��ָ�룬*p��ָ��ָ��Ķ��󣬲��ɱ�
	//int *const p; const����p��p���ɱ䣬pָ��Ķ���ɱ�
	//const int *const p; ǰһ��const����*p����һ��const����p��ָ��p��pָ��Ķ��󶼲��ɱ�

	//const���κ����Ĳ���
	void Fun(const int i);
	//const���κ����ķ���ֵ
	const int Fun(void);
}

//11. volatile: ���Ա�֤�������ַ���ȶ�����
void test9()
{
	volatile int i = 10;
	int j = i;
	int k = i;
	const volatile int a = 10; //��ȷ�������޶�����ì�ܣ�
	//һ������ͬʱ���Ա�const��volatile���Σ�������������������ֳ������壬��ͬʱ���ܱ���ǰ�������ڳ�����������������޸�
}

//12. extern���������ڱ�������ǰ���Ա�ʾ�������ߺ��������ڱ���ļ���

//13. struct
struct A
{};
//��������: �ṹ������һ��Ԫ��������δ֪��С�����飬�ɶ���һ���䳤�Ľṹ��
struct B
{
	int i = 0;
	int arr[];
};
class C
{};
void test10()
{
	cout << sizeof(A) << endl; //�սṹ��Ĵ�СΪ1
	//sizeof���صĽṹ���С����������������ڴ�
	cout << sizeof(B) << endl; //4
	//�������������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬����
	B *p = (B*)malloc(sizeof(B));
	cout << sizeof(*p) << endl; //4 ��Ϊ����������ʵ��ṹ��û��ʲô��ϵ��ֻ�Ǳ������ṹ���һ����Ա
	free(p);
	cout << sizeof(C) << endl; //1 ����Ĵ�СҲ��1��
	//��ͽṹ�������
	//struct�ĳ�ԱĬ��Ϊpublic��classĬ��Ϊprivate������class����public��protected���ַ�����ʽ
}

//14. union: �����壬��ԱĬ��Ϊpublic
//��union�����е����ݳ�Ա����һ���ռ䣬ͬһʱ��ֻ�ܴ�������һ�����ݳ�Ա�����е����ݳ�Ա������ͬ����ʼ��ַ
union D
{
	char ch;
	int i;
	char *str;
	double d;
	char arr[2];
}*p,u;
void check()
{
	int a[5] = { 1,2,3,4,5 };
	int *ptr1 = (int*)(&a + 1); //&a+1ǿ��ת��������ָ�룬&a��������ָ�����4�����ͱ����������ָ�룬a��ָ����4����һ����ַ
	int *ptr2 = (int*)((int)a + 1); //ָ��a[0]����һ��*ptr2ָ��a[1],
	//ptr1[-1]�൱��*��ptr1-1��
	printf("%x,%x", ptr1[-1], *ptr2); //5 2000000 ���ģʽ
}
void test11()
{
	cout << sizeof(D) << endl; //8  ���ĳ�����double�ͣ�����union�Ĵ�С����8
	//������ķ��ʲ����Ƕ��ĸ������Ĵ�ȡ���Ǵ�union���׵�ַ��ʼ��
	//���ģʽ�������ݵĸ��ֽڴ洢�ڵ͵�ַ�У������ֽڴ洢�ڸߵ�ַ�У��͵�ֵַΪ0
	//С��ģʽ�������ݵĸ��ֽڴ洢�ڸߵ�ַ�У����ֽڴ洢�ڵ͵�ַ�С��͵�ֵַΪ1
	p = &u;
	p->arr[0] = 0x39;
	p->arr[1] = 0x38;
	cout << p->i << endl; //14393 = 16���Ƶ�3839  ���
	check();
}

//15. enum
//ö����#define�������
//��1��#define�곣������Ԥ����׶ν��м��滻��ö�ٳ��������ڱ����ʱ��ȷ����ֵ��
//��2��һ���ڱ������У����Ե���ö�ٳ��������ǲ��ܵ��Ժ곣��
//��3��ö�ٿ���һ�ζ��������صĳ�������#define��һ��ֻ�ܶ���һ��
//enum�������Ϳ��Կ��Ը��������Ÿ�ֵ������ֵ���ӱ�����ֵ���ĸ�������ʼ���μ�1�������û�и�ֵ�����0��ʼ������1.
void test12()
{
	enum Color
	{
		RED = 1,
		YELLOW,
		GREEN,
		BROWN = 8,
		BLACK,
		BLUE
	}colorval;
	cout << "RED:" << RED << " " << "YELLOW:" << YELLOW << " " << "GREEN:" << GREEN << endl;
	cout << "BROWN:" << BROWN << " " << "BLACK:" << BLACK << " " << "BLUE:" << BLUE << endl;
	cout << sizeof(colorval) << endl;//4
}

//16. typedef: ��һ���Ѿ����ڵ���������ȡһ�����������Ƕ���һ���µ���������
typedef struct student
{
	char *name;
	int score;
}Stu_st,*Stu_pst;
void test13()
{
	//���巽ʽ��
	struct student stu1;
	Stu_st stu2;
	struct student *stu3;
	Stu_pst stu4;
	Stu_st *stu5;
}
//#define a int[10];
//typedef int a[10];
//#define a int*[10];
//typedef int* a[10];
//#define *a int[10];
//typedef int(*a)[10];
//#define *a *int[10];
//typedef int* (*a)[10];
//a[10] a[10];
//a[10] a;
//int a[10];
//int a;
//a b[10];
//a b;
//a *b[10];
//a *b;

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test10();
	//test11();
	test12();
	return 0;
}