//****************************
//*例程：简单计算器         **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int num_1, num_2;
	char op;
	cin >> num_1 >> num_2 >> op; // 输入
	if (num_2==0&&op=='/') // 出现除数为0的情况
	{
		cout << "Divided by zero!";
		return 0;
	}
	switch (op) 
	{
		case '+':cout << num_1+num_2;break;
		case '-':cout << num_1-num_2;break;
		case '*':cout << num_1*num_2;break;
		case '/':cout << num_1/num_2;break;
		default:cout << "Invalid operator!"; // 出现无效的操作符
	}
	return 0;
}
