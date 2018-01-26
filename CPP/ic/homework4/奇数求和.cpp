//****************************
//*例程：奇数求和           **
//*作者：pkuzhd             **
//*时间：2017.9.21          **
//****************************

#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int m, n, sum;             // 声明m, n, sum为整型变量
	cin >> m >> n;             // 输入m, n
	m = m%2? m : m+1;
	n = n%2? n : n-1;
	sum = (m+n)*((n-m)/2+1)/2; // 计算sum
	cout << sum << endl;      // 输出 
	return 0;
}
