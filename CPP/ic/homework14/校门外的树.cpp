// 校门外的树
// pkuzhd
// 2018.01.05
#include <iostream>
#include <cstdio>

using namespace std;

// 用数组中的数来表示树
// 1表示有树
// 0表示没有树
int main()
{
	int L, M, i, j, sum = 0;
	int tree[10010];
	int begin[101], end[101];
	cin >> L >> M;
	for (i = 0; i <= L; i++)
		tree[i] = 1;
	for (i = 0; i < M; i++)
	{
		cin >> begin[i] >> end[i];
	}
	for (i = 0; i < M; i++)
	{
		for (j = begin[i]; j <= end[i]; j++)
			tree[j] = 0;
	}
	for (i = 0; i <= L; i++)
	{
		if (tree[i] == 1)
			sum++;
	}
	cout << sum << endl;
	return 0;
}