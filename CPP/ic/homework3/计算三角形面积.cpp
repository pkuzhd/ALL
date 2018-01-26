//****************************
//*例程：计算三角形面积     **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std; 

float sideLength(float, float, float, float);

int main(int argc, char const *argv[])
{
	float x1, y1, x2, y2, x3, y3;     // 声明x1, y1, x2, y2, x3, y3为浮点变量
	float a, b, c, p;                 // 声明边长和半周长
	float s;                          // 声明s为浮点变量
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; // 输入x1, y1, x2, y2, x3, y3

	a = sideLength(x1, y1, x2, y2);
	b = sideLength(x2, y2, x3, y3);
	c = sideLength(x1, y1, x3, y3);
	p = (a+b+c)/2;
	s = sqrt(p*(p-a)*(p-b)*(p-c));

	printf("%.2f", s);                           // 输出
	return 0;
}

float sideLength(float x1, float y1, float x2, float y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
