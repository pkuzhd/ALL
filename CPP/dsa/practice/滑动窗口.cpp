// 滑动窗口
// pkuzhd
// 2017.12.01
#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k;
	cin >> n >> k;
	int *num = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	deque<int> dqMin;
	deque<int> idxMin;
	// 前k个单独处理
	for (int i = 0; i < k; ++i)
	{
		while (!dqMin.empty() && dqMin.back() >= num[i])
		{
			dqMin.pop_back();
			idxMin.pop_back();
		}
		dqMin.push_back(num[i]);
		idxMin.push_back(i);
	}
	cout << dqMin.front();

	for (int i = k; i < n; ++i)
	{
		if (dqMin.size() == k)
		{
			dqMin.pop_front();
			idxMin.pop_front();
		}
		while (!dqMin.empty() && dqMin.back() >= num[i])
		{
			dqMin.pop_back();
			idxMin.pop_back();
		}
		dqMin.push_back(num[i]);
		idxMin.push_back(i);
		if (idxMin.front() <= i - k)
		{
			dqMin.pop_front();
			idxMin.pop_front();
		}

		cout << " " << dqMin.front();
	}
	cout << endl;


	deque<int> dqMax;
	deque<int> idxMax;
	// 前k个单独处理
	for (int i = 0; i < k; ++i)
	{
		while (!dqMax.empty() && dqMax.back() <= num[i])
		{
			dqMax.pop_back();
			idxMax.pop_back();
		}
		dqMax.push_back(num[i]);
		idxMax.push_back(i);
	}
	cout << dqMax.front();

	for (int i = k; i < n; ++i)
	{
		if (dqMax.size() == k)
		{
			dqMax.pop_front();
			idxMax.pop_front();
		}
		while (!dqMax.empty() && dqMax.back() <= num[i])
		{
			dqMax.pop_back();
			idxMax.pop_back();
		}
		dqMax.push_back(num[i]);
		idxMax.push_back(i);
		if (idxMax.front() <= i - k)
		{
			dqMax.pop_front();
			idxMax.pop_front();
		}

		cout << " " << dqMax.front();
	}
	cout << endl;

	delete[] num;
	return 0;
}