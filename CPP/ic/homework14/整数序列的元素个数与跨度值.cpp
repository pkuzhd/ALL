// 整数序列的元素个数与跨度值
// pkuzhd
// 2018.01.05
#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int t;
	char ch;
	scanf("%d%c", &t, &ch);
	int _max = t; // 记录最大值
	int _min = t; // 记录最小值
	int num = 1; // 记录数字个数
	while (scanf("%d%c", &t, &ch) != EOF)
	{
		if (t > _max)
			_max = t;
		if (t < _min)
			_min = t;
		++num;
	}
	cout << num << endl;
	cout << _max - _min << endl;
	return 0;
}