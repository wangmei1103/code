#include<stdio.h>
#include<iostream>
using namespace std;
#include<string>
#include<vector>

int min(int a, int b)
{
	return a > b ? b : a;
}
// 计算约数，求除了1和本身的约数
void divisorNum(int n, vector<int> &divNum) {
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			divNum.push_back(i);
			// 非平方数时还有另一个数也要加上
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}

int Jump(int N, int M) {
	// 存储的到达此stepNum点的步数，初始N为1步，从N到N为1步
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;

	for (int i = N; i < M; ++i) {
		// N的所有约数，即为从本身这个点开始能走的数量
		vector<int> divNum;

		// 0代表这个点不能到
		if (stepNum[i] == 0)
			continue;

		// 求出所有走的步数储存在divNum的容器中
		divisorNum(i, divNum);

		for (int j = 0; j < divNum.size(); ++j) {
			// 由位置i出发能到达的点为stepNum[divNum[j] + i]
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}

	if (stepNum[M] == 0)
		return -1;
	else
		// 初始化时多给了一步，故需要减1
		return stepNum[M] - 1;
}

int main() {
	int n, m;
	while (cin >> n >> m)
	{
		cout << Jump(n, m) << endl;
	}
	return 0;
}

//void get(int n, vector<int>& v)
//{
//	for (int i = 2; i < n; i++)
//	{
//		if (n%i == 0)
//			v.push_back(i);
//	}
//}
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		//到达当前石板用的最小步数
//		vector<int> arr(m + 1, -1);
//		arr[n] = 0;
//		for (int i = n; i <= m; i++)
//		{
//			//不能到达
//			if (arr[i] == -1)
//				continue;
//			vector<int> v;
//			get(i, v);
//			for (int j = 0; j < v.size(); j++)
//			{
//				if (i + v[j] <= m)
//				{
//					//没到达过这个石板
//					if (arr[i + v[j]] == -1)
//						arr[i + v[j]] = arr[i] + 1;
//					else
//					{
//						//多次到达求最小的步数
//						arr[i + v[j]] = (arr[i] + 1) > (arr[i + v[j]]) ? (arr[i+v[j]]) : (arr[i] + 1);
//					}
//				}
//			}
//		}
//		if (arr[m] == 0)
//			cout << "-1" << endl;
//		else
//			cout << arr[m] << endl;
//	}
//	return 0;
//}

//bool prime(int n)
//{
//	for (int i = 2; i < sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return false;
//		return true;
//	}
//}
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//	if (prime(N) == 1)
//		cout << "-1" << endl;
//	int count = 0;
//	int X = N;
//	while (X <= M)
//	{
//		for (int i = 2; i < M/N; i++)
//		{
//			if (N%i == 0)
//			{
//				X = N + i;
//				count++;
//				//break;
//			}
//		}
//		if (X > M)
//			cout << "-1" << endl;
//	}
//	if(X<=M)
//		cout << count << endl;
//	return 0;
//}

//void test(string str)
//{
//	int count = 1;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ' ')
//		{
//			count++;
//			str[i] = '\n';
//		}
//	}
//	cout << count << endl;
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str[i];
//	}
//	
//}
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	test(str);
//	return 0;
//}

//class A
//{
//public:
//	virtual void print()
//	{
//		cout << "A::print()" << "\n";
//	}
//};
//class B :public A
//{
//public:
//	virtual void print()
//	{
//		cout << "B::print()" << "\n";
//	}
//};
//class C : public A
//{
//public:
//	virtual void print()
//	{
//		cout << "C::print()" << "\n";
//	}
//};
//void print(A a)
//{
//	a.print();
//}
//int main()
//{
//	A a, *aa, *ab, *ac;
//	B b;
//	C c;
//	aa = &a;
//	ab = &b;
//	ac = &c;
//	a.print();
//	b.print();
//	c.print();
//	aa->print();
//	ab->print();
//	ac->print();
//	print(a);
//	print(b);
//	print(c);
//	return 0;
//}

//int main()
//{
//	int i, a[10];
//	for (i = 9; i >= 0; i--)
//		a[i] = 10 - i;
//	printf("%d%d%d", a[2], a[5], a[8]);
//	return 0;
//}

//class B
//{
//public:
//	B()
//	{
//		cout << "dc" << " ";
//	}
//	~B()
//	{
//		cout << "d" << " ";
//	}
//	B(int i) :data(i)
//	{
//		cout << "cbp" << " ";
//	}
//private:
//	int data;
//};
//B Play(B b)
//{
//	return b;
//}
//int main()
//{
//	B tmp = Play(5);
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3;
//	i = ++a || ++b || ++c;
//	cout<< i << " " << a << " " << b << " " << c << endl;
//	return 0;
//}

//struct str_t
//{
//	long long len;
//	char data[32];
//};
//struct data1_t
//{
//	long long len;
//	int data[2];
//};
//struct data2_t
//{
//	long long len;
//	char *data[1];
//};
//struct data3_t
//{
//	long long len;
//	void *data[];
//};
//int main()
//{
//	struct str_t str;
//	memset((void*)&str, 0, sizeof(struct str_t));
//	str.len = sizeof(struct str_t) - sizeof(int);
//	_snprint(str.data, str.len, "hello");
//	struct data2_t *pData = (struct data2_t*)&str;
//	printf("data:%s%s\n", str.data, (char*)(pData->data[0]));
//	return 0;
//}