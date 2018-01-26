#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

class tree {
public :
	tree() {left=right=parent=NULL;}
	int info;
	tree *left, *right, *parent;
};

int getSum(tree *root, int length) {
	// for (int i = 0; i > -7; --i)
	// 	cout <<  root[i].info << " " <<(root[i].left == NULL) << " " << (root[i].right == NULL) << endl;
	// cout << endl;
	if (root->left == NULL && root->right == NULL){
		return root->info * length;
	}
	return getSum(root->left, length+1) + getSum(root->right, length+1);
}

int main(int argc, char const *argv[])
{
	freopen("F:\\ALL\\data", "r", stdin);
	int t;
	cin >> t;
	int num[200];
	tree atree[300];
	int size = t;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < t; ++i) {
		cin >> num[i];
		atree[i].info = num[i];
		pq.push(num[i]);
	}
	while (pq.size()>1) {
		int temp1 = pq.top();
		pq.pop();
		int temp2 = pq.top();
		pq.pop();
		int t1, t2;
		atree[size].info = temp1 + temp2;
		for (int i = 0; i < size; ++i) {
			if (atree[i].info == temp1 && atree[i].parent == NULL) {
				t1 = i;
				break;
			}
		}
		atree[size].left = &atree[t1];
		atree[t1].parent = &atree[size];
		for (int i = 0; i < size; ++i) {
			if (atree[i].info == temp2 && atree[i].parent == NULL) {
				t2 = i;
				break;
			}
		}
		atree[size].right = &atree[t2];
		atree[t2].parent = &atree[size];
		pq.push(temp1+temp2);
		++size;
	}
	int sum = pq.top();
	int idx;
	for (int i = 0; i < size; ++i) {
		if (atree[i].info == sum && atree[i].parent == NULL) {
			idx = i;
			break;
		}
	}
	cout << getSum(&atree[idx], 0) << endl;
	return 0;
}
