#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int num[100000];
int pre[100000];
int post[100000];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			scanf("%d", &num[i]);
		int min = num[0];
		int max = num[n - 1];
		pre[0] = 0;
		post[n - 1] = 0;
		for (int i = 1; i < n; ++i)
		{
			pre[i] = pre[i - 1] > num[i] - min ? pre[i - 1] : num[i] - min;
			post[n - 1 - i] = post[n - i] > max - num[n - 1 - i] ? post[n - i] : max - num[n - 1 - i];
			min = num[i] < min ? num[i] : min;
			max = num[n - 1 - i] > max ? num[n - 1 - i] : max;
		}
		int max_v = 0;
		for (int i = 1; i < n - 1; ++i)
		{
			max_v = max_v < pre[i] + post[i] ? pre[i] + post[i] : max_v;
		}
		cout << max_v << endl;
	}
	return 0;
}
