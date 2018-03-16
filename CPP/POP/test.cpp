////////#include <iostream> 
////////#include <cstring> 
////////#include <cstdlib> 
////////#include <cstdio> 
////////using namespace std;
////////const int max = 110;
////////class chugeint {
////////	int num[210];
////////	int degree;
////////public:
////////	chugeint(int n) {
////////		memset(num, 0, sizeof(num));
////////		int i = 209;
////////		while (n != 0) {
////////			num[i] = n % 10;
////////			n /= 10;
////////			--i;
////////		}
////////		degree = 209 - i;
////////	}
////////	chugeint(const char *s) {
////////		memset(num, 0, sizeof(num));
////////		int i = 209;
////////		int j = strlen(s) - 1;
////////		for (; j >= 0; --j, --i) {
////////			num[i] = s[j] - '0';
////////		}
////////		degree = 209 - i;
////////	}
////////	chugeint(const chugeint &ch) {
////////		memset(num, 0, sizeof(num));
////////		degree = ch.degree;
////////		for (int i = 210 - degree; i < 210; ++i)
////////		{
////////			num[i] = ch.num[i];
////////		}
////////	}
////////	friend chugeint operator+(chugeint &one, chugeint &another) {
////////		chugeint tmp(one);
////////		int maxd = tmp.degree > another.degree ? tmp.degree : another.degree;
////////		int t = 0;
////////		for (int i = 209; i > 209 - maxd; --i)
////////		{
////////			tmp.num[i] += another.num[i] + t;
////////			if (tmp.num[i] > 10)
////////			{
////////				tmp.num[i] -= 10;
////////				t = 1;
////////			}
////////			else
////////				t = 0;
////////		}
////////		if (t == 1)
////////		{
////////			tmp.num[209 - maxd] = 1;
////////			tmp.degree = maxd + 1;
////////		}
////////		else
////////			tmp.degree = maxd;
////////		return tmp;
////////	}
////////	chugeint &operator+=(chugeint &other) {
////////		*this = *this + other;
////////		return *this;
////////	}
////////	chugeint &operator+=(int n) {
////////		*this += chugeint(n);
////////		return *this;
////////	}
////////	chugeint operator+(int n) {
////////		chugeint tmp(n);
////////		tmp += *this;
////////		return tmp;
////////	}
////////	friend chugeint operator+(int n, chugeint &ch)
////////	{
////////		chugeint tmp(n);
////////		tmp += ch;
////////		return tmp;
////////	}
////////	friend ostream &operator<<(ostream &o, chugeint &ch) {
////////		for (int i = 210 - ch.degree; i < 210; ++i)
////////			o << ch.num[i];
////////		return o;
////////	}
////////	chugeint &operator++() {
////////		*this += 1;
////////		return *this;
////////	}
////////	chugeint operator++(int) {
////////		static chugeint temp(*this);
////////		*this += 1;
////////		return temp;
////////	}
////////};
////////int  main()
////////{
////////	char s[210];
////////	int n;
////////
////////	while (cin >> s >> n) {
////////		chugeint a(s);
////////		chugeint b(n);
////////
////////		cout << a + b << endl;
////////		cout << n + a << endl;
////////		cout << a + n << endl;
////////		b += n;
////////		cout << ++b << endl;
////////		cout << b++ << endl;
////////		cout << b << endl;
////////	}
////////	return 0;
////////}