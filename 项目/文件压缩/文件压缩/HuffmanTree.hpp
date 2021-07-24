#pragma once
#include "filecompress.h"
#include<queue>
#include<vector>
#include<functional>
#include<iostream>
using namespace std;
//实现Huffman树（二叉树结构）
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
		//先创建n个只有根节点的二叉树森林
		//priority_queue<HTNode<W>*, vector<HTNode<W>*>, greater<HTNode<W>>> q;
		priority_queue<HTNode<W>*, vector<HTNode<W>*>, Compare<W>> q;

		for (size_t i = 0; i < size; i++)
		{
			if(array[i] != invalid)
				q.push(new HTNode<W>(array[i]));
		}
		
		while (q.size() > 1)
		{
			//从二叉树中取权值较小的两棵二叉树
			HTNode<W>* left = q.top();
			q.pop();
			HTNode<W>* right = q.top();
			q.pop();

			//以left和right作为一个新节点的左右孩子
			//新节点中的权值就是其左右孩子节点的权值之和
			HTNode<W>* parent = new HTNode<W>(left->weight + right->weight);
			parent->left = left;
			parent->right = right;
			left->parent = parent;
			right->parent = parent;

			//将创建好的新的二叉树插回到优先级队列中
			q.push(parent);
		}
		//当森林中只剩一棵树，就是Huffman树
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