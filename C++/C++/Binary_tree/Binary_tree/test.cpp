//#include<iostream>
//using namespace std;
//#include<time.h>
//
//
//template<class T>
//struct BNode
//{
//	T _data;
//	typedef BNode<T> Node;
//	Node* _left;
//	Node* _right;
//	BNode(const T& data)
//		:_data(data)
//		,_left(nullptr)
//		,_right(nullptr)
//	{}
//};
//
//template<class T>
//class BTree
//{
//public:
//	typedef BNode<T> Node;
//	Node* find(const T& val)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_data == val)
//				return cur;
//			else if (cur->_data > val)
//				cur = cur->_left;
//			else
//				cur = cur->_right;
//		}
//	}
//
//	//�������������������ݺͽṹ
//	Node* copy(Node* root)
//	{
//		if (root == nullptr)
//			return nullptr;
//		//ǰ�򿽱�
//		Node* newnode = new Node(root->_data);
//		newnode->_left = copy(root->_left);
//		newnode->_right = copy(root->_right);
//		return newnode;
//	}
//	//��������
//	BTree (const BTree<T>& btree)
//		:_root(copy(btree._root))
//	{}
//	BTree()
//		:_root(nullptr)
//	{}
//	//�������ظ���ֵ
//	bool insert(const T& val)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(val);
//			return true;
//		}
//		//�������ҵ����ʵ�λ��
//		Node* cur = _root;
//		Node* parent = nullptr;
//
//		while (cur)
//		{
//			parent = cur;
//			if (cur->_data == val)
//				return false;
//			else if (cur->_data > val)
//				cur = cur->_left;
//			else
//				cur = cur->_right;
//		}
//		//����
//		cur = new Node(val);
//		if (parent->_data > val)
//			parent->_left = cur;
//		else
//			parent->_right = cur;
//	}
//	//ɾ��
//	bool erase(const T& val)
//	{
//		
//		//����
//		Node* cur = _root;
//		Node* parent = nullptr;
//		while (cur)
//		{
//			if (cur->_data == val)
//				break;
//			parent = cur;
//			if (cur->_data > val)
//				cur = cur->_left;
//			else
//				cur = cur->_right;
//		}
//		//�ж��Ƿ��ҵ���Ҫɾ���Ľڵ�
//		if (_root == nullptr)
//			return false;
//		//ɾ��
//		//1.ɾ����ΪҶ�ӽڵ�
//		if (cur->_left == nullptr && cur->_right == nullptr)
//		{
//			//�ж��Ƿ�Ϊ���ڵ�
//			if (cur == _root)
//			{
//				_root = nullptr;
//			}
//			//�ж���Ҫɾ���Ľڵ��ڸ��ڵ���һ��
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = nullptr;
//				else
//					parent->_right = nullptr;
//			}
//			//ɾ���ڵ�
//			delete cur;
//		}
//		//2. ��Ҷ�ӽڵ�,����Ϊ��
//		else if(cur->_left == nullptr)
//		{
//			//�жϵ�ǰ�ڵ��Ƿ��Ǹ��ڵ�
//			if (cur == _root)
//				//���¸��ڵ�
//				_root = cur->_right;
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = cur->_right;
//				else
//					parent->_right = cur->_right;
//			}
//			//ɾ���ڵ�
//			delete cur;
//		}
//		//��Ҷ�ӽڵ㣬�Һ���Ϊ��
//		else if (cur->_right == nullptr)
//		{
//			//�жϵ�ǰ�ڵ��Ƿ��Ǹ��ڵ�
//			if (cur == _root)
//				//���¸��ڵ�
//				_root = cur->_left;
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = cur->_left;
//				else
//					parent->_right = cur->_left;
//			}
//			//ɾ���ڵ�
//			delete cur;
//		}
//		//��Ҷ�ӽڵ㣬���Һ��Ӷ�����
//		else
//		{
//			//1.�����������������ҽڵ�
//			Node* leftRightMost = cur->_left;
//			parent = cur;
//			while (leftRightMost->_right)
//			{
//				parent = leftRightMost;
//				leftRightMost = leftRightMost->_right;
//			}
//			//2.����
//			swap(cur->_data, leftRightMost->_data);
//			//3. ɾ�����ҽڵ�
//			if (parent->_left == leftRightMost)
//				parent->_left = leftRightMost->_left;
//			else
//				parent->_right = leftRightMost->_left;
//			delete leftRightMost;
//		}
//		return true;
//	}
//	void inorder()
//	{
//		_inorder(_root);
//		cout<<endl;
//	}
//	//�����������������
//	void _inorder(Node* root)
//	{
//		if (root)
//		{
//			_inorder(root->_left);
//			cout << root->_data << " ";
//			_inorder(root->_right);
//		}
//	}
//
//	void destroy(Node* root)
//	{
//		if (root)
//		{
//			destroy(root->_left);
//			destroy(root->_right);
//			cout << "destroy:" << root->_data << endl;
//			delete root;
//		}
//	}
//	~BTree()
//	{
//		if (_root)
//		{
//			destroy(_root);
//			_root = nullptr;
//		}
//
//	}
//private:
//	Node* _root;
//};
//
////void test()
////{
////	BTree<int> b;
////	srand(time(nullptr));
////	int num;
////	cin >> num;
////	for (int i = 0; i < num; i++)
////	{
////		b.insert(rand());
////	}
////	b.inorder();
////}
//
//void test()
//{
//	BTree<int> b;
//	b.insert(5);
//	b.insert(3);
//	b.insert(7);
//	b.insert(1);
//	b.insert(4);
//	b.insert(6);
//	b.insert(8);
//	b.insert(0);
//	b.insert(2);
//	b.insert(9);
//	b.inorder();
//	b.erase(5);
//	b.erase(3);
//	b.erase(8);
//	b.erase(9);
//	b.inorder();
//}
//int main()
//{
//	test();
//	return 0;
//}