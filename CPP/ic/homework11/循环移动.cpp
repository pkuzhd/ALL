// 循环移动
// pkuzhd
// 2017.12.18
#include <iostream>

using namespace std;

// 交换函数
// num: 数组名
// begin: 开始位置
// end: 结束位置
void change(int *num, int begin, int end) 
{
	for (int i = 0; begin + i < end - i; ++i)
	{
		int temp = num[begin + i];
		num[begin + i] = num[end - i];
		num[end - i] = temp;
	}
}

int main(int argc, char *argv[])
{
	// 海豚算法
	// 做三段的交换
	int n, m;
	cin >> n >> m;
	int *num = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}


	change(num, 0, n - m - 1);
	change(num, n - m, n - 1);
	change(num, 0, n - 1);


	cout << num[0];
	for (int i = 1; i < n; ++i)
	{
		cout << " " << num[i];
	}
	cout << endl;
	delete[] num;
	return 0;
}