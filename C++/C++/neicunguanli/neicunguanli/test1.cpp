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
	//��������
	//new: operator new --> malloc
	int* ptr = new int;
	//delete: operator delete --> free
	delete ptr;
	//new[]: operator new[] --> operator new --> malloc
	int* ptr2 = new int[];
	//delete[]: operator delete[] --> operator delete -->free
	delete[] ptr2;
	//�Զ�������
	//new��operator new --> malloc -->����
	A* pa = new A;
	//delete������--> operator delete --> free
	delete pa;
	//new[]: operator new[] --> operator new --> malloc --> N�ι���
	A* pa2 = new A[10];
	//delete[]: N������ --> operator delete[] --> operator delete -->free
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
//	//�Զ������ͣ�new������ռ�+���ù��캯�����пռ����ݵĳ�ʼ��
//	//����ָ�� ָ����� = new ���� -->����Ĭ�Ϲ��캯�����޲Ρ�ȫȱʡ��
//	A* pa1 = new A;
//	//����ָ�� ָ����� = new ���ͣ������б�-->���ô��ι���
//	A* pa2 = new A(10);
//	A* pa3 = new A(1, 2, 3);
//	//�Զ������ͣ�delete���������������Դ����+�ռ��ͷ�
//	delete pa1;
//	delete pa2;
//	delete pa3;
//	//�Զ������ͣ������ռ�
//	//����ʹ�ô��εĹ��캯�����ж������Ŀռ�����ͳ�ʼ��
//	//new[]������ռ�+����N�ι��캯������Ҫ��Ĭ�Ϲ���
//	A* arrA = new A[3];
//	//delete[]: ����N������+�ռ��ͷ�
//	delete[] arrA;
//}

//void test()
//{
//	//������ͷŵķ�ʽ����һ��
//	int* mptr = (int*)malloc(sizeof(int));
//	free(mptr);
//	//����ָ��  ָ����� = new ����
//	//����ָ��  ָ����� = new ���ͣ���ʼֵ��
//	//����ָ��  ָ����� = new ���ͣ�Ԫ�ظ�����
//	int* ptr = new int;
//	delete ptr;
//	//����ռ䣫��ʼ��  ��ʼֵΪ10-->4�ֽ�
//	int* ptr2 = new int(10);
//	delete ptr2;
//	//�����ռ�  ����10��Ԫ��-->����Ϊ���ֵ
//	int* arr = new int(10);
//	//�ͷ������ռ�
//	delete[] arr;
//}

//void test()
//{
//	//mallocֻ����ռ䣬�ռ�����Ϊ���ֵ������ʼ��
//	char* ptr1 = (char*)malloc(sizeof(char));
//	//�����ռ��С
//	char* ptr2 = (char*)realloc(ptr1, 2 * sizeof(char));
//	//�����µĿռ䣬���ܺ�malloc��ͬ������ʼ��
//	char* ptr3 = (char*)realloc(NULL, sizeof(char));
//	
//	//ptr1�Ŀռ䲻����ʽ�ͷţ��ᵼ�¶����ͷţ�
//	//ֻ����ʽ�ͷ�realloc����֮��Ŀռ䣬����realloc�е�ָ��ռ䲻����ʽ�ͷ�
//	free(ptr2);
//	free(ptr3);
//	//����ռ�+�ռ�ȫ����ʼ��Ϊ0
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
		cout << "������Դ" << endl;
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
	//�Զ������ͣ�new������ռ�+���ù��캯�����пռ����ݵĳ�ʼ��
	A* pa1 = new A;
	//�Զ������ͣ�delete���������������Դ����+�ռ��ͷ�
	delete pa1;
	//�Զ������ͣ������ռ�
	//new[]������ռ�+����N�ι��캯��
	A* arrA = new A[3];
	//delete[]:����N������+�ռ��ͷ�
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
	//������ͷŵķ�ʽ����һ��
	//malloc-->free
	int* mptr = (int*)malloc(sizeof(int));
	free(mptr);

	//����ָ��  ָ����� = new ����
	//����ָ��  ָ����� = new ���ͣ���ʼֵ��
	//����ָ��  ָ����� = new ����[Ԫ�ظ���]
	//new-->delete
	int* ptr = new int;
	delete ptr;
	//����ռ�+��ʼ������ʼֵΪ10-->4�ֽ�
	int* ptr2 = new int(10);
	delete ptr2;
	//new[]-->delete[]
	//�����ռ䣺����10��Ԫ��-->40�ֽڣ�����Ϊ���ֵ
	int* arr = new int(10);
	//�ͷ������ռ�
	delete[] arr;
}
*/
/*
void test()
{
	char* ptr = (char*)malloc(sizeof(char));
	//�����ռ��С
	char* ptr2 = (char*)realloc(ptr, 2 * sizeof(char));
	//�����µĿռ䣬���ܺ�malloc��ͬ
	char* ptr3 = (char*)realloc(NULL, sizeof(char));
	char* ptr4 = (char*)realloc(ptr3, sizeof(char) * 100);
	//ptrָ��Ŀռ䲻����ʽ�ͷ�
	//ֻ����ʽ�ͷ�realloc����֮��Ŀռ䣬����realloc�е�ָ��ռ䲻����ʽ�ͷ�
	
	//free(ptr);
	free(ptr2);
	//free(ptr3);
	free(ptr4);

	//����ռ�+�ռ�ȫ����ʼ��Ϊ0
	char* ptr5 = (char*)calloc(4, sizeof(char));

}
int main()
{
	test();
	return 0;
}*/