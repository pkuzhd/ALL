//****************************
//*例程：数组逆序           **
//*作者：pkuzhd             **
//*时间：2017.9.28          **
//****************************

#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{
	int n;
	int temp;
	cin >> n;
	int *number = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> number[i];
	}
	for (int i = 0; i < n/2; ++i)
	{
		temp = number[i];
		number[i] = number[n-i-1];
		number[n-i-1] = temp;
	}
	for (int i = 0; i < n-1; ++i)
	{
		cout << number[i] << ' ';
	}
	cout << number[n-1];
	delete [] number;
	return 0;
}
