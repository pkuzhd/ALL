//****************************
//*例程：苹果大战虫子       **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int n, x, y;
	cin >> n >> x >> y;        // 输入
	int left;
	left = n-y/x-(y%x==0?0:1); // 判断有无吃一部分的苹果
	if (left<0)                // 判断吃完的情况
		left = 0;
	cout << left;
	return 0;
}
