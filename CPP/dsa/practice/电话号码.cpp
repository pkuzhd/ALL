// 电话号码
// pkuzhd
// 2017.12.14
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct node
{
	bool stop;
	node *next[10];
	node()
	{
		for (int i = 0; i < 10; ++i)
		{
			next[i] = NULL;
		}
		stop = false;
	}
	~node()
	{
		for (int i = 0; i < 10; ++i)
		{
			if (next[i] != NULL)
			{
				delete next[i];
				next[i] = NULL;
			}
		}
	}
};

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for (int k = 0; k < t; ++k)
	{
		int n;
		cin >> n;
		bool flag = true;
		node *root = new node;
		for (int j = 0; j < n; ++j)
		{
			node *now = root;
			string str;
			cin >> str;
			if (flag)
			{
				for (int i = 0; i < str.size(); ++i)
				{
					if (now->stop == true)
					{
						flag = false;
						break;
					}
					if (now->next[str[i] - '0'] == NULL)
					{
						now->next[str[i] - '0'] = new node;
					}
					now = now->next[str[i] - '0'];
				}
				for (int i = 0; i < 10; ++i)
				{
					if (now->next[i] != NULL)
					{
						flag = false;
						break;
					}
				}
				now->stop = true;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		delete root;
	}
	return 0;
}