// 倒排索引查询
// pkuzhd
// 2017.12.17
// 学习自 http://blog.csdn.net/just_young/article/details/38240169
#include <set>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	vector<set<int> > table;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		table.push_back(set<int>());
		int t;
		cin >> t;
		for (int j = 0; j < t; ++j)
		{
			int temp;
			cin >> temp;
			table[i].insert(temp);
		}
	}
	int m;
	cin >> m;
	vector<vector<int> > dict(m);
	for (int i = 0; i < m; ++i)
	{
		dict[i] = vector<int>();
		for (int j = 0; j < n; ++j)
		{
			int temp;
			cin >> temp;
			dict[i].push_back(temp);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		set<int> result;
		for (int j = 0; j < n; ++j)
		{
			if (dict[i][j] == 0 || dict[i][j] == -1)
				continue;
			if (result.empty())
				result.insert(table[j].begin(), table[j].end());
			else
			{
				set<int> new_result;
				for (auto it = table[j].begin(); it != table[j].end(); ++it)
				{
					if (result.find(*it) != result.end())
					{
						new_result.insert(*it);
					}
				}
				result = new_result;
				if (result.empty())
					break;
			}
		}
		for (int j = 0; j < n; ++j)
		{
			if (dict[i][j] == 0 || dict[i][j] == 1)
				continue;
			for (auto it = table[j].begin(); it != table[j].end(); ++it)
			{
				result.erase(*it);
			}

		}
		if (result.empty())
			cout << "NOT FOUND" << endl;
		else
		{
			for (auto it = result.begin(); it != result.end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
	}
	return 0;
}