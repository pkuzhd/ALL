//****************************
//*例程：晶晶赴约会         **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int free[] = {0, 0, 1, 0, 1, 0, 1, 1}; // 有空的时间
	int day;
	cin >> day;  // 输入日期
	cout << (free[day]?"YES":"NO"); // 输出结果
	return 0;
}
