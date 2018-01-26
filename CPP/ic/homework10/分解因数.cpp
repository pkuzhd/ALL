// 分解因数
// pkuzhd
// 2017.11.27

#include <iostream>

using namespace std;

int calc(int a, int k)
{
	if (a == k)
		return 1;
	else
	{
		if (a%k == 0)
		{
			if (a / k >= k)
				return calc(a / k, k) + calc(a, k + 1);
			else
				return 1;
		}
		else
			return calc(a, k + 1);
	}
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		cout << calc(a, 2) << endl;
	}
	return 0;
}