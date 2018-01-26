// 置换选择排序
// pkuzhd
// 2017.12.01
// 认认真真写一次注释
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // 包含greater的头文件

using namespace std;

int main(int argc, char *argv[])
{
	int m, n;
	cin >> m >> n; // m为初始顺串的数的个数, n为二叉最小堆的大小
	int *num = new int[m]; // 动态分配内存
	for (int i = 0; i < m; ++i)
	{
		cin >> num[i];
	} // 初始顺串存在数组里面
	int temp;
	priority_queue<int, vector<int>, greater<int> > pq; // 用STL的优先队列来实现二叉最小堆
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		pq.push(temp); // 依次入堆
	}
	bool flag = true; // 标记是否为第一个输出的数
	for (int i = 0; i < m; ++i)
	{
		if (pq.empty()) // 当堆的大小为0时, 停止
			break;
		// 如果输入的数小于堆顶, 应该把他放到堆尾并让堆的大小减一, 这里为了方便, 直接舍弃
		if (num[i] >= pq.top()) 
		{
			pq.push(num[i]);
		}
		if (flag) // 判断是否为第一次输出
		{
			cout << pq.top();
			flag = false;
		}
		else
			cout << " " << pq.top();
		pq.pop();
	}
	cout << endl;
	delete[] num; // 释放动态分配的内存空间
	return 0;
}