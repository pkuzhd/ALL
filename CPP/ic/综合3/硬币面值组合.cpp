// 硬币面值组合
// pkuzhd
// 2018.01.05
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int t = 0;
int a = 0, b = 0, c = 0;
struct node
{
	int t, a, b, c;
	bool operator<(node o)
	{
		return o.c < c || (o.c == c && o.b < b);
	}
};
priority_queue<node> pq;

// flag表示可以使用的最小硬币
void f(int n, int flag)
{
	if (n == 0) // 剩余为0时， 开始输出
	{
		++t;
		node _t;
		_t.a = a;
		_t.b = b;
		_t.c = c;
		_t.t = t;
		pq.push(_t);
		return;
	}
	// 依次尝试各个面值的硬币
	if (n >= 1 && flag == 1)
	{
		++a;
		f(n - 1, 1);
		--a;
	}
	if (n >= 2 && flag <= 2)
	{
		++b;
		f(n - 2, 2);
		--b;
	}
	if (n >= 5)
	{
		++c;
		f(n - 5, 5);
		--c;
	}
	
	

}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	a = 0, b = 0, c = 0;
	f(n, 1);
	while (!pq.empty())
	{
		printf("%03d%12d%12d%12d\n", pq.top().t, pq.top().a, pq.top().b, pq.top().c);
		pq.pop();
	}

	return 0;
}