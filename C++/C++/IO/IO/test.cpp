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
	ss.clear();//��һ��ת��֮ǰ������clear�ӿ����״̬λ,�������stringstream�����е�����
	ss << f;
	ss >> str;

	//str(��������)������stringstream�����е�����
	ss.str("");
	//str():��ȡstringstream�����е�����
	str = ss.str();
	ss.clear();
	ss << f;
	str = ss.str();

	//�ַ���ƴ��
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
	//ofstream:����ļ���
	//ifstream�������ļ���
	//д�ļ����ļ������ڣ������ļ�
	//ofstream fout("test.txt");
	////fout.open("test.txt");
	//if (!fout.is_open())
	//	cout << "file not open" << endl;
	////д����
	////1.�ı���ʽ:�ַ�����д
	//fout << "test.txt" << endl;
	//fout.put(' ');
	//fout.put('a');
	//fout.close();

	//���ļ����ļ������ڣ���ʧ��
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
	////�����ƶ�д ���ֽ�����д
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
//	//cin��istream����
//	int a;
//	cin >> a;
//	//cin.operator>>(a);
//	float f;
//	cin >> f;
//	//cin.operator>>(f);
//	char arr[10];
//	cin >> arr;
//
//	//cout��ostream����
//	cout << a << endl;
//	cout.operator<<(a).operator<<(endl);
//	cout << f << endl;
//	cout << arr << endl;
//	//sacnf,printf:�⺯��
//
//	//cerr��clog
//	cerr << f << endl;
//	clog << arr << endl;
//
//}
//�����������
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