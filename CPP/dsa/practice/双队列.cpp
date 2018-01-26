// 双队列
// pkuzhd
// 2017.12.05

#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	map<int, int> mp;
	int t;
	int size = 0;
	while (cin >> t)
	{
		if (t == 0)
			return 0;
		else if (t == 1)
		{
			int k, p;
			cin >> k >> p;
			mp[p] = k;
			++size;
		}
		else if (t == 2)
		{
			if (size == 0)
				cout << 0 << endl;
			else
			{
				for (auto i = mp.rbegin(); i != mp.rend(); ++i)
				{
					if (i->second != 0)
					{
						cout << i->second << endl;
						i->second = 0;
						--size;
						break;
					}
				}
			}
		}
		else
		{
			if (size == 0)
				cout << 0 << endl;
			else
			{
				for (auto i = mp.begin(); i != mp.end(); ++i)
				{
					if (i->second != 0)
					{
						cout << i->second << endl;
						i->second = 0;
						--size;
						break;
					}
				}
			}
		}
	}
	return 0;
}