// 实现堆结构
// pkuzhd
// 2017.12.16
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>


using namespace std;

//void add(int *num, const int &val);
//int remove(int *num);
//void siftup(int *num, int position);
//void siftdown(int *num, int position);
//int length;
//void print(int *num)
//{
//	return;
//	for (int i = 1; i <= length; ++i)
//	{
//		cout << num[i] << " ";
//	}
//	cout << endl;
//}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int j = 0; j < n; ++j)
		{
			int type;
			cin >> type;
			//scanf("%d", &type);
			if (type == 1)
			{
				int u;
				cin >> u;
				//scanf("%d", &u);
				pq.push(u);
			}
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
	}
	return 0;
}
//
//void add(int *num, const int &val)
//{
//	++length;
//	num[length] = val;
//	siftup(num, length);
//}
//
//int remove(int *num)
//{
//	print(num);
//	int t = num[1];
//	num[1] = num[length];
//	--length;
//	print(num);
//	siftdown(num, 1);
//	
//	return t;
//}
//
//void siftup(int *num, int position)
//{
//	while (position > 0)
//	{
//		if (num[position] < num[position / 2])
//		{
//			int temp = num[position];
//			num[position] = num[position / 2];
//			num[position / 2] = num[position];
//			position /= 2;
//		}
//		else
//		{
//			return;
//		}
//	}
//}
//
//void siftdown(int *num, int position)
//{
//	while (position * 2 <= length)
//	{
//		print(num);
//		if (position * 2 + 1 > length)
//		{
//			if (num[position] > num[position * 2])
//			{
//				int temp = num[position];
//				num[position] = num[position * 2];
//				num[position * 2] = temp;
//			}
//			else
//			{
//				return;
//			}
//		}
//		else
//		{
//			if (num[position * 2] < num[position * 2 + 1])
//			{
//				if (num[position * 2] < num[position])
//				{
//					int temp = num[position];
//					num[position] = num[position * 2];
//					num[position * 2] = temp;
//				}
//				else
//					return;
//			}
//			else
//			{
//				if (num[position * 2 + 1] < num[position * 2])
//				{
//					int temp = num[position];
//					num[position] = num[position * 2 + 1];
//					num[position * 2 + 1] = temp;
//				}
//				else
//					return;
//			}
//		}
//	}
//}
