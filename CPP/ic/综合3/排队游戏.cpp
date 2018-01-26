#include <iostream>
#include <string>
#include <stack>

using namespace std;



int main(int argc, char *argv[])
{
	string str;
	cin >> str;
	stack<int> s;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(') // 遇到小男孩就入栈
		{
			s.push(i);
		}
		else // 遇到小女孩就出栈
		{
			cout << s.top() << " " << i << endl;
			s.pop();
		}
	}
	return 0;
}