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
	//全缺省构造
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
	//析构
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
		//第一个元素位置
		return _str; 
	}
	iterator end()
	{
		//最后一个元素的下一个位置
		return _str + _size;
	}
	const iterator begin()const
	{
		//第一个元素位置
		return _str;
	}
	const iterator end()const
	{
		//最后一个元素的下一个位置
		return _str + _size;
	}

	// modify
	//尾插字符'c'
	void push_back(char c)
	{
		//检查空间
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			//增容
			reserve(newC);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	//追加字符串
	void append(const char* str)
	{
		//检查容量
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//尾插  内存拷贝
		memcpy(_str + _size, str, sizeof(char)*len);
		//更新
		_size += len;
		_str[_size] = '\0';
	}
	//赋值运算符
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
		//n>_capacity：增容
		if (n > _capacity)
		{
			reserve(n);
		}
		//_size < n <= _capacity
		//填充字符 c
		if (n > _size)
		{
			memset(_str + _size, c, (n - _size) * sizeof(char));
		}
		//直接修改size
		_size = n;
		_str[_size] = '\0';
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//申请空间
			char* tmp = new char[n + 1];
			//拷贝
			strcpy(tmp, _str);
			//释放原有空间
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

	// 返回c在string中第一次出现的位置
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

	// 返回子串s在string中第一次出现的位置
	size_t find(const char* s, size_t pos = 0) const
	{
		char* ptr = strstr(_str,s);
		if (ptr)
		{
			return ptr - _str;
		}
		return npos;
	}

	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	String& insert(size_t pos, char c)
	{
		//检查位置
		assert(pos <= _size);
		//检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity = 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//移动元素，从后向前
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1]; //第一次拷贝的就是\0
			--end;
		}
		//插入
		_str[pos] = c;
		//更新
		++_size;
		return *this;
	}

	String& insert(size_t pos, const char* str)
	{
		//检查位置
		assert(pos <= _size);
		//检查容量
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//移动元素  从后向前
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		//插入
		memcpy(_str + pos, str, sizeof(char)*len);
		//更新
		_size += len;
		return *this;
	}


	// 删除pos位置上的元素，并返回该元素的下一个位置
	String& erase(size_t pos, size_t len)
	{
		//检查位置
		assert(pos < _size);
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else {
			//移动元素，从前向后
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
	size_t _size; //有效字符的个数
	size_t _capacity; //可以保存的最大有效字符个数
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