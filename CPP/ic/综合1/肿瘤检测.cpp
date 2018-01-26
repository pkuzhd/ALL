// 肿瘤检测
// pkuzhd
// 2018.01.04
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int num[101][101];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> num[i][j]; // 循环输入数组
		}
	}
	int area = 0;
	int length = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (num[i][j] <= 50) // 判断是否为肿瘤
			{
				++area;
				if ((i - 1 < 0 || num[i - 1][j] > 50) || (i + 1 >= n || num[i + 1][j] > 50) || (j - 1 < 0 || num[i][j - 1] > 50) || (j + 1 >= n || num[i][j + 1] > 50)) // 判断是否为边界
					++length;
			}
		}
	}
	cout << area << " " << length;
	return 0;
}