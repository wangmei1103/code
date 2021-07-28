#include<iostream>
#include<vector>
using namespace std;

enum STATE
{
	EXIST,
	DELETE,
	EMPTY
};

//��ϣ������̽��
template<class K, class V>
struct HashNode
{
	pair<K, V> _kv;
	STATE _state = EMPTY;
};

//˳���ʵ��hash
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
		//1.�����ϣλ��
		int idx = kv.first % _hTable.size();

		//2.�ж�key�Ƿ����
		while (_hTable[idx]._state != EMPTY)
		{
			//�����ǰλ��������Ч����key��ͬ������ʧ��
			if (_hTable[idx]._state == EXIST && kv.first == _hTable[idx]._kv.first)
				return false;

			//��������
			++idx;
			if (idx == _hTable.size())
				idx = 0;
		}
		//����
		_hTable[idx]._kv = kv;
		_hTable[idx]._state = EXIST;
		++_size;
	}
private:
	vector<Node> _hTable;
	size_t _size;//��ЧԪ�صĸ���
};

void test()
{
	HashTable<int, int> ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(14, 14));
	ht.insert(make_pair(16, 16));
	ht.insert(make_pair(11, 11));
	ht.insert(make_pair(14, 140));

}

int main()
{
	test();
	return 0;
}