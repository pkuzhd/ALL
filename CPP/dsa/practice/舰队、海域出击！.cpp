// 舰队、海域出击！
// pkuzhd
// 2017.12.18
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct node
{
	int next;
	int to;
};

node e[500001];
int h[500001] = { 0 };
int v[500001] = { 0 };

bool dfs(int i)
{
	v[i] = -1;
	for (int j = h[i]; j != 0; j = e[j].next)
	{
		int temp = e[j].to;
		if (v[temp] == -1)
			return 0;
		else if (v[temp] == 0 && !dfs(temp))
			return 0;
	}
	v[i] = 1;
	return 1;
} 

bool check(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (v[i] == 0)
		{
			if (!dfs(i))
				return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		memset(v, 0, sizeof(v));
		memset(h, 0, sizeof(h));
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < m; ++j)
		{
			int from, to;
			cin >> from >> to;
			//scanf("%d%d", &from, &to);
			e[j].next = h[from];
			e[j].to = to;
			h[from] = j;
		}
		if (check(n))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}