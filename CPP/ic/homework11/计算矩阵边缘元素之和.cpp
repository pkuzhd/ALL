// 计算矩阵边缘元素之和
// pkuzhd
// 2017.12.18
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int sum = 0;
		int m, n;
		cin >> m >> n;
		int **num = new int*[m]; // 动态分配数组
		for (int j = 0; j < m; ++j)
		{
			num[j] = new int[n]; // 动态分配数组
			for (int k = 0; k < n; ++k)
				cin >> num[j][k];
		}


		// 考虑特殊情况
		if (m == 1)
		{
			for (int k = 0; k < n; ++k)
				sum += num[0][k];
		}
		else
		{
			for (int k = 0; k < n; ++k)
				sum =  sum + num[0][k] + num[m - 1][k];
			if (n == 1)
			{
				for (int j = 1; j < m - 1; ++j)
				{
					sum += num[j][0];
				}
			}
			else
			{
				for (int j = 1; j < m - 1; ++j)
				{
					sum += num[j][0] + num[j][n - 1];
				}
			}
		}
		
		



		cout << sum << endl;
		for (int j = 0; j < m; ++j)
		{
			delete[] num[j]; // 销毁数组
		}
		delete[] num; // 销毁数组

	}
	return 0;
}