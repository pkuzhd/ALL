//****************************
//*例程：数值表达式计算     **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>

using namespace std; 

int main(int argc, char const *argv[])
{
	float x;                                   // 声明X为浮点变量
	x = (3.21e-8+2.31e-7)/(7.16e6+2.01e8);     // 计算x
	printf("%g", x);                           // 输出
	return 0;
}
