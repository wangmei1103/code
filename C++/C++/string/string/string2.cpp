#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>
#pragma warning (disable:4996)
class String
{
public:
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
private:
	char* _data;
	//size����Ч�ַ��ĸ���
	size_t _size;
	//capacity�����Ա���������Ч�ַ�����
	size_t _capacity;
};
void test()
{
	String str("0123456789");
	for (size_t i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
		//str.operator[i];
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}