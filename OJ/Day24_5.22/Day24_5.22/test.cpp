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
//};//定义一个结构体 
//int dc[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//右上左下（两个方向数组）
//void bfs(int x, int y);//搜索函数 
//bool bol[5][5];//记录走过的路径 
//bool in(int x, int y);//保证在地图内
//void print(point p);//打印函数 0
//point ans[25];//定义一个结构体数组，便于输出 
//int main() {
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			bol[i][j] = false; //初始化，相当于还没开始进入地图 
//		}
//	}
//	bfs(0, 0);
//}
//bool in(int x1, int y1) {//判断是否走在迷宫里面 
//	if (x1 >= 0 && x1 < 5 && y1 >= 0 && y1 < 5) {
//		return true;
//	}
//	else {
//		return false;
//	}
//};
//void print(point p) {//递归打印路径
//	while (p.root != -1) {
//		print(ans[p.root]);
//		cout << "(" << p.x << "," << p.y << ")" << endl;
//		return;
//	}
//	cout << "(0,0)" << endl;
//}
//void bfs(int x, int y) {//广度优先搜索 
//	int cnt = 0;
//	int k = 0;
//	point p;
//	p.x = x;
//	p.y = y;
//	p.root = -1;
//	queue<point> q;
//	q.push(p);
//	ans[0] = p;//结构体数组 
//	cnt++;
//	while (!q.empty()) {
//		point m = q.front();//指向队列的第一个 
//		q.pop();//将首元素取出队列 
//		if (p.x == 4 && p.y == 4) {//如果走到出口则打印路径
//			print(p);
//			return;
//		}
//		for (int i = 0; i < 4; i++) {
//			int _x = m.x + dc[i][0];
//			int _y = m.y + dc[i][1];
//			if (!bol[_x][_y] && !map[_x][_y] && in(_x, _y)) {//符合条件的进队列
//				bol[_x][_y] = true;
//				p.x = _x;
//				p.y = _y;
//				p.root = k;
//				q.push(p);//将p压入队列 
//				ans[cnt++] = p;//先++再赋值 将p点给ans数组便于最后输出
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
//		if (board[0].size() == 1) //列等于1
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
//		//删除行
//		board.erase(board.begin());
//		return getMost(board);
//	}
//
//	int getMostLowCol(vector<vector<int> > board) {
//		//删除列
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