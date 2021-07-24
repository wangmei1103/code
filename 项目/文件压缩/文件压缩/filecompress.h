#pragma once
#include "HuffmanTree.hpp"
#include<string>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

typedef unsigned char uchar;

//字符
//次数
//编码
struct CharInfo
{
	uchar ch;
	size_t appearCount; //字符出现的次数
	string strCode; //字符对应的编码
	//重载
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
	//文件压缩
	bool CompressFile(const string& strFilePath);
	//文件解压缩
	bool UNCompressFile(const string& strFilePath);
private:
	void GenerateCode(HTNode<CharInfo>* root);
	void WriteFileHead(FILE* fOut, const string& filePath);
	void GetLine(FILE* fIn, string& szContent);
private:
	CharInfo fileInfo[256]; //保存源文件中字符出现的次数信息以及编码
	//vector<string> _chatInfo;
};