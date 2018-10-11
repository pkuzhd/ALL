#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int x = grid.size();
		int y = grid[0].size();
		vector<vector<int>> flag(x, vector<int>(y, 0));
		int maxA = 0;
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				if (grid[i][j] && flag[i][j] == 0)
				{
					int temp = dfs(grid, flag, i, j);
					maxA = max(maxA, temp);
				}
			}
		}
		return maxA;
	}
	int dfs(vector<vector<int>>& grid, vector<vector<int>>& flag, int x, int y)
	{
		int num = 1;
		flag[x][y] = 1;
		if (x - 1 >= 0 && grid[x - 1][y] == 1 && flag[x - 1][y] == 0)
			num += dfs(grid, flag, x - 1, y);
		if (y - 1 >= 0 && grid[x][y - 1] == 1 && flag[x][y - 1] == 0)
			num += dfs(grid, flag, x, y - 1);
		if (x + 1<grid.size() && grid[x + 1][y] == 1 && flag[x + 1][y] == 0)
			num += dfs(grid, flag, x + 1, y);
		if (y + 1<grid[0].size() && grid[x][y + 1] == 1 && flag[x][y + 1] == 0)
			num += dfs(grid, flag, x, y + 1);
		return num;
	}
};
int main()
{
	vector<vector<int>> nums(3, vector<int>(8, 1));
	nums[0][2] = 0;
	nums[0][4] = 0;
	nums[0][5] = 0;
	nums[1][0] = 0;
	nums[1][2] = 0;
	nums[1][7] = 0;
	nums[2][4] = 0;
	nums[2][5] = 0;
	nums[2][6] = 0;
	cout << Solution().maxAreaOfIsland(nums) << endl;
	return 0;
}
