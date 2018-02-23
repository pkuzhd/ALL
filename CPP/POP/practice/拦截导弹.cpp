// pkuzhd
// 2018.02.12
// À¹½Øµ¼µ¯
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int k;
	cin >> k;
	int *data = new int[k];
	int *num = new int[k];
	for (int i = 0; i < k; ++i)
	{
		cin >> data[i];
		num[i] = 1;
	}
	int max_num = 0;
	for (int i = k - 2; i >= 0; --i)
	{
		for (int j = i + 1; j < k; ++j)
		{
			if (data[i] >= data[j] && num[i] < num[j] + 1)
			{
				num[i] = num[j] + 1;
			}
		}
		if (num[i] > max_num)
			max_num = num[i];
	}
	cout << max_num << endl;
	return 0;
}