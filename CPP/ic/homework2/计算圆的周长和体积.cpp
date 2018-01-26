//****************************
//*例程：计算圆的周长和体积 **
//*作者：pkuzhd             **
//*时间：2017.9.17          **
//****************************

#include <iostream>
#include <iomanip>

#define PI 3.14

using namespace std; 

int main(int argc, char const *argv[])
{ 
	double r;
	double v, c;
	cin >> r;
	v = 4.0/3 * PI * r * r * r;
	c = 2 * PI * r;
	cout << fixed << setprecision(2) << v << endl << c;
	return 0;
}
