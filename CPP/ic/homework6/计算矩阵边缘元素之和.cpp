//********************************
//*例程：计算矩阵边缘元素之和   **
//*作者：pkuzhd                 **
//*时间：2017.10.15             **
//********************************

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int k;
	int szNum[100][100];
	cin >> k;
	for (int _ = 0; _ < k; ++_)
	{
		int m, n;
		cin >> m >> n;
		// 输入矩阵
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> szNum[i][j];
			}
		}
		int sum=0;
		// 特殊情况
		// 只有一行
		if (m==1)
		{
			for (int i = 0; i < n; ++i)
			{
				sum+=szNum[0][i];
			}
			cout << sum << endl;
			continue;
		}

		// 只有一列
		if (n==1)
		{
			for (int i = 0; i < m; ++i)
			{
				sum+=szNum[i][0];
			}
			cout << sum << endl;
			continue;
		}
		// 计算上下边
		for (int i = 0; i < n; ++i)
		{
			sum += szNum[0][i]+szNum[m-1][i]; 
		}
		// 计算左右边
		for (int i = 1; i < m-1; ++i)
		{
			sum += szNum[i][0]+szNum[i][n-1];
		}
		cout << sum << endl;
	}
	return 0;
}
