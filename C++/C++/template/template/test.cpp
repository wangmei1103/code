//#include<iostream>
//#include<string>
//using namespace std;
//
////��ģ���ػ�: Ӧ�ó�����������ȡ
////ǰ�᣺����һ��ͨ�õ�ģ��
//template<class T1,class T2>
//struct D
//{
//public:
//	D(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1,T2)" << endl;
//	}
//	T1 _d1;
//	T2 _d2;
//};
////�ػ�
//template<>
//struct D<char, double>
//{
//	D(const char& d1, const double& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(char,double)" << endl;
//	}
//	char _d1;
//	double _d2;
//};
////ƫ�ػ���ֻ�ػ�һ����
//template<class T1>
//struct D<T1, char>
//{
//	D(const T1& d1, const double& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1,char)" << endl;
//	}
//	T1 _d1;
//	double _d2;
//};
////ƫ�ػ�����ģ���������һ��������
//template<class T1,class T2>
//struct D<T1*, T2*>
//{
//public:
//	D(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1*, T2*)" << endl;
//	}
//	T1 _d1;
//	T2 _d2;
//};
//void test1()
//{
//	D<int, int> d(1, 1); //ͨ��ģ��ʵ����
//	D<char, double> d1('a', 1.1); //ȫ�ػ�ģ��ʵ����
//	D<int, char> d2(1, 'a'); //ƫ�ػ�ģ��ʵ����
//	D<int*, int*> d3(1, 2); //ƫ�ػ�ģ��ʵ����
//}
//
//
//template<class T>
//bool isEqual(T a, T b)
//{
//	return a == b;
//}
////ģ����ػ�
////ǰ�᣺����һ��ͨ�õ�ģ��
//template<>
//bool isEqual<char*>(char* a, char* b)
//{
//	return strcmp(a, b) == 0;
//}
////��ͨ����
//bool isEqual(const char* a, char* b)
//{
//	return strcmp(a, b) == 0;
//}
//void test()
//{
//	bool ret = isEqual(1, 2); //false
//	ret = isEqual(2.3, 2.3); //true
//	ret = isEqual("123", "123"); //true
//	const char* ptr = "123";
//	char ptr2[] = "123";
//	ret = isEqual(ptr, ptr2); 
//}
//
//int main()
//{
//	//test();
//	test1();
//	return 0;
//}