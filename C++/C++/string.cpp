/*
#include<iostream>
#include<string>
using namespace std;
void test14()
{
	string str = "1234abcd123abc";
	size_t pos;
	pos = str.find_first_of("abc",0); //4 ƥ���һ���ַ�a
	cout << pos << endl;
	pos = str.find_last_of("123"); //10 ƥ�����һ���ַ�3
	cout << pos << endl;
	pos = str.find_first_not_of("123a",0); // 3 �������ַ������״β�ƥ��123a���ַ�����
	cout << pos << endl;
	pos = str.find_last_not_of("389"); //13 �������ַ��������һ�β�ƥ��389���ַ�����
	cout << pos << endl;
}

void test13()
{
	//�������
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
	//�������
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
	size_t pos = str.find(str2); //9 �ھŸ�λ��
	pos = str.find("abc", 5, 3); //5 �����λ��
	pos = str.find('a'); // 5 �����λ��
	pos = str.find("xyz"); //4294967295  ��-1  δ�ҵ�
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
>>>>>>> 5082bc018b6a51329c4e1713e6913cee6af8859d:C++/C++/模板/模板/string.cpp

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
	//���ݹ���1.5��
	string str;
	//��ǰ���ÿռ䣬����Ƶ�����ݣ���ߴ����Ч��
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
	str.shrink_to_fit(); //������������Ӧ��С
	cout << str.size() << endl; //3
	cout << str.capacity() << endl; //15
}

void test4()
{
	//���������
	string str = "12345";
	//���һ��Ԫ�ص�λ��
	string::reverse_iterator it = str.rbegin();
	while (it != str.rend())
	{
		cout << *it << " ";
		//�����ƶ�
		++it;
	}

	//ֻ�����������:��֧���޸�
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
	//���������
	string str = "12345";
	//��ʼλ�õĵ�����
	string::iterator it1 = str.begin();
	for (; it1 != str.end(); ++it1)
	{
		//�������Ľ�����
		cout << *it1 << " ";
		//ͨ���������������ݵ��޸�
		*it1 = 'a';
	}
	const string str2 = "abcde";
	//ֻ��������  �����޸�����
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
	s.reserve(100); //reserve����ı�string�е���ЧԪ�ظ���
	cout << s << endl;  
	cout << s.size() << endl;  //0
	cout << s.capacity() << endl;  //111

	s.reserve(50);
	cout << s << endl;  //reserve����С��string�ĵײ�ռ��Сʱ��������Сstring�ĵײ�ռ�
	cout << s.size() << endl;  //0
	cout << s.capacity() << endl;  //111
}

void test1()
{
	//string�����֧��ֱ����cin��cout�����������
	string s("hello world");
	cout << s << endl; 
	cout << s.size() << endl;  //11
	cout << s.length() << endl;  //11
	cout << s.capacity() << endl;  //15
	cout << s.max_size() << endl;  //2147483647

	s.clear();//��s�е��ַ�����գ�ֻ�ǽ�size��գ����ı�ײ�ռ�Ĵ�С
	cout << s.size() << endl;  //0
	cout << s.capacity() << endl;  //15
	
	//void resize(size_t n, char c);
	s.resize(10, 'a');//��s�е���Ч�ַ��������ӵ�10�����������λ�����ַ���a���������
	cout << s << endl;  //aaaaaaaaaa
	cout << s.size() << endl;  //10
	cout << s.capacity() << endl;  //15

	//void resize (size_t n);
	s.resize(15);//��s�е���Ч�ַ��������ӵ�15���������λ����ȱʡֵ'\0'�������
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
	//����һ���յ�string����
	string str;
	//copy(2)
	//	string(const string& str);
	//�������캯��
	string copy(str);
	//from c - string(3)
	//	string(const char* s);
	//��C-string������string�����
	string str2("abc");
	//substring(4)
	//	string(const string& str, size_t pos, size_t len = npos);
	//��һ�����󲿷����ݴ���һ���¶���
	string substr(str2, 1, 2);//"bc"
	//from sequence(5)
	//	string(const char* s, size_t n);
	//�ַ����н�ȡn���ַ�������string����
	string str3("123456789", 5);
	//fill(6)
	//	string(size_t n, char c);
	//����һ��string���󣬶����а������ַ�������n���ַ�c
	string str4(10, 'a');
	string str5 = "abcdef";//���ι������ʽ����ת��
}

//string��ĳ�������
void test0()
{
	//string s1;//����յ�string�����s1
	//string s2("hello world");//��C��ʽ�ַ�������string�����s2
	//string s3(s2);//��������s3

	const string str = "12345";
	string str2 = "12345";
	//const���󣬵��ýӿڣ�const char& operator[](size_t pos)const
	char ch = str[3];
	const char& ref = str[3];
	//��const���󣬵��ýӿڣ�char& operator[](size_t pos)
	char& ref2 = str2[3];
	str2[3] = 'a';

	str2.at(3) = 'b';
	//[]Խ�磺�����Դ���
	char ch2 = str[10];
	//st�ӿ�Խ�磺���쳣
	char ch3 = str.at(10);
}/*
int main()
{
	test14();
	return 0;

}
*/
