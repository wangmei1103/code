//Ԥ����
//#include��ʹ���������һԴ�ļ�Ƕ�뵽����#include��Դ�ļ��С�
//#include<filename>
//#include"filename"
#include<iostream>
using namespace std;
//1. #define���궨��
#define PI 3.1415926 
//#undef�������Ѷ�����ĺ���
#undef PI 

//2. ��������
//#if #endif ��#if��һ�㺬�������#if����ĳ������ʽΪtrue�����������#endif֮��Ĵ��룬����������Щ���룬#endif��ʶһ��#if�����
//#else ��������C�����е�else����#if��ʧ�ܵ�����½�����һ��ѡ��
//#elif ����������ͬelse if��ͬ���γ�һ��if else-if����״��䣬�ɽ��ж��ֱ���ѡ��
//#ifdef #ifndef ���ֱ��ʾ����ж��塢����޶��壬�������������һ�ַ���

/*#ifdef ��ʶ��
�����1
#else
�����2
#endif*/

/*#ifndef ��ʶ��
�����1
#else
�����2
#endif*/

/*#if �������ʽ
�����1
#else
�����2
#endif*/

//3. #line ���ı䵱ǰ�������ļ����ƣ����ڱ��������Ԥ�ȶ���ı�ʶ����#line number["filename"]
//#line 30 a.h

//4. #error ���������ʱ��ֻҪ����#error�ͻ�����һ������������ʾ��Ϣ��ֹͣ����
//#error error-massage

//5. #pragma ��Ϊʵ��ʱ����������������������͸���ָ��
//#pragma para  --paraΪ����
//#pragma message
/*#ifdef _X86
#Pragma message("_X86 macro actived!")
#endif*/  //������_X86������Ժ�Ӧ�ó����ڱ���ʱ�ͻ��ڱ������������ʾ��_X86 macro actived!��

//#pragma once ͷ�ļ��ʼ���ϴ���ָ��ܹ���֤ͷ�ļ�������һ�Σ�
//#pragma hdrstop Ԥ����ͷ�ļ�����Ϊֹ�������ͷ�ļ����ٽ���Ԥ����
//#pragma startup ָ���������ȼ�
//#pragma warning(disable:4996) //����ʾ4996�ž�����Ϣ
//#pragma warning(once:4385) //4385�ž�����Ϣֻ����һ��
//#pragma warning(push) //�������о�����Ϣ�����о���״̬
//#pragma warning(pop) //��ջ�е������һ��������Ϣ������ջ�ͳ�ջ֮��������һ�иĶ�ȡ��
//#pragma comment(lib,"user32.lib") //��user32.lib���ļ����뵽������
//#pragma comment(linker,"/include:_mySymbol") //ָ��/includeѡ��ǿ�ư���ĳ������

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
#pragma back(8) //����n���ֽڶ���
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
#pragma back() //ȡ���Զ����ֽڶ��뷽ʽ
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

