//****************************
//*例程：判断闰年           **
//*作者：pkuzhd             **
//*时间：2017.9.21          **
//****************************

#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int year;                    // 声明year为整型变量
	bool is_leap;                // 声明is_leap为布尔变量
	cin >> year;                 // 输入年份year
	// year = 1900;
	if ((year%4==0)&&((year%100!=0)||(year%400==0)))
		is_leap = true;
	else
		is_leap = false;
	cout << (is_leap ? 'Y' : 'N') << endl;     // 输出 
	return 0;
}
