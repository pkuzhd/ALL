#include <iostream>

using namespace std;

int is_happen[2000010];
int _index[100010];

int main(int argc, char *argv[])
{
	int n, t;
	cin >> n >> t;
	int temp;
	int num = 0;
	for (int i = 0; i<n; i++)
	{
		cin >> temp;
		temp += 1000000;
		if (is_happen[temp] == 0)
		{
			_index[num++] = temp;
		}
		is_happen[temp]++;
	}
	int times = 0;
	if (t == 0)
	{
		for (int i = 0; i<num; i++)
		{
			if (is_happen[_index[i]] >1)
				times++;
		}
	}
	else if (t>0)
	{
		for (int i = 0; i<num; i++)
			if (_index[i] + t <= 2000009 && is_happen[_index[i] + t] != 0)
				times++;
	}
	else
	{
		for (int i = 0; i<num; i++)
			if (_index[i] + t >= 0 && is_happen[_index[i] + t] != 0)
				times++;
	}
	cout << times << endl;
	return 0;
}