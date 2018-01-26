#include <iostream>

using namespace std;


double f(double x)
{
	return 5*x*x*x-3*x*x+2*x-8;
}

double f_(double x)
{
	return 15*x*x-6*x+2;
}

int main(int argc, char const *argv[])
{
	double x0 = 1.1;
	double x1 = x0 - f(x0)/f_(x0);
	while (x0-x1>0.000001 || x1-x0>0.000001)
	{
		x0 = x1;
		x1 = x0 - f(x0)/f_(x0);
	}
	cout << x1 << endl;


	return 0;
}
