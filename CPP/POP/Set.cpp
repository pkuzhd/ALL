#include <set>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	multiset<int> ms;
	set<int> s;
	int n; 
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string op;
		int num;
		cin >> op >> num;
		if (op == "add")
		{
			ms.insert(num);
			s.insert(num);
			cout << ms.count(num) << "\n";
		}
		else if (op == "del")
		{
			cout << ms.count(num) << "\n";
			while (ms.find(num) != ms.end())
			{
				ms.erase(ms.find(num));
			}
		}
		else if (op == "ask")
		{
			if (s.find(num) == s.end())
				cout << "0 0\n";
			else
			{
				cout << "1 " << ms.count(num) << "\n";
			}
		}
	}
	return 0;
}