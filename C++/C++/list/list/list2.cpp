#include<iostream>
#include<list>
#include<string>
using namespace std;

//list实现：双向带头的循环链表
template <class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;
	ListNode(const T& val=T())
		:_data(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};
template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	//无参构造
	List()
		:_header(new Node())
	{
		//循环结构
		_header->_next = _header->_prev = _header;
	}
	List(size_t n, const T& val)
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		for (size_t i = 0; i < n; i++)
		{
			pushBack(val);
		}
	}
	template<class inputIterator>
	List(inputIterator first, inputIterator last)
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}
	//尾插
	void pushBack(const T& val)
	{
		Node* prev = _header->_prev;
		Node* newNode = new Node(val);
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = _header;
		_header->_prev = newNode;
	}
	//析构
	~List()
	{
		if (_header)
		{
			Node* node = _header->_next;
			while (node != _header)
			{
				Node* next = node->_next;
				delete node;
				node = next;
			}
			delete _header;
			_header = nullptr;
		}
	}
private:
	ListNode<T>* _header;
};


void test()
{
	List<int> lst;

	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	lst.pushBack(5);
	List<int> lst2((size_t)10, 5);
	string str = "1234567";
	List<char> lst3(str.begin(), str.end());
}

int main()
{
	test();
	return 0;
}