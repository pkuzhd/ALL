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
int dp[12881];
int temp[12881];
int n, m;


void solve()
{
	for (int i = 0; i <= m; ++i)
	{
		if (things[0].w > i)
			dp[i] = 0;
		else
			dp[i] = things[0].d;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			temp[j] = dp[j];
			if (j - things[i].w >= 0)
			{
				if (temp[j - things[i].w] + things[i].d > temp[j])
					dp[j] = temp[j - things[i].w] + things[i].d;
			}
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
	cout << dp[m] << endl;
	return 0;
}