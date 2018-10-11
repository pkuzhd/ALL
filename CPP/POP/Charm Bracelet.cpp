#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct charm
{
	int w;
	int d;
};

charm things[3402];
int dp[3403][12881];
int n, m;


void solve()
{
	for (int i = 0; i <= m; ++i)
	{
		if (things[0].w > i)
			dp[0][i] = 0;
		else
			dp[0][i] = things[0].d;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			int t1 = dp[i - 1][j];
			int t2 = 0;
			if (j - things[i].w >= 0)
			{
				t2 = dp[i - 1][j - things[i].w] + things[i].d;
			}
			dp[i][j] = t1 > t2 ? t1 : t2;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &things[i].w, &things[i].d);
	}
	solve();
	cout << dp[n-1][m] << endl;
	return 0;
}