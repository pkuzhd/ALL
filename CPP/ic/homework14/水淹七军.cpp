// 水淹七军
// pkuzhd
// 2018.01.05
#include<stdio.h>  
#include<iostream>  
#include<algorithm>  
#include<string.h>  
#include<vector>  
#include<queue> 

using namespace std;

int a[205][205];
int n, m, ha, haha;
int we[40000], ni[40000];

struct node
{
	int x, y;
} now1, next1;

int vis[205][205];//能淹就标记1  
int d[4][2] = { 0,1,0,-1,1,0,-1,0 };

int bfs(int x1, int y1)
{
	queue<node>q;
	now1.x = x1;
	now1.y = y1;
	vis[x1][y1] = 1;
	q.push(now1);
	while (!q.empty())
	{
		now1 = q.front();
		q.pop();
		for (int i = 0; i<4; i++)
		{
			next1.x = now1.x + d[i][0];
			next1.y = now1.y + d[i][1];
			if (next1.x >= 1 && next1.x <= n&&next1.y >= 1 && next1.y <= m&&vis[next1.x][next1.y] == 0 && (a[next1.x][next1.y] <= a[x1][y1]))//判断能淹的地方  
			{
				if ((next1.x == ha) && (next1.y == haha))//如果能淹到目的地，则返回1  
				{
					return 1;
				}
				vis[next1.x][next1.y] = 1;
				q.push(next1);
			}
		}
	}
	return 0;
}
int main(int argc, char *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		}
		scanf("%d%d", &ha, &haha);
		int fang;
		scanf("%d", &fang);
		for (int i = 0; i<fang; i++)
		{
			scanf("%d%d", &we[i], &ni[i]);
		}
		int l = 0;
		for (int i = 0; i<fang; i++)//遍历放水点  
		{
			memset(vis, 0, sizeof(vis));
			if (bfs(we[i], ni[i]))//如果能淹，我就标记l=1  
			{
				l = 1;
				break;
			}
		}
		if (l == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}