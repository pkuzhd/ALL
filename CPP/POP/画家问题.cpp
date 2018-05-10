#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int n = 0;
	int num = 1;
	bool flag = false;
	cin >> n;
	bitset<15> map[15];
	bitset<15> temp_map[15];
	bitset<15> switchs;
	for (int i = 0; i < n; ++i)
	{
		num *= 2;
		for (int j = 0; j < n; ++j)
		{
			char temp;
			cin >> temp;
			map[i][j] = temp == 'w' ? 1 : 0;
		}
	}

	int min_times = 1 << 30;
	for (int i = 0; i < num; ++i)
	{
		int times = 0;
		copy(map, map + n, temp_map);
		switchs = i;

		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				times += switchs[k];
				if (switchs[k])
				{
					if (k > 0)
					{
						temp_map[j].flip(k - 1);
					}
					temp_map[j].flip(k);
					if (k < n - 1)
					{
						temp_map[j].flip(k + 1);

					}
				}
			}
			if (j < n - 1)
			{
				temp_map[j + 1] ^= switchs;
			}
			switchs = temp_map[j];
			
		}
		if (temp_map[n - 1] == 0)
		{
			flag = true;
			if (times < min_times)
			{
				min_times = times;
			}
			
		}
	}
	if (flag)
		cout << min_times << endl;
	else
		cout << "inf" << endl;
	return 0;
}