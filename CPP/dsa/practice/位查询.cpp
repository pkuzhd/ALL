// 位操作
// pkuzhd
// 2017.12.05
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int num[100001];

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	for (int i = 0; i < m; ++i)
	{
		string str;
		int temp;
		cin >> str >> temp;
		if (str == "Q")
		{
			int count = 0;
			for (int i = 0; i < n; ++i)
			{
				int t = 1 << temp;
				if ((num[i] & t) == t)
				{
					++count;
				}
			}
			cout << count << endl;
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				num[i] = (num[i] + temp) % 65535;
			}
		}
	}
	return 0;
}