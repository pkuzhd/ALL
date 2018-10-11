#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int map[5][5];
int flag[5][5];

struct point
{
	int x, y;
	point(int a=0, int b=0)
	{
		x = a;
		y = b;
	}
};

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> map[i][j];
			flag[i][j] = map[i][j];
		}
	}
	point q[25];
	int p[25];
	int head = 0;
	int tail = 0;
	q[tail] = point(0, 0);
	p[tail] = -1;
	flag[0][0] = 1;
	++tail;
	while (head != tail)
	{
		if (q[head].x == 4 && q[head].y == 4)
		{
			stack<point> s;
			int cur = head;
			while (cur != -1)
			{
				s.push(q[cur]);
				cur = p[cur];
			}
			while (!s.empty())
			{
				cout << "(" <<  s.top().x << ", " << s.top().y << ")" << endl;
				s.pop();
			}
			break;
		}
		if (q[head].x - 1 >= 0 && !flag[q[head].x - 1][q[head].y])
		{
			q[tail] = point(q[head].x - 1, q[head].y);
			p[tail] = head;
			++tail;
			flag[q[head].x - 1][q[head].y] = 1;
		}
		if (q[head].x + 1 < 5 && !flag[q[head].x + 1][q[head].y])
		{
			q[tail] = point(q[head].x + 1, q[head].y);
			p[tail] = head;
			++tail;
			flag[q[head].x + 1][q[head].y] = 1;
		}
		if (q[head].y - 1 >= 0 && !flag[q[head].x][q[head].y - 1])
		{
			q[tail] = point(q[head].x, q[head].y - 1);
			p[tail] = head;
			++tail;
			flag[q[head].x][q[head].y - 1] = 1;
		}
		if (q[head].y + 1 < 5 && !flag[q[head].x][q[head].y + 1])
		{
			q[tail] = point(q[head].x, q[head].y + 1);
			p[tail] = head;
			++tail;
			flag[q[head].x][q[head].y + 1] = 1;
		}
		++head;
	}
	return 0;
}