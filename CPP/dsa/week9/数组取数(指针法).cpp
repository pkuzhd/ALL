// 数组取数(指针法)
// pkuzhd
// 2017.12.01
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, t;
	cin >> n >> t;
	int *num = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n); // 排序
	int *left = num, *right = num + 1; // 左指针和右指针
	t = t > 0 ? t : -t;
	int k = 0; // k为取法数目
	while (right < num + n)
	{
		if (*left + t == *right)
		{
			++k;
			while (right < num + n && *left + t == *right)
				++left, ++right;
		}
		else if (*left + t > *right)
			++right;
		else
		{
			while (left < right && *left + t < *right)
				++left;
			if (left == right)
				++right;
		}
	}
	cout << k << endl;
	delete[] num;
	return 0;
}