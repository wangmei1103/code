#include<iostream>
using namespace std;
#include<set>
#include<string>



template<class T>
void printSet(const set<T>& s)
{
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
//递减
void test1()
{
	set<int> s;
	int arr[] = { 1,2,3,10,2,3,4,4 };
	//set不存重复数据，天然去重,且有序
	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));

}
//递增
void test()
{
	set<int> s;
	int arr[] = { 1,2,3,10,2,3,4,4 };
	//set不存重复数据，天然去重,且有序
	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//set迭代器遍历，数据天然有序，本质迭代器进行中序遍历
	cout << "iterator" << endl;
	set<int>::iterator it = s2.begin();
	//set迭代器不支持修改，
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << "reverse iterator" << endl;
	set<int>::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//insert：插入失败：已有数据迭代器，false
	pair<set<int>::iterator, bool> ret = s2.insert(10);
	cout << ret.second << " " << *ret.first << endl;
	printSet(s2);
	//insert：插入成功：新数据迭代器，true
	ret = s2.insert(100);
	cout << ret.second << " " << *ret.first << endl;
	printSet(s2);
	//iterator insert(iterator position, const value_type& val;
	//insert(iterator, val): iterator 只是一个位置建议，最终数据的位置不一定在指定的迭代器之前
	s2.insert(ret.first, 0);
	printSet(s2);

	int arr2[] = { 12,9,6,18,19,15,3 };
	s2.insert(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
	printSet(s2);

	//删除
	int num = s2.erase(19);
	printSet(s2);
	cout << num << endl;
	num = s2.erase(18);
	printSet(s2);
	cout << num << endl;
	s2.erase(s2.begin());
	//erase：不能传非法位置：比如end
	//s2.erase(s2.end());不存在
	printSet(s2);
	/*s2.erase(++s2.begin(), --s2.end());
	printSet(s2);*/
	//find
	auto it1 = s2.find(12);
	cout << (it1 != s2.end()) << endl;
	it1 = s2.find(1000);
	cout << (it1 != s2.end()) << endl;
	
	//count
	cout << s2.count(6) << endl;
	cout << s2.count(8) << endl;
}

int main()
{
	test();
	return 0;
}