#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	int num = 1;
	bool flag = false;
	bitset<30> from;
	bitset<30> to;
	bitset<30> temp;
	int switchs;

	string str;
	cin >> str;
	for (int j = 0; j < str.size(); ++j)
	{
		num *= 2;
		from[j] = str[j] - '0';
	}
	cin >> str;
	for (int j = 0; j < str.size(); ++j)
	{
		to[j] = str[j] - '0';
	}
	int n = str.size();
	from ^= to;
	int min_times = 0;

	for (int i = 0; i < 2; ++i)
	{
		int times = 0;
		temp = from;
		switchs = i;

		for (int j = 0; j < n; ++j)
		{
			if (switchs)
			{
				++times;
				temp.flip(j);
				if (j < n - 1)
					temp.flip(j + 1);
			}
			switchs = temp[j];
		}
		if (temp[n - 1] == 0)
		{
			if (flag && times < min_times)
			{
				min_times = times;
			}
			else
			{
				flag = true;
				min_times = times;
			}
		}
	}
	if (flag)
		cout << min_times << endl;
	else
		cout << "impossible" << endl;
	return 0;
}