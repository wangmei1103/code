#include<iostream>
using namespace std;
#include<vector>
#include<string>

//int main() {
//	// ��������
//	int n;
//	// ����
//	string order;
//	while (cin >> n >> order) {
//		// �� n �׸������1 : n, numΪ��굱ǰ���ڸ����ı�ţ�firstΪ��ǰ��Ļ��ʾҳ�ĵ�һ�׸����ı��
//		int num = 1, first = 1;
//		if (n <= 4) {
//			// ��������������4ʱ�����и���һҳ������ʾ�꣬����Ҫ��ҳ��firstʼ�ղ���
//			for (int i = 0; i < order.size(); ++i) {
//				if (num == 1 && order[i] == 'U')
//					num = n;
//
//				else if (num == n && order[i] == 'D')
//					num = 1;
//				else if (order[i] == 'U')
//					num--;
//				else
//					num++;
//			}
//			for (int i = 1; i <= n - 1; ++i)
//				cout << i << ' ';
//			cout << n << endl;
//			cout << num << endl;
//		}
//		else {
//			// ������������4ʱ����ʾ��ȫ���и�����Ҫ��ҳ����Ļ������ʾ4�׸���
//			for (int i = 0; i < order.size(); ++i) {
//				if (first == 1 && num == 1 && order[i] == 'U') {
//					// ���ⷭҳ1
//					first = n - 3;;
//					num = n;
//				}
//				else if (first == n - 3 && num == n && order[i] == 'D') {
//					// ���ⷭҳ2
//					first = 1;
//					num = 1;
//				}
//				else if (first != 1 && num == first && order[i] == 'U') {
//					// һ�㷭ҳ1
//					first--;
//					num--;
//				}
//				else if (first != n - 3 && num == first + 3 && order[i] == 'D') {
//					// һ�㷭ҳ2
//					first++;
//					num++;
//				}
//				else if (order[i] == 'U')
//					// �������1
//					num--;
//				else
//					// �������2
//					num++;
//			}
//			for (int i = first; i < first + 3; ++i)
//				cout << i << ' ';
//			cout << first + 3 << endl;
//			cout << num << endl;
//		}
//	}
//	return 0;
//}

//void test(int n, vector<vector<int>> v)
//{
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		int a = 0, b = 0;
//		cin >> a >> b;
//		v[i].resize(2 * a);
//		for (int j = 0; j < 2 * a; j++)
//		{
//			cin >> v[i][j];
//		}
//		vector<int> v1(2 * a);
//		for (int k = 0; k < b; k++)
//		{
//			int start = a - 1, end = 2 * a - 1;
//			int count = end;
//			while (start >= 0)
//			{
//				v1[count--] = v[i][end--];
//				v1[count--] = v[i][start--];
//			}
//			v[i] = v1;
//		}
//		for (auto& e : v1)
//		{
//			cout << e << " ";
//		}
//		//cout << endl;
//	}
//	
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<vector<int>> v;
//		v.resize(n);
//		test(n, v);
//	}
//	return 0;
//}

/*int foo(int x, int y)
{
	if (x <= 0 || y <= 0)
		return 1;
	return 3 * foo(x - 6, y / 2);
}
int main()
{
	cout << foo(20, 13) << endl;
	return 0;
}*/