// Õ√◊””Î”£ª®
// pkuzhd
// 2017.12.18
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct path
{
	string from, to;
	int value;
};

struct node
{
	bool is_in;
	int length;
	string pre;
	string name;
	vector<path> next;
	friend bool operator<(node n1, node n2)
	{
		return n1.length > n2.length;
	}
};

void dijkstra(string &from, const map<string, node> &place, map<string, node> &dict)
{
	dict[from].is_in = true;
	dict[from].length = 0;
	dict[from].pre = from;
	for (int j = 0; j < dict[from].next.size(); ++j)
	{
		string to = dict[from].next[j].to;
		int length = dict[from].next[j].value;
		dict[to].pre = from;
		dict[to].length = length;
	}
	for (int i = 1; i < place.size(); ++i)
	{
		int min_length = 1 << 30;
		string new_name;
		for (auto it = dict.begin(); it != dict.end(); ++it)
		{
			if (!it->second.is_in && it->second.length < min_length)
			{
				new_name = it->first;
				min_length = it->second.length;
			}
		}
		dict[new_name].is_in = true;
		for (int j = 0; j < dict[new_name].next.size(); ++j)
		{
			string to = dict[new_name].next[j].to;
			if (dict[new_name].length + dict[new_name].next[j].value < dict[to].length)
			{
				int length = dict[new_name].length + dict[new_name].next[j].value;
				dict[to].pre = new_name;
				dict[to].length = length;
			}
		}
	}
}

void print(string &from, string &to, map<string, node> &dict)
{
	if (from == to)
		cout << from;
	else
	{
		string pre = dict[to].pre;
		print(from, pre, dict);
		cout << "->(" << dict[to].length - dict[pre].length << ")->" << to;
	}
}

int main(int argc, char *argv[])
{
	const int infinity = 1 << 30;
	int p;
	cin >> p;
	map<string, node> place;
	for (int i = 0; i < p; ++i)
	{
		string str;
		cin >> str;
		place[str] = node();
		place[str].name = str;
	}
	int q;
	cin >> q;
	for (int i = 0; i < p; ++i)
	{
		string from, to;
		int value;
		cin >> from >> to >> value;
		path apath;
		apath.from = from;
		apath.to = to;
		apath.value = value;
		place[from].next.push_back(apath);
		apath.from = to;
		apath.to = from;
		apath.value = value;
		place[to].next.push_back(apath);
	}
	int r;
	cin >> r;
	for (int i = 0; i < r; ++i)
	{
		string from, to;
		cin >> from >> to;
		map<string, node> dict;
		for (auto it = place.begin(); it != place.end(); ++it)
		{
			dict[it->first] = it->second;
			dict[it->first].length = infinity;
			dict[it->first].pre = it->first;
			dict[it->first].is_in = false;
		}
		dijkstra(from, place, dict);
		print(from, to, dict);
		cout << endl;
	}
	return 0;
}