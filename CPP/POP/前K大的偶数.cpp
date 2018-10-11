#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{
public:
	int k;
	vector<int> num;
	MyQueue(int k) :k(k) { ; }
	friend istream &operator>>(istream &in, MyQueue &my)
	{
		int temp;
		in >> temp;
		my.num.push_back(temp);
		return in;
	}
	friend bool compare(int n1, int n2)
	{
		return (n1 % 2 == 0 && n2 % 2 == 0 && n1 > n2) || (n1 % 2 == 0);
	}
	friend ostream &operator<<(ostream &out, MyQueue &my)
	{
		sort(my.num.begin(), my.num.end(), [](int n1, int n2)->bool {
			return (n1 % 2 == 0 && (n2 % 2 != 0 || n1 > n2)); });
		for (int i = 0; i < my.k; ++i)
			out << my.num[i] << " ";
		return out;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout << q;
		cout << endl;
	}
	return 0;
}