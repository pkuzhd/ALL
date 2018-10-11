#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

struct point
{
	int x, y;
	point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

int map[8][8];
int flag[8][8];
int n, k, number;
vector<point> board;
int times;
int nn;
void dfs(point p, int idx);
void dfs(int x, int y, int idx)
{
	if (k > board.size() - idx + times)
		return;
	int t_flag = true;
	for (int i = 0; i < n; ++i)
	{
		if (i != x && map[i][y] == 0 && flag[i][y] == 1)
		{
			t_flag = false;
			break;
		}
		if (i != y && map[x][i] == 0 && flag[x][i] == 1)
		{
			t_flag = false;
			break;
		}
	}
	if (t_flag)
	{
		flag[x][y] = 1;
		++times;
		if (times == k)
		{
			++nn;
		}
		else
			dfs(board[idx + 1], idx + 1);
		flag[x][y] = 0;
		--times;
	}
	if (idx + 1 < board.size())
		dfs(board[idx + 1], idx + 1);
}
void dfs(point p, int idx)
{
	dfs(p.x, p.y, idx);
}



int main()
{
	while (cin >> n >> k)
	{
		if (n == -1)
			return 0;
		number = 0;
		board.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				char ch;
				cin >> ch;
				if (ch == '#')
				{
					++number;
					map[i][j] = 0;
					board.push_back(point(i, j));
				}
				else
					map[i][j] = 1;
			}
		}
		number = 0;
		times = 0;
		nn = 0;
		dfs(board[0], 0);
		cout << nn << endl;
	}
}