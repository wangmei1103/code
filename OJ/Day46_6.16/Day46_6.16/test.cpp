#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		// ��ϣ��洢ĳ�������ֵĴ��� hash��ѯʱ�临�Ӷ�O��1��;��ʱ�临�Ӷ�O��n��
//		map<int, int> m;
//		for (int i = 0; i < numbers.size(); ++i) {
//			m[numbers[i]] += 1;
//			if (m[numbers[i]] > numbers.size() / 2)
//				return numbers[i];
//		}
//		return 0;
//	}
//};

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int key = numbers[numbers.size() / 2];
		int count = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			if (key == numbers[i])
				++count;
		}
		if (count > numbers.size() / 2)
			return key;
		return 0;
	}
};
