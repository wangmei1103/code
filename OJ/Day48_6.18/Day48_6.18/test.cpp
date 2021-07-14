//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////左右最值最大差
//class MaxGap {
//public:
//	int findMaxGap(vector<int> A, int n) {
//		if (n == 2)
//			return abs(A[0] - A[1]);
//		else
//		{
//			int maxnum = A[0];
//			for (int i = 0; i < n; i++)
//			{
//				maxnum = max(maxnum, A[i]);
//			}
//			int tmp = A[0] < A[n - 1] ? A[0] : A[n - 1];
//			return abs(maxnum - tmp);
//		}
//		return 0;
//	}
//};
////顺时针打印矩阵
//class Printer {
//public:
//	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
//		vector<int> v;
//		if (m == 0 || n == 0)
//			return v;
//		int a = 0;
//		int x = n - 1;
//		int y = m - 1;
//		do {
//			for (int i = a, j = a; j <= y; j++)
//				v.push_back(mat[i][j]);
//			for (int i = a + 1, j = y; i <= x; i++)
//				v.push_back(mat[i][j]);
//			if (a != x)
//			{
//				for (int i = x, j = y - 1; j >= a; j--)
//					v.push_back(mat[i][j]);
//			}
//			if (a != y)
//			{
//				for (int i = x - 1, j = a; i >= a + 1; i--)
//					v.push_back(mat[i][j]);
//			}
//		} while ((++a <= --x) && (a <= --y));
//		return v;
//	}
//};

#include<iostream>
using namespace std;
int main()
{
	int a[2][3] = { 2,4,6,8,10,12 };
	cout << *(&a[0][0]) << endl;
	cout << &a[0][0] << endl;
	cout << (&a[0][0] + 2 * 2 + 1) << endl;
	cout << *(&a[0][0] + 2 * 2 + 1) << endl;
	return 0;
}