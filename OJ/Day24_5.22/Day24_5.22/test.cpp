#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//int map[5][5] = {
//		0, 1, 0, 0, 0,
//
//		0, 1, 0, 1, 0,
//
//		0, 0, 0, 0, 0,
//
//		0, 1, 1, 1, 0,
//
//		0, 0, 0, 1, 0,
//};
//struct point {
//	int x, y, root;
//};//����һ���ṹ�� 
//int dc[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�������£������������飩
//void bfs(int x, int y);//�������� 
//bool bol[5][5];//��¼�߹���·�� 
//bool in(int x, int y);//��֤�ڵ�ͼ��
//void print(point p);//��ӡ���� 0
//point ans[25];//����һ���ṹ�����飬������� 
//int main() {
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			bol[i][j] = false; //��ʼ�����൱�ڻ�û��ʼ�����ͼ 
//		}
//	}
//	bfs(0, 0);
//}
//bool in(int x1, int y1) {//�ж��Ƿ������Թ����� 
//	if (x1 >= 0 && x1 < 5 && y1 >= 0 && y1 < 5) {
//		return true;
//	}
//	else {
//		return false;
//	}
//};
//void print(point p) {//�ݹ��ӡ·��
//	while (p.root != -1) {
//		print(ans[p.root]);
//		cout << "(" << p.x << "," << p.y << ")" << endl;
//		return;
//	}
//	cout << "(0,0)" << endl;
//}
//void bfs(int x, int y) {//����������� 
//	int cnt = 0;
//	int k = 0;
//	point p;
//	p.x = x;
//	p.y = y;
//	p.root = -1;
//	queue<point> q;
//	q.push(p);
//	ans[0] = p;//�ṹ������ 
//	cnt++;
//	while (!q.empty()) {
//		point m = q.front();//ָ����еĵ�һ�� 
//		q.pop();//����Ԫ��ȡ������ 
//		if (p.x == 4 && p.y == 4) {//����ߵ��������ӡ·��
//			print(p);
//			return;
//		}
//		for (int i = 0; i < 4; i++) {
//			int _x = m.x + dc[i][0];
//			int _y = m.y + dc[i][1];
//			if (!bol[_x][_y] && !map[_x][_y] && in(_x, _y)) {//���������Ľ�����
//				bol[_x][_y] = true;
//				p.x = _x;
//				p.y = _y;
//				p.root = k;
//				q.push(p);//��pѹ����� 
//				ans[cnt++] = p;//��++�ٸ�ֵ ��p���ans�������������
//			}
//		}
//		k++;
//	}
//}
//
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<numeric>
//using namespace std;
//
//class Bonus {
//public:
//	int getMost(vector<vector<int> > board) {
//		int sum = 0;
//		if (board.size() == 1)
//		{
//			for (int i = 0; i < board[0].size(); ++i)
//			{
//				sum = accumulate(board[0].begin(), board[0].end(), 0);
//			}
//			return sum;
//		}
//
//		if (board[0].size() == 1) //�е���1
//		{
//			for (int i = 0; i < board.size(); ++i)
//			{
//				sum = sum + board[i][0];
//			}
//			return sum;
//		}
//		return sum + max(getMostLowRow(board), getMostLowCol(board)) + board[0][0];
//	}
//	int getMostLowRow(vector<vector<int> > board) {
//		//ɾ����
//		board.erase(board.begin());
//		return getMost(board);
//	}
//
//	int getMostLowCol(vector<vector<int> > board) {
//		//ɾ����
//		for (int i = 0; i < board.size(); ++i)
//		{
//			board[i].erase(board[i].begin());
//		}
//		return getMost(board);
//	}
//};
//int main()
//{
//
//	vector<int> vec1 = { 1,2 };
//	vector<int> vec2 = { 3,4 };
//	vector<vector<int>> vec;
//	vec.push_back(vec1);
//	vec.push_back(vec2);
//	Bonus bo;
//	cout << bo.getMost(vec) << endl;
//	cout << endl;
//	return 0;
//}