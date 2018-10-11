#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int t[4][4];
void op(int i, int j)
{
	t[i][j] = 1 - t[i][j];
	if (i - 1 >= 0)
		t[i - 1][j] = 1 - t[i - 1][j];
	if (i + 1 < 4)
		t[i + 1][j] = 1 - t[i + 1][j];
	if (j - 1 >= 0)
		t[i][j - 1] = 1 - t[i][j - 1];
	if (j + 1 < 4)
		t[i][j + 1] = 1 - t[i][j + 1];
}

int main()
{
	char ch;
	int m[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> ch;
			m[i][j] = ch == 'w' ? 0 : 1;
		}
	}
	int min = 16;
	for (int i = 0; i < 16; ++i)
	{
		memcpy(t, m, sizeof(m));
		int num = 0;
		for (int j = 0; j < 4; ++j)
		{
			if ((1 << j) & i)
			{
				op(0, j);
				++num;
			}
		}
		for (int j = 1; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (t[j - 1][k] == 0)
				{
					op(j, k);
					++num;
				}
			}
		}
		if (t[3][0] == 1 && t[3][1] == 1 && t[3][2] == 1 && t[3][3] == 1 && num < min)
		{
			min = num;
		}
	}
	for (int i = 0; i < 16; ++i)
	{
		memcpy(t, m, sizeof(m));
		int num = 0;
		for (int j = 0; j < 4; ++j)
		{
			if ((1 << j) & i)
			{
				op(0, j);
				++num;
			}
		}
		for (int j = 1; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (t[j - 1][k] == 1)
				{
					op(j, k);
					++num;
				}
			}
		}
		if (t[3][0] == 0 && t[3][1] == 0 && t[3][2] == 0 && t[3][3] == 0 && num < min)
		{
			min = num;
		}
	}
	if (min == 16)
		cout << "Impossible" << endl;
	else
		cout << min << endl;
	return 0;
}