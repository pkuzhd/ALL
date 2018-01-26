// 数字7游戏
// pkuzhd
// 2018.01.04
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	queue<int> q; // 用队列模拟
	for (int i = 1; i <= n; ++i)
		q.push(i);
	int t = 0;
	while (!q.empty())
	{
		++t;
		bool flag = false;
		if (t % 7 == 0) // 判断是否为7的倍数
			flag = true;
		int temp = t;
		while (!flag && temp > 0) // 判断是否含有数字7
		{
			if (temp % 10 == 7)
				flag = true;
			temp /= 10;
		}
		if (flag)
		{
			cout << q.front() << endl;
			q.pop();
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
	}
	//cout << q.front() << endl;
	return 0;
}