//****************************
//*例程：出栈序列统计       **
//*作者：pkuzhd             **
//*时间：2017.10.12         **
//****************************

// 通过卡特兰数直接算出结果

#include <iostream>

using namespace std;

// 计算卡特兰数
int Catalan(int n);

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	cout << Catalan(n);
	return 0;
}

int Catalan(int n)
{
	long long num = 1;
	for (int i = 1; i <= n; ++i)
		num *= i+n;
	for (int i = 1; i <= n; ++i)
		num /= i;
	return num/(n+1);
}
