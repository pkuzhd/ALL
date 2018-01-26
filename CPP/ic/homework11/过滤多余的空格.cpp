// 过滤多余的空格
// pkuzhd
// 2017.12.18
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	char ch[201];
	char *point = ch;
	cin.getline(ch, 200);
	while (*point != '\0')
	{
		if (*point == ' ')
		{
			cout << " ";
			while (*point != '\0' && *point == ' ')
				++point;
		}
		else
		{
			cout << *point;
			++point;
		}
	}
	cout << endl;
	return 0;
}