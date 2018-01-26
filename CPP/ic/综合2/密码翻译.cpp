// ÃÜÂë·­Òë
// pkuzhd
// 2018.01.04
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	string str;
	getline(cin, str);
	for (int i = 0; i < n; ++i)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j] == 'z' || str[j] == 'Z') // ÅĞ¶ÏÊÇ·ñÎªz, Z
				str[j] = str[j] - 'z' + 'a';
			else if ((str[j] >= 'a' && str[j] < 'z') || (str[j] >= 'A' && str[j] < 'Z'))
			{
				str[j] = str[j] + 1;
			}
		}
		cout << str << endl;
	}
	return 0;
}