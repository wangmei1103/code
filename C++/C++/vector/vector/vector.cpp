#include<vector>
#include<iostream>
#include<assert.h>
using namespace std;

template <class T> 
class Vector
{
public:
	//迭代器类型：T*
	typedef T* iterator;
	typedef const T* const_iterator;
	//无参构造
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	Vector(size_t n, const T& val = T())
		:_start(new T[n])
		, _finish(_start + n)
		, _endOfStorage(_start + n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = val;
		}
	}
	size_t size() const
	{
		return _finish - _start;
	}
	size_t capacity() const
	{
		return _endOfStorage - _start;
	}

	/*void insert(iterator pos, const T& val)
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
	}*/
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
	//第一个元素的首地址
	iterator _start;
	//最后一个有效元素的结尾
	iterator _finish;
	//空间的结尾
	iterator _endOfStorage;
};

void test()
{
	Vector<int> v1;
	Vector<char> v2;
	Vector<int*> v3;

	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
}
int main()
{
	test();
	return 0;
}