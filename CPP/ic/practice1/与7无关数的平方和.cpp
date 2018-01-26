// 与7无关数的平方和
// pkuzhd
// 2017.10.25

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		int temp=i; 
		if (temp%7!=0)
		{
			while (temp != 0)
			{
				if ((temp-temp/10*10)==7)
					break;
				temp /= 10;
			}
			if (temp == 0)
				sum += i*i;
		}
	}
	cout << sum;
	return 0;
}