#include<iostream>
using namespace std;
#include<set>
#include<map>

void test3()
{
	multimap<int, int> m;
	m.insert(make_pair(10, 10));
	m.insert(make_pair(10, 20));
	m.insert(make_pair(10, 30));
	m.insert(make_pair(10, 40));
	m.insert(make_pair(1, 50));
	m.insert(make_pair(10, 50));
	m.insert(make_pair(3, 50));
	m.insert(make_pair(10, 50));
	m.insert(make_pair(17, 50));
	for (auto& p : m)
	{
		cout << p.first << "-->" << p.second << endl;
	}
	//multimap没有operator[]和at接口：数据不唯一
	//m[10] = 100;
}
int main()
{
	test3();
	return 0;
}

/*
template<class T1,class T2>
void printMap(const map<T1, T2>& m)
{
	//map种的数据是pair
	//迭代器访问的顺序：按照key的中序遍历的顺序
	typename map<T1, T2>::const_iterator it = m.begin();
	while (it != m.end())
	{
		//不能直接输出pair对象
		//cout << *it;
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
}

template<class T1, class T2>
void printMap2(const map<T1, T2>& m)
{
	//map种的数据是pair
	//迭代器访问的顺序：按照key的中序遍历的顺序
	typename map<T1, T2>::const_reverse_iterator rit = m.rbegin();
	while (rit != m.rend())
	{
		//不能直接输出pair对象
		//cout << *it;
		cout << rit->first << "-->" << rit->second << endl;
		++rit;
	}
}
void test2()
{
	map<int, int> m;
	//错误的插入方式
	//auto ret = m.insert(1,1);
	//插入类型为pair对象
	//两种常见的插入方式：
	//1. 调用pair构造函数创建对象
	auto ret = m.insert(pair<int, int>(1, 1));
	cout << ret.first->first << "-->" << ret.first->second << endl;
	//2. 调用make_pair函数创建对象
	ret = m.insert(make_pair(2, 2));
	cout << ret.first->first << "-->" << ret.first->second << endl;
	//key值已经存在，插入失败
	ret = m.insert(make_pair(2, 3));
	cout << ret.first->first << "-->" << ret.first->second << endl;
	
	size_t num = m.erase(2);
	cout << num << endl; //删除成功
	cout << m.erase(2) << endl; //删除失败

	//查找按照key值，
	auto it = m.find(1);
	cout << it->first << it->second << endl;
	//查找失败  返回end迭代器
	it = m.find(10);
	cout << (it == m.end()) << endl;

}

void test1()
{
	map<int, int> m;
	pair<int, int> arr[] = { pair<int,int>(5,5),pair<int,int>(1,2),pair<int,int>(3,3),pair<int,int>(0,0),pair<int,int>(1,3) };
	//map种key不能重复，value可以重复
	map<int, int> m2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	printMap(m2);
	//operator[]:读
	cout << m2[3] << endl;
	cout << m2[1] << endl;
	//operator[]:写
	m2[1] = 100;
	printMap2(m2);
	//operator[]:插入
	//100--0  -->   100--100
	m2[100] = 100;
	cout << m2[100] << endl;

	//operator[](k) ：
	//1. 创建一个pair对象，内容：k--value缺省值
	//2. 插入第一步创建的pair对象
	//a. 插入成功：返回pair<pair对象的迭代器，true>
	//b. 插入失败：返回pair<已经存在的键值为k的pair对象迭代器, false>
	//3. 获取插入返回值的first成员：是一个map中pair对象的迭代器
	//4. 解引用第三步中的迭代器：解引用之后为map中的pair对象
	//5. 获取第四步中的pair对象的second成员：其实就是k对应的v；
	//a. 如果插入成功：v是缺省值
	//b. 如果插入失败：v不是缺省值

	//at接口和operator[]区别：at执行插入的操作，如果key不存在，抛异常
	//cout << m2.at(1000) << endl;

}

void test()
{
	map<int, int> m;
	pair<int, int> arr[] = { pair<int,int>(5,5),pair<int,int>(1,2),pair<int,int>(3,3),pair<int,int>(0,0),pair<int,int>(1,3) };
	//map种key不能重复，value可以重复
	map<int, int> m2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	printMap(m2);
	cout << "reverse" << endl;
	printMap2(m2);

	map<int, int, greater<int>> m3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& p : m3)
	{
		cout << p.first << "-->" << p.second << endl;
	}
	//map的迭代器：可以修改value，不能修改key
	auto it = m2.begin();
	it->second = 1000;
	//it->first = 10;  map种key不能重复
}
int main()
{
	test2();
	return 0;
}*/