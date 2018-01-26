#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	// n = 12, m = 4;
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}
	int times = 0;
	int temp = 0;
	while(q.size()>1)
	{
		temp = q.front();
		q.pop();
		// if (q.empty())
		// {
		// 	break;
		// }
		++times;
		if (times==m)
		{
			times = 0;
		}
		else
		{
			q.push(temp);
		}
	}
	cout << q.front();
	return 0;
}