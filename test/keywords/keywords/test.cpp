#include<iostream>
using namespace std;

//1. 定义：
//编译器创建一个对象，为这个对象分配一块内存，并取一个名字（即变量名或对象名）
//一个变量或对象只能在一定的区域内（函数内、全局）被定义一次。
//int i;

//2. 声明：
//告诉编译器这个名字已经匹配到一块内存上了，声明可以出现多次
//extern int i;
//告诉编译器这个名字我先预定了，别的地方不能再用它作为变量名或者对象名。
//void fun(int i, char c); 
//定义和声明的区别：定义创建了对象，并为这个对象分配了一块内存，声明并没有分配内存

//3. auto
//编译器在默认缺省的情况下，所有的变量都是auto的
//范围for中的应用
void test1()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//范围for：遍历数组,可以避免越界访问
	for (auto& e : a)
	{
		cout << a[e] << " ";
	}
	cout << endl; //0 1 2 3 4 5 6 7 8 9
}

//4. static
//修饰变量和函数
//修饰全局变量
//作用域：从定义处到文件末尾
static int j;
void fun1(void)
{
	//修饰局部变量
	//作用域：仅限于本函数体
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

//5. 数据类型
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
	cout << sizeof(b) << endl; //4，只与b的类型有关
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

//7.signed、unsigned
//编译器默认为signed
void test5()
{
	//计算机系统中，数值一律用补码来存储，
	//-128是char类型数据能存储的最小负数，
	//i继续增加时会发生溢出，最高位别丢弃继续存储，
	//当i增加到256时，开始新一轮的循环...
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

	unsigned j;  //j是无符号数，不能等于0，循环不能停止
	for (j = 9; j >= 0; j--)
	{
		//cout << j << endl; //循环打印 4294967286  
	}
	cout << endl;	
}

//8.switch、case: 适用于很多分支
//case后面只能是整型或字符型的常量或常量表达式
//default子句只用于检查真正的默认情况
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

//9. do、while、for
void test7()
{
	//while循环
	int a = 5;
	while (a)
	{
		cout << a << " ";
		a--;
	}
	cout << "end" << endl;
	//for循环+while循环
	//冒泡排序
	//break终止本层循环，执行到break时，循环终止。
	//continue终止本轮循环，执行到continue时本轮循环终止，进入下一轮循环。
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
	//do while循环
	int m = 0;
	do
	{
		m++;
		cout << m << " ";
	} while (m < 8);
	cout << endl;
}

//10. const
//修饰只读变量、一般变量、数组、指针、函数参数、函数返回值
//可以节省空间，避免不必要的内存分配，提高效率
#define M 3 //宏常量
void test8()
{
	//修饰只读变量，具有不可变性
	//const int MAX = 10;
	//int arr[MAX]; 

	const int N = 5;//此时并未将N放入内存中
	int i = N;//此时为N分配内存，以后不再分配
	int j = M;//预编译期间进行宏替换，分配内存
	int a = N;//没有内存分配
	int b = M;//再进行宏替换，又一次分配内存

	//修饰一般变量
	const int c = 1;
	int const d = 1;

	//修饰数组
	const int arr1[10] = { 0 };
	int const arr2[10] = { 0 };

	//修饰指针：就近原则，离谁近就修饰谁
	//const int *p; const修饰*p，p是指针，*p是指针指向的对象，不可变
	//int const *p; const修饰*p，p是指针，*p是指针指向的对象，不可变
	//int *const p; const修饰p，p不可变，p指向的对象可变
	//const int *const p; 前一个const修饰*p，后一个const修饰p，指针p和p指向的对象都不可变

	//const修饰函数的参数
	void Fun(const int i);
	//const修饰函数的返回值
	const int Fun(void);
}

//11. volatile: 可以保证对特殊地址的稳定访问
void test9()
{
	volatile int i = 10;
	int j = i;
	int k = i;
	const volatile int a = 10; //正确，类型限定符不矛盾，
	//一个对象同时可以被const和volatile修饰，表明这个常量对象体现常量语义，但同时可能被当前对象所在程序上下文意外情况修改
}

//12. extern：可以置于变量或函数前，以标示变量或者函数定义在别的文件中

//13. struct
struct A
{};
//柔性数组: 结构体的最后一个元素允许是未知大小的数组，可定义一个变长的结构体
struct B
{
	int i = 0;
	int arr[];
};
class C
{};
void test10()
{
	cout << sizeof(A) << endl; //空结构体的大小为1
	//sizeof返回的结构体大小不包括柔性数组的内存
	cout << sizeof(B) << endl; //4
	//包含柔性数组成员的结构用malloc()函数进行内存的动态分配
	B *p = (B*)malloc(sizeof(B));
	cout << sizeof(*p) << endl; //4 因为柔性数组其实与结构体没有什么关系，只是被当作结构体的一个成员
	free(p);
	cout << sizeof(C) << endl; //1 空类的大小也是1，
	//类和结构体的区别：
	//struct的成员默认为public，class默认为private，另外class还有public和protected两种访问形式
}

//14. union: 联合体，成员默认为public
//在union中所有的数据成员共用一个空间，同一时间只能储存其中一个数据成员，所有的数据成员具有相同的起始地址
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
	int *ptr1 = (int*)(&a + 1); //&a+1强制转换成整型指针，&a的类型是指向具有4个整型变量的数组的指针，a的指向了4的下一个地址
	int *ptr2 = (int*)((int)a + 1); //指向a[0]的下一个*ptr2指向a[1],
	//ptr1[-1]相当于*（ptr1-1）
	printf("%x,%x", ptr1[-1], *ptr2); //5 2000000 大端模式
}
void test11()
{
	cout << sizeof(D) << endl; //8  最大的长度是double型，所有union的大小就是8
	//联合体的访问不论是对哪个变量的存取都是从union的首地址开始的
	//大端模式：字数据的高字节存储在低地址中，而低字节存储在高地址中；低地址值为0
	//小端模式：子数据的高字节存储在高地址中，低字节存储在低地址中。低地址值为1
	p = &u;
	p->arr[0] = 0x39;
	p->arr[1] = 0x38;
	cout << p->i << endl; //14393 = 16进制的3839  大端
	check();
}

//15. enum
//枚举与#define宏的区别
//（1）#define宏常量是在预编译阶段进行简单替换，枚举常量则是在编译的时候确定其值；
//（2）一般在编译器中，可以调试枚举常量，但是不能调试宏常量
//（3）枚举可以一次定义大量相关的常量，而#define宏一次只能定义一个
//enum变量类型可以可以给常量符号赋值，不赋值则会从被赋初值的哪个常量开始依次加1，如果都没有赋值，则从0开始依次增1.
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

//16. typedef: 给一个已经存在的数据类型取一个别名，而非定义一个新的数据类型
typedef struct student
{
	char *name;
	int score;
}Stu_st,*Stu_pst;
void test13()
{
	//定义方式：
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