#include<iostream>
using namespace std;

//我们拿5来说事，首先5个人来进行抽奖，有多少种抽法？
//因为是不放回抽，所以第一个人有5种抽法，
//第二个人有4种抽法，依次类推
//总共就是5！ 对有5的阶乘种抽法。这是分母
//那可想而知分子就是存在多少种情况每个人拿不到自己的名字。
//这里要应用错排算法。
//简单的做个介绍
//当n个编号元素放在n个编号位置，元素编号与位置编号各不对应的方法数用f(n)表示，
//那么f(n-1)就表示n-1个编号元素放在n-1个编号位置，各不对应的方法数，其它类推.
//第一步，把第n个元素放在一个位置，比如位置k，一共有n-1种方法；
//第二步，放编号为k的元素，这时有两种情况：把它放到位置n，那么，对于剩下的n-1个元素，
//由于第k个元素放到了位置n，剩下n-2个元素就有f(n-2)种方法；
//第k个元素不把它放到位置n，这时，对于这n-1个元素，有f(n-1)种方法；
//综上得到递推公式，可以发现可以用递归来做；
//f(n) = (n-1) [f(n-2) + f(n-1)]
//特殊地，f(1) = 0, f(2) = 1.
//那么f(5)=4*[f(3)+f(4)]；依次求得f(3)、f(4),最后f(5)=44
//所以5个人拿不到奖的概率就是44/120=36.67%
//void probability(int n)
//{
//	long long p[21] = { 0 };
//	p[1] = { 0 };
//	p[2] = { 1 };
//	long long f[21] = { 0 };
//	f[1] = { 1 };
//	f[2] = { 2 };
//	for (int i = 3; i < 21; i++)
//	{
//		p[i] = (i - 1)*(p[i - 2] + p[i - 1]);
//		f[i] = i * f[i - 1];
//	}
//	printf("%.2f", (1.0 * p[n] / f[n]) * 100);
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		probability(n);
//		cout << "%" << endl;
//	}
//	return 0;
//}
#include<string>
#include<vector>
#include<algorithm>
int main() {
	string str;
	while (getline(cin, str)) {
		vector<string> names;  // 存放所有数据
		int pos = 0;
		while (pos < str.length()) {  // 位置如果大于等于了长度，那么证明找完了，双引号的情况从该位置跳出
			if (str[pos] == '\"') {  // 找到双引号要处理双引号内部
				int end = str.find('\"', pos + 1);
				names.push_back(str.substr(pos + 1, end - pos - 1));  // 截取出来放到names中
				pos = end + 2;  // 跳过后面的双引号和逗号
			}
			else {
				int end = str.find(",", pos + 1);
				if (end == -1) {  // 找不到逗号证明这是最后一个字符串了，直接存该字符串后跳出
					names.push_back(str.substr(pos, str.size() - pos));
					break;
				}
				names.push_back(str.substr(pos, end - pos));
				pos = end + 1;  // 跳过后面的逗号
			}
		}
		getline(cin, str);
		if (names.end() == find(names.begin(), names.end(), str))
			// find函数在两个迭代器中间查找，最后一个参数为要找的值
			// 找到了返回对应迭代器，找不到返回区间末尾位置，本例子为end()
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
	}
	return 0;
}
