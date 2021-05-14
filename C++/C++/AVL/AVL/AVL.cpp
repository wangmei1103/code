#include<iostream>
using namespace std;
#include<time.h>
template<class T>
struct AVLNode
{
	AVLNode<T>* _parent;
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	T _val;
	//ƽ������
	int _bf;
	AVLNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _bf(0)
	{}
};
template<class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	bool insert(const T& val)
	{
		//����������������
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(val);
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;
			 
		//��������parent��ʼ	
		while (parent)
		{
			//����parent��ƽ������
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;
			//parent�ıȽ϶̵�����+1
			if (parent->_bf == 0)
				//��������
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
				//�������ϸ���
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					//��ߵ���߸�  ����
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					//�ұߵ��ұ߸�
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					//����subLR��ƽ������
					Node* subLR = cur->_right;
					int bf = subLR->_bf;
					//����˫��
					RotateL(cur);
					RotateR(parent);
					//����ƽ������ 
					if (bf == 1)
					{
						cur->_bf = -1;
						parent->_bf = 0;
					}
					else if (bf == -1)
					{
						cur->_bf = 0;
						parent->_bf = 1;
					}
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					//����subRL��ƽ������
					Node* subRL = cur->_left;
					int bf = subRL->_bf;
					//����˫��
					RotateR(cur);
					RotateL(parent);
					//����ƽ������ 
					if (bf == 1)
					{
						cur->_bf = 0;
						parent->_bf = -1;
					}
					else if (bf == -1)
					{
						cur->_bf = 1;
						parent->_bf = 0;
					}
				}
				break;
			}
		}
		return true;
	}
	//����
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		subL->_right = parent;
		parent->_left = subLR;
		if(subLR)
			subLR->_parent = parent;
		//�ж�parent�Ƿ�Ϊ���ڵ�
		if (parent == _root)
		{
			//���ڵ�
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;

			subL->_parent = pparent;

		}
		parent->_parent = subL;
		subL->_bf = parent->_bf = 0;
	}
	//����
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		//�ж�parent�Ƿ�Ϊ���ڵ�
		if (parent == _root)
		{
			//���ڵ�
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		parent->_parent = subR;
		parent->_bf = subR->_bf = 0;
	}
	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_val << " ";
			_inorder(root->_right);
		}
	}
	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = Height(root->_left);
		int right = Height(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	bool _isBalance(Node* root)
	{
		
		if (root == nullptr)
			return true;
		int left = Height(root->_left);
		int right = Height(root->_right);

		if (right - left != root->_bf)
		{
			cout << "Node:" << root->_val << " bf:" << root->_bf << " Height gap:" << right - left << endl;
			return false;
		}
		return abs(root->_bf) < 2 && _isBalance(root->_left) && _isBalance(root->_right);
	}
	int Balance()
	{
		return _isBalance(_root);
		
	}
private:
	Node* _root = nullptr;
};
void test()
{
	AVLTree<int> avl;
	int arr[] = { 16,3,7,11,9,26,18,14,15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; ++i)
	{
		avl.insert(arr[i]);
	}
	avl.inorder();
	cout << (avl.Balance()) << endl;
}

//void test2()
//{
//	srand(time(nullptr));
//	cout << "num: " << endl;
//	int num;
//	cin >> num;
//	AVLTree<int> avl;
//	for (int i = 0; i < num; ++i)
//	{
//		avl.insert(rand());
//	}
//	avl.inorder();
//	avl._isBalance();
//}
//
//void test1()
//{
//	AVLTree<int> av1;
//	av1.insert(5); 
//	av1.insert(3);
//	av1.insert(1); //����
//	av1.insert(0);
//	av1.insert(2);
//	av1.insert(-1);//����
//	av1.insert(10);
//	av1.insert(15);//����
//	av1.insert(20);// ����
//	//av1.insert(13);
//	//av1.insert(25);
//}

int main()
{
	test();
	return 0;
}