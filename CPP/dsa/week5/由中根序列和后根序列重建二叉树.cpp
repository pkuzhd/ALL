// 由中根序列和后根序列重建二叉树
// pkuzhd
// 2017.10.28

#include <iostream>
#include <vector>

using namespace std;


void getPreOrder(int *inOrder, int *postOrder, vector<int> &preOrder, int len);

int main(int argc, char const *argv[])
{
	freopen("C:\\Users\\pkuzhd\\Desktop\\data", "r", stdin);
	vector<int> order;
	int temp;
	while (cin>>temp) {
		order.push_back(temp);
	}
	int len = order.size()/2;
	vector<int> preOrder;
	int *inOrder = new int[len];
	int *postOrder = new int[len];
	for (int i = 0; i < len; ++i)
	{
		inOrder[i] = order[i];
		postOrder[i] = order[i+len];
	}
	getPreOrder(inOrder, postOrder, preOrder, len);
	bool flag = true;
	for (int i = 0; i <len; ++i)
	{
		if (flag) {
			cout << preOrder[i];
			flag = false;
		} else {
			cout << " " << preOrder[i];
		}
	}
	delete [] inOrder;
	delete [] postOrder;

	return 0;
}



void getPreOrder(int *inOrder, int *postOrder, vector<int> &preOrder, int len) {
	if (len == 0) {
		return;
	} else {
		int root = postOrder[len-1];
		preOrder.push_back(root);
		int idxRoot = 0;
		for (int i = 0; i < len; ++i) {
			if (root == inOrder[i]){
				idxRoot = i;
				break;
			}
		}
		getPreOrder(inOrder, postOrder, preOrder, idxRoot);
		getPreOrder(inOrder+idxRoot+1, postOrder+idxRoot, preOrder, len-idxRoot-1);
	}
}

