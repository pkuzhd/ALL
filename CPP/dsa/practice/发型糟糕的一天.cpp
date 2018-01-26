// 发型糟糕的一天
// pkuzhd
// 2017.12.07
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int num;
	long k = 0;
	stack<int> stk;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		while (!stk.empty() && num >= stk.top())
			stk.pop();
		k += stk.size();
		stk.push(num);
	}
	cout << k << endl;
	return 0;
}