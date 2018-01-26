// 数组区域数目问题
// pkuzhd
// 2018.01.05
#include <iostream>
#include <cstring>

using namespace std;

int num[10][10];
int visited[10][10];

int n;
int nm;
void dfs(int i, int j, int type) // 深度优先搜索，搜索所有可以走的路径
{
	if (i - 1 >= 0 && visited[i - 1][j] == 0 && num[i - 1][j] == type)
	{
		visited[i - 1][j] = 1;
		dfs(i - 1, j, type);
	}
	if (j - 1 >= 0 && visited[i][j - 1] == 0 && num[i][j - 1] == type)
	{
		visited[i][j - 1] = 1;
		dfs(i, j - 1, type);
	}
	if (i + 1 < n && visited[i + 1][j] == 0 && num[i + 1][j] == type)
	{
		visited[i + 1][j] = 1;
		dfs(i + 1, j, type);
	}
	if (j + 1 < n && visited[i][j + 1] == 0 && num[i][j + 1] == type)
	{
		visited[i][j + 1] = 1;
		dfs(i, j + 1, type);
	}
}
int main(int argc, char *argv[])
{
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> n;
		memset(visited, 0, sizeof(visited));
		nm = 0;
		for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < n; ++b)
			{
				cin >> num[a][b];
			}
		}
		for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < n; ++b)
			{
				if (visited[a][b] == 0)
				{
					++nm;
					visited[a][b] = 1;
					dfs(a, b, num[a][b]);
				}
			}
		}
		cout << nm << endl;
	}
	
	return 0;
}