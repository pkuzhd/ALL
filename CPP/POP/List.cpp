#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

int main(int argc, const char *argv[])
{
	int n;
	cin >> n;
	map<int, list<int> > dict;
	for (int i = 0; i < n; ++i)
	{
		string cmd;
		cin >> cmd;
		int argv1, argv2;
		if (cmd == "new")
		{
			cin >> argv1;
			dict[argv1] = list<int>();
		}
		else if (cmd == "add")
		{
			cin >> argv1 >> argv2;
			dict[argv1].push_back(argv2);
		}
		else if (cmd == "merge")
		{
			cin >> argv1 >> argv2;
			dict[argv1].merge(dict[argv2]);
		}
		else if (cmd == "unique")
		{
			cin >> argv1;
			dict[argv1].sort();
			dict[argv1].unique();
		}
		else if (cmd == "out")
		{
			cin >> argv1;
			dict[argv1].sort();
			list<int>::iterator i = dict[argv1].begin();
			for (; i != dict[argv1].end(); ++i)
			{
				cout << *i << " ";
			}
			cout << endl;
		}

	}
	return 0;
}