#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>
template<class T>
class Vector
{
public:
	//Vector的迭代器是一个原生指针
	typedef T* iterator;
	typedef const T* const_iterator;
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const_iterator cbegin()const
	{
		return _start;
	}
	const_iterator cend()const
	{
		return _finish;
	}
	//construct and destroy
	//无参构造
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	//给n个缺省值的构造
	Vector(int n, const T& value = T())
		:_start(new T[n])
		, _finish(_start + n)
		, _endOfStorage(_start + n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			_start[i] = value;
		}
	}
	//迭代器区间的构造
	template<class InputIterator>
	Vector(InputIterator first, InputIterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		while (first != last)
		{
			//元素遍历：尾插
			push_back(*first);
			++first;
		}
	}
	//拷贝构造
	Vector(const Vector<T>& v)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		reserve(v.capacity());
		iterator it = begin();
		const_iterator cit = v.cbegin();
		while (cit != v.cend())
		{
			*it++ = *cit++;
		}
		_finish = _start + v.size();
		_endOfStorage = _start + v.capacity();
	}
	//分配新内容，替换当前内容，相应的修改其大小
	Vector<T>& operator=(Vector<T> v)
	{
		swap(v);
		return *this;
	}
	//析构
	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}
	//capacity
	size_t size()const
	{
		return _finish - _start;
	}
	size_t capacity()const
	{
		return _endOfStorage - _start;
	}
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			//保存有效元素个数
			size_t sz = size();
			//申请空间
			T* tmp = new T[n];
			//拷贝内容
			if (_start)
			{
				//深拷贝
				for (size_t i = 0; i < sz; i++)
				{
					//调用当前数据的赋值运算符重载函数，完成深拷贝
					tmp[i] = _start[i];
				}
				//释放原有空间
				delete[] _start;
			}
			//更新
			_start = tmp;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}
	void resize(size_t n, const T& value = T())
	{
		//n > capacity
		if (n > capacity())
		{
			reserve(n);
		}
		//size < n <= capacity
		if (n > size)
		{
			//(size, n):填充value
			while (_finish != _start + n)
			{
				*_finish = value;
				++_finish;
			}
		}
		//n <= size
		_finish = _start + n;
	}
	//assess
	T& operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}
	const T& operator[](size_t pos)const
	{
		assert(pos < size());
		return _start[pos];
	}
	//modify
	//尾插
	void push_back(const T& x)
	{
		//insert(end(), x);
		//检查容量
		if (_finish == _endOfStorage)
		{
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}
		//插入
		*_finish = x;
		//更新
		++_finish;
	}
	//尾删
	void pop_back()
	{
		if (size() > 0)
		{
			erase(end() - 1);
		}
	}
	//交换
	void swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}
	//插入
	iterator insert(iterator pos, const T& x)
	{
		//检查位置
		assert(pos >= _start && pos <= _finish);
		//检查容量
		if (_finish == _endOfStorage)
		{
			//增容会导致迭代器失效
			//保存pos和_start的偏移量
			size_t offset = pos - _start;
			size_t newC = (0 == capacity()) ? 1 : 2 * capacity();
			reserve(newC);
			//更新pos
			pos = _start + offset;
		}
		//移动元素，从后向前
		iterator end = _finish;
		while(end != pos)
		{
			*end = *(end - 1);
			--end;
		}
		//插入
		*pos = x;
		//更新
		++_finish;
		return pos;
	}
	//删除
	iterator erase(iterator pos)
	{
		//检查范围
		assert(pos >= _start && pos < _finish);
		//元素移动：从后向前
		iterator start = pos + 1;
		while(start != _finish)
		{
			*(start - 1) = *start;
			++start;
		}
		//更新
		--_finish;
		return pos;
	}
private:
	iterator _start; //指向数据块的开始
	iterator _finish; //指向有效数据的尾
	iterator _endOfStorage; //指向存储容量的尾
};
//只读
template<class T>
void printVector( Vector<T>& vec)
{
	typename Vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test()
{
	Vector<int> v;
	v.push_back(1);
	printVector(v);
	v.push_back(2);
	printVector(v);
	v.push_back(3);
	printVector(v);
	v.push_back(4);
	printVector(v);
	v.pop_back();
	printVector(v);
	v.pop_back();
	printVector(v);
	v.pop_back();
	printVector(v);
	v.insert(v.begin(), 2);
	printVector(v);
	v.insert(v.end(), 3);
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.end() - 1);
	printVector(v);
}
int main()
{
	test();
	return 0;
}