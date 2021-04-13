#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)

//1. C/C++内存分布
//全局变量 ：数据段（静态区）
int globalVar = 1;
//静态全局变量：数据段（静态区）
static int staticGlobalVar = 1;
void test1()
{
	//静态局部变量 ：数据段（静态区）
	static int staticVar = 1;
	//局部变量（栈）
	int localVar = 1;
	int num1[10] = { 1,2,3,4 };
	char char2[] = "abcd";//abcd在代码段
	int *ptr1 = (int*)malloc(sizeof(int) * 4); //malloc动态开辟的空间（堆）
	int *ptr2 = (int*)calloc(4, sizeof(int)); //calloc动态开辟的空间（堆）
	int *ptr3 = (int*)realloc(ptr2, sizeof(int) * 4); //realloc动态开辟的空间（堆）
	free(ptr1);
	free(ptr3);
}
//栈（堆栈）：非静态局部变量/函数参数/返回值等，栈是向下增长的
//内存映射段：高效的I/O映射方式，用于装载一个共享的动态内存库
//堆：用于程序运行时动态内存分配，堆是向上增长的
//参数在栈空间存放，malloc或new申请的空间为堆区。

//2. 内存分配
struct student
{
	//char* name 只给name这个指针变量本身分配了4个字节，
	//name指针并没有指向一个合法的地址，所以需要为name指针malloc一块空间。
	char* name;
	int score;
}stu, *pstu;
void test2()
{
	//开辟一块内存，并让stu.name指向这块内存空间
	stu.name = (char*)malloc(sizeof(char) * 20);
	//实现字符串的复制过程
	//char * strcpy ( char * destination, const char * source );
	strcpy(stu.name, "Cling");
	stu.score = 99;
	cout << stu.name << stu.score << endl;
	free(stu.name);

	//开辟一块内存空间，并让pstu指向这块内存空间
	pstu = (struct student*)malloc(sizeof(struct student));
	//开辟一块内存空间，并让pstu->name指向这块内存空间
	pstu->name = (char*)malloc(sizeof(char) * 20);
	strcpy(pstu->name, "Cling");
	pstu->score = 99;
	cout << pstu->name << pstu->score << endl;
	free(pstu->name);
	free(pstu);
}

//3. 内存初始化
void test3()
{
	//初始化为一个有效的值
	int i = 10;
	char* p = (char*)malloc(sizeof(char));
	//free(p);
	//cout << i << endl;

	//初始化为0或者NULL
	//int i = 0;
	//char* p = NULL;
	//cout << i << endl;

	//数组初始化
	//int a[10] = { 0 };

	//memset函数初始化
	//void * memset ( void * ptr, int value, size_t num );
	//memset的三个参数：1：要被设置的内存起始地址，2.要被设置的值，3.被设置的内存大小
	//int a[10];
	//memset(a, 0, sizeof(a));
	/*for (auto& e : a)
	{
		a[e] = e;
		cout << a[e] << " ";
	}
	cout << endl;*/
}

//4.内存越界
//防止内存越界，可以使用for循环半开半闭的区间，或者范围for
void test4()
{
	int a[10] = { 0 };
	//for循环
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		cout << a[i] << " ";
	}
	cout << endl;
	//范围for
	for (auto& e : a)
	{
		a[e] = e;
		cout << a[e] << " ";
	}
	cout << endl;
}

//5. 内存释放
//malloc使用次数要和free使用次数相同，
//malloc两次只free一次会造成内存泄漏。
void test5()
{
	char* p = (char*)malloc(100);
	strcpy(p, "hi");
	cout << p << endl;
	free(p);//p所指的内存被释放，但是p所指的地址依然不变
	//释放完内存后，没有把指针置NULL，这个指针就成了野指针，
	p = NULL;
	if (NULL != p)
	{
		//若p不为空，就没有起到防错作用,所以free完之后需要给指针置空
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