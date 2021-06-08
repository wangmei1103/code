#include<iostream>
#include<utility>
using namespace std;
#include<time.h>
enum COLOR
{
	BLACK,
	RED
};
template<class V>
struct RBNode
{
	//typedef bool color;
	RBNode<V>* _parent;
	RBNode<V>* _left;
	RBNode<V>* _right;
	//key-value
	V _val;
	//��ɫ
	COLOR _color;
	RBNode(const V& val = V())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _color(RED)
	{}
};
template<class V>
struct RBTreeIterator
{
	typedef RBNode<V> Node;
	typedef RBTreeIterator<V> Self;
	Node* _node;
	RBTreeIterator(Node* node)
		:_node(node)
	{}
	//�����ã�*��->
	V& operator*()
	{
		return _node->_val;
	}
	V* operator->()
	{
		return &_node->_val;
	}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	//�������
	Self& operator++()
	{
		if (_node->_right)
		{
			//������������ڵ�
			_node = _node->_right;
			while (_node->_left)
				_node = _node->_left;
		}
		else
		{
			Node* parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			//����û�������������
			if (_node->_right != parent)
				_node = parent;
		}
		return *this;
	}
	Self& operator--()
	{
		if (_node->_left)
		{
			//�����������ҽڵ�
			_node - _node->_left;
			while (_node->_right)
				_node = _node->_right;
		}
		else
		{
			Node* parent = _node->_parent;
			while (_node == parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}
			//����û�������������
			if (_node->_left != parent)
				_node = parent;
		}
		return *this;
	}
};
//KeyOfValue: ͨ��V��ȡ���Ӧ��K
template <class K, class V, class KeyOfValue>
class RBTree
{
public:
	typedef RBNode<V> Node;
	typedef RBTreeIterator<V> iterator;
	RBTree()
		:_header(new Node)
	{
		//����һ������
		_header->_left = _header->_right = _header;
	}
	iterator begin()
	{
		return iterator(_header->_left);
	}
	iterator end()
	{
		return iterator(_header);
	}
	iterator rbegin()
	{
		return iterator(_header->_right);
	}
	//����
	//bool insert(const V& val)
	pair<iterator, bool> insert(const V& val)
	{
		//1.�������Ĳ���
		//������_header->_parent : nullptr
		if (_header->_parent == nullptr)
		{
			//�������ڵ�
			Node* root = new Node(val);
			_header->_parent = root;
			root->_parent = _header;
			_header->_left = _header->_right = root;
			//���ڵ��Ǻ�ɫ
			root->_color = BLACK;
			//return true;
			return make_pair(iterator(root), true);
		}
		//�Ӹ��ڵ㿪ʼ����
		Node* cur = _header->_parent;
		Node* parent = nullptr;
		KeyOfValue kov;
		while (cur)
		{
			parent = cur;
			//��keyֵ���бȽ�
			//kv: pair<K, V>, key: parent.first
			//if (cur->_kv.first == kv.first)
			if(kov(cur->_val) == kov(val))
			{
				//keyֵ�������ظ�
				//return false;
				return make_pair(iterator(cur), false);
			}
			//else if (cur->_kv.first > kv.first)
			else if(kov(cur->_val) > kov(val))
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		//����������Ľڵ�
		cur = new Node(val);
		Node* node = cur;
		//if (parent->_kv.first > cur->_kv.first)
		if(kov(parent->_val) > kov(cur->_val))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;
		//2. �޸���ɫ���ߵ����ṹ
		//�ж��Ƿ��к�ɫ�����ڵ�
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			Node* gfather = parent->_parent;
			if (gfather->_left == parent)
			{
				Node* uncle = gfather->_right;
				//1. uncle���ڵģ������Ǻ�ɫ��
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//��������
					cur = gfather;
				}
				else
				{
					//cout << "Rotate" << endl;
					//�ж��Ƿ�Ϊ˫���ĳ���
					if (cur == parent->_right)
					{
						//����
						RotateL(parent);
						//����cur��parentָ���˻��������ĳ���
						swap(cur, parent);
					}
					//����
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else
			{
				//gfather->right = parent
				Node* uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					//cout << "Rotate" << endl;
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}
		//���ڵ����ɫ��Ϊ��ɫ
		_header->_parent->_color = BLACK;
		//����header������ָ��
		_header->_left = leftMost();
		_header->_right = rightMost();
		//return true;
		return make_pair(iterator(node), true);
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		//�жϸ�
		if (parent == _header->_parent)
		{
			_header->_parent = subR;
			subR->_parent = _header;
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
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		//�жϸ�
		if (parent == _header->_parent)
		{
			_header->_parent = subL;
			subL->_parent = _header;
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
	}
	Node* leftMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}
	Node* rightMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}
	void inorder()
	{
		_inorder(_header->_parent);
		cout << endl;
	}
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_val.first << " ";
			_inorder(root->_right);
		}
	}
	//�����
	//1. ������ɫ
	//2.ÿ��·����ɫ������ͬ
	//3.��ɫ��������
	bool isBalance()
	{
		if (_header->_parent == nullptr)
			return true;
		Node* root = _header->_parent;
		if (root->_color == RED)
			return false;
		//ͳ��һ��·���ϵĺ�ɫ�ڵ����
		int bCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->_color == BLACK)
				++bCount;
			cur = cur->_left;
		}
		//����ÿһ��·��
		int curBCount = 0;
		return _isBalance(root, bCount, curBCount);
	}
	bool _isBalance(Node* root, int& bCount, int curBCount)
	{
		//��rootΪ��ʱ��һ��·����������
		if (root == nullptr)
		{
			//�жϺ�ɫ�ڵ�����Ƿ���ͬ
			if (curBCount != bCount)
				return false;
			else
				return true;
		}
		//�жϽڵ��Ƿ�Ϊ��ɫ
		if (root->_color == BLACK)
			++curBCount;
		//�ж��Ƿ��к�ɫ�����Ľڵ�
		if (root->_parent && root->_color == RED && root->_parent->_color == RED)
		{
			cout << "data:" << root->_val.first << endl;
			return false;
		}
		return _isBalance(root->_left, bCount, curBCount) && _isBalance(root->_right, bCount, curBCount);
	}
	
	//��Ա��_header
private:
	Node* _header;
};
template<class K, class T>
class Map
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, T>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename RBTree<K, pair<K, T>, MapKeyOfValue>::iterator iterator;
	pair<iterator, bool> insert(const pair<K, T>& kv)
	{
		return _rbt.insert(kv);
	}
	iterator begin()
	{
		return _rbt.begin();
	}
	iterator end()
	{
		return _rbt.end();
	}
	iterator rbegin()
	{
		return _rbt.rbegin();
	}
	T& operator[](const K& key)
	{
		pair<iterator, bool> ret = _rbt.insert(make_pair(key, T()));
		return ret.first->second;
	}
private:
	typedef RBTree<K, pair<K, T>, MapKeyOfValue> rbt;
	rbt _rbt;
};
template<class K>
class Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& val)
		{
			return val;
		}
	};

public:
	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;
	pair<iterator, bool> insert(const K& val)
	{
		return _rbt.insert(val);
	}
private:
	typedef RBTree<K, K, SetKeyOfValue> rbt;
	rbt _rbt;
};

void test()
{
	Map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
	m.insert(make_pair(3, 1));
	m.insert(make_pair(4, 1));
	Set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	
}

int main()
{
	test();
	return 0;
}