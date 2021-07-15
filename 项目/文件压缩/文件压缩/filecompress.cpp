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
	WriteFileHead(fOut, strFilePath);

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

void FileCompress::WriteFileHead(FILE* fOut, const string& filePath)
{
	//保存源文件后缀  substr--生成子串
	string postFix = filePath.substr(filePath.rfind('.')); //默认截取到末尾
	postFix += "\n";
	fwrite(postFix.c_str(), 1, postFix.size(), fOut);

	//保存字节频次信息总的行数
	//保存每行的字符频次信息
	string charAppear;
	size_t szLineCount = 0;
	for (auto& e : fileInfo)
	{
		//将出现次数非0次的字符：字符，出现次数\n
		if (e.appearCount > 0)
		{
			charAppear += e.ch;
			charAppear += ","; //A,
			charAppear += to_string(e.appearCount); //1234--“1234”
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


//解压缩
//保存：按照行保存解压缩信息
//读取：按照行方式进行读取

bool FileCompress::UNCompressFile(const string& strFilePath)
{
	FILE* fIn = fopen(strFilePath.c_str(), "r");
	//获取解压缩需要的信息，一次读取一行的内容
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

	//还原huffman树
	HuffmanTree<CharInfo> ht;
	CharInfo invalid;
	invalid.appearCount = 0;
	ht.CreateHuffmanTree(fileInfo, sizeof(fileInfo) / sizeof(fileInfo[0]), invalid);
	string fileName("3");
	fileName += postFix;
	FILE* fOut = fopen(fileName.c_str(), "w");

	//解压缩
	char readBuff[1024];
	HTNode<CharInfo>* cur = ht.GetRoot();
	size_t filesize = cur->weight.appearCount;
	size_t unCompressSize = 0;
	while (true)
	{
		// 读取压缩数据
		size_t rdsize = fread(readBuff, 1, 1024, fIn);
		if (0 == rdsize)
			break;

		// 逐个对rdBuff中的每个字节进行解析
		// 按照该字节中的二进制比特位--从高位往低位逐个比特位解析
		// 解析：就是按照比特位的值去遍历huffman树--一直遍历到叶子节点的位置
		for (size_t i = 0; i < rdsize; ++i)
		{
			// rdBuff[i]
			char ch = readBuff[i];
			for (size_t j = 0; j < 8; ++j)
			{
				// 检测ch最高是1还是0
				if (ch & 0x80)
					cur = cur->right;
				else
					cur = cur->left;
				ch <<= 1;
				if (NULL == cur->left && NULL == cur->right)
				{
					// cur一定是叶子节点
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
//按照行获取文件中内容
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