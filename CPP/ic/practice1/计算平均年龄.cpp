// 计算平均年龄
// pkuzhd
// 2017.10.25

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int sum = 0;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		sum += temp;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << (float)sum/n;
	return 0;
}