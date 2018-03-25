#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class warrior;
class army;

const int RED = 0;
const int BLUE = 1;


class warrior
{
protected:
	int loyalty;                     // 忠诚度
	int number;                      // 编号
	int color;
	string weapon[2];                   // 武器
	float morale;                    // 士气
public:
	static int hp_dragon;
	static int hp_ninja;
	static int hp_iceman;
	static int hp_lion;
	static int hp_wolf;
	static int hp[5];
	static string name[5];
	static string weapon_name[3];
	
	virtual string getName() = 0;
	friend class army;
	warrior(int num, int col) : number(num), color(col)
	{

	}
};

int warrior::hp[5] = { 0 };
string warrior::name[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
string warrior::weapon_name[3] = { "sword", "bomb", "arrow" };

class dragon : public warrior
{
private:


public:
	dragon(int num, int col, float mor) : warrior(num, col)
	{ 
		weapon[0] = warrior::weapon_name[num % 3];
		morale = mor;
	}
	string getName()
	{
		return "dragon";
	}
};

class ninja : public warrior
{

public:
	ninja(int num, int col) : warrior(num, col)
	{
		weapon[0] = warrior::weapon_name[num % 3];
		weapon[1] = warrior::weapon_name[(num + 1) % 3];
	}
	string getName()
	{
		return "ninja";
	}
};

class iceman : public warrior
{

public:
	iceman(int num, int col) : warrior(num, col)
	{
		weapon[0] = warrior::weapon_name[num % 3];
	}
	string getName()
	{
		return "iceman";
	}
};

class lion : public warrior
{
public:
	lion(int num, int col, int loy) : warrior(num, col)
	{
		loyalty = loy;
	}
	string getName()
	{
		return "lion";
	}
};

class wolf : public warrior
{
private:

public:
	wolf(int num, int col) : warrior(num, col)
	{

	}
	string getName()
	{
		return "wolf";
	}
};

class army
{
private:
	int color;                    // 阵营颜色
	int num_warrior[5];           // 战士数量
	int num_total;                // 已经造的战士数量
	int hp;                       // 目前的生命元个数
	bool stop;                    // 是否停止制造
	int order[5];                 // 制造战士的顺序
	bool flag[5];                 // 是否能造战士
	int tick;                     // 下一个制造的战士编号
	vector<warrior *> team;       // 战士们
public:
	army(int _color, int _hp);
	bool is_stop() { return stop; }
	void create(int time);
	~army()
	{
		for (auto it = team.begin(); it != team.end(); ++it)
		{
			if (*it)
			{
				delete *it;
				*it = NULL;
			}
		}
	}
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
			switch (type)
			{
			case 0: // dragon
				team.push_back(new dragon(num_total, color, (float)hp / warrior::hp[0]));
				cout << "It has a " << team.back()->weapon[0] <<  ",and it's morale is " << setiosflags(ios::fixed) << setprecision(2) <<  team.back()->morale << endl;
				break;
			case 1: // ninja
				team.push_back(new ninja(num_total, color));
				cout << "It has a " << team.back()->weapon[0] << " and a " << team.back()->weapon[1] << endl;
				break;
			case 2: // iceman
				team.push_back(new iceman(num_total, color));
				cout << "It has a " << team.back()->weapon[0] << endl;
				break;
			case 3: // lion
				team.push_back(new lion(num_total, color, hp));
				cout << "It's loyalty is " << team.back()->loyalty << endl;
				break;
			case 4: // wolf
				team.push_back(new wolf(num_total, color));
				break;
			}
			return;
		}
		tick = (tick + 1) % 5;
	}
	stop = true;
		cout << "headquarter stops making warriors" << endl;
}
