//#include <iostream>
//#include <string>
//#include <bitset>
//#include <vector>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> name;
//int cur;
//
//string name_str(string str, int level)
//{
//	string tmp;
//	for (int i = 0; i < level; ++i)
//		tmp += "|     ";
//	tmp += str;
//	return tmp;
//}
//void show(int level = 0)
//{
//	vector<string> files;
//	while (true)
//	{
//		if (cur == name.size())
//			return;
//		if (name[cur] == "]")
//		{
//			++cur;
//			sort(files.begin(), files.end());
//			for (int i = 0; i < files.size(); ++i)
//				cout << name_str(files[i], level - 1) << endl;
//			return;
//		}
//
//		if (name[cur][0] == 'd' || name[cur][0] == 'R')
//		{
//			cout << name_str(name[cur], level) << endl;
//			++cur;
//			show(level + 1);
//		}
//		else if (name[cur][0] == 'f')
//		{
//			files.push_back(name[cur]);
//			++cur;
//		}
//		else
//		{
//			string tmp = name[cur];
//			throw 1;
//		}
//	}
//}
//
//int main()
//{
//	string tmp;
//	int t = 0;
//	name.push_back("ROOT");
//	while (cin >> tmp)
//	{
//		if (tmp == "#")
//			break;
//		if (tmp == "*")
//		{
//			name.push_back("]");
//			cur = 0;
//			cout << "DATA SET " << ++t << ":" << endl;
//			show();
//			cout << endl;
//			name.clear();
//			name.push_back("ROOT");
//		}
//		else
//		{
//			name.push_back(tmp);
//		}
//	}
//	return 0;
//}