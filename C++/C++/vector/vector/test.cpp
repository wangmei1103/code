#include<vector>
#include<iostream>
#include<assert.h>
using namespace std;

template <class T>
class Vector
{
public:






	void insert(iterator pos, const T& val)
	{
		assert(pos >= _start && <= _finish);
		if (_finish == _endOfStorage)
		{
			size_t offset = pos - _start;
			size_t newC = _endOfStorage() == nullptr ? 1 : 2 * capacity();
			reserve(newC);
			pos = _start + offset;
		}
		iterator end = _finish;
		while (end >= pos)
		{
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++_finish;
	}
	iterator erase(iterator pos)
	{
		assert(pos >= _start && pos < _finish);
		iterator start = pos + 1;
		while (start != _finish)
		{
			*(start - 1) = *start;
			++start;
		}
		--_finish;
		return pos;
	}
private:
	iterator _start;
	iterator _finish;
	iterator _endOfStorage;
};



//class A
//{
//
//};
/*
void test()
{
	vector<int> v1;
	vector<char> v2;
	vector<A> v3;

	vector<A> v4(10);
	A a;
	//vector��n���Զ������͵�Ĭ�Ϲ��죨����
	vector<A> v5(20, A());
	vector<A> v6(20, a);
	//vector(n,�������͵���0ֵ)
	//���֣�0
	//�ַ���\0
	//ָ��nullptr
	vector<int> v7(10);
	vector<char> v8(10);
	vector<int*> v9(10);
	char arr[] = "123456";
	vector<char> v10(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//������
	vector<char>::iterator it = v10.begin();
	while (it != v10.end())
	{
		cout << *it << " ";
		*it = 'a';
		it++;
	}
	cout << endl;
	//���������
	vector<char>::reverse_iterator rit = v10.rbegin();
	while (rit != v10.rend())
	{
		cout << *rit << " ";
		*rit = 'a';
		rit++;
	}
	cout << endl;

	for (size_t i = 0; i < v10.size(); ++i)
	{
		v10.operator[](i) = 'a';
		v10[i] = 'b';
	}

	//[]Խ�磺debug�汾assert����release�汾���������
	v10[100] = 'a';
	//
	v10.at(100);
}
//��Χfor
template <class T>
void printFor(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
	
}*/
int main()
{
	test();
	return 0;
}