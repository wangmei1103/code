//#include<iostream>
//using namespace std;
//#include<deque>
//#include<functional>
//#include<list>
//#include<vector>

//stack: vector<T>, list<T>, dequeue<T>
//Ĭ�ϣ�dequeue
//��vector��ȣ����ݴ���С��stack����Ҫ������ʣ�stackû�е�����
//��list��ȣ��Ƚ���������ڴ���Ƭ���ռ䲻��������Ҫ���Ľ϶�Ŀռ���ָ��
//stack��Ҫ������λ�ò���ɾ��

//template<class T, class Container = deque<T>>
//class Stack
//{
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//	}
//	void pop()
//	{
//		_c.pop_back();
//	}
//	T& top()
//	{
//		return _c.back();
//	}
//	size_t size()const
//	{
//		return _c.size();
//	}
//	bool empty()const
//	{
//		return _c.empty();
//	}
//private:
//	Container _c;
//};


//queue��deque<T> list<T>
//template<class T, class Container = deque<T>>
//class Queue
//{
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//	}
//	void pop()
//	{
//		_c.pop_front();
//	}
//	T& front()
//	{
//		return _c.front();
//	}
//	size_t size()const
//	{
//		return _c.size();
//	}
//	bool empty()const
//	{
//		return _c.empty();
//	}
//private:
//	Container _c;
//};

//priority_queue:vector<T> deque<T>
//list��֧���������
//Ĭ�ϣ�vector
//template<class T>
////�º����ࣺ�����ˡ�()�������
//struct Greater
//{
//	bool operator()(const T& a, const T& b)
//	{
//		return a > b;
//	}
//}; 
//template<class T>
////�º����ࣺ�����ˡ�()�������
//struct Less
//{
//	bool operator()(const T& a, const T& b)
//	{
//		return a < b;
//	}
//};
//template<class T, class Container, class Compare>
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
//			if (child + 1 < arr.size() && cmp(arr[child], arr[child + 1]))
//			{
//				child++;
//			}
//			if (cmp(arr[parent], arr[child]))
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
//			if (cmp(arr[parent], arr[child]))
//			{
//				swap(arr[parent], arr[child]);
//				child = parent;
//				parent = (child - 1) / 2;
//			}
//			else
//				break;
//		}
//	}
//	void push(const T& val)
//	{
//		//β��
//		arr.push_back(val);
//		shiftUp(arr.size() - 1);//���ϵ����²����Ԫ��
//	}
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
//	size_t aize()const
//	{
//		return arr.size();
//	}
//	bool empty()const
//	{
//		return arr.empty();
//	}
//private:
//	Container arr;
//	Compare cmp;
//};
//void test()
//{
	//PriorityQueue<int, vector<int>, Greater<int>> pq;
	////PriorityQueue<int, vector<int>, Less<int>> pq;
	//for (int i = 0; i < 100; i++)
	//{
	//	pq.push(i);
	//}
	//while (!pq.empty())
	//{
	//	cout << pq.top() << " ";
	//	pq.pop();
	//}
	//cout << endl;
	/*Queue<int, list<int>> q;
	q.push(13);
	q.push(7);
	q.push(3);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;*/
	/*Stack<int, vector<int>> st;
	st.push(12);
	st.push(14);
	st.push(8);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;*/
//}
//int main()
//{
//	test();
//	return 0;
//}