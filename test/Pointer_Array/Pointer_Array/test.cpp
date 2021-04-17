#include<iostream>
using namespace std;

//int *p; //定义了一个指针p   p称为指针变量，p里存储的内存地址处的内存称为p所指向的内存
//int * 4个字节，同时限定这四个字节里面只能存储某个内存地址，这个内存地址开始的连续4个字节只能存储某个int型的数据
//int main()
//{
//	//int *p = NULL; //p的值为0x00000000，定义一个指针变量p， 其指向的内存里面保存的是int类型的数据，在定义变量p的同时，把p的值设置为0x00000000
//	int i = 10;
//	int *p = &i;
//	*p = NULL; //p指向的内存由原来的10变为0，而p本身的值，即内存地址并没有改变，
//	//*(int*)0x12ff7c = 0x100; //先将地址0x12ff7c强制转换，告诉编译器这个地址上将存储一个int类型的数据然后通过“*”向这个块内存写入一个数据。
//
//	return 0;
//}

void test1()
{
	int a[5] = { 0 };//定义一个数组，初始化为0；
	cout << sizeof(a) << endl; //20
	cout << sizeof(a[0]) << endl; //4
	int arr[5] = { 1,2,3,4,5 };
	int *ptr = (int*)(&arr + 1); //将上一步计算出来的地址，强制转换称int* 类型，赋值给ptr
	//cout << *(a + 1) << " " << *(ptr - 1);
	//*(arr+1)：a是数组元素的首地址，即a[0]的首地址，&a是数组的首地址，a+1是数组下一个元素的首地址，即a[1]的首地址，&a+1是下一个数组的首地址
	//*(ptr-1):因为ptr是指向a[5]，并且ptr是int* 类型，所以*(ptr-1)是指向a[4],输出5.
	printf("%d,%d", *(arr + 1), *(ptr - 1)); //2，5
}

//指针数组和数组指针
void test2()
{
	int *p1[10];//[]优先级比*高，指针数组
	int(*p2)[10];//()优先级比[]高，数组指针
	char a[5] = { 'A','B','C','D' };
	char (*p3)[5] = &a;//&a是整个数组的首地址

	//地址强制转换
	int arr[4] = { 1,2,3,4 };
	int *ptr1 = (int*)(&arr + 1);
	int *ptr2 = (int*)((int)arr + 1);
	printf("%x,%x", ptr1[-1], *ptr2); //4 20000000
}

//二维数组
void test3()
{
	//int a[3][2] = { (0,1),(2,3),(4,5) };//小括号，逗号表达式 相当于int a[3][2]={ 1, 3, 5 };
	int a[3][2] = { {0,1},{2,3},{4,5} }; 
	int *p;
	p = a[0];
	printf("%d", p[0]); 
}

//二级指针
//一级指针保存的是数据的地址，二级指针保存的是一级指针的地址。
void test4()
{
	char **p;//定义了一个二级指针变量，p是一个指针变量
	char *p2;
	p = &p2;
}

//数组参数和指针参数

//一维数组参数
void fun(char a[10])
{
	char c = a[3];
}
void test5()
{
	char b[10] = "abcdefg";
	//fun(b[10]); 错误写法，无法向函数传递一个数组
	//C语言中，当一维数组作为函数参数的时候，编译器总是把它解析成一个指向其首元素首地址的指针。
	//函数的返回值不能是一个数组，只能是指针。
	//函数本身是没有返回值的，只有函数的返回值才有类型。
	fun(b);
}
//一级指针参数
//无法把指针变量本身传递给一个函数
//用return
char* GetMemory(char* p, int num)
{
	p = (char*)malloc(num * sizeof(char));
	return p;
}
void test6()
{
	char *str = NULL;
	str = GetMemory(str, 10);
	strcpy(str, "hello");
	free(str);
}

//函数指针：它是一个指针，指向一个函数
//定义
char* (*fun1)(char* p1, char* p2); //fun1是一个指针变量，指向一个函数，有两个指针类型的参数，函数的返回值是一个指针
char* *fun2(char* p1, char* p2); //fun2是一个指针变量，指向一个函数，有两个指针类型的参数，函数的返回值是char**，是一个二级指针
char* fun3(char* p1, char* p2); //fun3是函数名，p1，p2是参数，其类型是char*型，函数的返回值是char*类型
char* fun(char* p1, char* p2)
{
	int i = 0;
	i = strcmp(p1, p2);
	if (0 == i)
	{
		return p1;
	}
	else
	{
		return p2;
	}
}
void test7()
{
	char* (*pf)(char* p1, char* p2);
	pf = &fun;
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
