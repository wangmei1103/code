#pragma once
#include "filecompress.h"
#include<iostream>
using namespace std;
#include<queue>
#include<functional>
//void TestPorityQueue()
//{
//	//Ĭ���ǰ���С�ڷ�ʽ�Ƚ�--���
//	//ֻ��Ҫ�����е�Ԫ�ذ��մ��ڷ�ʽ�Ƚ�--С��
//	priority_queue<int> q;
//	q.push(4);
//	q.push(1);
//	q.push(5);
//	q.push(7);
//	q.push(3);
//	q.push(2);
//	q.push(6);
//}
//void TestPorityQueue2()
//{
//	//Ĭ���ǰ���С�ڷ�ʽ�Ƚ�--���
//	//ֻ��Ҫ�����е�Ԫ�ذ��մ��ڷ�ʽ�Ƚ�--С��
//	priority_queue<int, vector<int>, greater<int>> q;
//	q.push(4);
//	q.push(1);
//	q.push(5);
//	q.push(7);
//	q.push(3);
//	q.push(2);
//	q.push(6);
//}
int main()
{
	//TestPorityQueue2();
	/*TestHuffmanTree();*/

	FileCompress fc;
	fc.CompressFile("1.txt");
	
	return 0;
}