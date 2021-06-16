//#include<iostream>
//#include<string>
//using namespace std;
//#include<map>
//int main()
//{
//	string A, B;
//	while (cin >> A >> B)
//	{
//		map<char, int> m1, m2;
//		for (int i = 0; i < A.size(); i++)
//		{
//			m1[A[i]]++;
//		}
//		for (int j = 0; j < B.size(); j++)
//		{
//			m2[B[j]]++;
//		}
//		for (int k = 'A'; k <= 'Z'; k++)
//		{
//			if (m1[k] < m2[k])
//			{
//				cout << "No" << endl;
//				break;
//			}
//			if (k == 'Z')
//				cout << "Yes" << endl;
//		}
//	}
//	return 0;
//
//}
//�����˺ܾã�ͨ��50%����Ϊ������һ���ؼ��㣬�ֵ�Ԫ��һ��Ҫ����
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isBrother(string str, string s) {
	if (str.size() == s.size()) {
		if (str == s)
			return false;
		sort(str.begin(), str.end());
		sort(s.begin(), s.end());
		if (str == s)
			return true;
	}
	return false;
}
int main() {
	int num;
	while (cin >> num) {
		string str;
		string word, s;
		int index;
		vector<string> vs;
		for (int i = 0; i < num; ++i) {
			cin >> str;
			vs.push_back(str);
		}
		sort(vs.begin(), vs.end());  // ��Ϊ���ֵ䣬һ��Ҫ���򣡣�
		cin >> word;
		cin >> index;
		int counts = 0;

		for (int i = 0; i < num; ++i) {
			if (isBrother(word, vs[i])) {
				counts++;
				if (counts == index)
					s = vs[i];
			}
		}
		if (!vs.empty())
			cout << counts << endl;
		if (counts >= index)
			cout << s << endl;

	}
	return 0;
}