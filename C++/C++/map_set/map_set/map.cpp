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
	//multimapû��operator[]��at�ӿڣ����ݲ�Ψһ
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
	//map�ֵ�������pair
	//���������ʵ�˳�򣺰���key�����������˳��
	typename map<T1, T2>::const_iterator it = m.begin();
	while (it != m.end())
	{
		//����ֱ�����pair����
		//cout << *it;
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
}

template<class T1, class T2>
void printMap2(const map<T1, T2>& m)
{
	//map�ֵ�������pair
	//���������ʵ�˳�򣺰���key�����������˳��
	typename map<T1, T2>::const_reverse_iterator rit = m.rbegin();
	while (rit != m.rend())
	{
		//����ֱ�����pair����
		//cout << *it;
		cout << rit->first << "-->" << rit->second << endl;
		++rit;
	}
}
void test2()
{
	map<int, int> m;
	//����Ĳ��뷽ʽ
	//auto ret = m.insert(1,1);
	//��������Ϊpair����
	//���ֳ����Ĳ��뷽ʽ��
	//1. ����pair���캯����������
	auto ret = m.insert(pair<int, int>(1, 1));
	cout << ret.first->first << "-->" << ret.first->second << endl;
	//2. ����make_pair������������
	ret = m.insert(make_pair(2, 2));
	cout << ret.first->first << "-->" << ret.first->second << endl;
	//keyֵ�Ѿ����ڣ�����ʧ��
	ret = m.insert(make_pair(2, 3));
	cout << ret.first->first << "-->" << ret.first->second << endl;
	
	size_t num = m.erase(2);
	cout << num << endl; //ɾ���ɹ�
	cout << m.erase(2) << endl; //ɾ��ʧ��

	//���Ұ���keyֵ��
	auto it = m.find(1);
	cout << it->first << it->second << endl;
	//����ʧ��  ����end������
	it = m.find(10);
	cout << (it == m.end()) << endl;

}

void test1()
{
	map<int, int> m;
	pair<int, int> arr[] = { pair<int,int>(5,5),pair<int,int>(1,2),pair<int,int>(3,3),pair<int,int>(0,0),pair<int,int>(1,3) };
	//map��key�����ظ���value�����ظ�
	map<int, int> m2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	printMap(m2);
	//operator[]:��
	cout << m2[3] << endl;
	cout << m2[1] << endl;
	//operator[]:д
	m2[1] = 100;
	printMap2(m2);
	//operator[]:����
	//100--0  -->   100--100
	m2[100] = 100;
	cout << m2[100] << endl;

	//operator[](k) ��
	//1. ����һ��pair�������ݣ�k--valueȱʡֵ
	//2. �����һ��������pair����
	//a. ����ɹ�������pair<pair����ĵ�������true>
	//b. ����ʧ�ܣ�����pair<�Ѿ����ڵļ�ֵΪk��pair���������, false>
	//3. ��ȡ���뷵��ֵ��first��Ա����һ��map��pair����ĵ�����
	//4. �����õ������еĵ�������������֮��Ϊmap�е�pair����
	//5. ��ȡ���Ĳ��е�pair�����second��Ա����ʵ����k��Ӧ��v��
	//a. �������ɹ���v��ȱʡֵ
	//b. �������ʧ�ܣ�v����ȱʡֵ

	//at�ӿں�operator[]����atִ�в���Ĳ��������key�����ڣ����쳣
	//cout << m2.at(1000) << endl;

}

void test()
{
	map<int, int> m;
	pair<int, int> arr[] = { pair<int,int>(5,5),pair<int,int>(1,2),pair<int,int>(3,3),pair<int,int>(0,0),pair<int,int>(1,3) };
	//map��key�����ظ���value�����ظ�
	map<int, int> m2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	printMap(m2);
	cout << "reverse" << endl;
	printMap2(m2);

	map<int, int, greater<int>> m3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& p : m3)
	{
		cout << p.first << "-->" << p.second << endl;
	}
	//map�ĵ������������޸�value�������޸�key
	auto it = m2.begin();
	it->second = 1000;
	//it->first = 10;  map��key�����ظ�
}
int main()
{
	test2();
	return 0;
}*/