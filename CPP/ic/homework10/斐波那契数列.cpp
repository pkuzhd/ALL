#include <iostream>

using namespace std;

int fab(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fab(n - 1) + fab(n - 2);
}

int main(int argc, const char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cout << fab(x) << endl;
	}
	
	return 0;
}
