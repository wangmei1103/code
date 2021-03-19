#include<iostream>
#include<string>
using namespace std;
class A
{
public:
	A(int a=10)
		:_a(a)
	{}
private:
	int _a;
};
void test()
{
	//内置类型
	//new: operator new --> malloc
	int* ptr = new int;
	//delete: operator delete --> free
	delete ptr;
	//new[]: operator new[] --> operator new --> malloc
	int* ptr2 = new int[];
	//delete[]: operator delete[] --> operator delete -->free
	delete[] ptr2;
	//自定义类型
	//new：operator new --> malloc -->构造
	A* pa = new A;
	//delete：析构--> operator delete --> free
	delete pa;
	//new[]: operator new[] --> operator new --> malloc --> N次构造
	A* pa2 = new A[10];
	//delete[]: N次析构 --> operator delete[] --> operator delete -->free
	delete[] pa2;
}
int main()
{
	test();
	return 0;
}


//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	A(int a)
//		:_a(a)
//	{}
//	A(int a,int b,int c)
//		:_a(a)
//	{}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a = 10;
//};
//void test()
//{
//	A* mpa = (A*)malloc(sizeof(A));
//	free(mpa);
//	cout << "------" << endl;
//	//自定义类型：new：申请空间+调用构造函数进行空间内容的初始化
//	//类型指针 指针变量 = new 类型 -->调用默认构造函数（无参、全缺省）
//	A* pa1 = new A;
//	//类型指针 指针变量 = new 类型（参数列表）-->调用带参构造
//	A* pa2 = new A(10);
//	A* pa3 = new A(1, 2, 3);
//	//自定义类型：delete：调用析构完成资源清理+空间释放
//	delete pa1;
//	delete pa2;
//	delete pa3;
//	//自定义类型：连续空间
//	//不能使用带参的构造函数进行多个对象的空间申请和初始化
//	//new[]：申请空间+调用N次构造函数，需要有默认构造
//	A* arrA = new A[3];
//	//delete[]: 调用N次析构+空间释放
//	delete[] arrA;
//}

//void test()
//{
//	//申请和释放的方式保持一致
//	int* mptr = (int*)malloc(sizeof(int));
//	free(mptr);
//	//类型指针  指针变量 = new 类型
//	//类型指针  指针变量 = new 类型（初始值）
//	//类型指针  指针变量 = new 类型（元素个数）
//	int* ptr = new int;
//	delete ptr;
//	//申请空间＋初始化  初始值为10-->4字节
//	int* ptr2 = new int(10);
//	delete ptr2;
//	//连续空间  包含10个元素-->内容为随机值
//	int* arr = new int(10);
//	//释放连续空间
//	delete[] arr;
//}

//void test()
//{
//	//malloc只申请空间，空间内容为随机值，不初始化
//	char* ptr1 = (char*)malloc(sizeof(char));
//	//调整空间大小
//	char* ptr2 = (char*)realloc(ptr1, 2 * sizeof(char));
//	//申请新的空间，功能和malloc相同，不初始化
//	char* ptr3 = (char*)realloc(NULL, sizeof(char));
//	
//	//ptr1的空间不能显式释放（会导致二次释放）
//	//只能显式释放realloc返回之后的空间，传入realloc中的指针空间不能显式释放
//	free(ptr2);
//	free(ptr3);
//	//申请空间+空间全部初始化为0
//	char* ptr4 = (char*)calloc(4, sizeof(char));
//	free(ptr4);
//}
//int main()
//{
//	test();
//	return 0;
//}

/*
int globalVar = 1;
static int staticGlobalVar = 1;
void test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1,2,3,4 };
	char char2[] = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}
int main()
{
	test();
	return 0;
}*/
/*
class A {
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "清理资源" << endl;
		cout << "A()" << endl;
	}
private:
	int _a = 10;
};
void test()
{
	A* mpa = (A*)malloc(sizeof(A));
	free(mpa);
	cout << "-----" << endl;
	//自定义类型：new：申请空间+调用构造函数进行空间内容的初始化
	A* pa1 = new A;
	//自定义类型：delete：调用析构完成资源清理+空间释放
	delete pa1;
	//自定义类型：连续空间
	//new[]：申请空间+调用N次构造函数
	A* arrA = new A[3];
	//delete[]:调用N次析构+空间释放
	delete[] arrA;
}
int main()
{
	test();
	return 0;
}
*/
/*
void test()
{
	//申请和释放的方式保持一致
	//malloc-->free
	int* mptr = (int*)malloc(sizeof(int));
	free(mptr);

	//类型指针  指针变量 = new 类型
	//类型指针  指针变量 = new 类型（初始值）
	//类型指针  指针变量 = new 类型[元素个数]
	//new-->delete
	int* ptr = new int;
	delete ptr;
	//申请空间+初始化：初始值为10-->4字节
	int* ptr2 = new int(10);
	delete ptr2;
	//new[]-->delete[]
	//连续空间：包含10个元素-->40字节，内容为随机值
	int* arr = new int(10);
	//释放连续空间
	delete[] arr;
}
*/
/*
void test()
{
	char* ptr = (char*)malloc(sizeof(char));
	//调整空间大小
	char* ptr2 = (char*)realloc(ptr, 2 * sizeof(char));
	//申请新的空间，功能和malloc相同
	char* ptr3 = (char*)realloc(NULL, sizeof(char));
	char* ptr4 = (char*)realloc(ptr3, sizeof(char) * 100);
	//ptr指向的空间不能显式释放
	//只能显式释放realloc返回之后的空间，传入realloc中的指针空间不能显式释放
	
	//free(ptr);
	free(ptr2);
	//free(ptr3);
	free(ptr4);

	//申请空间+空间全部初始化为0
	char* ptr5 = (char*)calloc(4, sizeof(char));

}
int main()
{
	test();
	return 0;
}*/