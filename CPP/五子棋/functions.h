#include <stdio.h>
#include <iostream>
using namespace std;

int qipan[15][15] = { 0 };
int times = 0;

int print();
bool is_win(int x, int y, int flag);
bool is_near(int x, int y);
bool AI_set(int flag);
int calc_value(int x, int y, int flag, int depth, int _max_value);
int qixing(int x, int y);

int main(int argc, char **argv)
{
	int flag = 1;
	while (true)
	{
		++times;
		print();
		int x, y;
		if (flag == 1)
		{
			while (true)
			{
				cin >> x >> y;
				if (!qipan[x][y] || x < 0 || x >= 15 || y < 0 || y >= 15)
					break;
			}
			qipan[x][y] = flag;
			if (is_win(x, y, flag))
				break;
		}
		else
		{
			if (AI_set(flag))
				break;
		}
		flag *= -1;
	}
	if (flag == 1)
	{
		printf("black\n");
	}
	else
	{
		printf("white\n");
	}
 	system("pause");
	return 0;
}

int print()
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
			cout << (qipan[i][j] ? (qipan[i][j] == 1 ? "*" : "#") : "0");
		cout << endl;
	}
	cout << endl;
	return 0;
}

bool is_win(int x, int y, int flag)
{
	int number = 1;
	for (int i = x + 1; i < 15; ++i)
	{
		if (qipan[i][y] == flag)
			++number;
		else
			break;
	}
	for (int i = x - 1; i >= 0; --i)
	{
		if (qipan[i][y] == flag)
			++number;
		else
			break;
	}
	if (number >= 5)
		return true;
	number = 1;
	for (int i = y + 1; i < 15; ++i)
	{
		if (qipan[x][i] == flag)
			++number;
		else
			break;
	}
	for (int i = y - 1; i >= 0; --i)
	{
		if (qipan[x][i] == flag)
			++number;
		else
			break;
	}
	if (number >= 5)
		return true;
	number = 1;
	for (int j = 1; x + j < 15 && y + j < 15; ++j)
	{
		if (qipan[x + j][y + j] == flag)
			++number;
		else
			break;
	}
	for (int j = 1; x - j >= 0 && y - j >= 0; ++j)
	{
		if (qipan[x - j][y - j] == flag)
			++number;
		else
			break;
	}
	if (number >= 5)
		return true;
	number = 1;
	for (int j = 1; x + j < 15 && y - j >= 0; ++j)
	{
		if (qipan[x + j][y - j] == flag)
			++number;
		else
			break;
	}
	for (int j = 1; x - j >= 0 && y + j < 15; ++j)
	{
		if (qipan[x - j][y + j] == flag)
			++number;
		else
			break;
	}
	if (number >= 5)
		return true;
	return false;
}

bool is_near(int x, int y)
{
	// cout << x << " " << y << endl;
	int _near = 2;
	for (int i = (x - _near >= 0 ? x - _near : 0); i <= (x + _near < 15 ? x + _near : 14); ++i)
	{
		for (int j = (y - _near >= 0 ? y - _near : 0); j <= (y + _near < 15 ? y + _near : 14); ++j)
		{
			if (qipan[i][j])
				return true;
		}
	}
	return false;
}

bool AI_set(int flag)
{
	int max_value = -10000000;
	int x = 7, y = 7;
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (qipan[i][j])
				continue;
			if (!is_near(i, j))
				continue;
			int t_value = calc_value(i, j, flag, 0, max_value);
			if (is_win(i, j, flag))
			{
				qipan[i][j] = flag;
				return true;
			}
			if (t_value > max_value)
			{
				max_value = t_value;
				x = i;
				y = j;
			}
		}
	}
	qipan[x][y] = flag;
	cout << x << " " << y <<  " " << flag  << " " << is_win(x, y, flag)<< endl;

	return false;
}

int calc_value(int x, int y, int flag, int depth, int _max_value)
{
	int _value = 0;
	qipan[x][y] = flag;

	if (depth < 3)
	{
		_value += qixing(x, y) / 10;
		int max_value = -10000000;
		for (int i = 0; i < 15; ++i)
		{
			for (int j = 0; j < 15; ++j)
			{
				if (qipan[i][j] || !is_near(i, j))
					continue;
				int t_value = calc_value(i, j, -flag, depth + 1, _value - max_value);
				if (_value - t_value < _max_value)
				{
					qipan[x][y] = 0;
					return t_value;
				}
				if (is_win(i, j, -flag))
				{
					qipan[x][y] = 0;
					return -10000000;
				}
				if (t_value > max_value)
				{
					max_value = t_value;

				}
			}
		}
		_value -= max_value;
	}
	else
		_value += qixing(x, y);
	qipan[x][y] = 0;
	return _value;
}

int qixing(int x, int y)
{
	int flag = qipan[x][y];
	bool dead = false;
	int number = 1;
	int _value = 0;
	int sz_qixing[2][6] = { 0 };

	// x 方向
	number = 1;
	dead = false;
	for (int i = x + 1; ; ++i)
	{
		if (i < 15 && qipan[i][y] == flag)
			++number;
		else
		{
			if (i >= 15 || qipan[i][y])
				dead = true;
			break;
		}
	}
	for (int i = x - 1; i >= 0; --i)
	{
		if (i >= 0 && qipan[i][y] == flag)
			++number;
		else
		{
			if ((i < 0 || qipan[i][y]) && dead)
				break;
			else
			{
				if (dead || qipan[i][y])
					dead = true;
				++sz_qixing[dead][number];
			}
		}
	}

	// y方向
	number = 1;
	dead = false;
	for (int i = y + 1; ; ++i)
	{
		if (i < 15 && qipan[x][i] == flag)
			++number;
		else
		{
			if (i >= 15 || qipan[x][i])
				dead = true;
			break;
		}
	}
	for (int i = y - 1; i >= 0; --i)
	{
		if (i >= 0 && qipan[x][i] == flag)
			++number;
		else
		{
			if ((i < 0 || qipan[x][i]) && dead)
				break;
			else
			{
				if (dead || qipan[x][i])
					dead = true;
				++sz_qixing[dead][number];
			}
		}
	}

	// x y 方向
	number = 1;
	dead = false;
	for (int i = 1; ; ++i)
	{
		if (x + i < 15 && y + i < 15 && qipan[x + i][y + i] == flag)
			++number;
		else
		{
			if (x + i >= 15 || y + i >= 15 || qipan[x + i][y + i])
				dead = true;
			break;
		}
	}
	for (int i = 1; ; ++i)
	{
		if (x - i >= 0 && y - i >= 0 && qipan[x - i][y - i] == flag)
				++number;
		else
		{
			if ((x - i < 0 || y - i < 0 || qipan[x - i][y - i]) && dead)
				break;
			else
			{
				if (dead || qipan[x - i][y - i])
					dead = true;
				++sz_qixing[dead][number];
			}
		}
	}

	// x -y 方向
	number = 1;
	dead = false;
	for (int i = 1; ; ++i)
	{
		if (x + i < 15 && y - i >= 0 && qipan[x + i][y - i] == flag)
			++number;
		else
		{
			if (x + i >= 15 || y - i < 0 || qipan[x + i][y - i])
				dead = true;
			break;
		}
	}
	for (int i = 1; ; ++i)
	{
		if (x - i >= 0 && y + i < 15 && qipan[x - i][y + i] == flag)
			++number;
		else
		{
			if ((x - i < 0 || y + i >= 15 || qipan[x - i][y + i]) && dead)
				break;
			else
			{
				if (dead || qipan[x - i][y + i])
					dead = true;
				++sz_qixing[dead][number];
			}
		}
	}
	if (sz_qixing[false][4] || (sz_qixing[true][4] + sz_qixing[false][3]) >= 2)
		_value += 1000000;
	_value += sz_qixing[false][3] * 10000;
	_value += sz_qixing[true][3] * 1000;
	_value += sz_qixing[false][2] * 100;
	_value += sz_qixing[true][2] * 10;
	return _value;
}
