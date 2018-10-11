#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x) {
	string temp = "";
	while (x > 0)
	{
		temp = (x % 2 ? "1" : "0") + temp;
		x /= 2;
	}
	while (temp.size() < 31)
	{
		temp = "0" + temp;
	}
	return temp;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}