#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;


class Printer {
public:
	int x;
	Printer(int x) :x(x) { ; }
	void operator()(int n)
	{
		if (n > x)
			cout << n << ",";
	}
	void operator()(string n)
	{
		if (n.size() > x)
			cout << n << ",";
	}
};
	
int main() {

		int t;
		cin >> t;
		while (t--) {
			int n, x;
			cin >> x >> n;

			vector<int> intVec;
			for (int i = 0; i < n; ++i) {
				int y;
				cin >> y;
				intVec.push_back(y);
			}
			for_each(intVec.begin(), intVec.end(), Printer(x));
			cout << endl;

			vector<string> strVec;
			for (int i = 0; i < n; ++i) {
				string str;
				cin >> str;
				strVec.push_back(str);
			}
			for_each(strVec.begin(), strVec.end(), Printer(x));
			cout << endl;
		}
		return 0;
	}