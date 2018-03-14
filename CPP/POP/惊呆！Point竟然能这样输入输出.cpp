#include <iostream> 
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	Point() { };
	friend ostream &operator<<(ostream &o, const Point &p) {
		o << p.x << "," << p.y;
		return o;
	}
	friend istream &operator>>(istream &i, Point &p) {
		i >> p.x >> p.y;
		return i;
	}
};
int main()
{
	Point p;
	while (cin >> p) {
		cout << p << endl;
	}
	return 0;
}