
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<assert.h>

//��������
void swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}
//��������  ʱ�临�Ӷȣ�O(n^2)
void insertSort(int* arr, int n)
{
	//�����һ�������Ѿ����򣬲�������ݣ�[1,n]
	for (int i = 1; i < n; i++)
	{
		//���������ݵ����һ��λ����ǰ����
		int end = i - 1;
		int tmp = arr[i];
		//while (end >= 0 && arr[end] >= tmp)  ���ȶ�
		while (end >= 0 && arr[end] > tmp)  //�ȶ�
		{
			//�����������ƶ�
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = tmp;
	}
}
//ϣ������  ʱ�临�Ӷ�O(n^1.3)   ���ȶ�
void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//���һ�����򣬼��������1����֤����������ͬһ��
		//һ��ϣ������   
		for (int i = gap; i < n; i++)
		{
			//ͬ�����ݣ����һ����������ݵ�λ��
			int end = i - gap;
			//�����������
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

////ѡ������  ����
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

//ѡ������  ʱ�临�Ӷ�:O(n^2)   �ȶ�   
void selectSort1(int* arr, int n)
{
	//��δ������������ҳ���ֵ�������δ�������ʼλ��
	//δ��������[start,end];
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//�ҵ���Сֵλ��
		int minidx = start;
		for (int i = start + 1; i <= end; i++)
		{
			//if (arr[i] <= arr[minidx])  ���ȶ�
			if (arr[i] < arr[minidx])
				minidx = i;
		}
		//����Сֵ�浽�ʼ��λ��
		swap(arr, start, minidx);
		//ʣ��δ�����λ������[start + 1, end];
		++start;
	}
}
void selectSort2(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	//ÿ��δ����������ҵ�һ�����ֵ����Сֵ
	//��Сֵ����ͷ�������ֵ����β��
	//�����Ĵ�������һ��
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
		//����Сֵ������ʼ��λ��
		swap(arr, start, minidx);
		//�ж����ֵ��λ���Ƿ�����ʼλ��
		if (maxidx == start)
			maxidx = minidx;
		//���ֵ�����ĩβ
		swap(arr, end, maxidx);
		++start;
		--end;
	}
}

//������  ʱ�临�Ӷȣ�O(n(logn))  ���ȶ�
//����ѣ������һ��
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

////ð������
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
//ð������  ʱ�临�Ӷ�O(n^2)  ��������O(n)  �ȶ�
void bubbleSort(int* arr, int n)
{
	//����Ԫ�ؽ��бȽ�
	//��һ�α����ķ�Χ��0~δ�������ݵ����һ��λ��
	//flag:���һ��ð���������Ƿ����˽���
	int flag = 0;
	int end = n;
	while (end > 1)
	{
		//һ��ð������
		for (int i = 1; i < end; ++i)
		{
			if (arr[i - 1] > arr[i]) {
				//���������ƶ�
				swap(arr, i - 1, i);
				flag = 1;
			}
		}
		//���û�з���������˵��ʣ��Ԫ��ȫ������
		if (!flag)
			break;
		--end;
	}
}

//��������
//��ȡ��׼ֵ������ȡ�з�
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
//���ַ�����ǰ��ָ�뷨
int partion3(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);
	int key = arr[begin];
	//��һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = begin + 1;
	while (cur <= end)
	{
		//��cur�ߵ���һ��С�ڻ�׼ֵ��λ�ã��ж�prev��cur�Ƿ�����
		if (arr[cur] < key && ++prev != cur)
		{
			//����������������
			swap(arr, prev, cur);
		}
		++cur;
	}
	swap(arr, begin, prev);
	return prev;
}

//���ַ������ڿӷ�
int partion2(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);
	//��һ��ֵ��Ϊ��׼ֵ����һ�� λ��Ϊ��ʼ�Ŀӵ�λ��
	int key = arr[begin];
	while (begin < end)
	{
		//�Ӻ���ǰ��С��
		while (begin < end && arr[end] >= key)
			--end;
		//���
		arr[begin] = arr[end];
		//��ǰ�����Ҵ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//���
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}
//�������� �ݹ�  O(n^2)
//���ػ���֮�󣬻�׼ֵ����λ��
//��������ʱ�����ܻᵼ��ջ���
int partion1(int* arr, int begin,int end)
{
	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;
	while (begin < end) {
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	swap(arr, start, begin);
	return begin;
}
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div:һ�λ���֮�󣬻�׼ֵλ��
	int div = partion1(arr, begin, end);
	//���������ֽ��п�������
	//[begin,div-1]  [div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
}
void quickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//С�����Ż�
	if (end - begin < 10)
	{
		insertSort(arr + begin, end - begin + 1);
	}
	else
	{
		//div:һ�λ���֮�󣬻�׼ֵλ��
		int div = partion2(arr, begin, end);
		//���������ֽ��п�������
		//[begin,div-1]  [div+1,end]
		quickSort(arr, begin, div - 1);
		quickSort(arr, div + 1, end);
	}
}
//�������� �ǵݹ�  ������ջ����ķ���
//1.˳���
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

//��ȡ���һ��Ԫ��
SLDataType SeqListBack(SeqList* ps)
{
	return ps->a[ps->size - 1];
}
//�������򣬷ǵݹ�  ˳���
void quickSortNOR1(int* arr, int n)
{
	//����һ��˳������滮�ֵ�����
	SeqList sq;
	initSeqList(&sq);
	//���ȱ�����������
	//���ȷ��ң��ٷ���
	SeqListPushBack(&sq, n - 1);
	SeqListPushBack(&sq, 0);
	//����˳����������е�����
	while (!IsEmpty(&sq))
	{
		//ȡ��һ������
		int left = SeqListBack(&sq);
		SeqListPopBack(&sq);
		int right = SeqListBack(&sq);
		SeqListPopBack(&sq);
		//��������
		int div = partion1(arr, left, right);
		//�������������������
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

//2.ջ
typedef int STDataType;
//˳��ṹʵ�֣�ʵ��һ�����򵥵�˳���
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
	//β��
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
//3.����  ��β��ӣ���ͷ����
typedef int QDataType;
typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ
typedef struct Queue
{
	//ͷβָ��
	QNode* _head;
	QNode* _tail;
	int _size;
}Queue;

//��ʼ��
void initQueue(Queue* q)
{
	//�ն���
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

//β��
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
//ͷɾ
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
	//����[0,n-1]����  �����󣬺�����
	queuePush(&q, 0);
	queuePush(&q, n - 1);
	while (!queueEmpty(&q))
	{
		//ȡ��һ���������ʼ�ͽ���λ��
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);
		//���� 
		int div = partion1(arr, left, right);
		//������[left,div-1]
		if (left < div - 1)
		{
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}
		//������[div+1,right]
		if (div + 1 < right)
		{
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}
	}
}


//���������кϲ���
void merge(int* arr, int begin,int mid, int end, int* tmp)
{
	//����
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	//�����ռ����ʼλ��
	int idx = begin;
	//�ϲ���������  �ȶ�
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//�ж��Ƿ���δ�ϲ���Ԫ��
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
	//�ϲ�֮������п�����ԭʼ����Ķ�Ӧ����
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
//�鲢����  �ݹ�  n(logn)
void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//���Ⱥϲ�������
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	//�ϲ����������������
	merge(arr, begin, mid, end, tmp);
}
void mergeSort(int* arr, int n)
{
	//���븨���ռ�
	int* tmp = (int*)malloc(sizeof(int)*n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

//�鲢����  �ǵݹ�
void mergeSortNOR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	//�����в���
	int step = 1;
	while (step < n)
	{
		for (int idx = 0; idx < n; idx += 2 * step)
		{
			//�ҵ��������ϲ�������������
			//[begin,mid] [mid+1,end]
			int begin = idx;
			int mid = idx + step - 1;
			//�ж��Ƿ���ڵڶ�������
			if (mid >= n - 1)
				//�����ڵڶ��������У�ֱ������
				continue;
			int end = idx + 2 * step - 1;
			//�жϵڶ����������Ƿ�Խ��
			if (end >= n)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}
		//���²���
		step *= 2;
	}
}

//��������
void countSort(int* arr, int n)
{
	//�ҵ�������Сֵ
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	//������Χ
	int range = max - min + 1;
	//����һ����������  ��ʼ��Ϊ0
	int* countArr = (int*)calloc(range, sizeof(int));
	//����
	for (int i = 0; i < n; ++i)
	{
		countArr[arr[i] - min]++;
	}
	//�����������飬����
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
			arr[idx++] = i + min;
	}
}

//�������
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
	printf("������: \n");
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
	//��������
	time_t begin = clock();
	insertSort(copy1, n);
	time_t end = clock();
	printf("insertSort:%d\n", end - begin);
	//ϣ������
	begin = clock();
	shellSort(copy2, n);
	end = clock();
	printf("shellSort:%d\n", end - begin);
	//ѡ������
	begin = clock();
	selectSort1(copy3, n);
	end = clock();
	printf("selectSort:%d\n", end - begin);
	//ѡ������  ������������
	begin = clock();
	selectSort2(copy4, n);
	end = clock();
	printf("selectSort1:%d\n", end - begin);
	//������
	begin = clock();
	heapSort(copy5, n);
	end = clock();
	printf("heapSort:%d\n", end - begin);
	//ð������
	begin = clock();
	bubbleSort(copy6, n);
	end = clock();
	printf("bubbleSort:%d\n", end - begin);
	//�����ð������
	begin = clock();
	bubbleSort(copy6, n);
	end = clock();
	printf("����bubbleSort:%d\n", end - begin);
	//��������
	begin = clock();
	quickSort(copy7, 0, n);
	end = clock();
	printf("quickSort:%d\n", end - begin);
	//��������ǵݹ�--˳���
	begin = clock();
	quickSortNOR1(copy8, n);
	end = clock();
	printf("quickSortNOR1:%d\n", end - begin);
	//��������ǵݹ�--ջ
	begin = clock();
	quickSortNOR2(copy9, n);
	end = clock();
	printf("quickSortNOR2:%d\n", end - begin); 
	//��������ǵݹ�--����
	begin = clock();
	quickSortNOR3(copy10, n);
	end = clock();
	printf("quickSortNOR3:%d\n", end - begin);
	//�鲢����--�ݹ�
	begin = clock();
	mergeSort(copy11, n);
	end = clock();
	printf("mergeSort:%d\n", end - begin);
	//�鲢����--�ǵݹ�
	begin = clock();
	mergeSortNOR(copy12, n);
	end = clock();
	printf("mergeSortNOR:%d\n", end - begin);
	//��������
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