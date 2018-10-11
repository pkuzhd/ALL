#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class hugeint
{
public:
	string num;
	hugeint()
	{
		num = "0";
	}
	hugeint(const hugeint &other)
	{
		num = other.num;
	}
	hugeint(const int &other)
	{
		num = "";
		int t = other;
		if (other == 0)
		{
			num = "0";
			return;
		}
		while (t > 0)
		{
			num = string(1, '0' + t % 10) + num;
			t /= 10;
		}
	}
	hugeint(const string &other)
	{
		num = other;
	}
	~hugeint() { ; }
	hugeint(const char *number)
	{
		num = number;
	}
	friend ostream &operator<<(ostream &out, const hugeint &number)
	{
		out << number.num;
		return out;
	}
	friend istream &operator>>(istream &in, hugeint &number)
	{
		in >> number.num;
		return in;
	}
	hugeint &operator=(const hugeint &number)
	{
		if (this == &number)
			return *this;
		num = number.num;
		return *this;
	}
	hugeint &operator=(const char *number)
	{
		num = number;
		return *this;
	}
	hugeint operator+(const hugeint &number)
	{
		int len = num.size() > number.num.size() ? num.size() : number.num.size();
		++len;
		string temp(string(len, '0'));
		for (int i = 1; i <= num.size(); ++i)
		{
			temp[len - i] += num[num.size() - i] - '0';
		}
		for (int i = 1; i <= number.num.size(); ++i)
		{
			temp[len - i] += number.num[number.num.size() - i] - '0';
		}
		int t = 0;
		for (int i = temp.size() - 1; i >= 0; --i)
		{
			if (temp[i] - '0' + t >= 10)
			{
				temp[i] = temp[i] + t - 10;
				t = 1;
			}
			else
			{
				temp[i] += t;
				t = 0;
			}
		}
		if (temp[0] == '0')
			return temp.substr(1);
		return temp;
	}
	hugeint operator+(const int &number)
	{
		return *this + hugeint(number);
	}
	friend hugeint operator+(int num2, const hugeint &num1)
	{
		return hugeint(num2) + num1;
	}
	bool operator<(const hugeint &number)
	{
		if (num.size() < number.num.size())
			return true;
		if (num.size() > number.num.size())
			return false;
		for (int i = 0; i < num.size(); ++i)
		{
			if (num[i] < number.num[i])
				return true;
		}
		return false;
	}
	bool operator>(const hugeint &number)
	{
		if (num.size() > number.num.size())
			return true;
		if (num.size() < number.num.size())
			return false;
		for (int i = 0; i < num.size(); ++i)
		{
			if (num[i] > number.num[i])
				return true;
		}
		return false;

	}
	bool operator==(const hugeint &number)
	{
		if (num.size() != number.num.size())
			return false;
		for (int i = 0; i < num.size(); ++i)
		{
			if (num[i] != number.num[i])
				return false;
		}
		return true;
	}


};




hugeint dp[51][51];
hugeint num;
string str;
hugeint v(int m, int n)
{
	if (!(dp[m][n] == "-1"))
		return dp[m][n];
	if (m == 0)
	{
		if (n == 0)
			dp[m][n] = "0";
		else
			dp[m][n] = str.substr(0, n);
		return dp[m][n];
	}
	if (n < m + 1)
	{
		dp[m][n] = "1000000000000000000000000000000000000000000000000000000000000";
		return dp[m][n];
	}
	dp[m][n] = "1000000000000000000000000000000000000000000000000000000000000";
	for (int i = m; i < n; ++i)
	{
		hugeint n1 = v(m - 1, i);
		hugeint n2 = str.substr(i, n - i);
		hugeint sum = n1 + n2;
		if (sum < dp[m][n])
		{
			dp[m][n] = sum;
		}
	}
	return dp[m][n];
}

int main()
{
	int n;
	while (cin >> n)
	{
		cin >> str;
		num = str;

		
		int lenght = str.size();
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= lenght; ++j)
				dp[i][j] = "-1";
		}
		cout << v(n, lenght) << endl;
	}
	return 0;
}