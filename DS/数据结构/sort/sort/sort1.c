/*
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;
			int data = a[i];
			while (end >= 0 && a[end] > data)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = data;
		}
	}
}

void swap(int* a, int pos1, int pos2)
{
	int tmp = a[pos1];
	a[pos1] = a[pos2];
	a[pos2] = tmp;
}

// 选择排序
void SelectSort(int* a, int n)
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int min = start;
		for (int i = start + 1; i <= end; i++)
		{
			if (a[i] < a[min])
				min = i;
		}
		swap(a, start, min);
		++start;
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	int child = 2 * root + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		if (a[child] > a[root])
		{
			swap(a, child, root);
			root = child;
			child = 2 * root + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(a, end, 0);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
				swap(a, j, j + 1);
		}
	}
}

// 快速排序递归实现
//获取基准值：三数取中法
int getMid(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] > a[right])
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
	else
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
}
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int key = a[left];
	int start = left;
	while (left < right) 
	{
		while (left < right && a[right] >= key)
			--right;
		while (left < right && a[left] <= key)
			++left;
		swap(a, left, right);
	}
	swap(a, start, left);
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	swap(a, mid, left);
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
			--right;
		a[left] = a[right];
		while (left < right && a[left] <= key)
			++left;
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	swap(a, mid, left);
	int key = a[left];
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < key && ++prev != cur)
		{
			swap(a, prev, cur);
		}
		++cur;
	}
	swap(a, left, prev);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartSort3(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}

// 快速排序 非递归实现
//顺序表
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
SLDataType SeqListBack(SeqList* ps)
{
	return ps->a[ps->size - 1];
}
void QuickSortNonR(int* a, int left, int right)
{
	SeqList sq;
	initSeqList(&sq);
	SeqListPushBack(&sq, right);
	SeqListPushBack(&sq, left);
	while (!IsEmpty(&sq))
	{
		left = SeqListBack(&sq);
		SeqListPopBack(&sq);
		right = SeqListBack(&sq);
		SeqListPopBack(&sq);
		int div = PartSort3(a, left, right);
		if (left < div - 1)
		{
			SeqListPushBack(&sq, div - 1);
			SeqListPushBack(&sq, left);
		}
		if (div + 1 < right)
		{
			SeqListPushBack(&sq, right);
			SeqListPushBack(&sq, div + 1);
		}
	}
}

//栈
typedef int STDataType;
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
void QuickSortNonR2(int* a, int left, int right)
{
	stack st;
	initStack(&st);
	stackPush(&st, right);
	stackPush(&st, left);
	while (!stackEmpty(&st))
	{
		left = stackTop(&st);
		stackPop(&st);
		right = stackTop(&st);
		stackPop(&st);
		int div = PartSort1(a, left, right);
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

//队列
typedef int QDataType;
typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;
typedef struct Queue
{
	QNode* _head;
	QNode* _tail;
	int _size;
}Queue;
void initQueue(Queue* q)
{
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
void QuickSortNonR3(int* a, int left, int right)
{
	Queue q;
	initQueue(&q);
	queuePush(&q, left);
	queuePush(&q, right);
	while (!queueEmpty(&q))
	{
		left = queueFront(&q);
		queuePop(&q);
		right = queueFront(&q);
		queuePop(&q);
		int div = PartSort1(a, left, right);
		if (left < div - 1)
		{
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}
		if (div + 1 < right)
		{
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}
	}
}

// 归并排序递归实现
//相邻子序列合并：
void merge(int* a, int begin, int mid, int end, int* tmp)
{
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[idx++] = a[begin1++];
		else
			tmp[idx++] = a[begin2++];
	}
	if (begin1 <= end1)
		memcpy(tmp + idx, a + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, a + begin2, sizeof(int)*(end2 - begin2 + 1));
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
//归并排序  递归  n(logn)
void _mergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	_mergeSort(a, begin, mid, tmp);
	_mergeSort(a, mid + 1, end, tmp);
	merge(a, begin, mid, end, tmp);
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_mergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	//子序列步长
	int step = 1;
	while (step < n)
	{
		for (int idx = 0; idx < n; idx += 2 * step)
		{
			int begin = idx;
			int mid = idx + step - 1;
			if (mid >= n - 1)
				continue;
			int end = idx + 2 * step - 1;
			if (end >= n)
				end = n - 1;
			merge(a, begin, mid, end, tmp);
		}
		step *= 2;
	}
}

// 计数排序
void CountSort(int* a, int n)
{
	int max, min;
	min = max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* countArr = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		countArr[a[i] - min]++;
	}
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
			a[idx++] = i + min;
	}
}

void printArr(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void test()
{
	int a[] = { 2,4,0,6,8,1,3,5,7,9 };
	printArr(a, sizeof(a) / sizeof(a[0]));
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//ShellSort(a, sizeof(a) / sizeof(a[0]));
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//SelectSort(a, sizeof(a) / sizeof(a[0]));
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//QuickSortNonR2(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//QuickSortNonR3(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//MergeSort(a, sizeof(a) / sizeof(a[0]));
	//printArr(a, sizeof(a) / sizeof(a[0]));
	//MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	//printArr(a, sizeof(a) / sizeof(a[0]));
	CountSort(a, sizeof(a) / sizeof(a[0]));
	printArr(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	test();
	return 0;
}
*/