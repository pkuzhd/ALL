// 提取数字
// pkuzhd
// 2017.12.18
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char ch[32];
	cin.getline(ch, 32);
	char *point = ch; // 指针指向字符串开始
	while (*point != '\0') // 当指向末尾时结束
	{
		while (*point <= '9' && *point >= '0') // 当是数字时直接输出
		{
			cout << *point;
			++point;
		}
		cout << endl;
		while (*point != '\0' && !(*point <= '9' && *point >= '0'))
			++point;
	}
	return 0;
}
