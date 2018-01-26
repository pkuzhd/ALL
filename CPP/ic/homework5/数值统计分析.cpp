//****************************
//*例程：数值统计分析       **
//*作者：pkuzhd             **
//*时间：2017.9.28          **
//****************************

#include <iostream>

using namespace std; 

int my_abs(int number);

int main(int argc, char const *argv[])
{
	int n;
	int temp;                 // 临时变量
	int abs_max, abs_min;     // 绝对值最大的数和绝对值最小的数
	int sum = 0;                  // 总和
	int nPositive = 0, nNegative = 0; // 正数和负数的个数
	cin >> n >> temp;
	abs_max = temp;
	abs_min = temp;
	sum += temp;
	if (temp > 0)
		++nPositive;
	if (temp < 0)
		++nNegative;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> temp;
		if (my_abs(abs_max) < my_abs(temp))
			abs_max = temp;
		if (my_abs(abs_min) > my_abs(temp))
			abs_min = temp;
		sum += temp;
		if (temp > 0)
			++nPositive;
		if (temp < 0)
			++nNegative;
	}
	cout << nPositive << endl;
	cout << nNegative << endl;
	cout << sum << endl;
	cout << abs_max << endl;
	cout << abs_min;
	return 0;
}

int my_abs(int number)
{
	if (number > 0)
		return number;
	else
		return -number;
}
