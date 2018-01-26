// 文本二叉树
// pkuzhd
// 2017.10.28
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class tree
{
public:
	tree() { left = right = parent = NULL; }
	char info;
	tree *left, *right, *parent;
};

void preOrder(tree *root)
{
	if (root == NULL || root->info == '*')
		return;
	cout << root->info;
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(tree *root)
{
	if (root == NULL || root->info == '*')
		return;
	inOrder(root->left);
	cout << root->info;
	inOrder(root->right);
}
void postOrder(tree *root)
{
	if (root == NULL || root->info == '*')
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->info;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		tree atree[101];
		int atreeSize = 0;
		string str;
		tree *parent = NULL;
		int currentH = 0;
		while (true)
		{
			cin >> str;
			if (str == "0")
				break;
			int height = str.size() - 1;
			atree[atreeSize].info = str[height];
			if (atreeSize == 0)
			{
				// 第一个节点
				parent = &atree[atreeSize];
			}
			else if (height > currentH)
			{
				// 是上一个节点的子节点
				atree[atreeSize].parent = parent;
				if (parent->left == NULL)
					parent->left = &atree[atreeSize];
				else
					parent->right = &atree[atreeSize];
				currentH = height;
				parent = &atree[atreeSize];
			}
			else
			{
				// 不是上一个节点的子节点
				while (height <= currentH)
				{
					parent = parent->parent;
					--currentH;
				}
				currentH = height;
				atree[atreeSize].parent = parent;
				if (parent->left == NULL)
					parent->left = &atree[atreeSize];
				else
					parent->right = &atree[atreeSize];
				parent = &atree[atreeSize];
			}
			++atreeSize;
		}
		preOrder(atree);
		cout << endl;
		postOrder(atree);
		cout << endl;
		inOrder(atree);
		cout << endl;
		cout << endl;

	}
	return 0;
}