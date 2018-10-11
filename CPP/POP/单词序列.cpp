#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

bool eq(string a, string b)
{
	int num = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
			++num;
	}
	return num == 1;
}
struct state
{
	string word;
	int pre;
	state(string w, int p)
	{
		word = w;
		pre = p;
	}
};
int main()
{
	vector<string> words;
	vector<state> q;
	bool flag[31] = { 0 };
	string begin, end;
	cin >> begin >> end;
	string t;
	while (cin >> t)
		words.push_back(t);
	q.push_back(state(begin, -1));
	for (int i = 0; ; ++i)
	{
		if (i >= q.size())
		{
			cout << 0 << endl;
			break;
		}
		if (eq(q[i].word, end))
		{
			int num = 2;
			int pre = q[i].pre;
			while (pre != -1)
			{
				pre = q[pre].pre;
				++num;
			}
			cout << num << endl;
			break;
		}
		for (int j = 0; j < words.size(); ++j)
		{
			if (!flag[j] && eq(q[i].word, words[j]))
			{
				q.push_back(state(words[j], i));
				flag[j] = 1;
			}
		}
	}
	return 0;
}