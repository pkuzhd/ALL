#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class warrior;
class army;

const int RED = 0;
const int BLUE = 1;


class warrior
{
private:

public:
	static int hp_dragon;
	static int hp_ninja;
	static int hp_iceman;
	static int hp_lion;
	static int hp_wolf;
	static int hp[5];
	static string name[5];
	friend class army;
	virtual string getName() = 0;
};

int warrior::hp[5] = { 0 };
string warrior::name[5] = { "dragon","ninja","iceman","lion","wolf" };

class army
{
private:
	int num[5];
	int color;
	int num_dragon;
	int num_ninja;
	int num_iceman;
	int num_lion;
	int num_wolf;
	int num_warrior[5];
	int num_total;
	int hp;
	bool stop;
	int order[5];
	bool flag[5];
	int tick;
public:
	army(int _color, int _hp);
	bool is_stop() { return stop; }
	void create(int time);
};

int main(int argc, const char *argv[])
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int hp_total;
		cin >> hp_total;
		for (int j = 0; j < 5; ++j)
			cin >> warrior::hp[j];

		army red(RED, hp_total), blue(BLUE, hp_total);
		cout << "Case:" << i << endl;
		for (int time = 0; !(red.is_stop() && blue.is_stop()); ++time)
		{
			if (!red.is_stop())
			{
				red.create(time);
			}
			if (!blue.is_stop())
			{
				blue.create(time);
			}
		}
	}
	return 0;
}

army::army(int _color, int _hp) : color(_color), hp(_hp), stop(false), tick(0), num_total(0)
{
	if (color == RED)
	{
		order[0] = 2;
		order[1] = 3;
		order[2] = 4;
		order[3] = 1;
		order[4] = 0;
	}
	else
	{
		order[0] = 3;
		order[1] = 0;
		order[2] = 1;
		order[3] = 2;
		order[4] = 4;
	}
	for (int i = 0; i < 5; ++i)
	{
		flag[i] = true;
		num_warrior[i] = 0;
	}
}

void army::create(int time)
{
	printf("%03d %s ", time, color == RED ? "red" : "blue");
	for (int i = 0; i < 5; ++i)
	{
		if (hp >= warrior::hp[order[tick]])
		{
			int type = order[tick];
			hp -= warrior::hp[type];
			++num_warrior[type];
			tick = (tick + 1) % 5;
			string temp = warrior::name[type];
			cout << temp << " " << ++num_total << " born with strength " << warrior::hp[type] << ",";
			cout << num_warrior[type] << " " << temp << " in " << (color == RED ? "red" : "blue") << " headquarter";
			cout << endl;
			return;
		}
		tick = (tick + 1) % 5;
	}
	stop = true;
		cout << "headquarter stops making warriors" << endl;
}