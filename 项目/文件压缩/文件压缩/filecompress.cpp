#include "filecompress.h"

FileCompress::FileCompress()
{
	for (size_t i = 0; i < 256; i++)
	{
		fileInfo[i].ch = i;
		fileInfo[i].appearCount = 0;
	}
}

bool FileCompress::CompressFile(const string& strFilePath)
{
	//统计源文件中每一个字节出现的次数
	FILE* pf = fopen(strFilePath.c_str(), "r");
	if (pf == NULL)
	{
		return false;
	}
	char readBuff[1024];
	while (true)
	{
		size_t rdsize = fread(readBuff, 1, 1024, pf);
		if (rdsize == 0)
			break;

		for (size_t i = 0; i < rdsize; i++)
		{
			//统计
			fileInfo[readBuff[i]].appearCount++;
		}
	}
	//创建huffman树
	HuffmanTree<CharInfo> ht;
	CharInfo invalid;
	invalid.appearCount = 0;
	ht.CreateHuffmanTree(fileInfo, 256, invalid);
	
	//根据huffman树找每个字节的编码
	GenerateCode(ht.GetRoot());

	
	//需要写入解压缩时用到的信息
	FILE* fOut = fopen("2.txt", "w");
	if (fOut == NULL)
	{
		fclose(pf);
		return false;
	}


	//A-100 B-101 C-11 D-0
	//ABBBCCCCCDDDDDDD
	//10010110 11011111 11111100 00000000
	//0x96     0xDF     0xFC     0x00

	//根据找到的编码改写源文件
	
	char chBit = 0; //用来防止转换结果的二进制比特位
	char bitCount = 0; //chBit中放置了几个比特位

	//获取源文件的内容
	fseek(pf, 0, SEEK_SET);
	while (true)
	{
		size_t rdsize = fread(readBuff, 1, 1024, pf);
		if (0 == rdsize)
			break; 
		//逐个字节进行转换
		for (size_t i = 0; i < rdsize; i++)
		{
			auto& strCode = fileInfo[readBuff[i]].strCode;

			//将该字节对应的字符编码以二进制格式组织--chBit
			for (size_t j = 0; j < strCode.size(); j++)
			{
				chBit <<= 1;//chBit末尾添加了一个比特0
				if (strCode[j] == '1')
					chBit |= 1;
				bitCount++;
				if (bitCount == 8)
				{
					//chBit里面8个比特位已经填充满了
					fputc(chBit, fOut);
					chBit = 0; //清空
					bitCount = 0;
				}
			}
		}
	}
	
	if (bitCount > 0 && bitCount < 8)
	{
		chBit <<= (8 - bitCount);
		fputc(chBit, fOut);
	}
	fclose(pf); 
	fclose(fOut);
	return true;
}

void FileCompress::GenerateCode(HTNode<CharInfo>* root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL && root->right == NULL)
	{
		//从叶子节点方向移动找编码
 		HTNode<CharInfo>* cur = root;
		HTNode<CharInfo>* parent = cur->parent;

		auto& strCode = fileInfo[cur->weight.ch].strCode;
		while (parent)
		{
			if (cur == parent->left)
				strCode += '0';
			else
				strCode += '1';
			cur = parent;
			parent = cur->parent;
		}
		reverse(strCode.begin(), strCode.end());
	}
	GenerateCode(root->left);
	GenerateCode(root->right);
}