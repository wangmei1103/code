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
//�ݼ�
void test1()
{
	set<int> s;
	int arr[] = { 1,2,3,10,2,3,4,4 };
	//set�����ظ����ݣ���Ȼȥ��,������
	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));

}
//����
void test()
{
	set<int> s;
	int arr[] = { 1,2,3,10,2,3,4,4 };
	//set�����ظ����ݣ���Ȼȥ��,������
	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//set������������������Ȼ���򣬱��ʵ����������������
	cout << "iterator" << endl;
	set<int>::iterator it = s2.begin();
	//set��������֧���޸ģ�
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
	//insert������ʧ�ܣ��������ݵ�������false
	pair<set<int>::iterator, bool> ret = s2.insert(10);
	cout << ret.second << " " << *ret.first << endl;
	printSet(s2);
	//insert������ɹ��������ݵ�������true
	ret = s2.insert(100);
	cout << ret.second << " " << *ret.first << endl;
	printSet(s2);
	//iterator insert(iterator position, const value_type& val;
	//insert(iterator, val): iterator ֻ��һ��λ�ý��飬�������ݵ�λ�ò�һ����ָ���ĵ�����֮ǰ
	s2.insert(ret.first, 0);
	printSet(s2);

	int arr2[] = { 12,9,6,18,19,15,3 };
	s2.insert(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
	printSet(s2);

	//ɾ��
	int num = s2.erase(19);
	printSet(s2);
	cout << num << endl;
	num = s2.erase(18);
	printSet(s2);
	cout << num << endl;
	s2.erase(s2.begin());
	//erase�����ܴ��Ƿ�λ�ã�����end
	//s2.erase(s2.end());������
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