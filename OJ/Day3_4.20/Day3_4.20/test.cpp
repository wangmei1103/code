#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int b;
	const int* a1 = &b;
	int const *a2 = &b;
	int *const a3 = &b;
	return 0;
}

//int main()
//{
//	char a[10] = { '1','2','3','4','5','6','7','8','9','0' }, *p;
//	int i;
//	i = 8;
//	p = a + i;
//	printf("%s\n", p - 3);
//	return 0;
//}

/*int fun()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	cout << (fun());
}*/

//int main()
//{
//	//��ά�����ʼ��
//	int a[][3] = { {0,1,2},{3,4,5} };
//	return 0;
//}

//int main()
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}