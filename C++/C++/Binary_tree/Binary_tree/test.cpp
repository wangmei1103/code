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
//	//拷贝二叉搜索树的数据和结构
//	Node* copy(Node* root)
//	{
//		if (root == nullptr)
//			return nullptr;
//		//前序拷贝
//		Node* newnode = new Node(root->_data);
//		newnode->_left = copy(root->_left);
//		newnode->_right = copy(root->_right);
//		return newnode;
//	}
//	//拷贝构造
//	BTree (const BTree<T>& btree)
//		:_root(copy(btree._root))
//	{}
//	BTree()
//		:_root(nullptr)
//	{}
//	//不插入重复的值
//	bool insert(const T& val)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(val);
//			return true;
//		}
//		//搜索，找到合适的位置
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
//		//插入
//		cur = new Node(val);
//		if (parent->_data > val)
//			parent->_left = cur;
//		else
//			parent->_right = cur;
//	}
//	//删除
//	bool erase(const T& val)
//	{
//		
//		//查找
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
//		//判断是否找到了要删除的节点
//		if (_root == nullptr)
//			return false;
//		//删除
//		//1.删除的为叶子节点
//		if (cur->_left == nullptr && cur->_right == nullptr)
//		{
//			//判断是否为根节点
//			if (cur == _root)
//			{
//				_root = nullptr;
//			}
//			//判断需要删除的节点在父节点哪一边
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = nullptr;
//				else
//					parent->_right = nullptr;
//			}
//			//删除节点
//			delete cur;
//		}
//		//2. 非叶子节点,左孩子为空
//		else if(cur->_left == nullptr)
//		{
//			//判断当前节点是否是根节点
//			if (cur == _root)
//				//更新根节点
//				_root = cur->_right;
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = cur->_right;
//				else
//					parent->_right = cur->_right;
//			}
//			//删除节点
//			delete cur;
//		}
//		//非叶子节点，右孩子为空
//		else if (cur->_right == nullptr)
//		{
//			//判断当前节点是否是根节点
//			if (cur == _root)
//				//更新根节点
//				_root = cur->_left;
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = cur->_left;
//				else
//					parent->_right = cur->_left;
//			}
//			//删除节点
//			delete cur;
//		}
//		//非叶子节点，左右孩子都存在
//		else
//		{
//			//1.假设找左子树的最右节点
//			Node* leftRightMost = cur->_left;
//			parent = cur;
//			while (leftRightMost->_right)
//			{
//				parent = leftRightMost;
//				leftRightMost = leftRightMost->_right;
//			}
//			//2.交换
//			swap(cur->_data, leftRightMost->_data);
//			//3. 删除最右节点
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
//	//搜索树中序遍历有序
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