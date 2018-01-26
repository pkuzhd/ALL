#include <iostream>
#include <cstring>

using namespace std;

long long merge(int *num, int a, int b, int len, int n)
{
	long long count = 0;
	int right;
	if (b + len - 1 > n - 1)
		right = n - 1;
	else
		right = len;
	int *temp = new int[len + right];
	int i = 0, j = 0;
	while (i <= len - 1 && j <= right - 1)
	{
		if (num[a + i] >= num[b + j])
		{
			count += j;
			temp[i + j] = num[a + i];
			++i;
		}
		else
		{
			temp[i + j] = num[b + j];
			++j;
		}
	}
	if (j == right)
	{
		memcpy(temp + i + j, num + a + i, (len - i) * sizeof(int));
		count += (len - i)*right;
	}
	else if (i == len)
	{
		memcpy(temp + i + j, num + b + j, (right - j) * sizeof(int));
	}
	memcpy(num + a, temp, (right + len) * sizeof(int));
	delete[] temp;
	return count;
}

long long count(int *num, int n)
{
	long long count = 0;
	int step = 1;
	while (step < n)
	{
		for (int i = 0; i < n - step - 1; i += 2 * step)
		{

		}
		step *= 2;
	}
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}

	cout << count(num, n) << endl;

	delete[] num;
	return 0;
}