// 打印极值点下标
// pkuzhd
// 2018.01.04
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		int *num = new int[t];
		bool flag = true;
		for (int j = 0; j < t; ++j)
		{
			cin >> num[j];
		}
		if (num[0] != num[1])
		{
			cout << "0";
			flag = false;
		}
		for (int j = 1; j < t - 1; ++j)
		{
			if ((num[j] > num[j - 1] && num[j] > num[j + 1]) || (num[j] < num[j - 1] && num[j] < num[j + 1]))
			{
				if (flag)
				{
					cout << j;
					flag = false;
				}
				else
					cout << " " << j;
			}
		}
		if (num[t - 2] != num[t - 1])
		{
			if (flag)
				cout << t - 1;
			else
				cout << " " << t - 1;
		}
		
		cout << endl;

		delete[] num;
	}

	return 0;
}