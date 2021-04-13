#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)

//1. C/C++�ڴ�ֲ�
//ȫ�ֱ��� �����ݶΣ���̬����
int globalVar = 1;
//��̬ȫ�ֱ��������ݶΣ���̬����
static int staticGlobalVar = 1;
void test1()
{
	//��̬�ֲ����� �����ݶΣ���̬����
	static int staticVar = 1;
	//�ֲ�������ջ��
	int localVar = 1;
	int num1[10] = { 1,2,3,4 };
	char char2[] = "abcd";//abcd�ڴ����
	int *ptr1 = (int*)malloc(sizeof(int) * 4); //malloc��̬���ٵĿռ䣨�ѣ�
	int *ptr2 = (int*)calloc(4, sizeof(int)); //calloc��̬���ٵĿռ䣨�ѣ�
	int *ptr3 = (int*)realloc(ptr2, sizeof(int) * 4); //realloc��̬���ٵĿռ䣨�ѣ�
	free(ptr1);
	free(ptr3);
}
//ջ����ջ�����Ǿ�̬�ֲ�����/��������/����ֵ�ȣ�ջ������������
//�ڴ�ӳ��Σ���Ч��I/Oӳ�䷽ʽ������װ��һ������Ķ�̬�ڴ��
//�ѣ����ڳ�������ʱ��̬�ڴ���䣬��������������
//������ջ�ռ��ţ�malloc��new����Ŀռ�Ϊ������

//2. �ڴ����
struct student
{
	//char* name ֻ��name���ָ��������������4���ֽڣ�
	//nameָ�벢û��ָ��һ���Ϸ��ĵ�ַ��������ҪΪnameָ��mallocһ��ռ䡣
	char* name;
	int score;
}stu, *pstu;
void test2()
{
	//����һ���ڴ棬����stu.nameָ������ڴ�ռ�
	stu.name = (char*)malloc(sizeof(char) * 20);
	//ʵ���ַ����ĸ��ƹ���
	//char * strcpy ( char * destination, const char * source );
	strcpy(stu.name, "Cling");
	stu.score = 99;
	cout << stu.name << stu.score << endl;
	free(stu.name);

	//����һ���ڴ�ռ䣬����pstuָ������ڴ�ռ�
	pstu = (struct student*)malloc(sizeof(struct student));
	//����һ���ڴ�ռ䣬����pstu->nameָ������ڴ�ռ�
	pstu->name = (char*)malloc(sizeof(char) * 20);
	strcpy(pstu->name, "Cling");
	pstu->score = 99;
	cout << pstu->name << pstu->score << endl;
	free(pstu->name);
	free(pstu);
}

//3. �ڴ��ʼ��
void test3()
{
	//��ʼ��Ϊһ����Ч��ֵ
	int i = 10;
	char* p = (char*)malloc(sizeof(char));
	//free(p);
	//cout << i << endl;

	//��ʼ��Ϊ0����NULL
	//int i = 0;
	//char* p = NULL;
	//cout << i << endl;

	//�����ʼ��
	//int a[10] = { 0 };

	//memset������ʼ��
	//void * memset ( void * ptr, int value, size_t num );
	//memset������������1��Ҫ�����õ��ڴ���ʼ��ַ��2.Ҫ�����õ�ֵ��3.�����õ��ڴ��С
	//int a[10];
	//memset(a, 0, sizeof(a));
	/*for (auto& e : a)
	{
		a[e] = e;
		cout << a[e] << " ";
	}
	cout << endl;*/
}

//4.�ڴ�Խ��
//��ֹ�ڴ�Խ�磬����ʹ��forѭ���뿪��յ����䣬���߷�Χfor
void test4()
{
	int a[10] = { 0 };
	//forѭ��
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		cout << a[i] << " ";
	}
	cout << endl;
	//��Χfor
	for (auto& e : a)
	{
		a[e] = e;
		cout << a[e] << " ";
	}
	cout << endl;
}

//5. �ڴ��ͷ�
//mallocʹ�ô���Ҫ��freeʹ�ô�����ͬ��
//malloc����ֻfreeһ�λ�����ڴ�й©��
void test5()
{
	char* p = (char*)malloc(100);
	strcpy(p, "hi");
	cout << p << endl;
	free(p);//p��ָ���ڴ汻�ͷţ�����p��ָ�ĵ�ַ��Ȼ����
	//�ͷ����ڴ��û�а�ָ����NULL�����ָ��ͳ���Ұָ�룬
	p = NULL;
	if (NULL != p)
	{
		//��p��Ϊ�գ���û���𵽷�������,����free��֮����Ҫ��ָ���ÿ�
		strcpy(p, "hello");
	}
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}