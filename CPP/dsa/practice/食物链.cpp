// 食物链
// pkuzhd
// 2017.12.12
#include <iostream>

using namespace std;


int myfind(int *pre, int *relation, int x) //查找根结点  
{
	int temp;
	if (x == pre[x])
		return x;
	temp = pre[x]; //路径压缩
	pre[x] = myfind(pre, relation, temp);
	relation[x] = (relation[x] + relation[temp]) % 3; //关系域更新  
	return pre[x]; //根结点
}

int main(int argc, char *argv[])
{
	int n, k;
	int n_false = 0;
	cin >> n >> k;
	int *pre = new int[n + 1]; // 父结点
	int *relation = new int[n + 1]; // 与父结点的关系，0表示同类，1表示被父结点吃，2表示吃父结点
	for (int i = 1; i <= n; ++i)
	{
		// 初始化，父结点为自己，关系为同类
		pre[i] = i;
		relation[i] = 0;
	}
	for (int i = 0; i < k; ++i)
	{
		int d, x, y;
		cin >> d >> x >> y;
		if (x > n || y > n)
		{
			++n_false;
			continue;
		}
		if (d == 2 && x == y)
		{
			++n_false;
			continue;
		}
		int root1 = myfind(pre, relation, x);
		int root2 = myfind(pre, relation, y);
		if (root1 != root2)
		{
			pre[root2] = root1;
			relation[root2] = (3 + (d - 1) + relation[x] - relation[y]) % 3;
		}
		else
		{
			if (d == 1 && relation[x] != relation[y])
			{
				++n_false;
				continue;
			}
			if (d == 2 && (3 + relation[y] - relation[x]) % 3 != 1)
			{
				++n_false;
				continue;
			}
		}


	}
	cout << n_false << endl;
	return 0;
}