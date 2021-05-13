#include<iostream>
using namespace std;
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
			parent->_left = cur->_left;
		else
			parent->_right = cur->_right;
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
private:
	Node* _root = nullptr;
};
void test()
{
	AVLTree<int> av1;
	av1.insert(5);
	av1.insert(3);
	av1.insert(1); //����
	av1.insert(0);
	av1.insert(2);
	av1.insert(-1);//����
}

int main()
{
	test()
		;
	return 0;
}