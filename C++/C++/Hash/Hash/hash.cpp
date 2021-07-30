/*
#include<iostream>
#include<vector>
using namespace std;

//闭散列
enum STATE
{
	EXIST,
	DELETE,
	EMPTY
};

//哈希表：线性探测
template<class K, class V>
struct HashNode
{
	pair<K, V> _kv;
	STATE _state = EMPTY;
};

//顺序表实现hash
template<class K, class V>
class HashTable
{
public:
	typedef HashNode<K, V> Node;

	HashTable(size_t n = 10)
		:_hTable(n)
		,_size(0)
	{}

	bool insert(const pair<K, V>& kv)
	{
		//0.检查容量
		CheckCapacity();

		//1.计算哈希位置
		int idx = kv.first % _hTable.size();

		//2.判断key是否存在
		while (_hTable[idx]._state != EMPTY)
		{
			//如果当前位置数据有效，且key相同，插入失败
			if (_hTable[idx]._state == EXIST && kv.first == _hTable[idx]._kv.first)
				return false;

			//继续搜索
			++idx;
	
			if (idx == _hTable.size())
				idx = 0;
		}
		//插入
		_hTable[idx]._kv = kv;
		_hTable[idx]._state = EXIST;
		++_size;

		return true;
	}

	void CheckCapacity()
	{
		//负载因子填入表的元素个数/散列表的长度
		//负载因子：小于1
		//0.6-0.8之间，选择0.7
		if (_hTable.size() == 0 || (_size * 10 / _hTable.size()) >= 7)
		{
			//开新表
			int newC = _hTable.size() == 0 ? 10 : 2 * _hTable.size();
			HashTable<K, V> newHT(newC);

			for (int i = 0; i < _hTable.size(); ++i)
			{
				//插入状态为exist的数据
				if (_hTable[i]._state == EXIST)
				{
					newHT.insert(_hTable[i]._kv);
				}
			}
			Swap(newHT);
		}
	}

	void Swap(HashTable<K, V>& Ht)
	{
		swap(_hTable, Ht._hTable);
		swap(_size, Ht._size);
	}

	Node* find(const K& key)
	{
		//计算位置
		int idx = key % _hTable.size();
		while (_hTable[idx]._state != EMPTY)
		{
			if (_hTable[idx]._state == EXIST && key == _hTable[idx]._kv.first)
			{
				return &_hTable[idx];
			}
			++idx;
			if (idx == _hTable.size())
			{
				idx = 0;
			}
			
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		Node* node = find(key);
		if (node)
		{
			//假删除
			--_size;
			node->_state = DELETE;
			return true;
		}
		return false;
	}

private:
	vector<Node> _hTable;
	size_t _size;//有效元素的个数
};
*/

//
//void test()
//{
//	HashTable<int, int> ht;
//	ht.insert(make_pair(1, 1));
//	ht.insert(make_pair(14, 14));
//	ht.insert(make_pair(16, 16));
//	ht.insert(make_pair(11, 11));
//	ht.insert(make_pair(14, 140));
//	ht.insert(make_pair(2, 1));
//	ht.insert(make_pair(3, 14));
//	ht.insert(make_pair(5, 16));
//	ht.insert(make_pair(7, 11));
//	ht.insert(make_pair(8, 140)); 
//	ht.insert(make_pair(13, 1));
//	
//	cout << ht.find(11) << endl;
//	cout << ht.find(100) << endl;
//
//	cout << ht.erase(11) << endl;
//	cout << ht.erase(100) << endl;
//}
//
