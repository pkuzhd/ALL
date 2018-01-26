// 数组逆序
// pkuzhd
// 2017.10.25

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	for (int i = 1; i < n; ++i)
	{
		cout << num[n-i] << " ";
	}
	cout << num[0];
	delete [] num;
	return 0;
}