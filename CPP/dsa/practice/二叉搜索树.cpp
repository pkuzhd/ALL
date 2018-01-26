// 二叉搜索树
// pkuzhd
// 2017.12.16
#include <iostream>

using namespace std;

struct node
{
	int val;
	node *left, *right;
};

void inorder(node *root)
{
	if (root == NULL)
		return;
	cout << " " << root->val;
	inorder(root->left);
	inorder(root->right);
}

void add(node *root, int val)
{
	while (root != NULL)
	{
		if (root->val < val)
		{
			root = root->right;
		}
		else if (root->val > val)
		{
			root = root->left;
		}
	}
	root = new node;
	root->left = root->right = NULL;
	root->val = val;
}

int main(int argc, char *argv[])
{
	int temp;
	node *root = NULL;
	while (cin >> temp)
	{
		if (root == NULL)
		{
			root = new node;
			root->left = root->right = NULL;
			root->val = temp;
			continue;
		}
		node *cur = root;
		while (true)
		{
			if (cur->val < temp)
			{
				if (cur->right == NULL)
				{
					cur->right = new node;
					cur = cur->right;
					cur->left = cur->right = NULL;
					cur->val = temp;
					break;
				}
				cur = cur->right;
			}
			else if (cur->val > temp)
			{
				if (cur->left == NULL)
				{
					cur->left = new node;
					cur = cur->left;
					cur->left = cur->right = NULL;
					cur->val = temp;
					break;
				}
				cur = cur->left;
			}
			else
				break;
		}
		
	}
	cout << root->val;
	inorder(root->left);
	inorder(root->right);
	return 0;
}