// 重建二叉树
// pkuzhd
// 2017.10.29

#include <iostream>
#include <vector>

using namespace std;


void getPreOrder(const char *inOrder, const char *preOrder, string &postOrder, int len);

int main(int argc, char const *argv[])
{
	freopen("F:\\ALL\\data", "r", stdin);
	string preOrder, inOrder;
	while (cin>>preOrder>>inOrder) {
		string postOrder;
		int len = inOrder.size();
		char *str1 = new char[len+1];
		char *str2 = new char[len+1];
		getPreOrder(inOrder.c_str(), preOrder.c_str(), postOrder, len);
		cout << postOrder << endl;
		delete [] str1;
		delete [] str2;
	}
	return 0;
}



void getPreOrder(const char *inOrder, const char *preOrder, string &postOrder, int len) {
	if (len == 0) {
		return;
	} else {
		char root = preOrder[0];
		postOrder = root + postOrder;
		int idxRoot = 0;
		for (int i = 0; i < len; ++i) {
			if (root == inOrder[i]){
				idxRoot = i;
				break;
			}
		}
		getPreOrder(inOrder+idxRoot+1, preOrder+idxRoot+1, postOrder, len-idxRoot-1);
		getPreOrder(inOrder, preOrder+1, postOrder, idxRoot);
	}
}

