// 用数组实现栈的进出
// pkuzhd
// 2018.01.05
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int stack[101];
	int len;
	cin >> len;
	for (int i = 0; i < len; ++i)
	{
		cin >> stack[i];
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (str == "POP")
		{
			if (len == 0)
			{
				cout << "INVALID OPERATION" << endl;
				return 0;
			}
			else
				--len;
		}
		else
		{
			cin >> stack[len];
			++len;
		}
	}
	for (int i = 0; i < len; ++i)
	{
		cout << stack[i] << " ";
	}
	return 0;
}