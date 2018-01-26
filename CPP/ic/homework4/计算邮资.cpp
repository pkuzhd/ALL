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
		int weight;
		char exp;
		float v = 0.0;
		cin >> weight >> exp;
		v += 0.8;                   // 基本费
		if (weight > 1)             // 超重费
			v += 0.5*(weight-1);
		if (exp == 'y')             // 加快费
			v += 2.0;
		printf("%.1f\n", v);
	}
	return 0;
}
