#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;



int main()
{
	int num[101] = { 0 };
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j * i <= 100; ++j)
		{
			num[i*j] = 1 - num[i*j];
		}
	}
	int sum = 0;
	for (int i = 1; i <= 100; ++i)
	{
		if (num[i] == 1)
		{
			cout << "S" << i << " ";
			++sum;
		}
	}
	cout << endl << sum << endl;
	return 0;
}