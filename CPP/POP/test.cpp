#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt {
	int num[210];
	int degree;
public:
	CHugeInt(int n) {
		memset(num, 0, sizeof(num));
		int i = 209;
		while (n != 0) {
			num[i] = n % 10;
			n /= 10;
			--i;
		}
		degree = 209 - i;
	}
	CHugeInt(const char *s) {
		memset(num, 0, sizeof(num));
		int i = 209;
		int j = strlen(s) - 1;
		for (; j >= 0; --j, --i) {
			num[i] = s[j] - '0';
		}
		degree = 209 - i;
	}
	CHugeInt &operator+=(CHugeInt &other) {
		int tmpd = degree > other.degree ? degree : other.degree;
		int t = 0;
		for (int i = 209; i > 209 - tmpd; --i)
		{
			num[i] += other.num[i] + t;
			if (num[i] > 10)
			{
				num[i] -= 10;
				t = 1;
			}
			else
				t = 0;
		}
		if (t == 1)
		{
			num[209 - tmpd] = 1;
			degree = tmpd + 1;
		}
		else
			degree = tmpd;
		return *this;
	}
	CHugeInt &operator+=(int n) {
		*this += CHugeInt(n);
		return *this;
	}
	CHugeInt &operator+(CHugeInt &other) {
		static CHugeInt tmp(0);
		tmp += *this;
		tmp += other;
		return tmp;
	}
	CHugeInt &operator+(int n) {
		static CHugeInt tmp(n);
		tmp += *this;
		return tmp;
	}
	friend CHugeInt &operator+(int n, CHugeInt &ch)
	{
		return ch + n;
	}
	friend ostream &operator<<(ostream &o, CHugeInt &ch) {
		o << 
	}
};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}