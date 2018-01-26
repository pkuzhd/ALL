// 统计字符数
// pkuzhd
// 2017.12.18
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int times[26] = { 0 };
		string str;
		cin >> str;
		int ch_max = 0;
		char max_ch = '#';
		for (auto ch : str)
		{
			++times[ch - 'a'];
		}
		for (int j = 0; j < 26; ++j)
		{
			if (times[j] > ch_max)
			{
				ch_max = times[j];
				max_ch = j + 'a';
			}
		}
		cout << max_ch << " " << ch_max << endl;
	}
	return 0;
}