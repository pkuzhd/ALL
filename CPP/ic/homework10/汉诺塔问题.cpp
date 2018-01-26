#include <iostream>

using namespace std;

void hanoi(char from, char to, char mid, int n)
{
	if (n == 1)
		cout << from << "->" << to << endl;
	else
	{
		hanoi(from, mid, to, n - 1);
		hanoi(from, to, mid, 1);
		hanoi(mid, to, from, n - 1);
	}
}

int main(int argc, const char *argv[])
{
	int n;
	cin >> n;
	hanoi('A', 'C', 'B', n);
	return 0;
}
