#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct player
{
	int weight;
	int height;
};
bool com_w(player p1, player p2)
{
	//�������ش�С�������� 
	if (p1.weight != p2.weight)
		return p1.weight <= p2.weight;
	//��������ȵ������£���߸ߵ���ǰ�����ϣ� 
	else
		return p1.height > p2.height;
}
int main(void)
{
	int n;
	int height;
	int weight;
	int index;
	vector<player> p;
	while (cin >> n)
	{
		p.clear();

		for (int i = 0; i < n; i++)
		{
			player t;
			cin >> index >> weight >> height;
			t.weight = weight;
			t.height = height;
			p.push_back(t);
		}
		sort(p.begin(), p.end(), com_w);
		//���������������������� 
		int dp2[n + 1];
		int max = 0;
		dp2[0] = 1;
		for (int i = 1; i < n; i++)
		{
			dp2[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (p[j].height <= p[i].height && dp2[j] + 1 > dp2[i])
					dp2[i] = dp2[j] + 1;
			}
		}
		for (int i = 0; i < n; i++)
			if (max < dp2[i])
				max = dp2[i];
		cout << max << endl;
	}
	return 0;
}