#pragma once
#include "HuffmanTree.hpp"
#include<string>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

//字符
//次数
//编码
struct CharInfo
{
	char ch;
	size_t appearCount; //字符出现的次数
	string strCode; //字符对应的编码

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
	CharInfo fileInfo[256]; //保存源文件中字符出现的次数信息以及编码
	//vector<string> _chatInfo;
};