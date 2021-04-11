#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void test()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	cout << q.size() << endl;
}



//void test()
//{
//	stack<int> st;//构造
//	//入栈
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		//出栈
//		st.pop();
//	}
//	cout << endl;
//	cout << st.size() << endl;
//}
int main()
{
	test();
	return 0;
}
