// 吉老师的汉诺塔
// pkuzhd
// 2017.12.05
//
// 利用归并排序的思想统计逆序对
// 在归并的过程中, 记录下每次产生的相邻交换次数
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int num[100001];
int temp[100001];

long long times = 0;

void my_merge(int begin, int end)
{
	if (end - begin == 1)
		return;
	else
	{
		int mid = (begin + end) / 2;
		my_merge(begin, mid);
		my_merge(mid, end);
		int i = 0, j = 0;
		int count = begin;
		for (i = begin; i < end; ++i)
			temp[i] = num[i];
		for (i = begin, j = mid; i < mid && j < end;)
		{
			if (temp[i] >= temp[j])
			{
				num[count] = temp[i];
				++count;
				++i;
			}
			else
			{
				num[count] = temp[j];
				times += mid - i;
				++count;
				++j;
				
			}
		}
		if (i != mid)
		{
			for (; i < mid; ++i)
			{
				num[count] = temp[i];
				++count;
			}
		}
		else if (j != end)
		{
			for (; j < end; ++j)
			{
				num[count] = temp[j];
				++count;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	my_merge(0, n);
	cout << times << endl;
	return 0;
}