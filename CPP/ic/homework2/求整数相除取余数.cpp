//****************************
//*例程：求整数相除取余数   **
//*作者：pkuzhd             **
//*时间：2017.9.17          **
//****************************

#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int a, b;               //声明a b为整型变量 
	cin >> a >> b;          //输入a b 
	cout << a - (a/b)*b << endl;
	return 0;
}
