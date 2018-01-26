// 词典
// pkuzhd
// 2017.12.05

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	vector<string> key, item;
	map<string, string> mp;
	while (getline(cin, str))
	{
		if (str == "")
			break;
		else
		{
			int j = 0;
			while (str[j] != ' ')
				++j;
			mp.insert(make_pair(str.substr(j + 1, str.size()), str.substr(0, j)));
		}
	}
	while (cin >> str)
	{
		if (mp[str] != "")
			cout << mp[str] << endl;
		else
			cout << "eh" << endl;
		
	}
	return 0;
}