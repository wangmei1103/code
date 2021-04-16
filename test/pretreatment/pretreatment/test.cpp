//预处理
//#include：使编译程序将另一源文件嵌入到带有#include的源文件中。
//#include<filename>
//#include"filename"
#include<iostream>
using namespace std;
//1. #define：宏定义
#define PI 3.1415926 
//#undef：撤销已定义过的宏名
#undef PI 

//2. 条件编译
//#if #endif ：#if的一般含义是如果#if后面的常量表达式为true，则编译它与#endif之间的代码，否则跳过这些代码，#endif标识一个#if块结束
//#else ：功能像C语言中的else，在#if块失败的情况下建立另一个选择，
//#elif ：命令意义同else if相同，形成一个if else-if阶梯状语句，可进行多种编译选择
//#ifdef #ifndef ：分别表示如果有定义、如果无定义，是条件编译的另一种方法

/*#ifdef 标识符
程序段1
#else
程序段2
#endif*/

/*#ifndef 标识符
程序段1
#else
程序段2
#endif*/

/*#if 常量表达式
程序段1
#else
程序段2
#endif*/

//3. #line ：改变当前行数和文件名称，是在编译程序中预先定义的标识符：#line number["filename"]
//#line 30 a.h

//4. #error ：编译程序时，只要遇到#error就会生成一个编译错误的提示信息，停止编译
//#error error-massage

//5. #pragma ：为实现时定义的命令允许向编译程序传送各种指令
//#pragma para  --para为参数
//#pragma message
/*#ifdef _X86
#Pragma message("_X86 macro actived!")
#endif*/  //定义了_X86这个宏以后，应用程序在编译时就会在编译输出窗口显示“_X86 macro actived!”

//#pragma once 头文件最开始加上此条指令，能够保证头文件被编译一次，
//#pragma hdrstop 预编译头文件到此为止，后面的头文件不再进行预编译
//#pragma startup 指定编译优先级
//#pragma warning(disable:4996) //不显示4996号警告信息
//#pragma warning(once:4385) //4385号警告信息只报告一次
//#pragma warning(push) //保存所有警告信息的现有警告状态
//#pragma warning(pop) //向栈中弹出最后一个警告信息，在入栈和出栈之间所作的一切改动取消
//#pragma comment(lib,"user32.lib") //将user32.lib库文件加入到本工程
//#pragma comment(linker,"/include:_mySymbol") //指定/include选项强制包含某个对象

struct A
{
	char c1;
	short s;
	char c2;
	int i;
};
void test1()
{
	A a;
	printf("c1 %p,s %p,c2 %p,i %p",
		(unsigned int)(void*)&a.c1 - (unsigned int)(void*)&a,
		(unsigned int)(void*)&a.s - (unsigned int)(void*)&a,
		(unsigned int)(void*)&a.c2 - (unsigned int)(void*)&a,
		(unsigned int)(void*)&a.i - (unsigned int)(void*)&a);//c1 00000000, s 00000002, c2 00000004, i 00000008
}
#pragma back(8) //按照n个字节对齐
struct B
{
	char a; //1
	long b; //4
}; //8
struct C
{
	char c; //1
	B d; //8
	long long e; //8
}; //24
#pragma back() //取消自定义字节对齐方式
void test2()
{
	cout << sizeof(B) << endl; //8
	cout << sizeof(C) << endl; //24
}


int main()
{
	//test1();
	test2();
	return 0;
}

