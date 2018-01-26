// 将字符串中的小写字母转换成大写字母 
// pkuzhd
// 2017.10.30

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	char str[101];
	while (cin >> str) {
		for (int i = 0; str[i]!='\0'; ++i) {
			if (str[i] <= 'z' && str[i] >= 'a')
				str[i] = str[i] - 'a' + 'A';
		}
		cout << str << endl;
	}
	return 0;
}