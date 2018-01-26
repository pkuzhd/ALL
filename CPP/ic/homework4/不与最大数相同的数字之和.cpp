//*********************************
//*例程：不与最大数相同的数字之和**
//*作者：pkuzhd                  **
//*时间：2017.9.22               **
//*********************************

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int n;
	cin >> n;        // 输入
	float *num = new float[n];
	float sum = 0.0; 
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
		sum += num[i];
	} // 计算和
	float p = 0; 
	for (int i = 0; i < n; ++i)
	{
		p += (num[i]-sum/n)*(num[i]-sum/n);
	} // 计算方差
	printf("%.4f %.4f\n", sum/n, sqrt(p/n));
	delete [] num;
	return 0;
}
