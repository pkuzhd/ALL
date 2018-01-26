// ∞Àª ∫ÛŒ Ã‚
// pkuzhd
// 2017.11.13

#include <iostream>

using namespace std;

int times = 0;

void queen(int n, int sz[8][8])
{
	if (n == 8)
	{
		cout << ++times << endl;
		for (int i=0; i < 8; ++i)
		{
			cout << (sz[i][0] ? "*" : ".");
			for (int j = 1; j < 8; ++j)
				cout << " " << (sz[i][j] ? "*" : ".");
			cout << endl;
		}
		return;
	}
	for (int i = 0; i < 8; ++i)
	{
		bool flag = true;
		for (int j = 1; j <= n; ++j)
		{
			if (sz[i][n-j] == 1 ||
				(i + j < 8 && sz[i + j][n - j] == 1) ||
				(i - j >= 0 && sz[i - j][n - j] == 1))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			sz[i][n] = 1;
			queen(n + 1, sz);
			sz[i][n] = 0;
		}
	}
}

int main(int argc, const char *argv[])
{

	int sz[8][8] = { 0 };
	queen(0, sz);
	return 0;
}
