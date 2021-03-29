/*
#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>
#pragma warning (disable:4996)
class String
{
public:
	//String的迭代器
	//迭代器操作：类似于指针
	//解引用：*iterator -->获取内容
	//移动 : ++iterator ,--iterator,移动到相邻元素的位置
	//String迭代器实现：字符指针
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		//第一个元素的位置
		return _data;
	}
	iterator end()
	{
		//最后一个元素的下一个位置
		return _data + _size;
	}
	const_iterator begin()const
	{
		//第一个元素的位置
		return _data;
	}
	const_iterator end()const
	{
		//最后一个元素的下一个位置
		return _data + _size;
	}
	//全缺省构造函数
	String(const char* str = "")
	{
		_size = strlen(str);
		_data = new char[_size + 1];
		_capacity = _size;
		strcpy(_data, str);
	}
	String(const String& str)
		:_data(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._data);
		Swap(tmp);
	}
	//交换函数
	void Swap(String& str)
	{
		swap(_data, str._data);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	//赋值运算符
	String& operator=(String str)
	{
		Swap(str);
	}
	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}
	//运算符重载
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}
	const char& operator[](size_t pos)const
	{
		assert(pos < _size);
		return _data[pos];
	}
	size_t size()const
	{
		return _size;
	}
	//尾插字符
	void push_back(const char& ch)
	{
		//检查空间
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			//增容
			reserve(newC);
		}
		_data[_size++] = ch;
		//添加结束字符'\0'
		_data[_size] = '\0';
	}
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//申请空间
			char* tmp = new char[n + 1];
			//拷贝
			strcpy(tmp, _data);
			//释放原有空间
			delete[] _data;
			_data = tmp;
			_capacity = n;
		}
	}
	void resize(size_t n, const char& ch = '\0')
	{
		// n > _capacity:增容
		if (n > _capacity)
		{
			reserve(n);
		}
		//_size < n <= _capacity
		//填充字符 ch
		if (n > _size)
		{
			memset(_data + _size, ch, (n - _size) * sizeof(char));
		}
		//直接修改size
		_size = n;
		_data[_size] = '\0';
	}
	const char* c_str()
	{
		return _data;
	}
	void append(const char* str)
	{
		//检查容量
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//尾插
		memcpy(_data + _size, str, sizeof(char)*len);//内存拷贝，O（1）
		//strcpy(_data + _size, str); //O（n）
		//更新
		_size += len;
		_data[_size] = '\0';
	}
	String& operator+=(const String& str)
	{
		this->append(str._data);
		//append(str._data);
		return *this;
	}
	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	String& operator+=(const char ch)
	{
		push_back(ch);
		return *this;
	}
	//插入字符
	void insert(size_t pos, const char& ch)
	{
		//检查位置有效性
		assert(pos <= _size);
		//检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity = 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//移动元素：[pos, size]  从后向前
		size_t end = _size + 1; 
		while (end > pos)
		{
			_data[end] = _data[end - 1]; //第一次拷贝的就是\0
			--end;
		}
		//插入：pos
		_data[pos] = ch;
		//更新
		++_size;
	}
	//插入字符串
	void insert(size_t pos, const char* ptr)
	{
		//检查位置
		assert(pos <= _size);
		//检查容量
		int len = strlen(ptr);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//移动元素  从后向前
		size_t end = _size + len;
		while (end > pos + len -1)
		{
			_data[end] = _data[end - len]; //第一次拷贝的就是'\0'
			--end;
		}
		//插入
		memcpy(_data + pos, ptr, sizeof(char)*len);
		//更新
		_size += len;
	}
	//删除字符
	void erase(size_t pos,size_t len)
	{
		//检查位置
		assert(pos < _size);
		//要删除的个数大于剩余字符的个数
		if (pos + len >= _size)
		{
			_size = pos;
			_data[_size] = '\0';
		}
		else {
			//移动元素   从前向后
			size_t start = pos + len;
			for (; start <= _size; ++start)
			{
				_data[pos++] = _data[start];
			}
			_size -= len;
		}
	}
	size_t find(const char& ch, size_t pos = 0 )
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_data[i] == ch)
				return i;
		}
		return npos;
	}
	size_t find(const char* str, size_t pos = 0)
	{
		//strstr返回值：
		//NULL：未找到
		//有效的地址：字串出现的首地址
		char* ptr = strstr(_data, str);
		if (ptr)
		{
			return ptr - _data;
		}
		return npos;
	}
	ostream& operator<<(ostream& out)
	{
		for (const char& ch : *this) // *this表示当前对象
		{
			out << ch;
		}
		return out;
	}
private:
	char* _data;
	//size：有效字符的个数
	size_t _size;
	//capacity：可以保存的最大有效字符个数
	size_t _capacity;

	static const size_t npos;
};
ostream& operator<<(ostream& out, const String& str)
{
	for (const auto& ch : str) 
	{
		out << ch;
	}
	return out;
}
istream& operator>>(istream& in, String& str)
{
	char ch;
	while (ch = getchar())
	{
		if (ch == ' ' || ch == '\n' || ch == '\t')
			break;
		str += ch;
	}
	return in;
}
bool operator>(const String& str1, const String& str2)
{
	int ret = strcmp(str1.c_str(), str2.c_str());
	if (ret > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

String operator+(const String& str1, const String& str2)
{
	String copy(str1);
	copy += str2;
	return copy;
}
String operator+(const String& str1, const char* str2)
{
	String str;
	str += str1;
	str += str2;
	return str;
}
String operator+(const char& ch, const String& str1)
{
	String copy(str1);
	copy += ch;
	return copy;
}
 
void test()
{
	String str("6789"); //6789
	str.insert(0, "879"); //8796789
	str.insert(3, "abd"); //879abd6789
	str.erase(0, 2); //9abd6789
	str.erase(3, 6); //9ab
}*/
/*
void test()
{
	String str, str2;
	str = "1234";
	str2 = "12345";
	const char* ptr = "567";
	char ch = '8';

	str += str2;
	str += ptr;
	str += ch;
	String ret = str + str2;
	ret = str + ptr;
	ret = ch + str;

	String str3;
	str3.insert(0, '6'); //头插 6
	str3.insert(1, '7'); //尾插 67 
	str3.insert(1, 'a'); //任意插 6a7
}*/

/*
void test()
{
	String str;
	str.append ("123456");
	str.append ("123678");
}*/

/*
void test()
{
	String str;
	str.push_back('1');
	cout << str.c_str() << endl;
	str.push_back('2');
	cout << str.c_str() << endl;
	str.push_back('3');
	cout << str.c_str() << endl;
	str.push_back('4');
	cout << str.c_str() << endl;
	str.push_back('5');
	cout << str.c_str() << endl;

	str.resize(3); //123
	str.resize(10, 'a'); //123aaaaaaa
	str.resize(20, 'b'); //123aaaaaaaaaaaaaaaaa
}*/
/*
void printStringFor(const String& str)
{
	for (const char& ch : str)
	{
		cout << ch << " ";
	}
	cout << endl;
}
void printStringIt(const String& str)
{
	String::const_iterator it = str.begin(); //不支持写操作
	while (it != str.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test()
{
	String str = "123456789";
	printStringFor(str);
	printStringIt(str);
}*/
/*
void test()
{
	String str("0123456789");
	//for循环
	for (size_t i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
		//str.operator[i];
		str[i] = 'a';
		//str.operator[](i) = 'b'; 修改内容为b
	}
	cout << endl;
	//范围for:通过迭代器实现
	for (const auto& ch : str)
	{
		cout << ch << " ";
	}
	cout << endl;
	//迭代器
	String::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		//*it = 'c'; 修改内容为c
		++it;
	}
	cout << endl;
}*/
//int main()
//{
//	test();
//	return 0;
//}