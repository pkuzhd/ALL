//****************************
//*例程：计算并联电阻的阻抗 **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>

using namespace std; 

int main(int argc, char const *argv[])
{
	float r1, r2;             // 声明r1, r2为浮点变量
	float r;                  // 声明r为浮点变量
	cin >> r1 >> r2;            // 输入r1, r2
	// r1 = 1, r2 = 2;
	r = 1/(1/r1+1/r2);

	printf("%.2f", r);
	return 0;
}
