#pragma once
#include "filecompress.h"
#include<queue>
#include<vector>
#include<functional>
#include<iostream>
using namespace std;
//ʵ��Huffman�����������ṹ��
template<class W>
struct HTNode
{
	HTNode(const W& w)
		:left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, weight(w)
	{}
	HTNode<W>* left;
	HTNode<W>* right;
	HTNode<W>* parent;
	W weight;
};
template<class W>
struct Compare
{
	bool operator()(const HTNode<W>* left, const HTNode<W>* right)
	{
		return left->weight > right->weight;
	}
};

template<class W>
class HuffmanTree
{
public:
	HuffmanTree() 
		:root(nullptr) 
	{}
	~HuffmanTree()
	{
		DestroyTree(root);
	}
	void CreateHuffmanTree(const W array[], size_t size, const W& invalid)
	{
		//�ȴ���n��ֻ�и��ڵ�Ķ�����ɭ��
		//priority_queue<HTNode<W>*, vector<HTNode<W>*>, greater<HTNode<W>>> q;
		priority_queue<HTNode<W>*, vector<HTNode<W>*>, Compare<W>> q;

		for (size_t i = 0; i < size; i++)
		{
			if(array[i] != invalid)
				q.push(new HTNode<W>(array[i]));
		}
		
		while (q.size() > 1)
		{
			//�Ӷ�������ȡȨֵ��С�����ö�����
			HTNode<W>* left = q.top();
			q.pop();
			HTNode<W>* right = q.top();
			q.pop();

			//��left��right��Ϊһ���½ڵ�����Һ���
			//�½ڵ��е�Ȩֵ���������Һ��ӽڵ��Ȩֵ֮��
			HTNode<W>* parent = new HTNode<W>(left->weight + right->weight);
			parent->left = left;
			parent->right = right;
			left->parent = parent;
			right->parent = parent;

			//�������õ��µĶ�������ص����ȼ�������
			q.push(parent);
		}
		//��ɭ����ֻʣһ����������Huffman��
		root = q.top();
	}
	void DestroyTree(HTNode<W>*& pRoot)
	{
		if (pRoot)
		{
			DestroyTree(pRoot->left);
			DestroyTree(pRoot->right);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	HTNode<W>* GetRoot()
	{
		return root;
	}
private:
	HTNode<W>* root;
};

//void TestHuffmanTree()
//{
//	HuffmanTree<int> ht;
//	int arr[] = { 3,5,1,7 };
//	ht.CreateHuffmanTree(arr, sizeof(arr) / sizeof(arr[0]));
//}