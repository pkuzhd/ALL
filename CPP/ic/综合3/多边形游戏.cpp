// 多边形游戏
// pkuzhd
// 2018.01.05
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int num[100];
	int dp[100][100] = { 0 }; // dp[i][j]表示从第i个数合并到第j个数
	int flag[100] = { 0 }; // 记录符号
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char ch;
		cin >> num[i] >> ch;
		if (ch == '+')
			flag[i] = 0;
		else
			flag[i] = 1;
		num[i + n] = num[i];
		flag[i + n] = flag[i];
		dp[i][i] = num[i];
		dp[i + n][i + n] = num[i];
	}
	for (int k = 1; k < n; ++k)
	{
		for (int i = 0; i < 2 * n - k - 1; ++i)
		{
			int _max = 0;
			for (int t = 1; t <= k; ++t)
			{
				if (flag[i + k - t] == 0 && dp[i][i + k - t] + dp[i + k - t + 1][i + k] > _max)
					_max = dp[i][i + k - t] + dp[i + k + 1 - t][i + k];
				else if (flag[i + k - t] == 1 && dp[i][i + k - t] * dp[i + k - t + 1][i + k] > _max)
					_max = dp[i][i + k - t] * dp[i + k - t + 1][i + k];
			}
			dp[i][i + k] = _max;
		}
	}
	int _max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (dp[i][i + n - 1] > _max)
			_max = dp[i][i + n - 1];
	}
	cout << _max << endl;
	return 0;
}