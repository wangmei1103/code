//#include<iostream>
//using namespace std;
//#include<vector>
//#include<list>
//queueʵ�֣�
//˳���
//push:push_back-->β��
//pop:pop_front-->ͷɾ
//front:front-->��ȡ��һ��Ԫ��
//��������������βָ�룩
//push:push_back-->β��
//pop:pop_front-->ͷɾ
//front:front-->��ȡͷ�ڵ��Ԫ��
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