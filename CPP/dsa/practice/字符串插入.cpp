// 字符串插入
// pkuzhd
// 2017.12.05

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string str, substr;
	while (cin >> str >> substr)
	{
		int idx = 0;
		int max = str[0];
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] > max)
			{
				idx = i;
				max = str[i];
			}
		}
		for (int i = 0; i <= idx; ++i)
		{
			cout << str[i];
		}
		cout << substr;
		for (int i = idx + 1; i < str.size(); ++i)
		{
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}