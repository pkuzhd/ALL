//****************************
//*例程：大象喝水           **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>

#define PI 3.14159

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int h, r;
	float v;
	int num;
	cin >> h >> r;
	v = PI * r * r * h;
	num = 20.0*1000/v + 1;
	cout << num << endl;
	return 0;
}
