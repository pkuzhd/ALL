// 关押罪犯
// pkuzhd
// 2017.12.18
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

struct node
{
	int member1;
	int member2;
	int value;
};


bool cmp(node a, node b)
{
	return a.value > b.value;
}

int find(int *pre, int *rel, int x)
{
	if (pre[x] == x)
		return x;
	int temp = pre[x];
	pre[x] = find(pre, rel, pre[x]);
	rel[x] = (rel[x] + rel[temp]) % 2;
	return pre[x];
}

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	node *num = new node[m];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &num[i].member1);
		scanf("%d", &num[i].member2);
		scanf("%d", &num[i].value);
	}
	int *pre = new int[n+1];
	int *rel = new int[n+1];
	for (int i = 1; i <= n; ++i)
	{
		pre[i] = i;
		rel[i] = 0;
	}
	sort(num, num + m, cmp);
	for (int i = 0; i < m; ++i)
	{
		int root1 = find(pre, rel, num[i].member1);
		int root2 = find(pre, rel, num[i].member2);
		if (root1 == root2 && rel[num[i].member1] == rel[num[i].member2])
		{
			cout << num[i].value << endl;
			return 0;
		}
		pre[root2] = root1;
		rel[root2] = (rel[num[i].member1] + rel[num[i].member2] + 1) % 2;

	}
	printf("0\n");
	return 0;
}