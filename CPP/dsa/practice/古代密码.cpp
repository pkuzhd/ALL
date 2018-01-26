// 古代密码
// pkuzhd
// 2017.12.18
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	string str1, str2;
	cin >> str1 >> str2;
	int num[2][26] = { 0 };
	if (str1.size() != str2.size())
	{
		cout << "NO" << endl;
		return 0;
	}
	for (auto ch : str1)
	{
		++num[0][ch - 'A'];
	}
	for (auto ch : str2)
	{
		++num[1][ch - 'A'];
	}
	sort(num[0], num[0] + 26);
	sort(num[1], num[1] + 26);
	for (int i = 0; i < 26; ++i)
	{
		if (num[0][i] != num[1][i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}