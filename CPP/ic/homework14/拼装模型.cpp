// 拼装模型
// pkuzhd
// 2017.12.29
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

// 直接用优先队列来做
// 每次取两个最小的合并
// 当队列大小为1时停止
int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}
	int time = 0;
	while (pq.size() > 1)
	{
		int t1 = pq.top();
		pq.pop();
		int t2 = pq.top();
		pq.pop();
		pq.push(t1 + t2);
		time += t1 + t2;
	}
	cout << time << endl;
	return 0;
}