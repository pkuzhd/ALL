// Hardwood Species
// pkuzhd
// 2017.12.17
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct node
{
	string name;
	int num;
	node *left, *right;
};

void add(node *root, string name)
{
	if (root->name == name)
	{
		++(root->num);
		return;
	}
	else if (root->name < name)
	{
		if (root->right == NULL)
		{
			root->right = new node;
			root = root->right;
			root->name = name;
			root->left = NULL;
			root->right = NULL;
			root->num = 1;
		}
		else
			add(root->right, name);
	}
	else
	{
		if (root->left == NULL)
		{
			root->left = new node;
			root = root->left;
			root->name = name;
			root->left = NULL;
			root->right = NULL;
			root->num = 1;
		}
		else
			add(root->left, name);
	}
}

void print(node *root, int sum)
{
	if (root == NULL)
		return;
	print(root->left, sum);
	cout << root->name;
	printf(" %.4f\n", (float)root->num / sum * 100);
	print(root->right, sum);
	// delete root;
}

int main(int argc, char *argv[])
{
	string str;
	int sum = 0;
	node *root = NULL;
	if (getline(cin, str))
	{
		root = new node;
		root->name = str;
		root->left = NULL;
		root->right = NULL;
		root->num = 1;
		++sum;
		node *cur = root;
		while (getline(cin, str))
		{
			if (str == "")
				continue;
			add(root, str);
			++sum;
		}
	}
	print(root, sum);
	return 0;
}