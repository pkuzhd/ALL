//****************************
//*例程：自除整数           **
//*作者：pkuzhd             **
//*时间：2017.10.15         **
//****************************

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n=0;
	cin >> n;
	// 从10到n
	for (int i = 10; i <= n; ++i)
	{
		int num=i;// 记录当前数字
		int sum=0;// 记录各位数字的和
		while (num!=0)
		{
			sum += num%10;
			num /= 10;
		}
		if (i%sum==0)
		{
			cout << i << endl;
		}
	}
	return 0;
}