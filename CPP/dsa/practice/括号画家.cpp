// 括号画家
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
	string str;
	cin >> str;
	stack<char> stk;
	for (auto i = str.begin(); i != str.end(); ++i)
	{
		if (*i == '{' || *i == '(' || *i == '[')
			stk.push(*i);
		else if (*i == '}')
		{
			if (!stk.empty() && stk.top() == '{')
			{
				stk.pop();
			}
			else
			{
				cout << "No" << endl;
				return 0;
			}
		}
		else if (*i == ']')
		{
			if (stk.top() == '[')
			{
				stk.pop();
			}
			else
			{
				cout << "No" << endl;
				return 0;
			}
		}
		else if (*i == ')')
		{
			if (stk.top() == '(')
			{
				stk.pop();
			}
			else
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}
	if (!stk.empty())
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}