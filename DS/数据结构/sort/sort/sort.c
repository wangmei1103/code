
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<assert.h>

//交换函数
void swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}
//插入排序  时间复杂度：O(n^2)
void insertSort(int* arr, int n)
{
	//假设第一个数据已经有序，插入的数据：[1,n]
	for (int i = 1; i < n; i++)
	{
		//从有序数据的最后一个位置向前遍历
		int end = i - 1;
		int tmp = arr[i];
		//while (end >= 0 && arr[end] >= tmp)  不稳定
		while (end >= 0 && arr[end] > tmp)  //稳定
		{
			//大的数据向后移动
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = tmp;
	}
}
//希尔排序  时间复杂度O(n^1.3)   不稳定
void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//最后一趟排序，间隔必须是1，保证所有数据在同一组
		//一趟希尔排序   
		for (int i = gap; i < n; i++)
		{
			//同组数据，最后一个有序的数据的位置
			int end = i - gap;
			//待插入的数据
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}

////选择排序  升序
//void selectSort(int* arr,int n)
//{
//	int tmp;
//	for (int i = 0; i < n - 1; i++)
//	{
//		int min = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[j] < arr[i])
//				min = j;
//		}
//		tmp = arr[i];
//		arr[i] = arr[min];
//		arr[min] = tmp;
//	}
//}

//选择排序  时间复杂度:O(n^2)   稳定   
void selectSort1(int* arr, int n)
{
	//从未排序的序列中找出最值，存放在未排序的起始位置
	//未排序区间[start,end];
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//找到最小值位置
		int minidx = start;
		for (int i = start + 1; i <= end; i++)
		{
			//if (arr[i] <= arr[minidx])  不稳定
			if (arr[i] < arr[minidx])
				minidx = i;
		}
		//把最小值存到最开始的位置
		swap(arr, start, minidx);
		//剩余未排序的位置区间[start + 1, end];
		++start;
	}
}
void selectSort2(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	//每次未排序的区间找到一个最大值和最小值
	//最小值放在头部，最大值放在尾部
	//遍历的次数减少一半
	while (start < end)
	{
		int minidx = start;
		int maxidx = start;
		for (int j = start + 1; j <= end; j++)
		{
			if (arr[j] < arr[minidx])
				minidx = j;
			if (arr[j] > arr[maxidx])
				maxidx = j;
		}
		//把最小值存放在最开始的位置
		swap(arr, start, minidx);
		//判断最大值的位置是否在起始位置
		if (maxidx == start)
			maxidx = minidx;
		//最大值存放在末尾
		swap(arr, end, maxidx);
		++start;
		--end;
	}
}

//堆排序  时间复杂度：O(n(logn))  不稳定
//建大堆，从最后一个
void shiftDown(int* arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		if (arr[child] > arr[parent])
		{
			swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
void heapSort(int* arr, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(arr, end, 0);
		shiftDown(arr, end, 0);
		end--;
	}
}

////冒泡排序
//void bubbleSort(int* arr, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//				swap(arr, j, j + 1);
//		}
//	}
//}
//冒泡排序  时间复杂度O(n^2)  数据有序：O(n)  稳定
void bubbleSort(int* arr, int n)
{
	//相邻元素进行比较
	//第一次遍历的范围：0~未排序数据的最后一个位置
	//flag:标记一轮冒泡排序中是否发生了交换
	int flag = 0;
	int end = n;
	while (end > 1)
	{
		//一轮冒泡排序
		for (int i = 1; i < end; ++i)
		{
			if (arr[i - 1] > arr[i]) {
				//大的数向后移动
				swap(arr, i - 1, i);
				flag = 1;
			}
		}
		//如果没有发生交换，说明剩余元素全部有序
		if (!flag)
			break;
		--end;
	}
}

//快速排序
//获取基准值：三数取中法
int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[end])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}
//划分方法：前后指针法
int partion3(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);
	int key = arr[begin];
	//上一个小于基准值的位置
	int prev = begin;
	//下一个小于基准值的位置
	int cur = begin + 1;
	while (cur <= end)
	{
		//当cur走到下一个小于基准值的位置，判断prev和cur是否连续
		if (arr[cur] < key && ++prev != cur)
		{
			//不连续，交换数据
			swap(arr, prev, cur);
		}
		++cur;
	}
	swap(arr, begin, prev);
	return prev;
}

//划分方法：挖坑法
int partion2(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);
	//第一个值作为基准值，第一个 位置为初始的坑的位置
	int key = arr[begin];
	while (begin < end)
	{
		//从后往前找小的
		while (begin < end && arr[end] >= key)
			--end;
		//填坑
		arr[begin] = arr[end];
		//从前往后找大的
		while (begin < end && arr[begin] <= key)
			++begin;
		//填坑
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}
//快速排序 递归  O(n^2)
//返回划分之后，基准值所在位置
//数据有序时，可能会导致栈溢出
int partion1(int* arr, int begin,int end)
{
	//选择基准值
	int key = arr[begin];
	int start = begin;
	while (begin < end) {
		//从后向前先找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		//从前向后找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		//交换
		swap(arr, begin, end);
	}
	//交换基准值和相遇位置的数据
	swap(arr, start, begin);
	return begin;
}
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div:一次划分之后，基准值位置
	int div = partion1(arr, begin, end);
	//左右两部分进行快速排序
	//[begin,div-1]  [div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
}
void quickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//小区间优化
	if (end - begin < 10)
	{
		insertSort(arr + begin, end - begin + 1);
	}
	else
	{
		//div:一次划分之后，基准值位置
		int div = partion2(arr, begin, end);
		//左右两部分进行快速排序
		//[begin,div-1]  [div+1,end]
		quickSort(arr, begin, div - 1);
		quickSort(arr, div + 1, end);
	}
}
//快速排序 非递归  不会有栈溢出的风险
//1.顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SeqList;
void initSeqList(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 1 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
		memcpy(tmp, ps->a, sizeof(SLDataType)* ps->size);
		free(ps->a);
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps != NULL);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		return;
	}
	ps->size--;
}

int IsEmpty(SeqList* ps)
{
	assert(ps != NULL);
	return ps->size == 0;
}

//获取最后一个元素
SLDataType SeqListBack(SeqList* ps)
{
	return ps->a[ps->size - 1];
}
//快速排序，非递归  顺序表
void quickSortNOR1(int* arr, int n)
{
	//创建一个顺序表，保存划分的区间
	SeqList sq;
	initSeqList(&sq);
	//首先保存整个区间
	//首先放右，再放左
	SeqListPushBack(&sq, n - 1);
	SeqListPushBack(&sq, 0);
	//遍历顺序表，处理所有的区间
	while (!IsEmpty(&sq))
	{
		//取出一个区间
		int left = SeqListBack(&sq);
		SeqListPopBack(&sq);
		int right = SeqListBack(&sq);
		SeqListPopBack(&sq);
		//划分区间
		int div = partion1(arr, left, right);
		//保存产生的两个新区间
		//[left,div-1]
		if (left < div - 1)
		{
			SeqListPushBack(&sq, div - 1);
			SeqListPushBack(&sq, left);
		}
		//[div+1,right]
		if (div + 1 < right)
		{
			SeqListPushBack(&sq, right);
			SeqListPushBack(&sq, div + 1);
		}
	}
}

//2.栈
typedef int STDataType;
//顺序结构实现：实现一个更简单的顺序表
typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;
}stack;

void initStack(stack* st)
{
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}

void checkCapacity(stack* st)
{
	if (st->_size == st->_capacity)
	{
		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType)* newCap);
		st->_capacity = newCap;
	}
}

void stackPush(stack* st, STDataType val)
{
	//尾插
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

void stackPop(stack* st)
{
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}

int stackEmpty(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}

STDataType stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}
void quickSortNOR2(int* arr, int n)
{
	stack st;
	initStack(&st);
	stackPush(&st, n - 1);
	stackPush(&st, 0);
	while (!stackEmpty(&st))
	{
		int left = stackTop(&st);
		stackPop(&st);
		int right = stackTop(&st);
		stackPop(&st);
		int div = partion1(arr, left, right);
		if (left < div - 1)
		{
			stackPush(&st, div - 1);
			stackPush(&st, left);
		}
		if (div + 1 < right)
		{
			stackPush(&st, right);
			stackPush(&st, div + 1);
		}
	}
}
//3.队列  队尾入队，队头出队
typedef int QDataType;
typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;

// 队列的结构
typedef struct Queue
{
	//头尾指针
	QNode* _head;
	QNode* _tail;
	int _size;
}Queue;

//初始化
void initQueue(Queue* q)
{
	//空队列
	if (q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->_size = 0;
}

struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
}

//尾插
void queuePush(Queue* q, QDataType val)
{
	struct	QNode* node = creatNode(val);
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else {
		q->_tail->_next = node;
		q->_tail = node;
	}
	++q->_size;
}
//头删
void queuePop(Queue* q)
{
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode* next = q->_head->_next;
	free(q->_head);
	q->_head = next;
	if (q->_head == NULL)
		q->_tail = NULL;
	--q->_size;
}

QDataType queueFront(Queue* q)
{
	return q->_head->_data;
}

int queueEmpty(Queue* q)
{
	return q->_head == NULL;
}

void quickSortNOR3(int* arr, int n)
{
	Queue q;
	initQueue(&q);
	//保存[0,n-1]区间  先入左，后入右
	queuePush(&q, 0);
	queuePush(&q, n - 1);
	while (!queueEmpty(&q))
	{
		//取出一个区间的起始和结束位置
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);
		//划分 
		int div = partion1(arr, left, right);
		//子区间[left,div-1]
		if (left < div - 1)
		{
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}
		//子区间[div+1,right]
		if (div + 1 < right)
		{
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}
	}
}


//相邻子序列合并：
void merge(int* arr, int begin,int mid, int end, int* tmp)
{
	//递增
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	//辅助空间的起始位置
	int idx = begin;
	//合并有序序列  稳定
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//判断是否有未合并的元素
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
	//合并之后的序列拷贝到原始数组的对应区间
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
//归并排序  递归  n(logn)
void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//首先合并子序列
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	//合并两个有序的子序列
	merge(arr, begin, mid, end, tmp);
}
void mergeSort(int* arr, int n)
{
	//申请辅助空间
	int* tmp = (int*)malloc(sizeof(int)*n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

//归并排序  非递归
void mergeSortNOR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	//子序列步长
	int step = 1;
	while (step < n)
	{
		for (int idx = 0; idx < n; idx += 2 * step)
		{
			//找到两个待合并的子序列区间
			//[begin,mid] [mid+1,end]
			int begin = idx;
			int mid = idx + step - 1;
			//判断是否存在第二个序列
			if (mid >= n - 1)
				//不存在第二个子序列，直接跳过
				continue;
			int end = idx + 2 * step - 1;
			//判断第二个子序列是否越界
			if (end >= n)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}
		//更新步长
		step *= 2;
	}
}

//计数排序
void countSort(int* arr, int n)
{
	//找到最大和最小值
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	//计数范围
	int range = max - min + 1;
	//创建一个计数数组  初始化为0
	int* countArr = (int*)calloc(range, sizeof(int));
	//计数
	for (int i = 0; i < n; ++i)
	{
		countArr[arr[i] - min]++;
	}
	//遍历计数数组，排序
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
			arr[idx++] = i + min;
	}
}

//输出函数
void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test()
{
	//int arr[] = { 10,3,8,4,5,6,2,7 };
	int arr[] = { 1,3,2,4,5,6,7,8,9 };
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//insertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//shellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//selectSort1(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//selectSort2(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//heapSort(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//quickSortNOR1(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//quickSortNOR2(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//quickSortNOR3(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//mergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//mergeSortNOR(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
	countSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void timetest()
{
	/*int n;
	printf("数据量: \n");
	scanf_s("%d", &n);
	srand(time(NULL));*/
	int arr[] = { 1,3,2,4,5,6,7,8,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//int* arr = (int*)malloc(sizeof(int)*n);
	int* copy1 = (int*)malloc(sizeof(int)*n);
	int* copy2 = (int*)malloc(sizeof(int)*n);
	int* copy3 = (int*)malloc(sizeof(int)*n);
	int* copy4 = (int*)malloc(sizeof(int)*n);
	int* copy5 = (int*)malloc(sizeof(int)*n);
	int* copy6 = (int*)malloc(sizeof(int)*n);
	int* copy7 = (int*)malloc(sizeof(int)*n);
	int* copy8 = (int*)malloc(sizeof(int)*n);
	int* copy9 = (int*)malloc(sizeof(int)*n);
	int* copy10 = (int*)malloc(sizeof(int)*n);
	int* copy11 = (int*)malloc(sizeof(int)*n);
	int* copy12 = (int*)malloc(sizeof(int)*n);
	int* copy13 = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
	memcpy(copy1, arr, sizeof(int)* n);
	memcpy(copy2, arr, sizeof(int)* n);
	memcpy(copy3, arr, sizeof(int)* n);
	memcpy(copy4, arr, sizeof(int)* n);
	memcpy(copy5, arr, sizeof(int)* n);
	memcpy(copy6, arr, sizeof(int)* n);
	memcpy(copy7, arr, sizeof(int)* n);
	memcpy(copy8, arr, sizeof(int)* n);
	memcpy(copy9, arr, sizeof(int)* n);
	memcpy(copy10, arr, sizeof(int)* n);
	memcpy(copy11, arr, sizeof(int)* n);
	memcpy(copy12, arr, sizeof(int)* n);
	memcpy(copy13, arr, sizeof(int)* n);
	//插入排序
	time_t begin = clock();
	insertSort(copy1, n);
	time_t end = clock();
	printf("insertSort:%d\n", end - begin);
	//希尔排序
	begin = clock();
	shellSort(copy2, n);
	end = clock();
	printf("shellSort:%d\n", end - begin);
	//选择排序
	begin = clock();
	selectSort1(copy3, n);
	end = clock();
	printf("selectSort:%d\n", end - begin);
	//选择排序  遍历次数减半
	begin = clock();
	selectSort2(copy4, n);
	end = clock();
	printf("selectSort1:%d\n", end - begin);
	//堆排序
	begin = clock();
	heapSort(copy5, n);
	end = clock();
	printf("heapSort:%d\n", end - begin);
	//冒泡排序
	begin = clock();
	bubbleSort(copy6, n);
	end = clock();
	printf("bubbleSort:%d\n", end - begin);
	//有序的冒泡排序
	begin = clock();
	bubbleSort(copy6, n);
	end = clock();
	printf("有序：bubbleSort:%d\n", end - begin);
	//快速排序
	begin = clock();
	quickSort(copy7, 0, n);
	end = clock();
	printf("quickSort:%d\n", end - begin);
	//快速排序非递归--顺序表
	begin = clock();
	quickSortNOR1(copy8, n);
	end = clock();
	printf("quickSortNOR1:%d\n", end - begin);
	//快速排序非递归--栈
	begin = clock();
	quickSortNOR2(copy9, n);
	end = clock();
	printf("quickSortNOR2:%d\n", end - begin); 
	//快速排序非递归--队列
	begin = clock();
	quickSortNOR3(copy10, n);
	end = clock();
	printf("quickSortNOR3:%d\n", end - begin);
	//归并排序--递归
	begin = clock();
	mergeSort(copy11, n);
	end = clock();
	printf("mergeSort:%d\n", end - begin);
	//归并排序--非递归
	begin = clock();
	mergeSortNOR(copy12, n);
	end = clock();
	printf("mergeSortNOR:%d\n", end - begin);
	//计数排序
	begin = clock();
	countSort(copy13, n);
	end = clock();
	printf("countSort:%d\n", end - begin);
}

int main()
{
	test();
	timetest();
	return 0;
}