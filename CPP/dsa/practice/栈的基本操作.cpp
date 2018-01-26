// 栈的基本操作
// pkuzhd
// 2017.12.16
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		stack<int> stk;
		int n;
		cin >> n;
		bool flag = true;

		for (int j = 0; j < n; ++j)
		{
			string str;
			cin >> str;
			if (str == "pop")
			{
				if (stk.empty())
				{
					flag = false;
				}
				else
				{
					stk.pop();
				}
			}
			else
			{
				int temp;
				cin >> temp;
				stk.push(temp);
			}
		}
		stack<int> stk1;
		if (flag)
		{
			if (!stk.empty())
			{
				while (!stk.empty())
				{
					stk1.push(stk.top());
					stk.pop();
				}
				cout << stk1.top();
				stk1.pop();
				while (!stk1.empty())
				{
					cout << " " << stk1.top();
					stk1.pop();
				}
				cout << endl;
			}
		}
		else
		{
			cout << "error" << endl;
		}
	}
	return 0;
}