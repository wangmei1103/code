#include<iostream>
using namespace std;
#include<string>
#include<vector>

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m, k;
	while (scanf_s("%d%d%d", &n, &m, &k) != EOF) {
		vector<vector<int>> table((n + 1), vector<int>(m + 1));
		vector<vector<double>> P((n + 1), vector<double>(m + 1));
		int x, y;
		for (int i = 0; i < k; i++) {
			scanf_s("%d%d", &x, &y);
			table[x][y] = 1;
		}
		P[1][1] = 1.0;      //������Ϊ1
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!(i == 1 && j == 1)) {      //�������
					P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) + P[i][j - 1] * (i == n ? 1 : 0.5);   //�߽��ʱ�򣬸���Ϊ1
					if (table[i][j] == 1) P[i][j] = 0;        //����õ���Ģ����������Ϊ0
				}
			}
		}
		printf("%.2lf\n", P[n][m]);
	}
}

//int main()
//{
//	char a[21][21] = { 0 };
//	int m, n;
//	cin >> m >> n;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//		getchar();
//	}
//	return 0;
//}