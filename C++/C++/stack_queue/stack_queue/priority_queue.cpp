//#include<iostream>
//#include<vector>
//using namespace std;
////ʵ�ִ�ѽṹ
//template<class T>
//class PriorityQueue
//{
//public:
//	//��
//	//���µ���
//	void shiftDown()
//	{
//		int parent = 0;
//		int child = 2 * parent + 1;
//		while (child < arr.size())
//		{
//			//���Һ������ҵ���С��
//			if (child + 1 < arr.size() && arr[child] < arr[child + 1])
//			{
//				child++;
//			}
//			if (arr[parent] < arr[child])
//			{
//				swap(arr[parent], arr[child]);
//				//����
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//				break;
//		}
//	}
//	//���ϵ���
//	void shiftUp(int child)
//	{
//		int parent = (child - 1) / 2;
//		while (child > 0)
//		{
//			if (arr[parent] < arr[child])
//			{
//				swap(arr[parent], arr[child]);
//				child = parent;
//				parent = (child - 1) / 2;
//			}
//			else
//				break;
//		}
//	}
//
//	void push(const T& val)
//	{
//		//β��
//		arr.push_back(val);
//		shiftUp(arr.size() - 1);//���ϵ����²����Ԫ��
//
//	}
//
//	void pop()
//	{
//		//����
//		swap(arr[0], arr[arr.size() - 1]);
//		//βɾ
//		arr.pop_back();
//		//���µ���
//		shiftDown();
//	}
//	T& top()
//	{
//		return arr.front();
//	}
//	size_t size()const
//	{
//		return arr.size();
//	}
//	bool empty()const
//	{
//		return arr.empty();
//	}
//private:
//	vector<T> arr;
//};
//
//void test()
//{
//	PriorityQueue<int> pq;
//	pq.push(8);
//	pq.push(9);
//	pq.push(4);
//	pq.push(7);
//	pq.push(6);
//	pq.push(2);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}