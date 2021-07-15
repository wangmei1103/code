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
	WriteFileHead(fOut, strFilePath);

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

void FileCompress::WriteFileHead(FILE* fOut, const string& filePath)
{
	//����Դ�ļ���׺  substr--�����Ӵ�
	string postFix = filePath.substr(filePath.rfind('.')); //Ĭ�Ͻ�ȡ��ĩβ
	postFix += "\n";
	fwrite(postFix.c_str(), 1, postFix.size(), fOut);

	//�����ֽ�Ƶ����Ϣ�ܵ�����
	//����ÿ�е��ַ�Ƶ����Ϣ
	string charAppear;
	size_t szLineCount = 0;
	for (auto& e : fileInfo)
	{
		//�����ִ�����0�ε��ַ����ַ������ִ���\n
		if (e.appearCount > 0)
		{
			charAppear += e.ch;
			charAppear += ","; //A,
			charAppear += to_string(e.appearCount); //1234--��1234��
			charAppear += "\n";
			szLineCount++;
		}
	}
	string strLineCount = to_string(szLineCount);
	strLineCount += "\n";
	fwrite(strLineCount.c_str(), 1, strLineCount.size(), fOut);
	fwrite(charAppear.c_str(), 1, charAppear.size(), fOut);

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


//��ѹ��
//���棺�����б����ѹ����Ϣ
//��ȡ�������з�ʽ���ж�ȡ

bool FileCompress::UNCompressFile(const string& strFilePath)
{
	FILE* fIn = fopen(strFilePath.c_str(), "r");
	//��ȡ��ѹ����Ҫ����Ϣ��һ�ζ�ȡһ�е�����
	string szContent;
	GetLine(fIn, szContent);
	string postFix = szContent;

	szContent = "";
	GetLine(fIn, szContent); //"4"

	size_t lineCount = atoi(szContent.c_str());
	for (size_t i = 0; i < lineCount; i++)
	{
		szContent = "";
		GetLine(fIn, szContent); //"A,1"

		char ch = szContent[0];
		fileInfo[ch].appearCount = atoi(szContent.c_str() + 2);
	}

	//��ԭhuffman��
	HuffmanTree<CharInfo> ht;
	CharInfo invalid;
	invalid.appearCount = 0;
	ht.CreateHuffmanTree(fileInfo, sizeof(fileInfo) / sizeof(fileInfo[0]), invalid);
	string fileName("3");
	fileName += postFix;
	FILE* fOut = fopen(fileName.c_str(), "w");

	//��ѹ��
	char readBuff[1024];
	HTNode<CharInfo>* cur = ht.GetRoot();
	size_t filesize = cur->weight.appearCount;
	size_t unCompressSize = 0;
	while (true)
	{
		// ��ȡѹ������
		size_t rdsize = fread(readBuff, 1, 1024, fIn);
		if (0 == rdsize)
			break;

		// �����rdBuff�е�ÿ���ֽڽ��н���
		// ���ո��ֽ��еĶ����Ʊ���λ--�Ӹ�λ����λ�������λ����
		// ���������ǰ��ձ���λ��ֵȥ����huffman��--һֱ������Ҷ�ӽڵ��λ��
		for (size_t i = 0; i < rdsize; ++i)
		{
			// rdBuff[i]
			char ch = readBuff[i];
			for (size_t j = 0; j < 8; ++j)
			{
				// ���ch�����1����0
				if (ch & 0x80)
					cur = cur->right;
				else
					cur = cur->left;
				ch <<= 1;
				if (NULL == cur->left && NULL == cur->right)
				{
					// curһ����Ҷ�ӽڵ�
					fputc(cur->weight.ch, fOut);
					cur = ht.GetRoot();
					unCompressSize++;
					if (filesize == unCompressSize)
						break;
				}
			}
		}
	}

	fclose(fIn);
	fclose(fOut);

	return true;
}
//�����л�ȡ�ļ�������
void FileCompress::GetLine(FILE* fIn, string& szContent)
{
	while (!feof(fIn))
	{
		char ch = fgetc(fIn);
		if (ch == '\n')
			return;

		szContent += ch;
	}
}