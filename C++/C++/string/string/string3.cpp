//#include<iostream>
//using namespace std;
//#include<string.h>
//#pragma warning (disable:4996)
////
//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str)
//			str = "";
//		_str = new char(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	String(const String &s)
//		:_str(nullptr)
//	{
//		String tmp(s._str);
//		Swap(tmp);
//	}
//	void Swap(String& s)
//	{
//		swap(_str, s._str);
//	}
//	String& operator=(const String &s)
//	{
//		if (this != &s)
//		{
//			String tmp(s._str);
//			Swap(tmp);
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (_str)  
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char *_str;
//};
//
//void test()
//{
//	String str("123456");
//	String str2 = str;
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//
