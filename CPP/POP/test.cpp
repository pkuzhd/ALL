#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int n = 0;
	int num = 1;
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
			map[i][j] = temp == 'w' ? 0 : 1;
		}
	}
	for (int i = 0; i < num; ++i)
	{
		copy(map, map + n, temp_map);
		switchs = i;
		for (int j = 0; j < n; ++j)
		{

		}
	}


	return 0;
}