#include<iostream>
using namespace std;
#include<assert.h>
/*
template<typename T1,typename T2,...,typename Tn>
����ֵ���� ������ �������б�
{}

template<class T1,class T2,...,class Tn>
class ��ģ����
{
	//���Ա����
}
*/
/*
//seqList���Ǿ�����࣬�Ǳ��������ݱ�ʵ�������������ɾ������ģ��
template<class T>
class seqList
{
public:
	seqList(int n)
		:_data(new T[n])
		,_size(0)
		,_capacity(n)
	{}
	//���������������������������ⶨ��
	~seqList();
	void Pushback(const T& data);
	void Popback();
	size_t Size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}
private:
	T* _data;
	size_t _size;
	size_t _capacity;
};
//��ģ���к����������ⶨ��ʱ����Ҫ��ģ������б�
template<class T>
seqList<T>::~seqList()
{
	if (_data)
	{
		delete[] _data;
	}
	_size = _capacity = 0;
}
int main()
{
	return 0;
}*/

/*
template<class T>
class seqlist
{
public:
	seqlist(int n)
		:_data(new T[n])
		, _size(0)
		, _capacity(n)
	{}
	T seqlistAt(size_t pos);
private:
	T* _data;
	size_t _size;
	size_t _capacity;
};
//���ⶨ�庯������Ҫ�ӷ���˵��
template <class T>
T seqlist::seqlistAt(size_t pos)
{
	return _data[pos];
}
void test()
{

}*/
/*
//����ģ��
//T��ģ�����
template <typename T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right; 
	right = temp;
}

template<typename T>
T add(T a, T b)
{
	return a + b;
}
template <class T1,class T2,class T3>
void print(const T1& a, const T2& b, const T3& c)
{
	cout << a << " " << b << " " << c << endl;
}
void print(const int& a, const int& b, const double& c)
{
	cout << a << " " << b << " " << c << endl;
}
void test()
{
	int a = 1, b = 2;
	char d = 'm', e = 'n';
	double f = 1.2, g = 2.5;
	//��ʽʵ����
	Swap(a, b);
	Swap(d, e);
	Swap(f, g);

	add(a, b);
	//ǿ������
	add(a, (int)e);
	//���������ܽ��������Ƶ���ʱ��ʹ����ʽʵ����
	//��ʽʵ����
	add<char>(a, e);
	
	print(a, b, d);
	print(b, f, a);

	print(a, b, f);
}
int main()
{
	test();
	return 0;
}*/