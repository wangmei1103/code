#include<iostream>
#include<array>
#include<fstream>
#include<sstream>
using namespace std;
#pragma warning(disable:4996)
void test()
{
	//aoti atof
	int a = 10;
	int b = 010; //8
	int c = 0x10; //16
	char arr[100];
	itoa(a, arr, 10);
	itoa(b, arr, 8);
	itoa(c, arr, 16);
	sprintf(arr, "%d", a);
	float f = 2.3;
	sprintf(arr, "%f", f);
	printf("%d", a);

	stringstream ss;
	string str;
	ss << a;
	ss >> str;
	ss.clear();//下一次转换之前，调用clear接口清空状态位,不会清空stringstream对象中的内容
	ss << f;
	ss >> str;

	//str(重置内容)：重置stringstream对象中的内容
	ss.str("");
	//str():获取stringstream对象中的内容
	str = ss.str();
	ss.clear();
	ss << f;
	str = ss.str();

	//字符串拼接
	ss.str("");
	ss << "123" << "345" << "789";
	cout << ss.str() << endl;
}

struct Student
{
	char name[10];
	int age;
};

//void test()
//{
	//ofstream:输出文件流
	//ifstream：输入文件流
	//写文件：文件不存在，创建文件
	//ofstream fout("test.txt");
	////fout.open("test.txt");
	//if (!fout.is_open())
	//	cout << "file not open" << endl;
	////写内容
	////1.文本形式:字符流读写
	//fout << "test.txt" << endl;
	//fout.put(' ');
	//fout.put('a');
	//fout.close();

	//读文件：文件不存在，打开失败
	//ifstream fin("test.txt");
	//char arr[100];
	////fin >> arr;
	//char ch;
	//ch = fin.get();
	//fin.get(ch);
	////fin.get(arr, 100);
	//fin.getline(arr, 10);


	//ofstream fout("test.txt");
	//Student stu;
	//stu.age = 30;
	//strcpy(stu.name, "abc");
	//fout << stu.name << endl;
	//fout << stu.age << endl;
	//fout.close();
	////二进制读写 ：字节流读写
	//ofstream fout2("test.binary.txt");
	//fout2.write((char*)&stu, sizeof(stu));
	//fout2.close();

	//ifstream fin("test.binary.txt");
	//Student stu;
	///*fin >> stu.name;
	//fin >> stu.age;*/
	//fin.read((char*)&stu, sizeof(stu));
//}


//void test()
//{
//	//cin：istream对象
//	int a;
//	cin >> a;
//	//cin.operator>>(a);
//	float f;
//	cin >> f;
//	//cin.operator>>(f);
//	char arr[10];
//	cin >> arr;
//
//	//cout：ostream对象
//	cout << a << endl;
//	cout.operator<<(a).operator<<(endl);
//	cout << f << endl;
//	cout << arr << endl;
//	//sacnf,printf:库函数
//
//	//cerr、clog
//	cerr << f << endl;
//	clog << arr << endl;
//
//}
//输入输出数据
//void test()
//{
//	
//	int a;
//	while (cin >> a)
//	{
//		cout << a << endl;
//	}
//}
int main()
{
	test();
	return 0;
}