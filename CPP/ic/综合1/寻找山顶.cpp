// Ѱ��ɽ��
// pkuzhd
// 2018.01.04
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int num[25][25];
	int m, n;
	cin >> m >> n; // ����m, n
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> num[i][j]; // ѭ����������
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((i - 1 < 0 || num[i][j] >= num[i - 1][j]) && (i + 1 >= m || num[i][j] >= num[i + 1][j]) && (j - 1 < 0 || num[i][j] >= num[i][j - 1]) && (j + 1 >= n || num[i][j] >= num[i][j + 1])) // �ж��Ƿ�Ϊɽ��
				cout << i << " " << j << endl; // ���ɽ������
		}
	}
	return 0;
}