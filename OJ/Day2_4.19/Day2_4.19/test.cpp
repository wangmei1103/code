//#include<iostream>
//using namespace std;
//#include<string>
//#include<algorithm>
//int main()
//{
//	string str;
//	getline(cin, str);
//	reverse(str.begin(), str.end());
//	str.push_back(' ');
//	string::iterator it = str.begin();
//	string::iterator it1 = str.begin();
//	while (it != str.end())
//	{
//		if (*it == ' ')
//		{
//			reverse(it1, it);
//			it1 = it + 1;
//		}
//		it++;
//	}
//	str.pop_back();
//	cout << str << endl;
//}



#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int count = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if ((A[i - 1] <= A[i] && A[i + 1] <= A[i]) || (A[i - 1] >= A[i] && A[i + 1] >= A[i]))
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char acX[] = "abc";
//	char acY[] = { 'a','b','c' };
//	const char *szX = "abc";
//	const char *szY = "abc";
//	return 0;
//}

//class Sample
//{
//public:
//	Sample(int x)
//	{
//		p = new int(x);
//	}
//	~Sample()
//	{
//		if(p)
//			delete p;
//	}
//	int show()
//	{
//		return *p;
//	}
//private:
//	int *p;
//};
//int main()
//{
//	Sample S(5);
//	cout << S.show() << endl;
//	return 0;
//}

//struct A
//{
//	unsigned a : 19;
//	unsigned b : 11;
//	unsigned c : 4;
//	unsigned d : 29;
//	char index;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	return 0;
//}

//void sss(char[], int[]);
//int main()
//{
//	int a[10];
//	char b[80];
//	sss(b,a);//调用形式
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	int *b = a;
//	*b += 2;
//	*(b + 2) = 2;
//	cout << *b << " " << *(b + 2) << endl;
//	return 0;
//}