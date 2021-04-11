//#include<iostream>
//using namespace std;
//#include<vector>
//#include<list>
//queue实现：
//顺序表：
//push:push_back-->尾插
//pop:pop_front-->头删
//front:front-->获取第一个元素
//链表：单链表（加入尾指针）
//push:push_back-->尾插
//pop:pop_front-->头删
//front:front-->获取头节点的元素
//template<class T>
//class Queue
//{
//public:
//	void push(const T& val)
//	{
//		_q.push_back(val);
//		//_q.push_front(val);
//	}
//	void pop()
//	{
//		_q.pop_front();
//		//_q.pop_back();
//	}
//	T& front()
//	{
//		return _q.front();
//		//return _q.back();
//	}
//	size_t size()const
//	{
//		return _q.size();
//	}
//	bool empty()
//	{
//		return _q.empty();
//	}
//private:
//	list<T> _q;
//};
//void test()
//{
//	Queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//	cout << q.size() << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}