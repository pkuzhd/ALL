// 我爱北大
// pkuzhd
// 2017.12.18
// Floyd算法
#include <iostream>
#include <cstdio>
#include <string>
#include <limits.h>

using namespace std;

#define MAXP 33
string place[MAXP];
int dis[MAXP][MAXP] = { 0 };
int path[MAXP][MAXP] = { 0 };
int P, Q, R;

int getNum(string src)
{
	for (int i = 0; i<P; ++i)
	{
		if (src == place[i])
		{
			return i;
		}
	}
	return -1;
}

void process() // Floyd算法
{
	for (int k = 0; k < P; ++k)
	{
		for (int i = 0; i < P; ++i)
		{
			for (int j = 0; j < P; ++j)
			{
				int dis1 = dis[i][j];
				int dis2 = INT_MAX;
				if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX)
				{
					dis2 = dis[i][k] + dis[k][j];
				}
				if (dis2 < dis1)
				{
					dis[i][j] = dis2;
					path[i][j] = k;
				}
			}
		}
	}

}

void print(int _x, int _y)
{
	if (path[_x][_y] == -1)
	{
		cout << "->(" << dis[_x][_y] << ")->" << place[_y];
		return;
	}
	print(_x, path[_x][_y]);
	print(path[_x][_y], _y);
}


int main()
{
	cin >> P;
	for (int i = 0; i < P; ++i) // 初始化
	{
		for (int j = 0; j < P; ++j)
		{
			dis[i][j] = INT_MAX;
			path[i][j] = -1;
		}
	}
	for (int i = 0; i < P; ++i)
	{
		cin >> place[i];
	}
	for (int i = 0; i < P; ++i)
	{
		dis[i][i] = 0;
		path[i][i] = i;
	}

	cin >> Q;
	while (Q--)
	{
		string p1, p2;
		int dis0;
		cin >> p1 >> p2;
		scanf("%d", &dis0);
		int a = getNum(p1);
		int b = getNum(p2);
		if (dis0 < dis[a][b])
		{
			dis[a][b] = dis0;
			dis[b][a] = dis0;
		}
	}

	process();

	cin >> R;
	while (R--)
	{
		string p1, p2;
		cin >> p1 >> p2;
		int x = getNum(p1);
		int y = getNum(p2);
		if (x == y)
		{
			cout << place[x] << endl;
			continue;
		}
		cout << place[x];
		print(x, y);
		cout << endl;
	}
	return 0;
}
