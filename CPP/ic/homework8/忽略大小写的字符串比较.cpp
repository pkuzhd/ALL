// 忽略大小写的字符串比较
// pkuzhd
// 2017.10.30

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	char str1[81];
	char str2[81];
	gets(str1);
	gets(str2);
	for (int i = 0; str1[i]!='\0'&&str2[i]!='\0'; ++i) {
		if (str1[i] <= 'Z' && str1[i] >= 'A')
			str1[i] = str1[i] - 'A' + 'a';
		if (str2[i] <= 'Z' && str2[i] >= 'A')
			str2[i] = str2[i] - 'A' + 'a';
		if (str1[i] > str2[i]) {
			cout << ">" << endl;
			return 0;
		} else if (str1[i] < str2[i]) {
			cout << "<" << endl;
			return 0;
		}
	}
	cout << "=" << endl;
	return 0;
}