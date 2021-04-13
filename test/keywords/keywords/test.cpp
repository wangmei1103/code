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