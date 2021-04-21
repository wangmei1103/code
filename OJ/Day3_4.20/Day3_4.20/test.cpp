#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>


//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if (numbers.empty())
//			return 0;
//		sort(numbers.begin(), numbers.end());
//		int mid = numbers[numbers.size() / 2];
//		int count = 0;
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			if (numbers[i] == mid)
//				++count;
//		}
//		return (count > numbers.size() / 2) ? mid : 0;
//	}
//};
//int main()
//{
//	vector<int> numbers;
//	numbers = { 1,2,3,4,3,3,3,3,3,4,5 };
//	
//	Solution nums;
//	nums.MoreThanHalfNum_Solution(numbers);
//	return 0;
//}

//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if (numbers.empty())
//			return 0;
//		if (numbers.size() == 1)
//			return 1;
//		sort(numbers.begin(), numbers.end());
//		int sz = numbers.size();
//		int max = 0;
//		int tmp, idex;
//		for (int i = 1; i < sz; i++)
//		{
//
//			if (numbers[i] == numbers[i - 1])
//			{
//				int count = 1;
//				tmp = i;
//				while (numbers[i] == numbers[i - 1])
//				{
//					count++;
//					if (i == sz - 1)
//					{
//						break;
//					}
//					i++;
//				}
//				if (count > max)
//				{
//					max = count;
//					idex = tmp;
//				}
//			}
//		}
//		return max >= (sz / 2) + 1 ? numbers[idex] : 0;
//	}
//};

//int main()
//{
//	vector<int> numbers;
//	//numbers = { 1,2,3,4,3,3,3,3,3,4,5 };
//	
//	Solution nums;
//	nums.MoreThanHalfNum_Solution(numbers);
//	return 0;
//}

//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//
//		int max = 0;
//		int sz = numbers.size();
//		for (int i = 0; i < sz; i++)
//		{
//			int count = 1;
//			int idex = i;
//			
//			for (int j = i + 1; j < sz; j++)
//			{
//				if (numbers[idex] == numbers[j])
//				{
//					count++;
//
//					if (count > (sz / 2))
//					{
//						cout << numbers[idex] << endl;
//					}
//					if (max < count)
//					{
//						max = count;
//					}
//				}
//			}
//			
//		}
//		if (max <= sz / 2)
//		{
//			cout << "0" << endl;
//		}
//		return 0;
//	}
//};
//int main()
//{
//	vector<int> numbers;
//	//numbers = { 1,2,3,4,3,3,3,3,3,4,5 };
//	Solution nums;
//	nums.MoreThanHalfNum_Solution(numbers);
//	return 0;
//}
//
//int main()
//{
//	string str("123as1234a");
//	//getline(cin, str);
//	
//	int max = 0;
//	int tmp, index;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			int count = 0;
//			tmp = i;
//			while (str[i] >= '0' && str[i] <= '9')
//			{
//				count++;
//				i++;
//			}
//			if (max < count)
//			{
//				max = count;
//				index = tmp;
//			}
//		}
//	}
//	cout << str.substr(index, max);
//	return 0;
//}
//int main()
//{
//	int b;
//	const int* a1 = &b;
//	int const *a2 = &b;
//	int *const a3 = &b;
//
//	return 0;
//}

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
//	//二维数组初始化
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