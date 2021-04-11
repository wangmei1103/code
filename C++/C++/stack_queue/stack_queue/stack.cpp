//#include<iostream>
//#include<stack>
//#include<vector>
//#include<list>
//using namespace std;
//stack实现
//顺序表：
//push:push_back-->尾插
//pop:pop_back-->尾删
//top:back-->获取最后一个元素
//链表：单链表
//push:push_front-->尾删
//pop:pop_front-->头删
//top:front-->获取头节点的值
//template<class T>
//class Stack
//{
//public:
//	//封装vector
//	void push(const T& val)
//	{
//		_st.push_back(val);
//	}
//	void pop()
//	{
//		_st.pop_back();
//	}
//	T& top()
//	{
//		return _st.back();
//	}
//	size_t size()const
//	{
//		return _st.size();
//	}
//	bool empty()const
//	{
//		return _st.empty();
//	}
//private:
//	vector<T> _st;
//};
//template<class T>
//class Stack2
//{
//public:
//	void push(const T& val)
//	{
//		_st.push_back(val);
//		//_st.push_front(val);
//	}
//	void pop()
//	{
//		_st.pop_back();
//		//_st.pop_front();
//	}
//	T& top()
//	{
//		return _st.back();
//		//return _st.front();
//	}
//	size_t size()const
//	{
//		return _st.size();
//	}
//	bool empty()const
//	{
//		return _st.empty();
//	}
//private:
//	list<T> _st;
//};
//void test()
//{
//	Stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//	cout << st.size() << endl; 
//	Stack2<int> st2;
//	st2.push(1);
//	st2.push(2);
//	st2.push(3);
//	while (!st2.empty())
//	{
//		cout << st2.top() << " ";
//		st2.pop();
//	}
//	cout << endl;
//	cout << st2.size() << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
