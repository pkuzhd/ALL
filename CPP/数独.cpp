#include <iostream>
#include <fstream>

using namespace std;

int n = 0;

bool check(int num[10][10], int i, int j, int number)
{
	int col = (i - 1) / 3;
	int row = (j - 1) / 3;
	for (int k = 1; k < 10; ++k)
	{
		if (k != j && num[i][k] == number)
			return false;
		if (k != i && num[k][j] == number)
			return false;
	}
	for (int k = 1 + 3 * col; k <= 3 * col + 3; ++k)
		for (int l = 1 + 3 * row; l <= 3 + 3 * row; ++l)
		{
			if ((k != i || l != j) && num[k][l] == number)
				return false;
		}
	return true;
}

void set_times(int num[10][10], int times[10][10])
{
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			if (num[i][j] == 0)
			{
				times[i][j] = 0;
				for (int k = 1; k < 10; ++k)
				{
					if (check(num, i, j, k))
					{
						++times[i][j];
					}
				}
			}
			else
				times[i][j] = -1;
		}
	}
}
void dfs(int num[10][10], int times[10][10], bool &flag)
{
	int i_idx = 1, j_idx = 1;
	int min = 10;
	set_times(num, times);

	int left = 0;
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			if (num[i][j] == 0)
			{
				++left;
			}
		}
	}
	if (left == 0)
	{
		flag = true;
		return;
	}
	
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			if (num[i][j] == 0)
			{
				if (times[i][j] == 0)
					return;
				if (min > times[i][j])
				{
					i_idx = i;
					j_idx = j;
					min = times[i][j];
				}
			}
		}
	}
	
	

	for (int k = 1; k < 10; ++k)
	{
		if (check(num, i_idx, j_idx, k))
		{
			num[i_idx][j_idx] = k;
			++n;
			dfs(num, times, flag);
			if (flag)
				return;
			num[i_idx][j_idx] = 0;
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	ifstream fin("C:\\Users\\pkuzhd\\Desktop\\fin.txt");
	ofstream fout("C:\\Users\\pkuzhd\\Desktop\\fout.txt");
	int num[10][10];
	int times[10][10];
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
			fin >> num[i][j];
	}
	bool flag = false;
	dfs(num, times, flag);
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << n;
	cout << endl;
	fin.close();
	fout.close();
	return 0;
}