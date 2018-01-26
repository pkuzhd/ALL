// 放苹果问题
// pkuzhd
// 2017.11.26
#include <iostream>

using namespace std;


int apple(int m, int n)
{
	if (n == 1)
		return 1;
	if (m < 0)
		return 0;
	else if (m == 0)
		return 1;
	else
		return apple(m, n - 1) + apple(m - n, n);
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int m, n;
		cin >> m >> n;
		cout << apple(m, n) << endl;
	}
	return 0;
}