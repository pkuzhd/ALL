// ºìÓëºÚ
// pkuzhd
// 2017.11.26
#include <iostream>

using namespace std;

int calc(int map[20][20], int w, int h, int x, int y)
{
	int up = 0, down = 0, left = 0, right = 0;
	if (x != 0 && map[x - 1][y] == 1)
	{
		map[x - 1][y] = 0;
		up = calc(map, w, h, x-1, y);
	}
	if (x < w - 1 && map[x + 1][y] == 1)
	{
		map[x + 1][y] = 0;
		down = calc(map, w, h, x + 1, y);
	}
	if (y != 0 && map[x][y - 1] == 1)
	{
		map[x][y - 1] = 0;
		left = calc(map, w, h, x, y - 1);
	}
	if (y < h - 1 && map[x][y + 1] == 1)
	{
		map[x][y + 1] = 0;
		right = calc(map, w, h, x, y + 1);
	}
	return 1 + up + down + left + right;
}

int main(int argc, char *argv[])
{
	int w, h;
	while (cin >> w >> h)
	{
		if (w == 0 && h == 0)
			break;
		int map[20][20];
		char c;
		int x, y;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
			{
				cin >> c;
				if (c == '@')
				{
					x = i;
					y = j;
					map[i][j] = 0;
				}
				else
					map[i][j] = (c == '.') ? 1 : -1;
			}

			
		int num = calc(map, h, w, x, y);
		cout << num << endl;
	}
	return 0;
}