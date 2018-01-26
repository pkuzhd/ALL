#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int value, power;
		priority_queue <pair<int, int> > pq;
		while (true)
		{
			cin >> value >> power;
			if (power<0)
				break;
			pq.push(make_pair(power, value));
		}
		while (true)
		{
			cin >> value >> power;
			if (power<0)
				break;
			pq.push(make_pair(power, value));
		}
		int v, p;
		bool flag = false;
		while (!pq.empty())
		{
			if (flag)
				cout << ' ';
			flag = true;

			p = pq.top().first;
			v = pq.top().second;
			pq.pop();
			while (!pq.empty() && pq.top().first==p)
			{
				v += pq.top().second;
				pq.pop();
			}
			flag = false;
			if (v!=0)
			{
				cout << "[ " << v << ' ' << p << " ]";
				flag = true;
			}
			
			
		}
		cout << endl;
	}
	
	return 0;
}
