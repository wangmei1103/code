/*
#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>
#pragma warning (disable:4996)
class String
{
public:
	//String�ĵ�����
	//������������������ָ��
	//�����ã�*iterator -->��ȡ����
	//�ƶ� : ++iterator ,--iterator,�ƶ�������Ԫ�ص�λ��
	//String������ʵ�֣��ַ�ָ��
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		//��һ��Ԫ�ص�λ��
		return _data;
	}
	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}
	const_iterator begin()const
	{
		//��һ��Ԫ�ص�λ��
		return _data;
	}
	const_iterator end()const
	{
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}
	//ȫȱʡ���캯��
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
	//��������
	void Swap(String& str)
	{
		swap(_data, str._data);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	//��ֵ�����
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
	//���������
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
	//β���ַ�
	void push_back(const char& ch)
	{
		//���ռ�
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			//����
			reserve(newC);
		}
		_data[_size++] = ch;
		//��ӽ����ַ�'\0'
		_data[_size] = '\0';
	}
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//����ռ�
			char* tmp = new char[n + 1];
			//����
			strcpy(tmp, _data);
			//�ͷ�ԭ�пռ�
			delete[] _data;
			_data = tmp;
			_capacity = n;
		}
	}
	void resize(size_t n, const char& ch = '\0')
	{
		// n > _capacity:����
		if (n > _capacity)
		{
			reserve(n);
		}
		//_size < n <= _capacity
		//����ַ� ch
		if (n > _size)
		{
			memset(_data + _size, ch, (n - _size) * sizeof(char));
		}
		//ֱ���޸�size
		_size = n;
		_data[_size] = '\0';
	}
	const char* c_str()
	{
		return _data;
	}
	void append(const char* str)
	{
		//�������
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//β��
		memcpy(_data + _size, str, sizeof(char)*len);//�ڴ濽����O��1��
		//strcpy(_data + _size, str); //O��n��
		//����
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
	//�����ַ�
	void insert(size_t pos, const char& ch)
	{
		//���λ����Ч��
		assert(pos <= _size);
		//�������
		if (_size == _capacity)
		{
			size_t newC = _capacity = 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//�ƶ�Ԫ�أ�[pos, size]  �Ӻ���ǰ
		size_t end = _size + 1; 
		while (end > pos)
		{
			_data[end] = _data[end - 1]; //��һ�ο����ľ���\0
			--end;
		}
		//���룺pos
		_data[pos] = ch;
		//����
		++_size;
	}
	//�����ַ���
	void insert(size_t pos, const char* ptr)
	{
		//���λ��
		assert(pos <= _size);
		//�������
		int len = strlen(ptr);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//�ƶ�Ԫ��  �Ӻ���ǰ
		size_t end = _size + len;
		while (end > pos + len -1)
		{
			_data[end] = _data[end - len]; //��һ�ο����ľ���'\0'
			--end;
		}
		//����
		memcpy(_data + pos, ptr, sizeof(char)*len);
		//����
		_size += len;
	}
	//ɾ���ַ�
	void erase(size_t pos,size_t len)
	{
		//���λ��
		assert(pos < _size);
		//Ҫɾ���ĸ�������ʣ���ַ��ĸ���
		if (pos + len >= _size)
		{
			_size = pos;
			_data[_size] = '\0';
		}
		else {
			//�ƶ�Ԫ��   ��ǰ���
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
		//strstr����ֵ��
		//NULL��δ�ҵ�
		//��Ч�ĵ�ַ���ִ����ֵ��׵�ַ
		char* ptr = strstr(_data, str);
		if (ptr)
		{
			return ptr - _data;
		}
		return npos;
	}
	ostream& operator<<(ostream& out)
	{
		for (const char& ch : *this) // *this��ʾ��ǰ����
		{
			out << ch;
		}
		return out;
	}
private:
	char* _data;
	//size����Ч�ַ��ĸ���
	size_t _size;
	//capacity�����Ա���������Ч�ַ�����
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
	str3.insert(0, '6'); //ͷ�� 6
	str3.insert(1, '7'); //β�� 67 
	str3.insert(1, 'a'); //����� 6a7
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
	String::const_iterator it = str.begin(); //��֧��д����
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
	//forѭ��
	for (size_t i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
		//str.operator[i];
		str[i] = 'a';
		//str.operator[](i) = 'b'; �޸�����Ϊb
	}
	cout << endl;
	//��Χfor:ͨ��������ʵ��
	for (const auto& ch : str)
	{
		cout << ch << " ";
	}
	cout << endl;
	//������
	String::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		//*it = 'c'; �޸�����Ϊc
		++it;
	}
	cout << endl;
}*/
//int main()
//{
//	test();
//	return 0;
//}