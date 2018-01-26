// 统计字符数
// pkuzhd
// 2017.10.30

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char str[1001];
		int times[26] = {0};
		cin >> str;
		for (int j = 0; str[j] != '\0'; ++j) {
			++times[str[j]-'a'];
		}
		char idx = 'a';
		int max = 0;
		for (int j = 0; j < 26; ++j) {
			if (times[j] > max) {
				max = times[j];
				idx = j+'a';
			}
		}
		cout << idx << ' ' << max << endl;
	}
	return 0;
}