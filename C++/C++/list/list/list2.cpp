//#include<iostream>
//#include<list>
//#include<string>
//using namespace std;
//
////listʵ�֣�˫���ͷ��ѭ������
//template <class T>
//struct ListNode
//{
//	T _data;
//	ListNode<T>* _next;
//	ListNode<T>* _prev;
//	ListNode(const T& val=T())
//		:_data(val)
//		, _next(nullptr)
//		, _prev(nullptr)
//	{}
//};
////������������*��node->data
////������++��node->next
////list������ʵ�֣��Զ������ͣ���װ�ڵ�
////����������
//template<class T>
//struct ListIterator
//{
//	typedef ListNode<T> Node;
//	//typedef ListIterator<T>* iterator;
//	//��װ�ڵ�
//	Node* _node;
//	ListIterator(Node* node)
//		:_node(node)
//	{}
//	//���� *iterator
//	T& operator*()
//	{
//		return _node->_data;//�������ݱ������޸�������
//	}
//	// it --> T* --> ->
//	T* operator->()
//	{
//		//return &(operator*());
//		return &_node->_data;
//	}
//	ListIterator<T>& operator++()
//	{
//		_node = _node->_next;
//		return *this;//�����Ѿ�ָ����һ���ڵ������
//	}
//	//iterator++  ���ص���ֵ����������
//	ListIterator<T> operator++(int)
//	{
//		//iterator tmp(_node);
//		//iterator tmp(*this);
//		iterator tmp = *this;
//		_node = _node->_next;
//		return *this;
//	}
//	ListIterator<T>&  operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//	bool operator!=(const ListIterator<T>& it)
//	{
//		return _node != it._node;
//	}
//	bool operator==(const ListIterator<T>& it)
//	{
//		return _node == it._node;
//	}
//};
////����������
//template<class T>
//struct ConstListIterator
//{
//	typedef ListNode<T> Node;
//	//typedef ConstListIterator<T, Ref, Ptr> self;
//	//typedef ListIterator<T>* iterator;
//	//��װ�ڵ�
//	Node* _node;
//	ConstListIterator(Node* node)
//		:_node(node)
//	{}
//	//���� *iterator
//	T& operator*()
//	{
//		return _node->_data;//�������ݱ������޸�������
//	}
//	// it --> T* --> ->
//	T* operator->()
//	{
//		//return &(operator*());
//		return &_node->_data;
//	}
//
//	ConstListIterator<T>& operator++()
//	{
//		_node = _node->_next;
//		return *this;//�����Ѿ�ָ����һ���ڵ������
//	}
//	//iterator++  ���ص���ֵ����������
//	ConstListIterator<T> operator++(int)
//	{
//		//iterator tmp(_node);
//		//iterator tmp(*this);
//		iterator tmp = *this;
//		_node = _node->_next;
//		return *this;
//	}
//	ConstListIterator<T>& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//	bool operator!=(const ConstListIterator<T>& it)
//	{
//		return _node != it._node;
//	}
//	bool operator==(const ConstListIterator<T>& it)
//	{
//		return _node == it._node;
//	}
//};
//struct A
//{
//	A(int a = 1)
//		:_a(a)
//	{}
//	int _a;
//	int _b;
//};
//template <class T>
//class List
//{
//public:
//	typedef ListNode<T> Node;
//	typedef Node* pNode;
//
//	typedef ListIterator<T>* iterator;
//	typedef ConstListIterator<T> const_iterator;
//	iterator begin()
//	{
//		//����һ������������node��Աָ��_header->_next
//		/*iterator it(_header->_next);
//		return it;*/
//		return iterator(_header->_next);
//	}
//	iterator end()
//	{
//		return iterator(_header);
//	}
//	const_iterator begin()const
//	{
//		//����һ������������node��Աָ��_header->_next
//		/*iterator it(_header->_next);
//		return it;*/
//		return const_iterator(_header->_next);
//	}
//	const_iterator end()const
//	{
//		return const_iterator(_header);
//	}
//	//�޲ι���
//	List()
//		:_header(new Node())
//	{
//		//ѭ���ṹ
//		_header->_next = _header->_prev = _header;
//	}
//	List(size_t n, const T& val)
//		:_header(new Node())
//	{
//		_header->_next = _header->_prev = _header;
//		for (size_t i = 0; i < n; i++)
//		{
//			pushBack(val);
//		}
//	}
//	template<class inputIterator>
//	List(inputIterator first, inputIterator last)
//		:_header(new Node())
//	{
//		_header->_next = _header->_prev = _header;
//		while (first != last)
//		{
//			pushBack(*first);
//			++first;
//		}
//	}
//	//β��
//	void pushBack(const T& val)
//	{
//		//insert(end(), val);
//		Node* prev = _header->_prev;
//		Node* newNode = new Node(val);
//		prev->_next = newNode;
//		newNode->_prev = prev;
//		newNode->_next = _header;
//		_header->_prev = newNode;
//	}
//	void pushFront(const T& val)
//	{
//		insert(begin(), val);
//	}
//	void popBack()
//	{
//		erase(--end());
//	}
//	void popFront()
//	{
//		erase(begin());
//	}
//	//������ָ��Ľڵ��ͷţ�������ʧЧ
//	//���µ�����
//	//����ֵ��iterator--��ɾ��Ԫ�ص���һ��λ��
//	iterator erase(iterator pos)
//	{
//		//�ж��Ƿ�β��Чλ��
//		if (pos != end())
//		{
//			Node* cur = pos._node;
//			Node* prev = cur->_prev;
//			Node* next = cur->_next;
//			delete cur;
//			prev->_next = next;
//			next->_prev = prev;
//			return iterator(next);
//		}
//		return pos;
//	}
//	//���룺���ᵼ�µ�����ʧЧ
//	void insert(iterator pos, const T& val)
//	{
//		//cur->_prev newNode cur
//		Node* newNode = new Node(val);
//		Node* cur = pos._node;
//		newNode->_prev = cur->_prev;
//		newNode->_next = cur;
//		newNode->_prev->_next = newNode;
//		cur->_prev = newNode;
//		
//	}
//	//���
//	List(const List<T>& lst)
//		:_header(new Node())
//	{
//		//ѭ���ṹ
//		_header->_prev = _header->_next = _header;
//		for (auto& e : lst)
//		{
//			pushBack(e);
//		}
//	}
//	//���
//	List<T>& operator=(const List<T>& lst)
//	{
//		Swap(lst);
//		return *this;
//	}
//	void Swap(const List<T>& lst)
//	{
//		//swap(_header, lst._header);
//		Node* tmp = _header;
//		_header = lst._header;
//		lst._header = tmp;
//	}
//	//����
//	~List()
//	{
//		if (_header)
//		{
//			Node* node = _header->_next;
//			while (node != _header)
//			{
//				Node* next = node->_next;
//				delete node;
//				node = next;
//			}
//			delete _header;
//			_header = nullptr;
//		}
//	}
//private:
//	ListNode<T>* _header;
//};
//template<class T>
//void printList(const List<T>& lst)
//{
//	typename List<T>::const_iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		*it = T();
//		++it;
//	}
//	cout << endl;
//}
//void test()
//{
//	List<A> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	for (auto& e : lst)
//	{
//		//cout << e << " ";
//		++e;
//	}
//	cout << endl;
//}
//void test3()
//{
//	List<A> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4); 
//	List<A>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		//cout << *it << " ";
//		//(*it)._a = 1;
//		//(*it)._b = 2;
//		//it->_a;
//		//it->_b;
//		A a(100);
//		A* pa = &a;
//		pa->_a;
//		pa->_b;
//		(*pa)._a;
//		(*pa)._b;
//		++it;
//
//	}
//
//}
//void test2()
//{
//	List<int> lst;
//
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		//cout << *it << " ";
//		++it;
//	}
//}
//void test1()
//{
//	List<int> lst;
//
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	lst.pushBack(5);
//	List<int> lst2((size_t)10, 5);
//	string str = "1234567";
//	List<char> lst3(str.begin(), str.end());
//}
//
//int main()
//{
//	test();
//	return 0;
//}