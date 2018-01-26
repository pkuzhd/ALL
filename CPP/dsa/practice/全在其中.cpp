// 全在其中
// pkuzhd
// 2017.12.18
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string s, t;
	while (cin >> s >> t)
	{
		bool flag = true;
		int k = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			flag = false;
			for (int j = k; j<t.size(); ++j)
			{
				if (s[i] == t[j])
				{
					flag = true;
					k = j + 1;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}