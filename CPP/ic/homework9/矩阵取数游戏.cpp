// 矩阵取数游戏
// pkuzhd
// 2017.11.4

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	int **num = new int*[n];
	int ***dp = new int**[n];
	for (int i = 0; i < n; ++i)
	{
		num[i] = new int[m];
		dp[i] = new int*[m];
		for (int j = 0; j < m; ++j)
			dp[i][j] = new int[m];
	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> num[i][j];
			dp[i][j][j] = m*num[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			for (int k = 0; k < m-j; ++k)
			{
				dp[i][k][k+j] = max(dp[i][k+1][k+j]+num[i][k]*(m-j), 
									dp[i][k][k+j-1]+num[i][k+j]*(m-j));
			}
		}
		sum += dp[i][0][m-1];
	}
	cout << sum << endl;
	for (int i = 0; i < n; ++i)
	{
		delete [] num[i];
		for (int j = 0; j < m; ++j)
			delete [] dp[i][j];
		delete [] dp[i];
	}
	delete [] num;
	delete [] dp;
	return 0;
}
