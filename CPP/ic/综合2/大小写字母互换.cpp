// ��Сд��ĸ����
// pkuzhd
// 2018.01.04
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	getline(cin, str); // ����һ��
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z') // �����Сд��ĸ����ת���ɴ�д��ĸ
		{
			str[i] = str[i] - 'a' + 'A';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') // ����Ǵ�д��ĸ����ת����Сд��ĸ
		{
			str[i] = str[i] - 'A' + 'a';
		}
		cout << str[i];
	}
	return 0;
}