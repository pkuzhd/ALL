// ¶þ²æÊ÷
// pkuzhd
// 2017.11.22
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int x, y;
	cin >> x >> y;
	while (x != y)
	{
		if (x > y)
			x /= 2;
		else
			y /= 2;
	}
	cout << x << endl;
	return 0;
}