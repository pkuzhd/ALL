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


struct op
{
	string type;
	int n1, n2;
	int pre;
	int A, B;
};

int main()
{
	int flag[101][101] = { 0 };
	int a, b, c;
	cin >> a >> b >> c;
	flag[0][0] = 1;
	flag[a][0] = 1;
	flag[0][b] = 1;
	vector<op> q;
	q.push_back(op());
	q.push_back(op());
	q[0].n1 = 1;
	q[1].n1 = 2;
	q[0].pre = -1;
	q[1].pre = -1;
	q[0].type = "FILL";
	q[1].type = "FILL";
	q[0].A = a;
	q[1].A = 0; 
	q[0].B = 0;
	q[1].B = b;
	stack<op> s;
	for (int i = 0; ; ++i)
	{
		if (i >= q.size())
		{
			cout << "impossible" << endl;
			break;
		}
		if (q[i].A == c || q[i].B == c)
		{
			s.push(q[i]);
			int pre = q[i].pre;
			while (pre != -1)
			{
				s.push(q[pre]);
				pre = q[pre].pre;
			}
			cout << s.size() << endl;
			while (!s.empty())
			{
				op t = s.top();
				s.pop();
				if (t.type == "POUR")
					cout << "POUR(" << t.n1 << "," << t.n2 << ")" << endl;
				else
					cout << t.type << "(" << t.n1 << ")" << endl;
			}
			break;
		}
		if (q[i].A > 0)
		{
			if (q[i].B < b)
			{
				q.push_back(op());
				q.back().type = "POUR";
				q.back().n1 = 1;
				q.back().n2 = 2;
				q.back().A = q[i].A - (b - q[i].B) > 0 ? q[i].A - (b - q[i].B) : 0;
				q.back().B = q[i].A - (b - q[i].B) > 0 ? b : q[i].B + q[i].A;
				q.back().pre = i;
				if (flag[q.back().A][q.back().B])
				{
					q.pop_back();
				}
				else
				{
					flag[q.back().A][q.back().B] = 1;
				}
			}
			if (true)
			{
				q.push_back(op());
				q.back().type = "DROP";
				q.back().n1 = 1;
				q.back().A = 0;
				q.back().B = q[i].B;
				q.back().pre = i;
				if (flag[q.back().A][q.back().B])
				{
					q.pop_back();
				}
				else
				{
					flag[q.back().A][q.back().B] = 1;
				}
			}
		}
		if (q[i].B > 0)
		{
			if (q[i].A < a)
			{
				q.push_back(op());
				q.back().type = "POUR";
				q.back().n1 = 2;
				q.back().n2 = 1;
				q.back().A = q[i].B - (a - q[i].A) > 0 ? a : q[i].B + q[i].A;
				q.back().B = q[i].B - (a - q[i].A) > 0 ? q[i].B - (a - q[i].A) : 0;
				q.back().pre = i;
				if (flag[q.back().A][q.back().B])
				{
					q.pop_back();
				}
				else
				{
					flag[q.back().A][q.back().B] = 1;
				}
			}
			if (true)
			{
				q.push_back(op());
				q.back().type = "DROP";
				q.back().n1 = 2;
				q.back().A = q[i].A;
				q.back().B = 0;
				q.back().pre = i;
				if (flag[q.back().A][q.back().B])
				{
					q.pop_back();
				}
				else
				{
					flag[q.back().A][q.back().B] = 1;
				}
			}
		}
		if (q[i].A < a)
		{
			q.push_back(op());
			q.back().type = "FILL";
			q.back().n1 = 1;
			q.back().A = a;
			q.back().B = q[i].B;
			q.back().pre = i;
			if (flag[q.back().A][q.back().B])
			{
				q.pop_back();
			}
			else
			{
				flag[q.back().A][q.back().B] = 1;
			}
		}
		if (q[i].B < b)
		{
			q.push_back(op());
			q.back().type = "FILL";
			q.back().n1 = 2;
			q.back().A = q[i].A;
			q.back().B = b;
			q.back().pre = i;
			if (flag[q.back().A][q.back().B])
			{
				q.pop_back();
			}
			else
			{
				flag[q.back().A][q.back().B] = 1;
			}
		}
	}
	return 0;
}