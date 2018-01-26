// 抓住那头牛
// pkuzhd
// 2017.12.14
#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
	int x;
	int step;
	node(int xx, int ss) : x(xx), step(ss) {}
};

int main(int argc, char *argv[])
{
	int n, k;
	cin >> n >> k;
	int visit[200001];
	memset(visit, 0, sizeof(visit));
	visit[n] = 1;
	queue<node> q;
	node temp(n, 0);
	q.push(temp);
	while (!q.empty())
	{
		temp = q.front();
		if (temp.x == k)
		{
			cout << temp.step << endl;
			return 0;
		}
		else
		{
			if (temp.x - 1 >= 0 && visit[temp.x - 1] == 0)
			{
				visit[temp.x - 1] = 1;
				q.push(node(temp.x - 1, temp.step + 1));
			}
			if (temp.x + 1 <= 100000 && visit[temp.x + 1] == 0)
			{
				visit[temp.x + 1] = 1;
				q.push(node(temp.x + 1, temp.step + 1));
			}
			if (temp.x * 2 <= 100000 && visit[temp.x * 2] == 0)
			{
				visit[temp.x * 2] = 1;
				q.push(node(temp.x * 2, temp.step + 1));
			}
			q.pop();
		}
	}
	return 0;
}