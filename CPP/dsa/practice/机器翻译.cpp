// 机器翻译
// pkuzhd
// 2017.12.16
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;



int main(int argc, char *argv[])
{
	int m, n;
	cin >> m >> n;
	bool is_in[1000000];
	memset(is_in, 0, sizeof(is_in));
	queue<int> q;
	int times = 0;
	int size = 0;
	int now = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		//cin >> temp;
		scanf("%d", &temp);
		if (is_in[temp])
			continue;
		else
		{
			++times;
			if (q.size() == m)
			{
				is_in[q.front()] = false;
				q.pop();
			}
			is_in[temp] = true;
			q.push(temp);
		}
	}
	cout << times << endl;
	return 0;
}