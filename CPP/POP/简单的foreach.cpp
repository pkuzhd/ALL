#include <iostream>
#include <string>
using namespace std;
template <class T>
void MyForeach(T *begin, T *end, void(*p)(T&))
{
	for (T *i = begin; i != end; ++i)
	{
		(*p)(*i);
	}
}
template <class T>
void MyForeach(T *begin, T *end, void(*p)(T))
{
	for (T *i = begin; i != end; ++i)
	{
		(*p)(*i);
	}
}
void Print(string s)
{
	cout << s;
}
void Inc(int & n)
{
	++n;
}
string barray[100];
int a[100];
int main() {
	int m, n;
	while (cin >> m >> n) {
		for (int i = 0; i < m; ++i)
			cin >> barray[i];
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		MyForeach(barray, barray + m, Print);
		cout << endl;
		MyForeach(a, a + n, Inc);
		for (int i = 0; i < n; ++i)
			cout << a[i] << ",";
		cout << endl;
	}
	return 0;
}