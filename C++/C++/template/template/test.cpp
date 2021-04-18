//#include<iostream>
//#include<string>
//using namespace std;
//
////类模板特化: 应用场景：类型萃取
////前提：已有一个通用的模板
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
////特化
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
////偏特化：只特化一部分
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
////偏特化：给模板参数做进一步的限制
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
//	D<int, int> d(1, 1); //通用模板实例化
//	D<char, double> d1('a', 1.1); //全特化模板实例化
//	D<int, char> d2(1, 'a'); //偏特化模板实例化
//	D<int*, int*> d3(1, 2); //偏特化模板实例化
//}
//
//
//template<class T>
//bool isEqual(T a, T b)
//{
//	return a == b;
//}
////模板的特化
////前提：已有一个通用的模板
//template<>
//bool isEqual<char*>(char* a, char* b)
//{
//	return strcmp(a, b) == 0;
//}
////普通函数
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