//****************************
//*例程：满足条件的数       **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int m, n, k;      // 声明变量
	bool flag = true; // 用flag记录是否有满足条件的数
	cin >> m >> n >> k;
	for (int i = m; i <= n; ++i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			if ((i+j)%k==0)
			{
				cout << '(' << i << ',' << j << ')' << endl; // 输出结果
				flag = false;
			}
		}
	}
	if (flag)
	{
		cout << 'no';
	}
	return 0;
}
