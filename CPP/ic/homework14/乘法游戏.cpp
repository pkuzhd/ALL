// 乘法游戏
// pkuzhd
// 2018.01.05
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int dp[11][11] = { 0 };
	int num[11];
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	for (int i = 1; i < n - 1; ++i)
		dp[i][i] = num[i - 1] * num[i] * num[i + 1];
	for (int k = 1; k < n - 2; ++k)
	{
		
		for (int i = 1; i < n - k; ++i)
		{
			int _max = 0;
			for (int t = 1; t < n; ++t)
			{
				
			}
			dp[i][i + k] = _max;
		}
		

	}
	cout << dp[1][n - 2] << endl;
	return 0;
}