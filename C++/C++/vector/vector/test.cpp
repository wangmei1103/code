//#include<vector>
//#include<iostream>
//#include<assert.h>
//using namespace std;
////class A
////{};
////��Χfor
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
//	//emplace �����ȹ��죬�ٲ���
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
//	//��ֵ
//	v.assign(5, 1);
//	vector<int> v2(3, 6);
//	v.assign(v2.begin(), v2.end());
//	int arr[] = { 1,2,3,4,5 };
//	v2.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
	//ɾ��
	//printFor(v2); //1 2 3 4 5
	//v2.erase(v2.begin()); //ɾ��ͷԪ��
	//printFor(v2); //2 3 4 5
	//v2.erase(++v2.begin(), --v2.end()); //ɾ��ͷ����һ��λ�õ�β��ǰһ��λ�õ�����Ԫ��
	//printFor(v2); //2 5

	//v.insert(v.begin(), 0); //ͷ��0
	//printFor(v); //0 6 6 6
	//v.insert(v.end(), 10); //β��10
	//printFor(v); //0 6 6 6 10
	//v.insert(++v.begin(), 1); //ͷ����һ��λ�ò�1
	//printFor(v); //0 1 6 6 6 10
	//v.insert(--v.end(), v2.begin(), v2.end()); //β��ǰһ��λ�ò���v2ͷ��β��Ԫ��
	//printFor(v); //0 1 6 6 6 1 2 3 4 10
	//v.insert(v.begin(), 3, -1); //��ͷǰ����3��-1
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
//	//���ݹ���
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
//	//resize(n,T()) n����������Ӱ������
//	v1.resize(20, 'a');
//	v1.reserve(10); //capacity:20
//	v1.reserve(30); //capacity:30

	/*cout << v1.max_size() << endl;
	cout << v2.max_size() << endl;
	cout << v3.max_size() << endl;
	cout << v4.max_size() << endl;*/
	
//}
/*
//ֻ�����������
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
//ֻ�����������
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
//	//vector��n���Զ������͵�Ĭ�Ϲ��죨����
//	vector<A> v5(20, A());
//	vector<A> v6(20, a);
//	//vector(n,�������͵���0ֵ)
//	//���֣�0
//	//�ַ���\0
//	//ָ��nullptr
//	vector<int> v7(10);
//	vector<char> v8(10);
//	vector<int*> v9(10);
//	//�ַ��������ݴ��һ����ʼ���ַ���vector
//	char arr[] = "123456";
//	vector<char> v10(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//����������  �ɶ���д
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
//	//�������������  �ɶ���д
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
//	//[]Խ�磺debug�汾assert����release�汾���������
//	//v10[100] = 'a';
//	//atԽ�磺���쳣
//	//v10.at(100);
//}
//
//int main()
//{
//	test();
//	return 0;
//}