// 文字排版
// pkuzhd
// 2018.01.04
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int num = 0; // 记录当前行已经有的字符数
	string str;
	cin >> str;
	cout << str;
	num = str.size();
	for (int i = 1; i < n; ++i)
	{
		string str;
		cin >> str;
		if (num + str.size() + 1 <= 80) // 判断是否需要换行
		{
			cout << " " << str;
			num += str.size() + 1;
		}
		else // 换行
		{
			cout << endl;
			cout << str;
			num = str.size();
		}
	}
	cout << endl;
	return 0;
}