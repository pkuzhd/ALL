// 发现它，抓住它
// pkuzhd
// 2017.12.13
#include <iostream>

using namespace std;

int myfind(int *pre, int *rel, int x)
{
	if (pre[x] == x)
		return x;
	int temp = pre[x];
	pre[x]= myfind(pre, rel, temp);
	rel[x] = (rel[x] + rel[temp]) % 2;
	return pre[x];
}

int main(int argc, char *argv[])
{
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int n, m;
		cin >> n >> m;
		int *pre = new int[n + 1];
		int *rel = new int[n + 1];
		for (int j = 1; j <= n; ++j)
		{
			pre[j] = j;
			rel[j] = 0;
		}
		for (int j = 0; j < m; ++j)
		{
			char ch;
			int a, b;
			cin >> ch >> a >> b;
			int root1 = myfind(pre, rel, a);
			int root2 = myfind(pre, rel, b);
			if (ch == 'D')
			{
				if (root1 != root2)
				{
					pre[root2] = root1;
					rel[root2] = (rel[a] + rel[b] + 1) % 2;
				}
			}
			else
			{
				if (root1 != root2)
				{
					cout << "Not sure yet." << endl;
				}
				else
				{
					if ((rel[a] + rel[b]) % 2 == 1)
						cout << "In different gangs." << endl;
					else
						cout << "In the same gang." << endl;
				}
			}
		}


		delete[] pre;
		delete[] rel;
	}
	return 0;
}