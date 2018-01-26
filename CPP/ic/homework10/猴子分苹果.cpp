// ºï×Ó·ÖÆ»¹û
// pkuzhd
// 2017.11.22
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k;
	cin >> n >> k;
	int *num = new int[n];
	num[0] = k;
	bool flag = true;
	while (flag)
	{
		num[0] += n;
		flag = false;
		for (int i = 1; i < n; ++i)
		{
			if (num[i - 1] % (n - 1) == 0)
				num[i] = num[i - 1] / (n - 1)*n + k;
			else
			{
				flag = true;
				break;
			}
		}
	}
	cout << num[n - 1] << endl;
	return 0;
}