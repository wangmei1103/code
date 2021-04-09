#include<iostream>
#include<list>
#include<assert.h>
using namespace std;

template<class T>
struct ListNode
{
	ListNode(const T& val = T())
		:_pPre(nullptr)
		, _pNext(nullptr)
		, _val(val)
	{}
	ListNode<T>* _pPre;
	ListNode<T>* _pNext;
	T _val;
};

//list的迭代器类
template<class T, class Ref, class Ptr>
class ListIterator
{
	typedef ListNode<T>* PNode;
	typedef ListIterator<T, Ref, Ptr> Self;
public:
	//封装节点
	PNode _pNode;
	ListIterator(PNode pNode = nullptr)
		:_pNode(pNode)
	{}
	ListIterator(const Self& l)
		:_pNode(l._pNode)
	{}
	T& operator*()
	{
		return _pNode->_val;
	}
	T* operator->()
	{
		return &_pNode->val;
	}
	Self& operator++()
	{
		_pNode = _pNode->_pNext;
		return *this;
	}
	Self operator++(int)
	{
		Self tmp = *this;
		_pNode = _pNode->_pNext;
		return *this;
	}
	Self& operator--()
	{
		_pNode = _pNode->_pPre;
		return *this;
	}
	Self operator--(int)
	{
		Self tmp = *this;
		_pNode = _pNode->_pPre;
		return *this;
	}
	bool operator!=(const Self& l)
	{
		return _pNode != l._pNode;
	}
	bool operator ==(const Self& l)
	{
		return _pNode == l._pNode;
	}
private:
	//PNode _pNode;
};

//list类
template<class T>
class List
{
	typedef ListNode<T> Node;
	typedef Node* PNode;
public:
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T&> const_iterator;
public:
	//list的构造
	List()
		:_pHead(new Node())
	{
		//循环结构
		_pHead->_pNext = _pHead->_pPre = _pHead;
	}
	List(int n, const T& value = T())
		:_pHead(new Node())
	{
		_pHead->_pNext = _pHead->_pPre = _pHead;
		for (size_t i = 0; i < n; i++)
		{
			push_back(value);
		}
	}
	template<class iterator>
	List(iterator first, iterator last)
		:_pHead(new Node())
	{
		_pHead->_pNext = _pHead->_pPre = _pHead;
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}
	List(const List<T>& l)
		:_pHead(new Node())
	{
		//循环结构
		_pHead->_pNext = _pHead->_pPre = _pHead;
		for (auto& e : l)
		{
			push_back(e);
		}
	}
	List<T>& operator=(const List<T> l)
	{
		Swap(l);
		return *this;
	}
	~List()
	{
		if (_pHead)
		{
			Node* node = _pHead->_pNext;
			while (node != _pHead)
			{
				Node* next = node->_pNext;
				delete node;
				node = next;
			}
			delete _pHead;
			_pHead = nullptr;
		}
	}
	//List iterator
	iterator begin()
	{
		return iterator(_pHead->_pNext);
	}
	iterator end()
	{
		return iterator(_pHead);
	}
	const_iterator begin()const
	{
		return const_iterator(_pHead->_pNext);
	}
	const_iterator end()const
	{
		return const_iterator(_pHead);
	}

	//List Capacity
	size_t size()const
	{
		size_t size = 0;
		Node* p = _pHead->_pNext;
		while (p != _pHead)
		{
			size++;
			p = p->_pNext;
		}
		return size;
	}
	bool empty()const
	{
		return size() == 0;
	}

	//List Access
	T& front()
	{
		assert(!empty());
		return _pHead->_pNext->_val;
	}
	const T& front()const
	{
		assert(!empty());
		return _pHead->_pNext->_val;
	}
	T& back()
	{
		assert(!empty());
		return _pHead->_pPre->_val;
	}
	const T& back()const
	{
		assert(!empty());
		return _pHead->_pPre->_val;
	}

	//List Modify
	void push_front(const T& val)
	{
		insert(begin(), val);
	}
	void push_back(const T& val)
	{
		insert(end(), val);
	}
	void pop_front()
	{
		erase(begin());
	}
	void pop_back()
	{
		erase(--end());
	}
	//在pos位置前插入值尾val的节点
	void insert(iterator pos, const T& val)
	{
		Node* newNode = new Node(val);
		Node* cur = pos._pNode;
		//curpre newnode cur
		newNode->_pPre = cur->_pPre;
		newNode->_pNext = cur;
		newNode->_pPre->_pNext = newNode;
		cur->_pPre = newNode;
	}
	//删除pos位置的节点，返回该节点的下一个位置
	iterator erase(iterator pos)
	{
		if (pos != end())
		{
			Node* cur = pos._pNode;
			Node* prev = cur->_pPre;
			Node* next = cur->_pNext;
			delete cur;
			prev->_pNext = next;
			next->_pPre = prev;
			return iterator(next);
		}
		return pos;
	}
	void clear()
	{
		iterator p = begin();
		while (p != end()) {
			p = erase(p);
		}
	}
	void Swap(List<T>& l)
	{
		/*pNode* tmp = _pHead;
		_pHead = l._pHead;
		l._pHead = tmp;*/
		swap(_pHead, l._pHead);
	}
private:
	void CreateHead()
	{
		_pHead = new Node;
		_pHead->_pPre = _pHead;
		_pHead->_pNext = _pHead;
	}
	PNode _pHead;
};
template<class T>
void printFor(const List<T>& lst)
{
	for (const auto e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test()
{
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	printFor(lst);
	lst.push_front(5);
	lst.push_front(6);
	lst.push_front(7);
	printFor(lst);
	lst.pop_back();
	printFor(lst);
	lst.pop_front();
	printFor(lst);
	lst.insert(lst.begin(), 5);
	printFor(lst);
	lst.erase(lst.begin());
	printFor(lst);
	lst.insert(lst.end(), 1);
	printFor(lst);
	lst.erase(lst.end());
	printFor(lst);
	cout << "size: " << lst.size() << endl;
}
int main()
{
	test();
	return 0;
}