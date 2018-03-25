#include <iostream>
using namespace std;
class MyCin
{
private:
	bool flag = false;
public:
	MyCin & operator>>(int &n)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
			flag = true;
		else
			n = temp;
		return *this;
	}
	operator bool()
	{
		if (flag)
		{
			flag = !flag;
			return flag;
		}
		return !flag;
	}
};
int main()
{
	MyCin m;
	int n1, n2;
	while (m >> n1 >> n2)
		cout << n1 << " " << n2 << endl;
	return 0;
}