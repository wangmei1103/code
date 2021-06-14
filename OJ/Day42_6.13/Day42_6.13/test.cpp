//#include<iostream>
//using namespace std;
//#include<string>
//void code(string str)
//{
//	int sz = str.length();
//	for (int i = 0; i < sz; i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//			cout << str[i];
//	}
//	cout << endl;
//}
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		code(str);
//	}
//	return 0;
//}


#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef  int ElemType;
typedef struct
{
	ElemType *base;
	int front;
	int rear;
} SqQueue;

int InitQueue(SqQueue &Q)
{
	Q.base = new ElemType[MAXSIZE];
	if (Q.base == NULL)
		return 0;
	Q.front = Q.rear = 0;
	return 1;
}

int EnQueue(SqQueue &Q, ElemType e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		printf("queue is full");
		return 0;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 0;
}

int Dequeue(SqQueue &Q, ElemType &e)
{
	if (Q.front == Q.rear)
	{
		printf("queue is null");
		return 0;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return 1;
}

int QueueEmpty(SqQueue Q)
{
	return Q.front == Q.rear;
}

int visited[MAXSIZE][MAXSIZE];
int xp[] = { -1, 1, 0, 0 };
int yp[] = { 0, 0, -1, 1 };
int sx, sy, ex, ey;

int BFS(char r[MAXSIZE][MAXSIZE], int N, int M)
{
	visited[sx][sy] = 1;
	SqQueue Qx, Qy;
	InitQueue(Qx);
	InitQueue(Qy);
	EnQueue(Qx, sx);
	EnQueue(Qy, sy);
	while (!QueueEmpty(Qx) && !QueueEmpty(Qy))
	{
		int tx, ty;
		Dequeue(Qx, tx);
		Dequeue(Qy, ty);
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + xp[i];
			int ny = ty + yp[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && r[nx][ny] != '#' && visited[nx][ny] == 0)
			{
				EnQueue(Qx, nx);
				EnQueue(Qy, ny);
				visited[nx][ny] = visited[tx][ty] + 1;
				if (nx == ex && ny == ey)
				{
					return visited[nx][ny] - 1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	int N = 10, M = 10;
	char r[MAXSIZE][MAXSIZE];
	sx = 0;
	sy = 1;
	ex = 9;
	ey = 8;
	while (fgets(r[0], 11, stdin) != NULL)
	{
		getchar();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visited[i][j] = 0;
			}
		}
		for (int i = 1; i < N; i++)
		{
			fgets(r[i], 11, stdin);
			getchar();
		}
		printf("%d\n", BFS(r, N, M));
	}
	return 0;
}


