// 大小写字母互换
// pkuzhd
// 2018.01.04
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	getline(cin, str); // 输入一行
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z') // 如果是小写字母，就转化成大写字母
		{
			str[i] = str[i] - 'a' + 'A';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') // 如果是大写字母，就转化成小写字母
		{
			str[i] = str[i] - 'A' + 'a';
		}
		cout << str[i];
	}
	return 0;
}