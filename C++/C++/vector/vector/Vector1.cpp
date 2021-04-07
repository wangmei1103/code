#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>
template<class T>
class Vector
{
public:
	//Vector�ĵ�������һ��ԭ��ָ��
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
	//�޲ι���
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	//��n��ȱʡֵ�Ĺ���
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
	//����������Ĺ���
	template<class InputIterator>
	Vector(InputIterator first, InputIterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		while (first != last)
		{
			//Ԫ�ر�����β��
			push_back(*first);
			++first;
		}
	}
	//��������
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
	//���������ݣ��滻��ǰ���ݣ���Ӧ���޸����С
	Vector<T>& operator=(Vector<T> v)
	{
		swap(v);
		return *this;
	}
	//����
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
			//������ЧԪ�ظ���
			size_t sz = size();
			//����ռ�
			T* tmp = new T[n];
			//��������
			if (_start)
			{
				//���
				for (size_t i = 0; i < sz; i++)
				{
					//���õ�ǰ���ݵĸ�ֵ��������غ�����������
					tmp[i] = _start[i];
				}
				//�ͷ�ԭ�пռ�
				delete[] _start;
			}
			//����
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
			//(size, n):���value
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
	//β��
	void push_back(const T& x)
	{
		//insert(end(), x);
		//�������
		if (_finish == _endOfStorage)
		{
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}
		//����
		*_finish = x;
		//����
		++_finish;
	}
	//βɾ
	void pop_back()
	{
		if (size() > 0)
		{
			erase(end() - 1);
		}
	}
	//����
	void swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}
	//����
	iterator insert(iterator pos, const T& x)
	{
		//���λ��
		assert(pos >= _start && pos <= _finish);
		//�������
		if (_finish == _endOfStorage)
		{
			//���ݻᵼ�µ�����ʧЧ
			//����pos��_start��ƫ����
			size_t offset = pos - _start;
			size_t newC = (0 == capacity()) ? 1 : 2 * capacity();
			reserve(newC);
			//����pos
			pos = _start + offset;
		}
		//�ƶ�Ԫ�أ��Ӻ���ǰ
		iterator end = _finish;
		while(end != pos)
		{
			*end = *(end - 1);
			--end;
		}
		//����
		*pos = x;
		//����
		++_finish;
		return pos;
	}
	//ɾ��
	iterator erase(iterator pos)
	{
		//��鷶Χ
		assert(pos >= _start && pos < _finish);
		//Ԫ���ƶ����Ӻ���ǰ
		iterator start = pos + 1;
		while(start != _finish)
		{
			*(start - 1) = *start;
			++start;
		}
		//����
		--_finish;
		return pos;
	}
private:
	iterator _start; //ָ�����ݿ�Ŀ�ʼ
	iterator _finish; //ָ����Ч���ݵ�β
	iterator _endOfStorage; //ָ��洢������β
};
//ֻ��
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