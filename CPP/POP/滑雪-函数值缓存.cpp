#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int num[100][100];
int dp[100][100];
int r, c;

void set_length(int x, int y)
{
	if (dp[x][y] != -1)
		return;
	int max = 0;
	if (x > 0 && num[x - 1][y] > num[x][y])
	{
		if (dp[x - 1][y] == -1)
			set_length(x - 1, y);
		if (dp[x - 1][y] > max)
			max = dp[x - 1][y];
	}
	if (x < r-1 && num[x + 1][y] > num[x][y])
	{
		if (dp[x + 1][y] == -1)
			set_length(x + 1, y);
		if (dp[x + 1][y] > max)
			max = dp[x + 1][y];
	}
	if (y > 0 && num[x][y - 1] > num[x][y])
	{
		if (dp[x][y - 1] == -1)
			set_length(x, y - 1);
		if (dp[x][y - 1] > max)
			max = dp[x][y - 1];
	}
	if (y < c - 1 && num[x][y + 1] > num[x][y])
	{
		if (dp[x][y + 1] == -1)
			set_length(x, y + 1);
		if (dp[x][y + 1] > max)
			max = dp[x][y + 1];
	}
	dp[x][y] = max + 1;
}

int main()
{
	
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			scanf("%d", &num[i][j]);
			dp[i][j] = -1;
		}
	}
	int max = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			set_length(i, j);
			if (dp[i][j] > max)
				max = dp[i][j];
		}
	}
	cout << max << endl;
	return 0;
}