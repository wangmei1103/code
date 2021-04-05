#include<iostream>
using namespace std;
#include<string>
#include<assert.h>
#include<string.h>
#pragma warning (disable:4996)
class String
{
	friend ostream& operator<<(ostream& _cout, const String& s);
	friend istream& operator>>(istream& _cin, String& s);

public:
	typedef char* iterator;
 	typedef const char* const_iterator;
public:
	//ȫȱʡ����
	String(const char* str = "")
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	//����
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	// iterator
	iterator begin()
	{
		//��һ��Ԫ��λ��
		return _str; 
	}
	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}
	const iterator begin()const
	{
		//��һ��Ԫ��λ��
		return _str;
	}
	const iterator end()const
	{
		//���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}

	// modify
	//β���ַ�'c'
	void push_back(char c)
	{
		//���ռ�
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			//����
			reserve(newC);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	//׷���ַ���
	void append(const char* str)
	{
		//�������
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//β��  �ڴ濽��
		memcpy(_str + _size, str, sizeof(char)*len);
		//����
		_size += len;
		_str[_size] = '\0';
	}
	//��ֵ�����
	String& operator=(const String &s)
	{
		if (this != &s)
		{
			String tmp(s);
			this->Swap(tmp);
		}
		return *this;
	}
	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	String& operator+=(const String& str)
	{
		this->append(str._str);
		return *this;
	}
	String& operator+=(char c)
	{
		push_back(c);
		return *this;
	}
	void clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}
	const char* c_str()const
	{
		return _str;
	}
	// capacity
	size_t size()const
	{
		return _size;
	}
	size_t capacity()const
	{
		return _capacity;
	}
	bool empty()const
	{
		return _size == 0;
	}

	void resize(size_t n, char c = '\0')
	{
		//n>_capacity������
		if (n > _capacity)
		{
			reserve(n);
		}
		//_size < n <= _capacity
		//����ַ� c
		if (n > _size)
		{
			memset(_str + _size, c, (n - _size) * sizeof(char));
		}
		//ֱ���޸�size
		_size = n;
		_str[_size] = '\0';
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//����ռ�
			char* tmp = new char[n + 1];
			//����
			strcpy(tmp, _str);
			//�ͷ�ԭ�пռ�
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	// access
	char& operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}
	const char& operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}

	//relational operators
	bool operator<(const String& s)
	{
		int ret = strcmp(_str, s._str);
		if (ret < 0)
			return true;
		return false;
	}
	bool operator<=(const String& s)
	{
		return !(*this > s);
	}
	bool operator>(const String& s)
	{
		int ret = strcmp(_str, s._str);
		if (ret > 0)
			return true;
		return false;
	}
	bool operator>=(const String& s)
	{
		return !(*this < s);
	}
	bool operator==(const String& s)
	{
		int ret = strcmp(_str, s._str);
		if (ret == 0)
			return true;
		return false;
	}
	bool operator!=(const String& s)
	{
		return !(*this == s);
	}

	// ����c��string�е�һ�γ��ֵ�λ��
	size_t find(char c, size_t pos = 0) const
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_str[i] == c)
			{
				return i;
			}
			return npos;
		}
	}

	// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
	size_t find(const char* s, size_t pos = 0) const
	{
		char* ptr = strstr(_str,s);
		if (ptr)
		{
			return ptr - _str;
		}
		return npos;
	}

	// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
	String& insert(size_t pos, char c)
	{
		//���λ��
		assert(pos <= _size);
		//�������
		if (_size == _capacity)
		{
			size_t newC = _capacity = 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//�ƶ�Ԫ�أ��Ӻ���ǰ
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1]; //��һ�ο����ľ���\0
			--end;
		}
		//����
		_str[pos] = c;
		//����
		++_size;
		return *this;
	}

	String& insert(size_t pos, const char* str)
	{
		//���λ��
		assert(pos <= _size);
		//�������
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//�ƶ�Ԫ��  �Ӻ���ǰ
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		//����
		memcpy(_str + pos, str, sizeof(char)*len);
		//����
		_size += len;
		return *this;
	}


	// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
	String& erase(size_t pos, size_t len)
	{
		//���λ��
		assert(pos < _size);
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else {
			//�ƶ�Ԫ�أ���ǰ���
			size_t start = pos + len;
			for (; start <= _size; ++start)
			{
				_str[pos++] = _str[start];
			}
			_size -= len;
		}
		return *this;
	}

private:
	char* _str; 
	size_t _size; //��Ч�ַ��ĸ���
	size_t _capacity; //���Ա���������Ч�ַ�����
	static const size_t npos;
};

ostream& operator<<(ostream& _cout, const String& str)
{
	for (const auto& ch : str)
	{
		_cout << ch;
	}
	return _cout;
}
istream& operator>>(istream& _cin, String& str)
{
	char ch;
	while (ch = getchar())
	{
		if (ch == ' ' || ch == '\n' || ch == '\t')
		{
			break;
		}
		str += ch;
	}
	return _cin;
}

void test()
{
	String str("a");
	String str2("hh");
	char str3('c');
	str.push_back('a');
	str.push_back('b');
	str.push_back('c');
	str.push_back('d');
	str.push_back('e');
	cout << "push_back: " << str << endl;
	str += str2;
	cout << "+=: " << str << endl;
	str += str3;
	cout << "+=: " << str << endl;
	str.append("abc");
	cout << "append: " << str << endl;
	cout << "size: " << str.size() << endl;
	cout << "capacity: " << str.capacity() << endl;
	str.insert(0,"12");
	cout << "insert: " << str << endl;
	str.insert(0, 'c');
	cout << "insert: " << str << endl;
	str.erase(0, 2);
	cout << "erase: " << str << endl;
	str.erase(3, 4);
	cout << "erase: " << str << endl;

		
	String str4("hh");
	bool ret1 = str < str2;
	bool ret2 = str <= str4;
	bool ret3 = str > str2;
	bool ret4 = str2 >= str;
}

int main()
{
	test();
	return 0;
}