// stack or queue
// pkuzhd
// 2017.12.16
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		queue<int> q;
		stack<int> s;
		bool not_queue = false;
		bool not_stack = false;
		for (int j = 0; j < m; ++j)
		{
			int t1, t2;
			cin >> t1 >> t2;
			if (!(not_queue || not_stack))
			{
				if (t1 == 1)
				{
					q.push(t2);
					s.push(t2);
				}
				else
				{
					if (q.front() != t2)
					{
						not_queue = true;
					}
					else if (s.top() != t2)
					{
						not_stack = true;
					}
					else
					{
						q.pop();
						s.pop();
					}
				}
			}
		}
		if (not_queue)
			cout << "Stack" << endl;
		else
			cout << "Queue" << endl;
	}
	return 0;
}