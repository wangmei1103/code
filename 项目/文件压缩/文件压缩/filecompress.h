#pragma once
#include "HuffmanTree.hpp"
#include<string>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

//�ַ�
//����
//����
struct CharInfo
{
	char ch;
	size_t appearCount; //�ַ����ֵĴ���
	string strCode; //�ַ���Ӧ�ı���

	CharInfo operator+(const CharInfo& ci)const
	{
		CharInfo tmp;
		tmp.appearCount = this->appearCount + ci.appearCount;
		return tmp;
	}
	bool operator>(const CharInfo& ci)const
	{
		return this->appearCount > ci.appearCount;
	}
	bool operator!=(const CharInfo& ci)const
	{
		return this->appearCount != ci.appearCount;
	}
	bool operator==(const CharInfo& ci)const
	{
		return this->appearCount == ci.appearCount;
	}
};
class FileCompress
{
public:
	FileCompress();
	bool CompressFile(const string& strFilePath);
	bool UNCompressFile(const string& strFilePath);
private:
	void GenerateCode(HTNode<CharInfo>* root);
private:
	CharInfo fileInfo[256]; //����Դ�ļ����ַ����ֵĴ�����Ϣ�Լ�����
	//vector<string> _chatInfo;
};