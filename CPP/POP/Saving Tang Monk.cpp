#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <map>
using namespace std;

char palace[100][100];
bool flag[100][100][33][11];
int n, m;
int d[4][2] = { {0, 1},{0, -1}, {1, 0}, {-1, 0} };


struct state
{
	int x, y;
	int t;
	int key_idx;
	int guard;
	bool operator<(const state &other) const
	{
		return t > other.t;
	}
};

int main()
{
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			return 0;

		state first;
		first.t = 0;
		first.key_idx = 0;
		first.guard = 0;

		memset(flag, 0, sizeof(flag));

		priority_queue<state> pq;
		map<pair<int, int>, int> guard_map;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> palace[i][j];
				if (palace[i][j] == 'K')
				{
					first.x = i;
					first.y = j;
				}
				else if (palace[i][j] == 'S')
				{
					int _ = guard_map.size();
					guard_map[make_pair(i, j)] = _;
					first.guard <<= 1;
					++first.guard;
				}
			}
		}
		flag[first.x][first.y][first.guard][0] = 1;
		pq.push(first);
		while (true)
		{
			if (pq.empty())
			{
				cout << "impossible" << endl;
				break;
			}
			state cur = pq.top();
			pq.pop();
			state next;
			bool t_flag = false;
			
			for (int i = 0; i < 4; ++i)
			{
				int x = d[i][0];
				int y = d[i][1];
				if (cur.x + x >= 0 && cur.x + x < n && cur.y + y >= 0 && cur.y + y < n && palace[cur.x + x][cur.y + y] != '#')
				{
					next.x = cur.x + x;
					next.y = cur.y + y;
					next.t = cur.t + 1;
					next.guard = cur.guard;
					next.key_idx = cur.key_idx;

					
					if (palace[next.x][next.y] == '.' || palace[next.x][next.y] == 'K')
						;
					else if (palace[next.x][next.y] == 'T')
					{
						if (next.key_idx == m)
						{
							t_flag = true;
							cout << next.t << endl;
							break;
						}

					}
					else if (palace[next.x][next.y] == 'S')
					{
						int guard_idx = guard_map[make_pair(next.x, next.y)];
						if (cur.guard & (1 << guard_idx))
						{
							++next.t;
							next.guard = cur.guard ^ (1 << guard_idx);
						}
					}
					else
					{
						if (palace[next.x][next.y] - '0'  == next.key_idx + 1)
						{
							++next.key_idx;
						}
					}
					if (!flag[next.x][next.y][next.guard][next.key_idx])
					{
						flag[next.x][next.y][next.guard][next.key_idx] = 1;
						pq.push(next);
					}
				}
			}
			if (t_flag)
				break;
		}
	}
}