/*
#include<vector>
#include<iostream>
#include<assert.h>
#include<list>
using namespace std;
//��ͨ����
struct A
{
public:
	A(int a = 1)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}
private:
	friend ostream& operator<<(ostream& out, const A& a);
	int _a;
};
ostream& operator<<(ostream& out, const A& a)
{
	cout << a._a;
	return out;
}
//����
template <class T> 
class Vector
{
public:
	//���������ͣ�T*
	typedef T* iterator;
	typedef const T* const_iterator;
	//�޲ι���
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	//��n��ȱʡֵ�Ĺ���
	Vector(size_t n, const T& val = T())//��ʼ���б�Ҫ����������һ��
		:_start(new T[n])
		, _finish(_start + n)
		, _endOfStorage(_start + n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			_start[i] = val;
		}
	}
	//������������Ĺ���
	template<class InputIterator>
	Vector(InputIterator first, InputIterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		while (first != last)
		{
			//Ԫ�ر�����β��
			pushBack(*first);
			++first;
		} 
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
	//β��
	void pushBack(const T& val)
	{
		//�������
		if (_finish == _endOfStorage)
		{
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}
		//����
		*_finish = val;
		//����size
		++_finish;

	}
	//���� capacity
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			//������ЧԪ�صĸ���
			size_t sz = size();
			//����ռ�
			T* tmp = new T[n];
			//��������
			if (_start)
			{
				//������ЧԪ�أ�size���ص�ֵ
				//memcpy(tmp, _start, sizeof(T)* size());
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
	void resize(size_t n, const T& val = T())
	{
		//n > capacity
		if (n > capacity())
		{
			reserve(n);
		}
		//size < n <= capacity
		if (n > size())
		{
			//(size,n):���val
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		//n <= size
		_finish = _start + n;
	}
	size_t size()const
	{
		return _finish - _start;
	}
	size_t capacity()const
	{
		return _endOfStorage - _start;
	}
	//������
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const iterator begin()const
	{
		return _start;
	}
	const iterator end()const
	{
		return _finish;
	}
	T& operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}
	const T& operator[](size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}
	//����Ԫ��
	void insert(iterator pos, const T& val)
	{
		//���λ��[_start, _finish]
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
		while (end != pos)
		{
			*end = *(end - 1);
			--end;
		}
		//����
		*pos = val;
		//����
		++_finish;
	}
	//ɾ��Ԫ��
	iterator erase(iterator pos)
	{
		//��鷶Χ
		assert(pos >= _start && pos < _finish);
		//Ԫ���ƶ�����ǰ����ƶ�
		iterator start = pos + 1;
		while (start != _finish)
		{
			//��һ�Σ�pos+1 --> pos
			//���һ�Σ�_finish-1 --> _finish - 2
			*(start - 1) = *start;
			++start;
		}
		//����
		--_finish;
		return pos;
	}
	void popBack()
	{
		if (size() > 0)
		{
			erase(end() - 1);
		}
	}
private:
	//��һ��Ԫ�ص��׵�ַ
	iterator _start;
	//���һ����ЧԪ�صĽ�β
	iterator _finish;
	//�ռ�Ľ�β
	iterator _endOfStorage;
};
//������
//�ɶ���д
template<class T>//����ģ��
void printVector(Vector<T>& vec, const T& val) 
{
	typename Vector<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		*it = val;
		++it;
	}
	cout << endl;
}
//ֻ��
template<class T>
void printVector(const Vector<T>& vec) 
{
	typename Vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
//��Χfor
//�ɶ���д
template<class T>
void printVectorFor(Vector<T>& vec, const T& val)
{
	for (auto& e : vec)
	{
		cout << e << " ";
		e = val;
	}
	cout << endl;
}
//ֻ��
template<class T>
void printVectorFor(const Vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
}
//[]
//�ɶ���д
template<class T>
void printOperator(Vector<T>& vec, const T& val)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec.operator[](i) << " ";
		vec[i] = val;
	}
	cout << endl;
}
//ֻ��
template<class T>
void printOperator(const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec.operator[](i) << " ";
	}
	cout << endl;
}

void test()
{
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	Vector<Vector<int>> vv;
	Vector<Vector<Vector<int>>> vvv;
}
void test8()
{
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	Vector<int>::iterator it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{ 
		cout << *it << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
	it = find(v.begin(), v.end(), 5);
	if (it != v.end())
	{
		cout << *it << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
}
void test7()
{
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	v.popBack();
	printVector(v); //1 2 3
	v.popBack();
	printVector(v); //1 2
	v.popBack();
	printVector(v); //1

}
void test6()
{
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	Vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
		else
			++it;
	}
}
void test5()
{
	Vector<int> v;
	v.insert(v.begin(),2);
	printVector(v); //2
	v.insert(v.end(), 4);
	printVector(v); //2 4
	v.insert(v.begin(), 3);
	printVector(v); //3 2 4

	v.erase(v.begin());
	printVector(v); //2 4
	v.erase(v.begin());
	printVector(v); //4
	v.erase(v.begin());
	printVector(v); 
}
void test4()
{
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	v.pushBack(5);
	printVector(v); //1 2 3 4 5
	cout << v.size() << endl; //5
	cout << v.capacity() << endl; //8
	v.resize(2, 100); 
	printVector(v); //1 2
	cout << v.size() << endl; //2
	cout << v.capacity() << endl; //8
	v.resize(4, 5);
	printVector(v); //1 2 5 5
	cout << v.size() << endl; //4
	cout << v.capacity() << endl; //8
	v.resize(10, 10);
	printVector(v); //1 2 5 5 10 10 10 10 10 10
	cout << v.size() << endl; //10
	cout << v.capacity() << endl; //10

}
void test3()
{
	Vector<A> v;
	v.pushBack(A(1));
	v.pushBack(A(2));
	v.pushBack(A(3));
	v.pushBack(A(4));
	v.pushBack(A(5));
	printVector(v, A(100)); //1 2 3 4 5
	printVector(v); //100 100 100 100 100

	printVectorFor(v, A(200)); //100 100 100 100 100
	printVectorFor(v); //200 200 200 200 200
	
	printOperator(v,A(300)); //200 200 200 200 200
	printOperator(v); //300 300 300 300 300
}

void test2()
{
	string str = "123456789";
	//list<char> lst(str.begin(), str.end());
	Vector<char> v(str.begin(), str.end());
	//Vector<char> v(lst.begin(), lst.end());
	printVector(v, 'a'); //1 2 3 4 5 6 7 8 9
	printVector(v); //a a a a a a a a a 
}
void test1()
{
	Vector<int> v1;
	Vector<char> v2;
	Vector<int*> v3;
	Vector<A> v4(5);
	cout << v1.size() << endl;
	cout << v2.size() << endl;
	cout << v3.size() << endl;
	cout << v4.size() << endl;
	cout << v1.capacity() << endl;
	cout << v2.capacity() << endl;
	cout << v3.capacity() << endl;
	cout << v4.capacity() << endl;
}
int main()
{
	test();
	return 0;
}*/