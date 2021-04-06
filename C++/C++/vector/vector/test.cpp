//#include<vector>
//#include<iostream>
//#include<assert.h>
//using namespace std;
////class A
////{};
////范围for
//template <class T>
//void printFor(const vector<T>& vec)
//{
//	for (const auto& e : vec)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}
//template <class T>
//void printFor2(const vector<T>& vec)
//{
//	for (size_t i = 0; i < vec.size(); ++i)
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//}
//struct A
//{
//	int _a;
//	int _b;
//	char _c;
//	char *_ptr;
//};
//struct B
//{
//	B(int a, int b, char c)
//		:_a(a)
//		,_b(b)
//		,_c(c)
//		,_ptr(nullptr)
//	{}
//	int _a;
//	int _b;
//	char _c;
//	char *_ptr;
//};
//void test()
//{
//	vector<int> v(3, 0);
//	vector<int>::iterator it = v.begin();
//	cout << *it << endl;
//	v.resize(30, 1);
//	cout << *it << endl;
//}
//void test6()
//{
//	//emplace 可以先构造，再插入
//	vector<B> v;
//	B a1(1, 1, 1);
//	v.insert(v.begin(), a1);
//	v.emplace(v.begin(), a1);
//	v.emplace(v.end(), 2, 2, 2);
//	vector<B> v2;
//	v2.swap(v);
//	swap(v2, v);
//	v.clear();
//}
//void test5()
//{
//	vector<int> v(3, 2);
//	//赋值
//	v.assign(5, 1);
//	vector<int> v2(3, 6);
//	v.assign(v2.begin(), v2.end());
//	int arr[] = { 1,2,3,4,5 };
//	v2.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
	//删除
	//printFor(v2); //1 2 3 4 5
	//v2.erase(v2.begin()); //删除头元素
	//printFor(v2); //2 3 4 5
	//v2.erase(++v2.begin(), --v2.end()); //删除头的下一个位置到尾的前一个位置的所有元素
	//printFor(v2); //2 5

	//v.insert(v.begin(), 0); //头插0
	//printFor(v); //0 6 6 6
	//v.insert(v.end(), 10); //尾插10
	//printFor(v); //0 6 6 6 10
	//v.insert(++v.begin(), 1); //头的下一个位置插1
	//printFor(v); //0 1 6 6 6 10
	//v.insert(--v.end(), v2.begin(), v2.end()); //尾的前一个位置插入v2头到尾的元素
	//printFor(v); //0 1 6 6 6 1 2 3 4 10
	//v.insert(v.begin(), 3, -1); //在头前插入3个-1
	//printFor(v); //-1 -1 -1 0 6 6 6 1 2 3 4 10


	//printFor(v); //6 6 6
	//v.pop_back();
	//printFor(v); //6 6
	//v.pop_back();
	//printFor(v); //6

	//printFor(v2); //1 2 3 4
	//v2.push_back(2);
	//printFor(v2); //1 2 3 4 2
	//v2.push_back(2);
	//printFor(v2); //1 2 3 4 2 2
	//v2.push_back(2);
	//printFor(v2); //1 2 3 4 2 2 2
//}

//void test4()
//{
//	vector<int> v;
//	cout << v.size() << endl; //0
//	cout << v.capacity() << endl; //0
//	v.resize(10);
//	v.reserve(30);
//	v.shrink_to_fit();
//	cout << v.size() << endl; //10 
//	cout << v.capacity() << endl; //10
//	v.reserve(1000); 
//	cout << v.size() << endl; //10
//	cout << v.capacity() << endl; //1000
//}

//void test3()
//{
//	//增容规则
//	vector<int> v;
//	size_t cap = v.capacity();
//	cout << cap << endl;
//	for (int i = 0; i < 200; i++)
//	{
//		v.push_back(i);
//		if (cap != v.capacity())
//		{
//			cap = v.capacity();
//			cout << cap << endl;
//		}
//	}
//
//}
//void test2()
//{
//	vector<char> v1;
//	vector<char*> v2;
//	vector<int> v3;
//	vector<A> v4;
//	printFor(v1);
//	v1.resize(10);
//	printFor(v1);
//	//resize(n,T()) n大于容量：影响容量
//	v1.resize(20, 'a');
//	v1.reserve(10); //capacity:20
//	v1.reserve(30); //capacity:30

	/*cout << v1.max_size() << endl;
	cout << v2.max_size() << endl;
	cout << v3.max_size() << endl;
	cout << v4.max_size() << endl;*/
	
//}
/*
//只读正向迭代器
template <class T>
void printfIterator(const vector<T>& vec)
{
	vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
//只读反向迭代器
template <class T>
void printfReverseIterator(const vector<T>& vec)
{
	vector<T>::const_revrese_iterator rit = vec.rbegin();
	while (rit != vec.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}*/

//void test1()
//{
//	vector<int> v1;
//	vector<char> v2;
//	vector<A> v3;
//
//	vector<A> v4(10);
//	A a;
//	//vector（n，自定义类型的默认构造（））
//	vector<A> v5(20, A());
//	vector<A> v6(20, a);
//	//vector(n,内置类型的类0值)
//	//数字：0
//	//字符：\0
//	//指针nullptr
//	vector<int> v7(10);
//	vector<char> v8(10);
//	vector<int*> v9(10);
//	//字符数组内容存放一个初始化字符的vector
//	char arr[] = "123456";
//	vector<char> v10(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//迭代器操作  可读可写
//	/*vector<char>::iterator it = v10.begin();
//	while (it != v10.end())
//	{
//		cout << *it << " ";
//		*it = 'a';
//		it++;
//	}
//	cout << endl;
//	it = v10.begin();
//	while (it != v10.end())
//	{
//		cout << *it << " ";
//		*it = 'a';
//		it++;
//	}
//	cout << endl;*/
//
//	//反向迭代器操作  可读可写
//	/*vector<char>::reverse_iterator rit = v10.rbegin();
//	while (rit != v10.rend())
//	{
//		cout << *rit << " ";
//		*rit = 'a';
//		rit++;
//	}
//	cout << endl;
//	rit = v10.rbegin();
//	while (rit != v10.rend())
//	{
//		cout << *rit << " ";
//		*rit = 'a';
//		rit++;
//	}
//	cout << endl;*/
//	//printfIterator(v10);
//	//printfReverseIterator(v10);
//	/*for (auto& ch : v10)
//	{
//		ch = '1';
//	}
//	printFor(v10);*/
//	/*printFor2(v10);
//	for (size_t i = 0; i < v10.size(); ++i)
//	{
//		v10.operator[](i) = 'a';
//		v10[i] = 'b';
//	}
//	printFor2(v10);*/
//	
//	//[]越界：debug版本assert错误，release版本不会检查错误
//	//v10[100] = 'a';
//	//at越界：抛异常
//	//v10.at(100);
//}
//
//int main()
//{
//	test();
//	return 0;
//}