#include<iostream>
using namespace std;
#include <stdio.h>

//猜数字游戏
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
	//1.生成随机数
	int ret = rand() % 100 + 1;
	int num = 0;
	//2.猜数字
	while (1)
	{
		printf("请猜数字:>");
		scanf_s("%d", &num);
		if (num == ret)
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		else if (num > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
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
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
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
//	int right = sizeof(arr) / sizeof(arr[0]); // right位置的数据取不到
//
//	while (left < right) // right位置没有数据，此处不需要添加=
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > key) // key小于中间位置数据，说明key可能在左半侧，需要改变右边界
//		{
//			right = mid; // right位置的数据取不到，因此right=mid，不需要减1
//		}
//		else if (arr[mid] < key)// key大于中间位置数据，说明key可能在右半侧，需要改变左边界
//		{
//			left = mid + 1; // left位置的数据可以取到，因此left=mid+1
//		}
//		else
//		{
//			printf("找到了，下标是：%d\n", mid);
//			break;
//		}
//	}
//	if (left >= right)
//		printf("找不到\n");
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
//	//冒泡排序
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
//	//希尔排序，
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