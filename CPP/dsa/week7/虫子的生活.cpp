// 虫子的生活
// pkuzhd
// 2017.12.12
#include <iostream>
#include <cstdio>

using namespace std;

int myfind(int *num, int *rel, int i)
{
	if (num[i] == i)
		return i;
	int temp;
	temp = num[i];
	num[i] = myfind(num, rel, temp);
	rel[i] = (rel[i] + rel[temp]) % 2;
	return num[i];
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		bool flag = true;
		int bugs, times;
		cin >> bugs >> times;
		int *num = new int[bugs + 1]; // 父结点
		int *rel = new int[bugs + 1]; // 与父结点的关系，0表示同性，1表示异性
		for (int j = 1; j <= bugs; ++j) // 初始化
		{
			num[j] = j;
			rel[j] = 0;
		}
		for (int j = 0; j < times; ++j)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			//cin >> x >> y;
			if (flag)
			{
				int root1 = myfind(num, rel, x);
				int root2 = myfind(num, rel, y);
				if (root1 != root2)
				{
					num[root2] = root1;
					rel[root2] = (rel[x] + rel[y] + 1) % 2;
				}
				else
				{
					if ((rel[x] + rel[y]) % 2 != 1)
						flag = false;
				}
			}
		}



		cout << "Scenario #" << i + 1 << ":" << endl;
		if (flag)
			cout << "No suspicious bugs found!" << endl;
		else
			cout << "Suspicious bugs found!" << endl;
		cout << endl;
		delete[] num;
		delete[] rel;
	}
	return 0;
}