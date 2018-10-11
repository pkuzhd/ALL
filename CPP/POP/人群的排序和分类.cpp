#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
class A
{
public:
	char type;
	int k;
	A(int k):k(k)
	{
		type = 'A';
	}
	
};
class B : public A
{
public:
	B(int k) :A(k)
	{
		type = 'B';
	}
};
class Comp
{
public:
	bool operator()(A* n1, A* n2)
	{
		return n1->k < n2->k;
	}
};
void Print(A* n)
{
	cout << n->type << " " << n->k << endl;
}
int main()
{

	int t;
	cin >> t;
	set<A*, Comp> ct;
	while (t--) {
		int n;
		cin >> n;
		ct.clear();
		for (int i = 0; i < n; ++i) {
			char c; int k;
			cin >> c >> k;

			if (c == 'A')
				ct.insert(new A(k));
			else
				ct.insert(new B(k));
		}
		for_each(ct.begin(), ct.end(), Print);
		cout << "****" << endl;
	}
}