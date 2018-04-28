#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
public:
	char num[2 * MAX];
	int degree;
	CHugeInt(const char *s)
	{
		strcpy(num, s);
		degree = strlen(s);
	}
	CHugeInt(int n)
	{
		if (n == 0)
		{
			num[0] = '0';
			num[1] = '\0';
			degree = 1;
			return;
		}
		char temp[2 * MAX];
		int i = 0;
		while (n > 0)
		{
			temp[i] = '0' + n % 10;
			n /= 10;
			++i;
		}
		temp[i] = '\0';
		degree = strlen(temp);
		for (int i = 0; i < degree; ++i)
		{
			num[i] = temp[degree - i - 1];
		}
		num[degree] = '\0';
	}
	CHugeInt(const CHugeInt &n)
	{
		strcpy(num, n.num);
		degree = n.degree;
	}
	friend CHugeInt operator+(const CHugeInt &one, const CHugeInt &another)
	{
		CHugeInt temp(0);
		int temp_degree;
		int t = 0;
		if (one.degree > another.degree)
		{
			temp_degree = one.degree;
			int i = temp_degree - 1;
			temp.num[temp_degree] = '\0';
			for (; i >= temp_degree - another.degree; --i)
			{
				temp.num[i] = '0' + one.num[i] - '0' + another.num[i - temp_degree + another.degree] - '0' + t;
				t = 0;
				if (temp.num[i] - '0' >= 10)
				{
					temp.num[i] -= 10;
					t = 1;
				}
			}
			for (; i >= 0; --i)
			{
				temp.num[i] = '0' + one.num[i] - '0' + t;
				t = 0;
				if (temp.num[i] - '0' >= 10)
				{
					temp.num[i] -= 10;
					t = 1;
				}
			}
		}
		else
		{
			temp_degree = another.degree;
			int i = temp_degree - 1;
			temp.num[temp_degree] = '\0';
			for (; i >= temp_degree - one.degree; --i)
			{
				temp.num[i] = '0' + another.num[i] - '0' + one.num[i - temp_degree + one.degree] - '0' + t;
				t = 0;
				if (temp.num[i] - '0' >= 10)
				{
					temp.num[i] -= 10;
					t = 1;
				}
			}
			for (; i >= 0; --i)
			{
				temp.num[i] = '0' + another.num[i] - '0' + t;
				t = 0;
				if (temp.num[i] - '0' >= 10)
				{
					temp.num[i] -= 10;
					t = 1;
				}
			}
		}
		if (t == 1)
		{
			char t_ch[2 * MAX];
			strcpy(t_ch, temp.num);
			temp.num[0] = '1';
			strcpy(temp.num + 1, t_ch);
			++temp.degree;
		}
		temp.degree = strlen(temp.num);
		return temp;
	}
	friend CHugeInt operator+(const CHugeInt &one, int &another)
	{
		return one + CHugeInt(another);
	}
	friend CHugeInt operator+(const int &one, const CHugeInt &another)
	{
		return another + CHugeInt(one);
	}
	friend CHugeInt &operator+=(CHugeInt &one, const CHugeInt &another)
	{
		one = one + another;
		return one;
	}
	friend CHugeInt &operator+=(CHugeInt &one, int &another)
	{
		return one += CHugeInt(another);
	}
	friend CHugeInt &operator++(CHugeInt &one)
	{
		CHugeInt real_one = CHugeInt(1);
		one += real_one;
		return one;
	}
	friend CHugeInt operator++(CHugeInt &one, int)
	{
		CHugeInt temp = one;
		one += CHugeInt(1);
		return temp;
	}
	friend ostream &operator<<(ostream &out, const CHugeInt &one)
	{
		out << one.num;
		return out;
	};
	CHugeInt &operator=(const CHugeInt &another)
	{
		strcpy(this->num, another.num);
		this->degree = another.degree;
		return *this;
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
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}