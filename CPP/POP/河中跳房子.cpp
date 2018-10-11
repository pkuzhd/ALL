#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int stone[50000];
int L, M, N;


bool judge(int k)
{
	int num = 0, pre = 0, i;
	for (i = 1; i <= N; ++i)
	{
		if (stone[i] - stone[pre] < k)
		{
			++num;
		}
		else pre = i;
	}
	if (L - stone[pre] < k)
		++num;
	return num <= M;
}

int main()
{
	cin >> L >> N >> M;
	stone[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> stone[i];
	}
	int left = 1;
	int right = L / (N - M);
	int mid = left + (right - left) / 2;
	int pre = 0;
	while (right >= left)
	{
		if (judge(mid))
			left = mid + 1;
		else
			right = mid - 1;
		mid = left + (right - left) / 2;
	}
	cout << right << endl;
	return 0;
}