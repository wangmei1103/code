#include<iostream>
using namespace std;
#include <stdio.h>

//��������Ϸ
#include <time.h>
void menu()
{
	printf("********************************\n");
	printf("*******     1. play      *******\n");
	printf("*******     0. exit      *******\n");
	printf("********************************\n");
}
void game()
{
	//RAND_MAX-32767
	//1.���������
	int ret = rand() % 100 + 1;
	int num = 0;
	//2.������
	while (1)
	{
		printf("�������:>");
		scanf_s("%d", &num);
		if (num == ret)
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
		else if (num > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��С��\n");
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 8;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]); // rightλ�õ�����ȡ����
//
//	while (left < right) // rightλ��û�����ݣ��˴�����Ҫ���=
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > key) // keyС���м�λ�����ݣ�˵��key���������࣬��Ҫ�ı��ұ߽�
//		{
//			right = mid; // rightλ�õ�����ȡ���������right=mid������Ҫ��1
//		}
//		else if (arr[mid] < key)// key�����м�λ�����ݣ�˵��key�������Ұ�࣬��Ҫ�ı���߽�
//		{
//			left = mid + 1; // leftλ�õ����ݿ���ȡ�������left=mid+1
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
//			break;
//		}
//	}
//	if (left >= right)
//		printf("�Ҳ���\n");
//	return 0;
//}


//#include<vector>
//class Solution {
//public:
//	vector<int> MySort(vector<int>& arr) {
//		int sz = arr.size();
//		for (int i = 0; i < sz; i++)
//		{
//			for (int j = i + 1; j < sz; j++)
//			{
//				if (arr[i] > arr[j])
//				{
//					int tmp = arr[i];
//					arr[i] = arr[j];
//					arr[j] = tmp;
//				}
//			}
//		}
//		return arr;
//	}
//};
//int main()
//{
//	int arr[] = { 3,4,2,5,6,7,2,4,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//ð������
//
//	for (int i = 0; i < sz; i++)
//	{
//		for (int j = i + 1; j < sz; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				int tmp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//	//ϣ������
//	int gap = sz;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = gap; i < sz; i++)
//		{
//			int end = i - gap;
//			int data = arr[i];
//			while (end >= 0 && arr[end] > data)
//			{
//
//				arr[end + gap] = arr[end];
//				end -= gap;
//			}
//			arr[end + gap] = data;
//		}
//	}
//	return 0;
//}