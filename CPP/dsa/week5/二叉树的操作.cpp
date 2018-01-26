// 二叉树的操作
// pkuzhd
// 2017.10.28

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	// freopen("C:\\Users\\pkuzhd\\Desktop\\data", "r", stdin);
	int t;
	cin >> t;
	int y[101];
	int z[101];
	int dict[101];
	for (int k = 0; k < t; ++k) {
		memset(z,-1,sizeof(z));
		memset(dict,-1,sizeof(dict));
		memset(y,-1,sizeof(y));
		int n, m;
		cin >> n >> m;
		int x;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			cin >> y[x] >> z[x];
			dict[i] = i;
		}
		int type, t1, t2, temp, idx;
		for (int i = 0; i < m; ++i) {
			cin >> type;
			if (type==1) {
				cin >> t1 >> t2;
				temp = dict[t1];
				dict[t1] = dict[t2];
				dict[t2] = temp;
			} else {
				cin >> idx;
				while (y[idx]!=-1) {
					idx = dict[y[idx]];
				}
				cout << idx << endl;
			}
		}
	}
	return 0;
}

