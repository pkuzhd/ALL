// ����7��Ϸ
// pkuzhd
// 2018.01.04
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	queue<int> q; // �ö���ģ��
	for (int i = 1; i <= n; ++i)
		q.push(i);
	int t = 0;
	while (!q.empty())
	{
		++t;
		bool flag = false;
		if (t % 7 == 0) // �ж��Ƿ�Ϊ7�ı���
			flag = true;
		int temp = t;
		while (!flag && temp > 0) // �ж��Ƿ�������7
		{
			if (temp % 10 == 7)
				flag = true;
			temp /= 10;
		}
		if (flag)
		{
			cout << q.front() << endl;
			q.pop();
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
	}
	//cout << q.front() << endl;
	return 0;
}