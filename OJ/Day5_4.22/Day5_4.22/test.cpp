#include<iostream>
using namespace std;

//int main()
//{
//	int a[3];
//	a[0] = 0; a[1] = 1; a[2] = 2;
//	int *p, *q;
//	p = a;
//	q = &a[2];
//	cout << a[q - p] << endl;
//	const char* node ="ABC";
//	node = "kyu";
//
//	int b = 0xabcd1234;
//	char c = ((char*)&a)[0];
//	return 0;
//}



//#include<string>
//#include<vector>
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> array(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> array[i];
//	}
//	int cursum = array[0];
//	int maxsum = array[0];
//	for (int i = 1; i < array.size(); i++)
//	{
//		cursum += array[i];
//		if (cursum < array[i])
//			cursum = array[i];
//		if (cursum > maxsum)
//			maxsum = cursum;
//	}
//	cout << maxsum;
//	return 0;
//}


//bool test(string str1) {
//	int n = str1.size();
//	if (n == 1) {
//		return true;
//	}
//	else {
//		for (int i = 0, j = n - 1; i < j; i++, j--) {
//			if (str1[i] != str1[j]) {
//				return 	false;
//			}
//		}
//		return true;
//	}
//}
//int main() {
//	int count = 0;
//	string str1, str2, tmp;
//	cin >> str1 >> str2;
//	for (int i = 0; i < str1.size() + 1; i++) {
//		tmp = str1.substr(0, i) + str2 + str1.substr(i);
//		if (test(tmp)) {
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//int main()
//{
//	int a;
//	float b, c;
//	scanf_s("%2d%3f%4f", &a, &b, &c);
//	printf("\na=%d,b=%d,c=%f\n", a, b, c);
//	return 0;
//}


/*int main()
{
	int n[][3] = { 10,20,30,40,50,60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2] << endl;
	return 0;
}*/

//#pragma pack(4)
////#pragma pack(8)
//struct A {
//	double d;
//	char c;
//	int i;
//};
//struct B
//{
//	char c;
//	double d;
//	int i;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	return 0;
//}

//class B0
//{
//public:
//	virtual void display()
//	{
//		cout << "B0::display0" << endl;
//	}
//};
//class B1 :public B0
//{
//public:
//	void display()
//	{
//		cout << "B1::display0" << endl;
//	}
//};
//class D1 :public B1
//{
//public:
//	void display()
//	{
//		cout << "D1::display0" << endl;
//	}
//};
//void fun(B0 ptr)
//{
//	ptr.display();
//}
//int main()
//{
//	B0 b0;
//	B1 b1;
//	D1 d1;
//	fun(b0);
//	fun(b1);
//	fun(d1);
//	return 0;
//}

//#pragma warning (disable :4996)
//int main()
//{
//	char p1[15] = "abcd", str[50] = "xyz";
//	const char *p2 = "ABCD";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	cout << str;
//	return 0;
//}

//int main()
//{
//	int x = 1;
//	do {
//		cout << x++ << endl;
//	} while (x--);
//	return 0;
//}