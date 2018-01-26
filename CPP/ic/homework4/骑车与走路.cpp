//****************************
//*例程：计算邮资           **
//*作者：pkuzhd             **
//*时间：2017.9.22          **
//****************************

#include <iostream>
#include <cstdio>

using namespace std; 

int main(int argc, char const *argv[])
{ 
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int length;
		cin >> length;
		float t_walk, t_bike;
		t_walk = length/1.2;
		t_bike = length/3.0 + 50;
		if (t_bike==t_walk)
			cout << "All" << endl;   // 一样快
		else if (t_bike<t_walk)
			cout << "Bike" << endl;  // 骑车快
		else
			cout << "Walk" << endl;  // 走路快
	}
	return 0;
}
