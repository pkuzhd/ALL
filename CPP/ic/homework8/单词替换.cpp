// 单词替换
// pkuzhd
// 2017.10.30

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	char str[101];
	char a[101];
	char b[101];
	gets(str);
	gets(a);
	gets(b);
	bool flag = true; // flag记录是否匹配
	for (int i = 0; str[i]!='\0'; ++i) {
		int j;
		flag = true;
		for (j = 0; a[j]!='\0'; ++j) {
			if (str[j+i] != a[j]) {
				flag = false;
				break;
			}
		}
		if (flag && (str[i+j]==' ' || str[i+j]=='\0')) {
			if (str[i+j]==' ') {
				cout << b << str[i+j];
				i += j;
			} else {
				cout << b;
				break;
			} 
		} else {
			for (; str[i] != '\0'&& str[i] != ' '; ++i) {
				cout << str[i];
			}
			if (str[i] == ' ')
				cout << str[i];
			else
				break;
		}
	}
	return 0;
}