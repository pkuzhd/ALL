// Rainbow的商店
// pkuzhd
// 2017.12.13
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct goods
{
	int days;
	int value;
};

bool cmp(goods &a, goods &b)
{
	return (a.days < b.days) || (a.days == b.days && a.value < b.value);
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	goods *num = new goods[n];
	int *not_sale = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i].value >> num[i].days;
		not_sale[i] = 1;
	}
	sort(num, num + n, cmp);
	int value = 0;
	for (int i = num[n - 1].days; i >= 1; i--) // 枚举天数
	{
		int max_value = 0;
		int idx;
		for (int j = n - 1; num[j].days >= i; j--) // 当前天以及当前天之后的货物
		{
			if (not_sale[j] == 1 && num[j].value > max_value) // 找出最大的输出
			{
				idx = j;
				max_value = num[j].value;
			}
		}
		not_sale[idx] = 0;
		value += max_value;
	}
	cout << value << endl;
	delete[] num;
	return 0;
}
