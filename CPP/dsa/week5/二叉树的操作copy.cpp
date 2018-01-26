#include <iostream>
#include <cstdio>
using namespace std;

class tree {
public :
	tree() {left=right=NULL;}
	int info;
	tree *left, *right;
};


tree * SearchTree(int iFind, tree *g_arrNode)
{
	for (int i = 1; i <= 100; i++)
		if (g_arrNode[i - 1].info == iFind)
			return &(g_arrNode[i - 1]);
	return 0;
}

int main()
{
    freopen("C:\\Users\\pkuzhd\\Desktop\\data", "r", stdin);
	int t;
	cin >> t;
	int n, m;
	for (int k = 1; k <= t; k++){
		cin >> n >> m;
		tree g_arrNode[101];

		int x, y, z;
		for (int i = 1; i <= n; i++){
			cin >> x >> y >> z;
			g_arrNode[x].info = x;
			if (y != -1)
				g_arrNode[x].left = &(g_arrNode[y]);
			if (z != -1)
				g_arrNode[x].right = &(g_arrNode[z]);
		}

		int t1, t2, t3;
		for (int i = 1; i <= m; i++){
			cin >> t1 >> t2;
			if (t1 == 1)
			cin >> t3;
			if (t1 == 1){
				tree * pA = SearchTree(t2, g_arrNode);
				tree * pB = SearchTree(t3, g_arrNode);
				tree nodeTmp = *pA;
				*pA = *pB;
				*pB = nodeTmp;
			}else{
				tree * pNode = SearchTree(t2, g_arrNode);
				while (pNode->left)
				pNode = pNode->left;
				cout << pNode->info << endl;
			}
		}
	}
	return 0;
}
