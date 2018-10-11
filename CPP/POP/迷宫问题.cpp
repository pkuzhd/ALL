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
	point(int x, int y) :x(x), y(y) { ; }
};
int map[5][5];
int flag[5][5];
int minLength = 9;
int curLength = 0;
point now(0, 0);
vector<point> minWay;
vector<point> way;

bool dfs(int i, int j)
{
	if (way.size() >= minLength)
		return false;
	way.push_back(point(i, j));
	if (i == 4 && j == 4)
	{
		minLength = way.size() - 1;
		minWay = way;
		return true;
	}
	bool t_flag = false;
	if (i > 0 && !flag[i - 1][j] && !map[i - 1][j])
	{
		flag[i - 1][j] = 1;
		t_flag |= dfs(i - 1, j);
		flag[i - 1][j] = 0;
	}
	if (i < 4 && !flag[i + 1][j] && !map[i + 1][j])
	{
 		flag[i + 1][j] = 1;
		t_flag |= dfs(i + 1, j);
		flag[i + 1][j] = 0;
	}
	if (j > 0 && !flag[i][j - 1] && !map[i][j - 1])
	{
		flag[i][j - 1] = 1;
		t_flag |= dfs(i, j - 1);
		flag[i][j - 1] = 0;
	}
	if (j < 4 && !flag[i][j + 1] && !map[i][j + 1])
	{
		flag[i][j + 1] = 1;
		t_flag |= dfs(i, j + 1);
		flag[i][j + 1] = 0;
	}
	way.pop_back();
	return t_flag;
}

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> map[i][j];
			flag[i][j] = 0;
		}
	}
	flag[0][0] = 1;
	dfs(0, 0);
	for (int i = 0; i < minWay.size(); ++i)
		cout << "(" << minWay[i].x << ", " << minWay[i].y << ")\n";
	return 0;
}