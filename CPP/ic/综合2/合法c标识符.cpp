// 合法c标识符
// pkuzhd
// 2018.01.04
#include <iostream>
#include <string>

using namespace std;

bool is_ch(char ch) // 判断是否为字母和下划线
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

bool is_chnum(char ch) // 判断是否为字母数字下划线
{
	return (ch >= '0' && ch <= '9') || is_ch(ch);
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		bool flag = true;
		if (!is_ch(str[0])) // 判断开头是否为字母和下划线
		{
			flag = false;
			cout << "no" << endl;
			continue;
		}
		for (int j = 1; j < str.size(); ++j)
		{
			if (!is_chnum(str[j])) // 判断其他是否为字母数字下划线
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}