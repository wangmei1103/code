#include<iostream>
using namespace std;
#include<assert.h>
/*
template<typename T1,typename T2,...,typename Tn>
返回值类型 函数名 （参数列表）
{}

template<class T1,class T2,...,class Tn>
class 类模板名
{
	//类成员定义
}
*/
/*
//seqList不是具体的类，是编译器根据被实例化的类型生成具体类的模具
template<class T>
class seqList
{
public:
	seqList(int n)
		:_data(new T[n])
		,_size(0)
		,_capacity(n)
	{}
	//析构函数：在类外声明，在类外定义
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
//类模板中函数放在类外定义时，需要加模板参数列表
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
//类外定义函数：需要加泛型说明
template <class T>
T seqlist::seqlistAt(size_t pos)
{
	return _data[pos];
}
void test()
{

}*/
/*
//函数模板
//T：模板参数
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
	//隐式实例化
	Swap(a, b);
	Swap(d, e);
	Swap(f, g);

	add(a, b);
	//强制类型
	add(a, (int)e);
	//编译器不能进行类型推导的时候，使用显式实例化
	//显式实例化
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