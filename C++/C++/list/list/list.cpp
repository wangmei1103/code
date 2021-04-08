//#include<iostream>
//#include<list>
//#include<string>
//using namespace std;
//
//template<class T>
//void printList(const list<T>& lst)
//{
//
//	for (const auto& e : lst)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//bool compareList(const int& a, const int& b)
//{
//	return a > b;
//}
//void test()
//{
//	int arr[] = { 10,2,5,3,6 };
//	int arr2[] = { 23,5,36,7,8 };
//	list<int> lst(arr, arr + 5);
//	list<int> lst2(arr2, arr2 + 5);
//	lst.sort();
//	lst2.sort();
//	lst.merge(lst2);
//	printList(lst); //2 3 5 5 6 7 8 10 23 36
//}
//void test4()
//{
//	string s = "123";
//	string s2 = "abc";
//	list<char> lst(s.begin(), s.end());
//	list<char> lst2(s2.begin(), s2.end());
//	//lst.splice(lst.begin(), lst2);//a b c 1 2 3
//	lst.splice(lst.begin(), lst2, ++lst2.begin(), lst2.end()); //b c 1 2 3
//	printList(lst);
//	printList(lst2);
//	lst.remove('f');
//	printList(lst);
//	lst.push_back('1');
//	lst.push_back('2');
//	lst.push_back('3');
//	lst.push_back('a');
//	lst.push_back('b');
//	printList(lst);
//	//unique：在数据有序的情况下进行元素的去重
//	lst.unique();
//	printList(lst);
//	lst.sort(compareList);
//	printList(lst);
//	lst.unique();
//	printList(lst);
//}
//void test3()
//{
//	list<int> lst;
//	lst.push_front(1);
//	lst.push_back(2);
//	lst.insert(lst.begin(), 0);
//	list<int>::iterator it = lst.begin();
//	cout << *it << endl;
//	lst.insert(lst.end(), 0);
//	lst.emplace(lst.begin(), -1);
//	lst.emplace_back(4);
//	lst.emplace_front(-2);
//	list<int> copy = lst;
//	lst.insert(lst.end(), copy.begin(), copy.end());
//	for (const auto& e : lst)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //-2 -1 0 1 2 0 4 -2 -1 0 1 2 0 4
//	//插入不会导致迭代器失效
//	cout << *it << endl;
//	//删除迭代器会失效，需要重新获取
//	//erase返回值：迭代器-》被删除元素的下一个元素的位置
//	it = lst.erase(it);
//	cout << *it << endl;
//	//lst.clear();
//	//cout << lst.size() << endl;
//	lst.resize(4,100);
//	for (const auto& e : lst)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	lst.resize(6, 100);
//	for (const auto& e : lst)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}
//
//void test2()
//{
//	string str = "1234567";
//	list<char> lst(str.begin(), str.end());
//	list<char>::iterator it = lst.begin();
//	//正向迭代器：可读可写
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		*it = 'a';
//		++it;
//	}
//	cout << endl; //1 2 3 4 5 6 7
//	//正向只读迭代器
//	list<char>::const_iterator cit = lst.cbegin();
//	while (cit != lst.cend())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl; //a a a a a a a
//	//反向迭代器的正向输出
//	list<char> lst2(str.begin(), str.end());
//	list<char>::reverse_iterator rit = lst2.rbegin();
//	while (rit != lst2.rend())
//	{
//		cout << *rit << " ";
//		*rit = 'c';
//		++rit;
//	}
//	cout << endl; //7 6 5 4 3 2 1 
//	list<char> lst3(str.begin(), str.end());
//	list<char>::const_reverse_iterator crit = lst3.crend();
//	//反向迭代器向后退
//	--crit;
//	while (crit != lst3.crbegin())
//	{
//		cout << *crit << " ";
//		--crit;
//	}
//	cout << *crit << endl; //1 2 3 4 5 6 7
//
//	//范围for
//	for (auto& e : lst3)
//	{
//		cout << e << " ";
//		e = 'c';
//	}
//	cout << endl; //1 2 3 4 5 6 7
//	for (const auto& e : lst3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;//c c c c c c c 
//}
//void test1()
//{
//	list<int> lst;
//	list<char> lst2;
//	list<int> lst3(3, 5);//555
//	string str = "123456";
//	list<char> lst4(str.begin(), str.end());//123456
//	char arr[] = "abcd";
//	list<char> lst5(arr, arr + sizeof(arr) / sizeof(arr[0]));//abcd\0
//}
//
//int main()
//{
//	test();
//	return 0;
//}