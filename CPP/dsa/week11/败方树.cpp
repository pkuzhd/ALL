// 败方树
// pkuzhd
// 2017.12.11
#include <iostream>
#include <queue>

using namespace std;

// 构建败方树
// 返回败方树
// num：数组
// n：数组大小
// low_ext：最底层外部结点数
// off_set：最底层外部结点之上的结点总数
int *build(int *num, int n, int &low_ext, int &off_set);



// 胜者
// 返回胜者在数组中的下标
// num：数组
// x, y：比赛双方的下标
int winner(int *num, int x, int y)
{
	return (num[x] < num[y]) ? x : y;
}

// 败者
// 返回败者在数组中的下标
// num：数组
// x, y：比赛双方的下标
int loser(int *num, int x, int y)
{
	return (num[x] < num[y]) ? y : x;
}

// 比赛
// 无返回值
// num：数组
// loser_tree：败方树
// father：父结点存放比赛结果
// left：左结点
// right：右结点
void play(int *num, int *loser_tree, int father, int left, int right);

// 重新比赛
// 无返回值
// num：数组
// loser_tree：败方树
// n：数组大小
// low_ext：最底层外部结点数
// off_set：最底层外部结点之上的结点总数
// i：发生改变的数组的下标
void replay(int *num, int *loser_tree, int n, int low_ext, int off_set, int i);

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	int *num = new int[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		cin >> num[i];
	}
	int low_ext; // 最底层外部结点数
	int off_set; // 最底层外部结点之上的结点总数
	int *loser_tree = build(num, n, low_ext, off_set);
	cout << num[loser_tree[0]];
	for (int i = 1; i < n; ++i)
	{
		cout << " " << num[loser_tree[i]];
	}
	cout << endl;
	for (int j = 0; j < m; ++j)
	{
		int idx, number;
		cin >> idx >> number;
		num[idx + 1] = number;
		replay(num, loser_tree, n, low_ext, off_set, idx + 1);
		cout << num[loser_tree[0]];
		for (int i = 1; i < n; ++i)
		{
			cout << " " << num[loser_tree[i]];
		}
		cout << endl;
	}
	delete[] num;
	delete[] loser_tree;
	return 0;
}

int* build(int *num, int n, int &low_ext, int &off_set)
{
	int temp = 1; // 临时变量, 记录败方树最后一层的元素个数
	while (2 * temp < n)
		temp *= 2;
	low_ext = n - (2 * temp - n);
	off_set = 2 * temp - 1;
	int *loser_tree = new int[n]; // 败方树
	int i; // 数组下标
	for (i = 2; i <= low_ext; i += 2) // 最底层外部结点的比赛
	{
		play(num, loser_tree, (off_set + i) / 2, i - 1, i);
	}
	if (n % 2 == 1) // n为奇数，内部结点和外部结点比较一次
	{
		play(num, loser_tree, n / 2, loser_tree[(n - 1) / 2], low_ext + 1);
		i = low_ext + 3;
	}
	else // n为偶数
	{
		i = low_ext + 2;
	}
	for (; i <= n; i += 2)
	{
		play(num, loser_tree, (i - low_ext + n - 1) / 2, i - 1, i);
	}
	return loser_tree;
}

void play(int *num, int *loser_tree, int father, int left, int right)
{
	int temp_winner, new_winner;
	loser_tree[father] = loser(num, left, right);
	temp_winner = winner(num, left, right);
	while (father > 1 && father % 2 == 1) // father % 2 == 1保证每次都是从右子树向上更新
	{
		// loser_tree[father / 2] 为其左子树中的胜者
		new_winner = winner(num, temp_winner, loser_tree[father / 2]);
		loser_tree[father / 2] = loser(num, temp_winner, loser_tree[father / 2]);
		temp_winner = new_winner;
		father /= 2;
	}
	loser_tree[father / 2] = temp_winner; // 每次向上更新终止时顶部存放的是胜者
}

void replay(int * num, int * loser_tree, int n, int low_ext, int off_set, int i)
{
	int father;
	if (i <= low_ext) // 如果是最底层外部结点
		father = (i + off_set) / 2;
	else
		father = (i - low_ext + n - 1) / 2;
	loser_tree[0] = winner(num, i, loser_tree[father]);
	loser_tree[father] = loser(num, i, loser_tree[father]);
	while (father / 2 >= 1)
	{
		father /= 2;
		int temp_winner = winner(num, loser_tree[father], loser_tree[0]);
		loser_tree[father] = loser(num, loser_tree[father], loser_tree[0]);
		loser_tree[0] = temp_winner;
	 }
}
