// �����Ű�
// pkuzhd
// 2018.01.04
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int num = 0; // ��¼��ǰ���Ѿ��е��ַ���
	string str;
	cin >> str;
	cout << str;
	num = str.size();
	for (int i = 1; i < n; ++i)
	{
		string str;
		cin >> str;
		if (num + str.size() + 1 <= 80) // �ж��Ƿ���Ҫ����
		{
			cout << " " << str;
			num += str.size() + 1;
		}
		else // ����
		{
			cout << endl;
			cout << str;
			num = str.size();
		}
	}
	cout << endl;
	return 0;
}