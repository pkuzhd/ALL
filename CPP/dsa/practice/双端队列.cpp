// 双端队列
// pkuzhd
// 2017.12.18
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		deque<int> dq;
		for (int j = 0; j < n; ++j)
		{
			int t1, t2;
			cin >> t1 >> t2;
			if (t1 == 1)
			{
				dq.push_back(t2);
			}
			else
			{
				if (t2 == 0)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}
		if (dq.empty())
			cout << "NULL" << endl;
		else
		{
			while(!dq.empty())
			{
				cout << dq.front() << " ";
				dq.pop_front();
			}
			cout << endl;
		}
	}
	return 0;
}