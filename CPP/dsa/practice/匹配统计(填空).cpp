// 匹配统计(填空)
// pkuzhd
// 2017.12.18
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	//const int SIZE = 200010;
	//int f[SIZE], next[SIZE], cnt[SIZE];
	int n, m, q;
	cin >> n >> m >> q;
	string a, b;
	cin >> a >> b;
	string c = b + "#" + a + "@";

	int *next = new int[c.size()];
	next[0] = -1;
	int k = -1;
	int i = 0;
	cout << c << endl;
	while (i < c.size()) // 对B串自匹配，求next数组
	{
		while (k >= 0 && c[i] != c[k])
			k = next[k];
		++k;
		++i;
		if (i == c.size())
			break;
		next[i] = k;
	}
	for (int i = 0; i < c.size(); ++i)
		cout << next[i] << " ";
	cout << endl;

	int *f = new int[a.size()];

	for (int i = 2 + b.size(); i < c.size(); ++i)
	{
		int j = i;
		int t;
		if (i+1 == c.size())
			f[i-2-b.size] = 

	}






	delete[] next;
	return 0;

	

}