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
	//ͳ��Դ�ļ���ÿһ���ֽڳ��ֵĴ���
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
			//ͳ��
			fileInfo[readBuff[i]].appearCount++;
		}
	}
	//����huffman��
	HuffmanTree<CharInfo> ht;
	CharInfo invalid;
	invalid.appearCount = 0;
	ht.CreateHuffmanTree(fileInfo, 256, invalid);
	
	//����huffman����ÿ���ֽڵı���
	GenerateCode(ht.GetRoot());

	
	//��Ҫд���ѹ��ʱ�õ�����Ϣ
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

	//�����ҵ��ı����дԴ�ļ�
	
	char chBit = 0; //������ֹת������Ķ����Ʊ���λ
	char bitCount = 0; //chBit�з����˼�������λ

	//��ȡԴ�ļ�������
	fseek(pf, 0, SEEK_SET);
	while (true)
	{
		size_t rdsize = fread(readBuff, 1, 1024, pf);
		if (0 == rdsize)
			break; 
		//����ֽڽ���ת��
		for (size_t i = 0; i < rdsize; i++)
		{
			auto& strCode = fileInfo[readBuff[i]].strCode;

			//�����ֽڶ�Ӧ���ַ������Զ����Ƹ�ʽ��֯--chBit
			for (size_t j = 0; j < strCode.size(); j++)
			{
				chBit <<= 1;//chBitĩβ�����һ������0
				if (strCode[j] == '1')
					chBit |= 1;
				bitCount++;
				if (bitCount == 8)
				{
					//chBit����8������λ�Ѿ��������
					fputc(chBit, fOut);
					chBit = 0; //���
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
		//��Ҷ�ӽڵ㷽���ƶ��ұ���
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