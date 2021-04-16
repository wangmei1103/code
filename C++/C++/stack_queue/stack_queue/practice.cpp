#include<iostream>
using namespace std;
#include<deque>
#include<functional>
#include<list>
#include<vector>

template<class T, class Con = deque<T>>
class Stack
{
public:
	Stack() {}
	void push(const T& x)
	{
		_c.push_back(x);
	}
	void pop()
	{
		_c.pop_back();
	}
	T& top()
	{
		return _c.back();
	}
	const T& top()const
	{
		return _c.back();
	}
	size_t size()const
	{
		return _c.size();
	}
	bool empty()const
	{
		return _c.empty();
	}
private:
	Con _c;
};


template<class T, class Con = deque<T>>
class Queue
{
public:
	Queue() {}
	void push(const T& x)
	{
		_c.push_back(x);
	}
	void pop()
	{
		_c.pop_front();
	}
	T& back()
	{
		return _c.back();
	}
	const T& back()const
	{
		return _c.back();
	}
	T& front()
	{
		return _c.front();
	}
	const T& front()const 
	{
		return _c.front();
	}
	size_t size()const
	{
		return _c.size();
	}
	bool empty()const
	{
		return _c.empty();
	}
private:
	Con _c;
};
//
//priority_queue:vector
template<class T>
struct Less
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};
template<class T>
struct Greater
{
	bool operator()(const T& a, const T& b)
	{
		return a > b;
	}
};

template<class T, class Container = vector<T>, class Compare = Less<T>>
class Priority_queue
{
public:
	//堆
	//向下调整
	void AdjustDown()
	{
		int parent = 0;
		int child = 2 * parent + 1;
		while (child < c.size())
		{
			//左右孩子中找到最小的
			if (child + 1 < c.size() && comp(c[child], c[child + 1]))
			{
				child++;
			}
			if (comp(c[parent], c[child]))
			{
				swap(c[parent], c[child]);
				//更新
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
	//向上调整
	void AdjustUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (comp(c[parent], c[child]))
			{
				swap(c[parent], c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
	Priority_queue()
		:c()
	{}
	template<class InputIterator>
	Priority_queue(InputIterator first, InputIterator last)
		:c(first, last)
	{
		int count = c.size();
		int root = ((count - 2) >> 1);
		for (; root >= 0; root--)
		{
			AdjustDown(root);
		}
	}
	bool empty()const
	{
		return c.empty();
	}
	size_t size()const
	{
		return c.size();
	}
	T& top()

	{
		return c.front();
	}

	void push(const T& x)
	{
		c.push_back(x);
		AdjustUp(c.size() - 1);
	}
	void pop()
	{
		if (empty())
			return;
		swap(c[0], c[c.size() - 1]);
		c.pop_back();
		AdjustDown();
	}
private:
	Container c;
	Compare comp;
};
void test()
{
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

	Queue<int, list<int>> q;
	q.push(13);
	q.push(7);
	q.push(3);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	//Priority_queue<int, vector<int>, Greater<int>> pq;
	/*Priority_queue<int, vector<int>, Less<int>> pq;
	for (int i = 0; i < 100; i++)
	{
		pq.push(i);
	}
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;*/
}
int main()
{
	test();
	return 0;
}