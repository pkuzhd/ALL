#include <iostream>
#include <string>
#include <vector>
#define UNVISITID 0;
#define VISITID 1;

using namespace std;

struct place
{
	string name;
	vector<place *> next;
	vector<int> distance;
};

class dist
{
public:
	int idx;
	int length;
	int pre;
};

class edge
{
public:
	int from, to, weight;
	edge() { from = -1; to = -1; weight = 0; }
	edge(int f, int t, int w) { from = f; to = t; weight = w; }
};


class graph
{
public:
	int numV;
	int numE;
	int *mark;
	int *indegree;
	graph(int n)
	{
		numV = n;
		numE = 0;
		indegree = new int[n];
		mark = new int[n];
		for (int i = 0; i < n; ++i)
		{
			mark[i] = UNVISITID;
			indegree[i] = 0;
		}
	}
	~graph()
	{
		delete[] mark;
		delete[] indegree;
	}

private:

};






















int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	place *szP = new place[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> szP[i].name;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		bool flag_1 = false, flag_2 = false;
		string str1, str2;
		int dis;
		int idx1, idx2;
		cin >> str1 >> str2 >> dis;
		for (int j = 0; j < n; ++j)
		{
			if (!flag_1 && szP[j].name == str1)
			{
				flag_1 = true;
				idx1 = j;
			}
			if (!flag_2 && szP[j].name == str2)
			{
				flag_2 = true;
				idx2 = j;
			}
			if (flag_1 && flag_2)
				break;
		}
		szP[idx1].next.push_back(&szP[idx2]);
		szP[idx1].distance.push_back(dis);
	}
	int l;
	cin >> l;
	for (int i = 0; i < l; ++i)
	{
		int idx1, idx2;
		bool flag_1 = false, flag_2 = false;
		string str1, str2;
		cin >> str1 >> str2;
		for (int j = 0; j < n; ++j)
		{
			if (!flag_1 && szP[j].name == str1)
			{
				flag_1 = true;
				idx1 = j;
			}
			if (!flag_2 && szP[j].name == str2)
			{
				flag_2 = true;
				idx2 = j;
			}
			if (flag_1 && flag_2)
				break;
		}
		int *distance = new int[n];
		int *pre = new int[n];
		for (int j = 0; j < n; ++j)
		{
			if (j == idx1)
				distance[j] = 0;
			else
				distance[j] = INFINITY;
		}
		




		delete[] distance;
		delete[] pre;
	}


	delete[] szP;
	return 0;
}