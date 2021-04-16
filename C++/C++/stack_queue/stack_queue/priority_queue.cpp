//#include<iostream>
//#include<vector>
//using namespace std;
////实现大堆结构
//template<class T>
//class PriorityQueue
//{
//public:
//	//堆
//	//向下调整
//	void shiftDown()
//	{
//		int parent = 0;
//		int child = 2 * parent + 1;
//		while (child < arr.size())
//		{
//			//左右孩子中找到最小的
//			if (child + 1 < arr.size() && arr[child] < arr[child + 1])
//			{
//				child++;
//			}
//			if (arr[parent] < arr[child])
//			{
//				swap(arr[parent], arr[child]);
//				//更新
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//				break;
//		}
//	}
//	//向上调整
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
//		//尾插
//		arr.push_back(val);
//		shiftUp(arr.size() - 1);//向上调整新插入的元素
//
//	}
//
//	void pop()
//	{
//		//交换
//		swap(arr[0], arr[arr.size() - 1]);
//		//尾删
//		arr.pop_back();
//		//向下调整
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