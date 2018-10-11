#include <set>
#include <iostream>
#include <string>
using namespace std;

class myComp
{
public:
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const
	{
		if (p1.first == -1 || p2.first == -1)
			return p1.second > p2.second;
		else
			return p1.first < p2.first;
	}
};

int main() {
	string cmd;
	set<pair<int, int>, myComp> S;
	while (cin >> cmd) {
		if (cmd == "A") {
			int x, y;
			cin >> x >> y;
			S.insert(make_pair(x, y));
		}
		else if (cmd == "Qx") {
			int x;
			cin >> x;
			cout << S.lower_bound(make_pair(x, -1))->second << endl;
		}
		else if (cmd == "Qy") {
			int y;
			cin >> y;
			cout << S.lower_bound(make_pair(-1, y))->first << endl;
		}
		else {
			int x, y;
			cin >> x >> y;
			S.erase(make_pair(x, y));
		}
	}
	return 0;
}