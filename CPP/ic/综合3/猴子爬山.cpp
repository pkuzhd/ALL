// 猴子爬山
// pkuzhd
// 2018.01.05
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int m;
	cin >> m;
	int dp[40] = { 0 };
	// 初始化前五个台阶
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 5;
	for (int i = 6; i <= m; ++i)
	{
		// 考虑最后一步，只可能是1，3，5
		dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 5];
	}
	cout << dp[m] << endl; // 输出结果
	return 0;
}