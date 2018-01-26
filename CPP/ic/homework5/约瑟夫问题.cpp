//****************************
//*例程：约瑟夫问题         **
//*作者：pkuzhd             **
//*时间：2017.9.28          **
//****************************

#include <iostream>
#include <queue>

using namespace std;

int joseph(int n, int m);

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin >> n >> m)
	{
		if (n == 0 && m == 0)
			return 0;
		cout << joseph(n, m) << endl;
	}
}

int joseph(int n, int m)
{
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}
	int times = 0;
	int temp = 0;
	while(q.size()>1)
	{
		temp = q.front();
		q.pop();
		++times;
		if (times==m)
		{
			times = 0;
		}
		else
		{
			q.push(temp);
		}
	}
	return q.front();
}
