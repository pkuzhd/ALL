//****************************
//*例程：计算分数的浮点数值 **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>

using namespace std; 

int main(int argc, char const *argv[])
{
	int a, b;                    // 声明a, b为整型变量
	double c;                    // 声明c为双精度浮点变量
	cin >> a >> b;               // 输入a, b
	// a = 5, b = 7;
	c = (double)a/b;

	printf("%.9lf", c);
	return 0;
}
