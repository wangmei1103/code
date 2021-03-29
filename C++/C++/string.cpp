/*
#include<iostream>
#include<string>
using namespace std;
void test14()
{
	string str = "1234abcd123abc";
	size_t pos;
	pos = str.find_first_of("abc",0); //4 匹配第一个字符a
	cout << pos << endl;
	pos = str.find_last_of("123"); //10 匹配最后一个字符3
	cout << pos << endl;
	pos = str.find_first_not_of("123a",0); // 3 返回在字符串中首次不匹配123a的字符索引
	cout << pos << endl;
	pos = str.find_last_not_of("389"); //13 返回在字符串中最后一次不匹配389的字符索引
	cout << pos << endl;
}

void test13()
{
	//正向查找
	string str = "http://www.cplusplus.com/reference/string/string/substr/";
	size_t pos = str.find("://");
	if (pos != string::npos)
	{
		size_t pos2 = str.find("/", pos + 3);
		if (pos2 != string::npos)
		{
			pos += 3;
			string sub = str.substr(pos, pos2 - pos);
			cout << sub << endl; //www.cplusplus.com
		}
	}
	//反向查找
	string str2 = "test.txt.tar.gz.cpp";
	size_t pos2 = str2.rfind(".");
	if (pos != string::npos)
	{
		cout << str2.substr(pos2 + 1); //cpp
	}
}
void test12()
{
	string str = "12345abcd123456789";
	string str2 = "123456789";
	size_t pos = str.find(str2); //9 第九个位置
	pos = str.find("abc", 5, 3); //5 第五个位置
	pos = str.find('a'); // 5 第五个位置
	pos = str.find("xyz"); //4294967295  即-1  未找到
}

<<<<<<< HEAD:string/string.cpp
void test11()
{
	string str = "123456789";
	str.pop_back(); //12345678
	str.erase(0, 1); //2345678
	str.erase(3, 2); //23478
	str.erase(str.size() - 1, 1); //2347
	str.erase(str.end() - 1); //234
	str.erase(str.begin()); //34
	str.erase(str.begin(), str.end() - 1); //4
	str.erase(str.begin(), str.end()); //""
	
									   //replace
	//string str = "1234";
	//string str2 = "abc";
	//str.replace(1, 2, str2); //1abc4
}
=======
>>>>>>> 5082bc018b6a51329c4e1713e6913cee6af8859d:C++/C++/妯℃澘/妯℃澘/string.cpp

void test10()
{
	string str = "123";
	string str2 = "abc";
	str.insert(0, str2); //abc123
	str.insert(4, str2, 1, 2); //abc1bc23
	str.insert(str.size(), "abc"); //abc1bc23abc
	str.insert(5, "12345", 4); //abc1b 1234 c23abc
	str.insert(str.begin(), 2, '0'); //00 abc1b1234c23abc
	str.insert(str.end(), str2.begin(), str2.end()); //00abc1b1234c23abcabc
}

void test9()
{
	string str;
	string str2 = "123";
	str.assign(str2); //123
	str.assign(str2, 1, 1); //2
	str.assign("abc"); //abc
	str.assign("abcde", 2); //ab
	str.assign(5, 'a'); //aaaaa
	str.assign(++str2.begin(), str2.end());//23
}
void test8()
{
	string str;
	string str2 = "123";
	str.append(str2); //123
	str.append(str2, 1, 1); //1232
	str.append("abc"); //1232abc
	str.append("123456", 6); //1232abc123456
	str.append(5, 'm'); //1232abc123456mmmmm
	char arr[] = "abcd";
	str.append(arr, arr + sizeof(arr) / sizeof(arr[0]));  //1232abc123456mmmmmabcd
	str.append(str2.begin(), str2.end());  //1232abc123456mmmmmabcd123
}

void test7()
{
	string str;
	string str2 = "123";
	str.operator+=('a');
	str2.operator+=('4');
	cout << str << endl; //a
	cout << str2 << endl; //1234
}
void test6()
{
	//增容规则：1.5倍
	string str;
	//提前开好空间，避免频繁增容，提高代码的效率
	str.reserve(200);
	int cap = str.capacity();
	cout << cap << endl;
	for (int i = 0; i < 200; i++)
	{
		str.push_back('a');
		if (cap != str.capacity())
		{
			cap = str.capacity();
			cout << cap << endl;
		}
	}
}
//15 31 47 70 105 157 235

void test5()
{
	string str = "123";
	cout << str.size() << endl; //3
	cout << str.capacity() << endl; //15
	str.reserve(100);
	cout << str.size() << endl; //3
	cout << str.capacity() << endl; //111
	str.shrink_to_fit(); //降低容量以适应大小
	cout << str.size() << endl; //3
	cout << str.capacity() << endl; //15
}

void test4()
{
	//反向迭代器
	string str = "12345";
	//最后一个元素的位置
	string::reverse_iterator it = str.rbegin();
	while (it != str.rend())
	{
		cout << *it << " ";
		//反向移动
		++it;
	}

	//只读反向迭代器:不支持修改
	const string str2 = "abcde";
	string::const_reverse_iterator it2 = str2.rbegin();
	while (it2 != str2.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
}
void test3()
{
	//正向迭代器
	string str = "12345";
	//起始位置的迭代器
	string::iterator it1 = str.begin();
	for (; it1 != str.end(); ++it1)
	{
		//迭代器的解引用
		cout << *it1 << " ";
		//通过迭代器进行内容的修改
		*it1 = 'a';
	}
	const string str2 = "abcde";
	//只读迭代器  不能修改内容
	string::const_iterator it2 = str2.begin();
	while (it2 != str2.end())
	{
		cout << *it2 << " ";
		++it2;
	}
}

void test2()
{
	string s;
	//void reserve (size_t n = 0);
	s.reserve(100); //reserve不会改变string中的有效元素个数
	cout << s << endl;  
	cout << s.size() << endl;  //0
	cout << s.capacity() << endl;  //111

	s.reserve(50);
	cout << s << endl;  //reserve参数小于string的底层空间大小时，不会缩小string的底层空间
	cout << s.size() << endl;  //0
	cout << s.capacity() << endl;  //111
}

void test1()
{
	//string类对象支持直接用cin和cout进行输入输出
	string s("hello world");
	cout << s << endl; 
	cout << s.size() << endl;  //11
	cout << s.length() << endl;  //11
	cout << s.capacity() << endl;  //15
	cout << s.max_size() << endl;  //2147483647

	s.clear();//将s中的字符串清空，只是将size清空，不改变底层空间的大小
	cout << s.size() << endl;  //0
	cout << s.capacity() << endl;  //15
	
	//void resize(size_t n, char c);
	s.resize(10, 'a');//将s中的有效字符个数增加到10个，多出来的位置用字符‘a’进行填充
	cout << s << endl;  //aaaaaaaaaa
	cout << s.size() << endl;  //10
	cout << s.capacity() << endl;  //15

	//void resize (size_t n);
	s.resize(15);//将s中的有效字符个数增加到15个，多出的位置用缺省值'\0'进行填充
	cout << s << "over!" << endl;  //aaaaaaaaaa     over!	cout << s.size() << endl;
	cout << s.capacity() << endl;  //15
	s.resize(5);
	cout << s.size() << endl;  //5
	cout << s.capacity() << endl;  //15
}

void test()
{
	//default (1)
	//	string();
	//创建一个空的string对象
	string str;
	//copy(2)
	//	string(const string& str);
	//拷贝构造函数
	string copy(str);
	//from c - string(3)
	//	string(const char* s);
	//用C-string来创建string类对象
	string str2("abc");
	//substring(4)
	//	string(const string& str, size_t pos, size_t len = npos);
	//用一个对象部分内容创建一个新对象
	string substr(str2, 1, 2);//"bc"
	//from sequence(5)
	//	string(const char* s, size_t n);
	//字符串中截取n个字符来创建string对象
	string str3("123456789", 5);
	//fill(6)
	//	string(size_t n, char c);
	//创建一个string对象，对象中包含的字符内容是n个字符c
	string str4(10, 'a');
	string str5 = "abcdef";//单参构造的隐式类型转换
}

//string类的常见构造
void test0()
{
	//string s1;//构造空的string类对象s1
	//string s2("hello world");//用C格式字符串构造string类对象s2
	//string s3(s2);//拷贝构造s3

	const string str = "12345";
	string str2 = "12345";
	//const对象，调用接口：const char& operator[](size_t pos)const
	char ch = str[3];
	const char& ref = str[3];
	//非const对象，调用接口：char& operator[](size_t pos)
	char& ref2 = str2[3];
	str2[3] = 'a';

	str2.at(3) = 'b';
	//[]越界：报断言错误
	char ch2 = str[10];
	//st接口越界：抛异常
	char ch3 = str.at(10);
}/*
int main()
{
	test14();
	return 0;

}
*/
