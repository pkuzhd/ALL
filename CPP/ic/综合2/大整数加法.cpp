// �������ӷ�
// pkuzhd
// 2018.01.04
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string num1, num2;
		cin >> num1 >> num2;
		string sum;
		if (num1.size() < num2.size())
		{
			sum = num2;
			num2 = num1;
		}
		else
			sum = num1;
		bool flag = false; // ��¼�Ƿ��λ
		for (int i = 0; i < num2.size(); ++i)
		{
			sum[sum.size() - i - 1] += num2[num2.size() - i - 1] - '0' + flag; // ����ÿһλ�ĺ�
			flag = false;
			if (sum[sum.size() - i - 1] - '0' >= 10)
			{
				sum[sum.size() - i - 1] -= 10;
				flag = true;
			}
		}
		for (int i = num2.size(); i < sum.size(); ++i)
		{
			sum[sum.size() - i - 1] += flag; // �����λ
			flag = false;
			if (sum[sum.size() - i - 1] - '0' >= 10)
			{
				sum[sum.size() - i - 1] -= 10;
				flag = true;
			}
		}
		if (flag) // �ж������Ƿ��λ
		{
			cout << 1;
			cout << sum << endl;
		}
		else
		{
			bool flag2 = false;
			for (int j = 0; j < sum.size(); ++j) // ɾ��ǰ��0
			{
				if (!flag2)
					if (sum[j] == '0')
						continue;
					else
					{
						flag2 = true;
						cout << sum[j];
					}
				else
					cout << sum[j];
			}
			if (!flag2)
				cout << 0;
			cout << endl;
		}
	}
	return 0;
}