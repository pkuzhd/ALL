// 拼写检查
// pkuzhd
// 2017.12.13
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string dict[10001];
int length[10001];

bool is_change(string &str1, string &str2)
{
	if (str1.size() != str2.size())
		return false;
	else
	{
		int diff = 0;
		for (int i = 0; i < str1.size(); ++i)
		{
			if (str1[i] != str2[i])
				++diff;
		}
		if (diff == 1)
			return true;
		else
			return false;
	}
}

bool is_del(string &str1, string &str2)
{
	if (str1.size() != str2.size() + 1)
		return false;
	else
	{
		int i = 0;
		for (i = 0; i < str2.size(); ++i)
		{
			if (str1[i] != str2[i])
				break;
		}
		for (; i < str1.size(); ++i)
		{
			if (str1[i+1] != str2[i])
				return false;
		}
		return true;
	}
}

bool is_add(string &str1, string &str2)
{
	return is_del(str2, str1);
}

bool is_like(string &str1, string &str2)
{
	if (is_change(str1, str2) || is_del(str1, str2) || is_add(str1, str2))
		return true;
	else
		return false;
}

int main(int argc, char *argv[])
{
	int n = 0;
	while (cin >> dict[n] && dict[n] != "#")
	{
		++n;
	}
	string temp;
	while (cin >> temp && temp != "#")
	{
		int i = 0;
		for (i = 0; i < n; ++i)
		{
			if (dict[i] == temp)
			{
				cout << temp << " is correct" << endl;
				break;
			}
		}
		if (i == n)
		{
			cout << temp << ":";
			for (i = 0; i < n; ++i)
			{
				if (is_like(temp, dict[i]))
					cout << " " << dict[i];
			}
			cout << endl;
		}
	}
	return 0;
}