// �Ϸ�c��ʶ��
// pkuzhd
// 2018.01.04
#include <iostream>
#include <string>

using namespace std;

bool is_ch(char ch) // �ж��Ƿ�Ϊ��ĸ���»���
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

bool is_chnum(char ch) // �ж��Ƿ�Ϊ��ĸ�����»���
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
		if (!is_ch(str[0])) // �жϿ�ͷ�Ƿ�Ϊ��ĸ���»���
		{
			flag = false;
			cout << "no" << endl;
			continue;
		}
		for (int j = 1; j < str.size(); ++j)
		{
			if (!is_chnum(str[j])) // �ж������Ƿ�Ϊ��ĸ�����»���
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