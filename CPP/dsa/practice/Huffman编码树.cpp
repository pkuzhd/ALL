// Huffman编码树
// pkuzhd
// 2017.12.16
#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int val;
	node *left, *right;
};

struct cmp
{
	bool operator()(const node &a, const node &b)
	{
		return a.val > b.val;
	}
};

int getsum(const node *anode, int i = 0)
{
	if (anode->left == NULL)
		return anode->val*i;
	return getsum(anode->left, i + 1) + getsum(anode->right, i + 1);
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		priority_queue<node, vector<node>, cmp> pq;
		for (int j = 0; j < t; ++j)
		{
			int temp;
			cin >> temp;
			node *anode = new node;
			anode->val = temp;
			anode->left = anode->right = NULL;
			pq.push(*anode);
			delete anode;
		}
		while (pq.size() > 1)
		{
			node *anode = new node;
			anode->val = pq.top().val;
			anode->left = pq.top().left;
			anode->right = pq.top().right;
			pq.pop();
			node *bnode = new node;
			bnode->val = pq.top().val;
			bnode->left = pq.top().left;
			bnode->right = pq.top().right;
			pq.pop();
			node cnode;
			cnode.val = anode->val + bnode->val;
			cnode.left = anode;
			cnode.right = bnode;
			pq.push(cnode);
		}
		cout << getsum(&(pq.top())) << endl;
	}
	return 0;
}
