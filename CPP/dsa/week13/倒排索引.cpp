// µ¹ÅÅË÷Òý
// pkuzhd
// 2017.12.17
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	map<string, vector<int>> dict;
	for (int i = 1; i <= n; ++i)
	{
		int t;
		cin >> t;
		for (int j = 0; j < t; ++j)
		{
			string str;
			cin >> str;
			if (dict.find(str) == dict.end())
			{
				dict[str] = vector<int>{ i };
			}
			else
			{
				if (dict[str].back() != i)
					dict[str].push_back(i);
			}
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		if (dict.find(str) != dict.end())
		{
			cout << dict[str][0];
			for (auto it = dict[str].begin() + 1; it != dict[str].end(); ++it)
				cout << " " << *it;
			cout << endl;
		}
		else
			cout << "NOT FOUND" << endl;
	}
	return 0;
}