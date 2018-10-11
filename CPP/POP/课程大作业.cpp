#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

struct state
{
	int pre;       // 上一个状态（比当前状态完成的作业少了1个）
	int minScore;  // 到达当前状态的最低扣分
	int last;      // 当前状态下，最后完成的作业的编号
	int finishDay; // 作业last完成的时间
};
struct course
{
	string name;
	int ddl;
	int cost;
};
state dp[(1 << 16) + 10];
int n;
course courses[15];

void solve()
{
	dp[0].minScore = 0;
	dp[0].last = -1;
	dp[0].pre = -1;
	dp[0].finishDay = 0;

	for (int i = 1; i <= (1 << n) - 1; ++i)
	{
		dp[i].minScore = -1;
		dp[i].last = -1;
		dp[i].pre = -1;
		dp[i].finishDay = 0;

		for (int j = 0; j < n; ++j)
		{
			if ((i & (1 << j)) == 0)
				continue;
			int pre = i ^ (1 << j);

			state temp;
			temp.finishDay = dp[pre].finishDay + courses[j].cost;
			temp.minScore = dp[pre].minScore
				+ (temp.finishDay > courses[j].ddl ?
					temp.finishDay - courses[j].ddl : 0);
			temp.last = j;
			temp.pre = pre;

			if (dp[i].minScore == -1 || temp.minScore < dp[i].minScore)
			{
				dp[i] = temp;
			}
			else if (temp.minScore == dp[i].minScore)
			{
				stack<string> n1, n2;
				int cur1 = temp.pre;
				int cur2 = dp[i].pre;

				while (dp[cur1].last != -1)
				{
					n1.push(courses[dp[cur1].last].name);
					cur1 = dp[cur1].pre;

					n2.push(courses[dp[cur2].last].name);
					cur2 = dp[cur2].pre;
				}
				while (!n1.empty())
				{
					if (n1.top() == n2.top())
					{
						n1.pop();
						n2.pop();
					}
					else if (n1.top() < n2.top())
					{
						dp[i] = temp;
						break;
					}
					else
						break;
				}
			}
		}
	}
}
void print()
{
	int cur = (1 << n) - 1;
	cout << dp[cur].minScore << endl;
	stack<string> name;
	while (dp[cur].last != -1)
	{
		name.push(courses[dp[cur].last].name);
		cur = dp[cur].pre;
	}
	while (!name.empty())
	{
		cout << name.top() << endl;
		name.pop();
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> courses[i].name >> courses[i].ddl >> courses[i].cost;
		}
		solve();
		print();
	}
	return 0;
}