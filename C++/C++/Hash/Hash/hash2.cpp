#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<set>
#include<map>
//��ɢ��
//���嵥����Ľڵ�
template <class V>
struct HashNode
{
	V _val;
	HashNode<V>* _next;

	HashNode(const V& val)
		:_val(val)
		, _next(nullptr)
	{}
};

//��ϣǰ������
template <class K, class V, class KeyOfValue>
class HTable;

//��ϣ����������Զ�������
//ͨ����װ������Ľڵ�ʵ��
template<class K, class V, class KeyOfValue>
struct HashIterator
{
	typedef HashIterator<K, V, KeyOfValue> Self;
	typedef HTable<K, V, KeyOfValue> HT;
	//��Ա���ڵ�ָ��,��ϣ��ָ��
	typedef HashNode<V> Node;

	HT* _hPtr;

	Node* _node;
	HashIterator(Node* node, HT* hPtr)
		:_node(node)
		, _hPtr(hPtr)
	{}
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
	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//������һ���ǿ������ͷ�ڵ�
			//���㵱ǰ�ڵ��ڹ�ϣ���е�λ��

			KeyOfValue kov;
			size_t idx = kov(_node->_val) % _hPtr->_ht.size();
			//����һ����ϣλ�ÿ�ʼ����
			++idx;
			for (; idx < _hPtr->_ht.size(); ++idx)
			{
				if (_hPtr->_ht[idx])
				{
					//�ҵ���һ���ǿ�����
					_node = _hPtr->_ht[idx];
					break;
				}
			}
			//û����Ч�Ľڵ�
			if (idx == _hPtr->_ht.size())
			{
				_node = nullptr;
			}
		}
		return *this;
	}

};

template <class K, class V, class KeyOfValue>
class HTable
{
public:
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue> iterator;

	//�ѵ���������Ϊ��Ԫ��
	template<class K, class V, class KeyOfValue>
	friend struct HashIterator;



	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	iterator begin()
	{
		//��һ���ǿ������ͷ�ڵ�
		for (size_t i = 0; i < _ht.size(); i++)
		{
			if (_ht[i])
			{
				return iterator(_ht[i], this);
			}
		}
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}
	pair<iterator, bool> insert(const V& val)
	//bool insert(const V& val)
	{
		//0. �������
		CheckCapacity();
		//1.����hashλ��
		KeyOfValue kov;
		int idx = kov(val) % _ht.size();

		//2.����
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
			{
				//key�ظ�
				return make_pair(iterator(cur, this), false);
				//return false;
			}
			cur = cur->_next;
		}

		//3.���룺ͷ��
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		//return true; 
		return make_pair(iterator(cur, this), true);
	}

	void CheckCapacity()
	{
		if (_size == _ht.size())
		{
			int newC = _size == 0 ? 10 : 2 * _size;
			//�����µ�ָ������
			vector<Node*> newHt(newC);

			KeyOfValue kov;
			//�����ɱ�
			for (size_t i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				//����������
				while (cur)
				{
					Node* next = cur->_next;
					//�����µ�λ��
					int idx = kov(cur->_val) % newHt.size();
					//ͷ��
					cur->_next = newHt[idx];
					newHt[idx] = cur;
					cur = next;
				}
				//�ɱ�ָ���ÿ�
				_ht[i] = nullptr;
			}
			//�±�ɱ���
			swap(_ht, newHt);
		}
	}

	Node* Find(const K& key);
	bool Erase(const K& key);
	~HTable();
private:
	//ָ������
	vector<Node*> _ht;
	int _size;
};

template<class K>
class Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename HTable<K, K, SetKeyOfValue>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}

	bool insert(const K& key)
	{
		return _ht.insert(key);
	}
private:
	HTable<K, K, SetKeyOfValue> _ht;
};

template<class K, class V>
class Map
{
	struct MapKeyOfValue {
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename HTable<K, pair<K, V>, MapKeyOfValue>::iterator iterator;
	pair<iterator, bool> insert(const pair<K, V>& val)
	{
		return _ht.insert(val);
	}
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
		return ret.first->second;
	}
private:
	HTable<K, pair<K, V>, MapKeyOfValue> _ht;
};

void test()
{
	Map<int, int> m;
	m.insert(make_pair(1, 1));
	m[20] = 20;
	m[30] = 30; 
	m[1] = 100;
	m.insert(make_pair(20, 200));
	Map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
	cout << "��Χfor" << endl;
	for (const auto& p : m)
	{
		cout << p.first << "-->" << p.second << endl;
	}
}

//void test()
//{
//	Set<int> s;
//	s.insert(1);
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(13);
//	s.insert(44);
//	s.insert(15);
//	s.insert(18);
//	s.insert(16);
//	s.insert(19);
//	s.insert(10);
//
//	Set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (const auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
int main()
{
	test();
	return 0;
}
