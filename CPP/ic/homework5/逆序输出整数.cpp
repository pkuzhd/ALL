//****************************
//*例程：逆序输出整数       **
//*作者：pkuzhd             **
//*时间：2017.9.28          **
//****************************

#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	if (n < 10)
		cout << n;
	else
	{
		while (n!=0)
		{
			cout << n % 10;
			n = n/10;
		}
	}
	return 0;
}
