// The Unique MST
// pkuzhd
// 2017.12.18
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, m;
int a, minx, p[101];
bool flag, first;

struct edge
{
	int v1, v2, d, v;  //v标记MST中的每一条边 
}e[10001];

int findp(int x) 
{
	return x == p[x] ? x : p[x] = findp(p[x]);
}
int cmp(edge a, edge b)
{
	return a.d < b.d;
}

int Kruskal()
{
	for (int i = 1; i <= n; i++)
		p[i] = i;
	a = n; 
	int sum = 0;
	for (int i = 0; i<m; i++)
	{
		int p1 = findp(e[i].v1), p2 = findp(e[i].v2);
		if (p1 != p2)
		{
			sum += e[i].d;
			a--;
			p[p1] = p2;
			if (first) e[i].v = 1;  //边i属于MST 
		}
		if (a == 1)
			break;
	}
	if (a == 1)
		return sum;
	return -1;
}
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		flag = true; 
		first = true;
		for (int i = 0; i < m; i++)
		{
			cin >> e[i].v1 >> e[i].v2 >> e[i].d;
			e[i].v = 0;
		}
		sort(e, e + m, cmp);
		minx = Kruskal();        //求MST 
		first = false;               //注意MST已经求过了 
		for (int i = 0; i<m; i++)
		{
			if (e[i].v) 
			{        //删除MST中的一条边,再添加一条边形成连通图 
				int t = e[i].v1; //把这条件的两个点变成一个点，从而在下面的Kruskal中不会再选择这条边 
				e[i].v1 = e[i].v2;
				int sum = Kruskal();
				if (sum == minx)
				{
					flag = false; 
					break;
				}
				e[i].v1 = t;
			}
		}
		if (flag)
			cout << minx << endl;
		else
			cout << "Not Unique!" << endl;
	}
	return 0;
}