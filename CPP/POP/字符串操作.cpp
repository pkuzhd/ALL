#include <iostream>
#include <string>

using namespace std;
string str[21];
string S();
bool is_num(const string &s)
{
	if (s.size() > 5)
		return false;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			;
		}
		else
			return false;
	}
	return true;
}
int N()
{
	string t;
	cin >> t;
	if (t == "rfind")
	{
		string t_s = S();
		int t_n = N();
		int tt = str[t_n].rfind(t_s);
		if (tt == -1)
			return str[t_n].size();
		return tt;
	}
	else if (t == "find")
	{
		string t_s = S();
		int t_n = N();
		int tt = str[t_n].find(t_s);
		if (tt == -1)
			return str[t_n].size();
		return tt;
	}
	else
	{
		int temp = 0;
		for (int i = 0; i < t.size(); ++i)
		{
			temp = temp * 10 + t[i] - '0';
		}
		return temp;
	}
	
}

string S()
{
	string t;
	cin >> t;
	if (t == "copy")
	{
		int t_n = N();
		int t_x = N();
		int t_l = N();
		return str[t_n].substr(t_x, t_l);
	}
	else if (t == "add")
	{
		string s1 = S();
		string s2 = S();
		if (is_num(s1) && is_num(s2))
		{
			string num = "000000";
			for (int i = 0; i < s1.size(); ++i)
			{
				num[5 - i] += s1[s1.size() - 1 - i] - '0';
			}
			for (int i = 0; i < s2.size(); ++i)
			{
				num[5 - i] += s2[s2.size() - 1 - i] - '0';
			}
			int t_num = 0;
			for (int i = 5; i > 0; --i)
			{
				if (num[i] - '0' + t_num >= 10)
				{
					num[i] = num[i] - 10 + t_num;
					t_num = 1;
				}
				else
				{
					num[i] = num[i] + t_num;
					t_num = 0;
				}
			}
			int idx = 0;
			for (; idx < 6; ++idx)
			{
				if (num[idx] == '0')
					continue;
				else
					return num.substr(idx);
			}
			return "0";
		}
		else
		{
			return s1 + s2;
		}
	}
	else
	{
		return t;
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str[i];
	}
	string op;
	while (cin >> op)
	{
		if (op == "over")
			break;
		else if (op == "printall")
		{
			for (int i = 1; i <= n; ++i)
			{
				cout << str[i] << endl;;
			}
		}
		else if (op == "print")
		{
			int temp;
			cin >> temp;
			cout << str[temp] << endl;
		}
		else if (op == "insert")
		{
			string t_s = S();
			int t_n = N();
			int t_x = N();
			str[t_n].insert(t_x, t_s);
		}
		else if (op == "reset")
		{
			string t_s = S();
			int t_n = N();
			str[t_n] = t_s;
		}
	}
	


	return 0;
}