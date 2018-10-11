#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

string color_name[3] = { "red", "blue", "white" };

enum COLORS // 颜色
{
	RED, BLUE, WHITE
};
enum WARRIORS // 战士
{
	DRAGON, NINJA, ICEMAN, LION, WOLF
};
enum WEAPON // 武器
{
	SWORD = 0, BOMB = 1, ARROW = 2
};

const int WARRIORS_NUM = 5;
const int WEAPON_NUM = 3;

class city;
class army;
class warrior;
class weapon
{
public:
	int kind;
	warrior *host;
	static string name[WEAPON_NUM];
	weapon(int kind, warrior *host) : kind(kind), host(host) { ; }
	virtual ~weapon() { ; };
};
class arrow :public weapon
{
public:
	static int force;
	int use_left;
	arrow(warrior *host) :weapon(ARROW, host) { use_left = 3; }
};
class sword :public weapon
{
public:
	int force;
	sword(warrior *host);
};
class bomb : public weapon
{
public:
	bomb(warrior *host) :weapon(BOMB, host) { ; }

};

weapon *get_weapon(int kind, warrior *host)
{
	switch (kind)
	{
	case ARROW:return new arrow(host);
	case BOMB: return new bomb(host);
	case SWORD:
		sword * t_sword = new sword(host);
		if (t_sword->force == 0)
		{
			delete t_sword;
			return NULL;
		}
		else
			return t_sword;
	}
	throw 1;
}
class warrior // 战士基类
{
protected:
	army * parmy;                     // 阵营
	int color;                       // 阵营颜色
	int number;                      // 编号
	int hp_left;                     // 剩余生命值
	int city_num;                    // 所在城市
	bool alive;
public:
	int cur_force;
	friend class wolf;
	weapon *wp[3];                   // 武器
	int kind;                        // 种类
	warrior(int num, army &_army, int kind);
	static int hp[WARRIORS_NUM];
	static int force[WARRIORS_NUM];
	static string name[5];
	virtual string getName() { return name[kind]; }
	virtual ~warrior()
	{
		for (int i = 0; i < 3; ++i)
		{
			delete wp[i];
		};
	}
	virtual void born(int time, int kind);
	friend class army;
	virtual void reach(int time);
	virtual void report(int time);
	virtual void march(int time);
	static void fight(int time);
	static void shot(int time);
	static void use_bomb(int time);
	static void earn(int time);
};

class army
{
public:
	int number;                   // 编号
	int color;                    // 阵营颜色
	int num_warrior[5];           // 战士数量
	int num_total;                // 已经造的战士数量
	int hp;                       // 目前的生命元个数
	bool has_enemy;               // 是否有敌人到达
	bool stop;                    // 是否停止制造
	int *order;                   // 制造战士的顺序
	static int red_order[5];      // 红色顺序
	static int blue_order[5];     // 蓝色顺序
	bool flag[5];                 // 是否能造战士
	int tick;                     // 下一个制造的战士编号
	vector<warrior *> team;       // 战士们
public:
	bool taken;
	static army *armys[2];
	friend class warrior;
	army(int _color, int _hp);
	bool is_stop() { return stop; }
	void create(int time);
	~army()
	{
		for (vector<warrior *>::iterator it = team.begin(); it != team.end(); ++it)
		{
			if (*it)
			{
				delete *it;
				*it = NULL;
			}
		}
	}
	void report(int time)
	{
		printf("%03d:50 %d elements in %s headquarter\n", time, hp, color_name[color].c_str());
	}
};
army *army::armys[2];

class city // 城市
{
private:
	int color;
	int index;
	int elements;
public:
	int last_winner;
	static int number;
	static city *citys;
	friend class warrior;
	~city() { ; }
	vector<warrior* > warriors[2];
	void setindex(int idx)
	{
		index = idx;
	}
	city() :color(WHITE), elements(0), last_winner(WHITE)
	{
		;
	}
	city(int idx) :color(WHITE), index(idx) { ; }
	void change_color(int col)
	{
		color = col;
	}
	static void add_elements()
	{
		for (int j = 1; j <= city::number; ++j)
		{
			citys[j].elements += 10;
		}
	}
	static void move(int time)
	{
		vector<warrior *>::iterator it;
		bool blue_flag = false, red_flag = false;
		for (int j = 0; j <= city::number; ++j) // 蓝色移动
		{
			for (it = citys[j + 1].warriors[BLUE].begin(); it != citys[j + 1].warriors[BLUE].end(); ++it)
			{
				citys[j].warriors[BLUE].push_back(*it);
				if (j == 0)
				{
					blue_flag = true;
				}
			}
			citys[j + 1].warriors[BLUE].clear();
		}
		for (int j = city::number + 1; j > 0; --j) // 红色移动
		{
			for (it = citys[j - 1].warriors[RED].begin(); it != citys[j - 1].warriors[RED].end(); ++it)
			{
				citys[j].warriors[RED].push_back(*it);
				if (j == city::number + 1)
				{
					red_flag = true;
				}
			}
			citys[j - 1].warriors[RED].clear();
		}
		if (blue_flag)
			city::citys[0].warriors[BLUE].back()->reach(time);
		for (int j = 1; j <= city::number; ++j) // 中间城市
		{
			for (it = citys[j].warriors[RED].begin(); it != citys[j].warriors[RED].end(); ++it)
			{
				(*it)->march(time);
			}
			for (it = citys[j].warriors[BLUE].begin(); it != citys[j].warriors[BLUE].end(); ++it)
			{
				(*it)->march(time);
			}
		}
		if (red_flag)
			city::citys[city::number + 1].warriors[RED].back()->reach(time);
	}
	static void report(int time)
	{
		for (int j = 0; j <= city::number + 1; ++j)
		{
			vector<warrior *>::iterator it;
			for (it = citys[j].warriors[RED].begin(); it != citys[j].warriors[RED].end(); ++it)
			{
				(*it)->report(time);
			}
		}
		for (int j = 0; j <= city::number + 1; ++j)
		{
			vector<warrior *>::iterator it;
			for (it = citys[j].warriors[BLUE].begin(); it != citys[j].warriors[BLUE].end(); ++it)
			{
				(*it)->report(time);
			}
		}

	}
};
int city::number;
city *city::citys = NULL;




class dragon : public warrior
{
public:
	float morale;
	dragon(int num, army &_army) :warrior(num, _army, DRAGON)
	{
		hp_left = warrior::hp[DRAGON];
		wp[num % 3] = get_weapon(num % 3, this);

		morale = float(parmy->hp) / warrior::hp[DRAGON];
	}
	string getName()
	{
		return "dragon";
	}
	void yell(int time)
	{
		printf("%03d:40 %s dragon %d yelled in city %d\n",
			time, color_name[parmy->color].c_str(), number, city_num);
	}
	~dragon()
	{
		;
	}
	void born(int time, int kind)
	{
		warrior::born(time, kind);
		printf("Its morale is %.2f\n", morale);
	}
};

class ninja : public warrior
{
public:
	ninja(int num, army &_army) :warrior(num, _army, NINJA)
	{
		wp[num % 3] = get_weapon(num % 3, this);
		wp[(num + 1) % 3] = get_weapon((num + 1) % 3, this);
		hp_left = warrior::hp[NINJA];

	}
	string getName()
	{
		return "ninja";
	}
	~ninja()
	{
		;
	}
	void born(int time, int kind)
	{
		warrior::born(time, kind);
	}
};

class iceman : public warrior
{
private:
	bool move_flag;
public:
	iceman(int num, army &_army) :warrior(num, _army, ICEMAN), move_flag(false)
	{
		wp[num % 3] = get_weapon(num % 3, this);
		hp_left = warrior::hp[ICEMAN];
	}
	void reach(int time)
	{
		if (move_flag)
		{
			hp_left -= 9;
			cur_force += 20;
			if (hp_left <= 0)
				hp_left = 1;
			move_flag = false;
		}
		else
			move_flag = true;
		warrior::reach(time);
	}
	void march(int time)
	{
		if (move_flag)
		{
			hp_left -= 9;
			cur_force += 20;
			if (hp_left <= 0)
				hp_left = 1;
			move_flag = false;
		}
		else
			move_flag = true;
		warrior::march(time);
	}
	string getName()
	{
		return "iceman";
	}
	~iceman()
	{
		;
	}
	void born(int time, int kind)
	{
		warrior::born(time, kind);
	}
};

class lion : public warrior
{
public:
	int loyalty;
	static int k;
	static void ran(int time);
	bool is_ran()
	{
		return loyalty <= 0;
	}
	lion(int num, army &_army) :warrior(num, _army, LION)
	{
		loyalty = _army.hp;
		hp_left = warrior::hp[LION];
	}
	void born(int time, int kind)
	{
		warrior::born(time, kind);
		printf("Its loyalty is %d\n", loyalty);
	}
	virtual void march(int time)
	{
		warrior::march(time);
	}
	~lion()
	{
		;
	}
};

class wolf : public warrior
{
public:
	static void take(int time);
	wolf(int num, army &_army) :warrior(num, _army, WOLF)
	{
		hp_left = warrior::hp[WOLF];
	}
	string getName()
	{
		return "wolf";
	}
	~wolf()
	{
	}
	void born(int time, int kind)
	{
		warrior::born(time, kind);
	}
};



int lion::k;
int warrior::hp[WARRIORS_NUM];
int warrior::force[WARRIORS_NUM];
string warrior::name[WARRIORS_NUM] = { "dragon", "ninja", "iceman", "lion", "wolf" };
string weapon::name[WEAPON_NUM] = { "sword", "bomb", "arrow" };
int army::red_order[5] = { 2,3,4,1,0 };         // 红色顺序
int army::blue_order[5] = { 3,0,1,2,4 };        // 蓝色顺序
int arrow::force;

int main(int argc, const char *argv[])
{
	//freopen("C:\\Users\\pkuzhd\\Desktop\\w3\\in", "r", stdin);
	//freopen("C:\\Users\\pkuzhd\\Desktop\\w3\\my_out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int T;
		int hp_total;
		cin >> hp_total >> city::number >> arrow::force >> lion::k >> T;
		city::citys = new city[city::number + 2];
		for (int j = 0; j <= city::number + 1; ++j)
		{
			city::citys[j].setindex(j);
		}
		for (int j = 0; j < 5; ++j)
			cin >> warrior::hp[j];
		for (int j = 0; j < 5; ++j)
			cin >> warrior::force[j];

		army::armys[RED] = new army(RED, hp_total);
		army::armys[BLUE] = new army(BLUE, hp_total);
		printf("Case %d:\n", i);
		for (int time = 0; ; ++time)
		{
			army::armys[RED]->create(time); // 00分
			army::armys[BLUE]->create(time); // 00分
			T -= 5;
			if (T < 0)
				break;
			lion::ran(time); // 05分
			T -= 5;
			if (T < 0)
				break;
			city::move(time); // 10分
			if (army::armys[RED]->taken || army::armys[BLUE]->taken)
				break;
			T -= 10;
			city::add_elements(); // 20分
			T -= 10;
			if (T < 0)
				break;
			warrior::earn(time); // 30分
			T -= 5;
			if (T < 0)
				break;
			warrior::shot(time); // 35分
			T -= 3;
			if (T < 0)
				break;
			warrior::use_bomb(time); // 38分
			T -= 2;
			if (T < 0)
				break;
			// 40分
			warrior::fight(time);
			T -= 10;
			if (T < 0)
				break;
			army::armys[RED]->report(time); // 50分
			army::armys[BLUE]->report(time); // 50分
			T -= 5;
			if (T < 0)
				break;
			city::report(time); // 55分
			T -= 5;
			if (T < 0)
				break;
		}
		delete[] city::citys;
		delete army::armys[RED];
		delete army::armys[BLUE];
	}
	return 0;
}

army::army(int _color, int _hp) : color(_color), hp(_hp), stop(false), tick(0), num_total(0), taken(false), has_enemy(false)
{
	number = color == RED ? 0 : city::number + 1;
	order = color == RED ? red_order : blue_order;

	for (int i = 0; i < 5; ++i)
	{
		flag[i] = true;
		num_warrior[i] = 0;
	}
}
void army::create(int time)
{
	if (hp >= warrior::hp[order[tick]])
	{
		int type = order[tick];
		hp -= warrior::hp[type];
		++num_warrior[type];
		++num_total;
		tick = (tick + 1) % 5;
		warrior * t = NULL;
		switch (type)
		{
		case DRAGON: // dragon
			t = new dragon(num_total, *this);
			team.push_back(t);
			t->born(time, DRAGON);
			break;
		case NINJA: // ninja
			t = new ninja(num_total, *this);
			team.push_back(t);
			t->born(time, NINJA);
			break;
		case ICEMAN: // iceman
			t = new iceman(num_total, *this);
			team.push_back(t);
			t->born(time, ICEMAN);
			break;
		case LION: // lion
			t = new lion(num_total, *this);
			team.push_back(t);
			t->born(time, LION);
			break;
		case WOLF: // wolf
			t = new wolf(num_total, *this);
			team.push_back(t);
			t->born(time, WOLF);
			break;
		}
		t->city_num = number;
		city::citys[number].warriors[color].push_back(t);
		return;
	}
}

warrior::warrior(int num, army &_army, int kind)
	:number(num), parmy(&_army), city_num(_army.number), alive(true), color(_army.color), kind(kind)
{
	cur_force = force[kind];
	for (int i = 0; i < 3; ++i)
	{
		wp[i] = NULL;
	}
}
void warrior::born(int time, int kind)
{
	printf("%03d:00 %s %s %d born\n", time, color_name[parmy->color].c_str(), name[kind].c_str(), number);
}
void warrior::reach(int time)
{
	if (color == RED)
	{
		++city_num;
	}
	else
	{
		--city_num;
	}
	printf("%03d:10 %s %s %d reached %s headquarter with %d elements and force %d\n",
		time,
		color_name[color].c_str(),
		warrior::name[kind].c_str(),
		number,
		color_name[1 - color].c_str(),
		hp_left,
		cur_force
	);
	if (army::armys[1 - color]->has_enemy)
	{
		printf("%03d:10 %s headquarter was taken\n", time, color_name[1 - color].c_str());
		army::armys[1 - color]->taken = true;
	}
	else
		army::armys[1 - color]->has_enemy = true;
}
void warrior::march(int time)
{
	if (color == RED)
	{
		++city_num;
	}
	else
	{
		--city_num;
	}
	printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",
		time,
		color_name[color].c_str(),
		warrior::name[kind].c_str(),
		number,
		city_num,
		hp_left,
		cur_force
	);
}
void warrior::earn(int time)
{
	for (int i = 1; i <= city::number; ++i)
	{
		if (city::citys[i].warriors[RED].size() + city::citys[i].warriors[BLUE].size() == 1)
		{
			if (city::citys[i].warriors[RED].size())
			{
				warrior *temp = city::citys[i].warriors[RED][0];
				printf("%03d:30 %s %s %d earned %d elements for his headquarter\n",
					time,
					color_name[temp->color].c_str(),
					temp->getName().c_str(),
					temp->number,
					city::citys[i].elements);
				army::armys[RED]->hp += city::citys[i].elements;
				city::citys[i].elements = 0;
			}
			else
			{
				warrior *temp = city::citys[i].warriors[BLUE][0];
				printf("%03d:30 %s %s %d earned %d elements for his headquarter\n",
					time,
					color_name[temp->color].c_str(),
					temp->getName().c_str(),
					temp->number,
					city::citys[i].elements);
				army::armys[BLUE]->hp += city::citys[i].elements;
				city::citys[i].elements = 0;
			}
		}
	}

}
void warrior::shot(int time)
{
	if (city::number == 1)
		return;

	warrior *shot_warrior, *op_warrior;
	for (int i = 1; i <= city::number; ++i)
	{
		// 红色放箭
		if (i == city::number)
			;
		else if (city::citys[i].warriors[RED].size() && city::citys[i + 1].warriors[BLUE].size())
		{
			shot_warrior = city::citys[i].warriors[RED][0];
			op_warrior = city::citys[i + 1].warriors[BLUE][0];
			if (shot_warrior->wp[ARROW])
			{
				int &use_left = dynamic_cast<arrow*>(shot_warrior->wp[ARROW])->use_left;
				use_left -= 1;
				if (use_left == 0)
				{
					delete shot_warrior->wp[ARROW];
					shot_warrior->wp[ARROW] = NULL;
				}
				bool dead = false;
				op_warrior->hp_left -= arrow::force;
				if (op_warrior->hp_left <= 0)
					dead = true;
				printf("%03d:35 %s %s %d shot",
					time,
					color_name[shot_warrior->color].c_str(),
					shot_warrior->getName().c_str(),
					shot_warrior->number);
				if (dead)
					printf(" and killed %s %s %d",
						color_name[op_warrior->color].c_str(),
						op_warrior->getName().c_str(),
						op_warrior->number);
				printf("\n");
			}
		}


		// 蓝色放箭
		if (i == 0)
			;
		else if (city::citys[i - 1].warriors[RED].size() && city::citys[i].warriors[BLUE].size())
		{
			shot_warrior = city::citys[i].warriors[BLUE][0];
			op_warrior = city::citys[i - 1].warriors[RED][0];
			if (shot_warrior->wp[ARROW])
			{
				int &use_left = dynamic_cast<arrow*>(shot_warrior->wp[ARROW])->use_left;
				use_left -= 1;
				if (use_left == 0)
				{
					delete shot_warrior->wp[ARROW];
					shot_warrior->wp[ARROW] = NULL;
				}
				bool dead = false;
				op_warrior->hp_left -= arrow::force;
				if (op_warrior->hp_left <= 0)
					dead = true;
				printf("%03d:35 %s %s %d shot",
					time,
					color_name[shot_warrior->color].c_str(),
					shot_warrior->getName().c_str(),
					shot_warrior->number);
				if (dead)
					printf(" and killed %s %s %d",
						color_name[op_warrior->color].c_str(),
						op_warrior->getName().c_str(),
						op_warrior->number);
				printf("\n");
			}
		}
	}
}
void warrior::use_bomb(int time)
{
	for (int i = 1; i <= city::number; ++i)
	{
		if (city::citys[i].warriors[RED].size() && city::citys[i].warriors[BLUE].size())
		{
			warrior *t_warrior[2] = { city::citys[i].warriors[RED][0] , city::citys[i].warriors[BLUE][0] };
			if (t_warrior[RED]->hp_left <= 0 || t_warrior[BLUE]->hp_left <= 0)
				continue;
			int result = WHITE;
			int attack_color = (city::citys[i].color != WHITE) ? city::citys[i].color : (i % 2 ? RED : BLUE);

			if (t_warrior[1 - attack_color]->hp_left
				- t_warrior[attack_color]->cur_force
				- (t_warrior[attack_color]->wp[SWORD] ? dynamic_cast<sword*>(t_warrior[attack_color]->wp[SWORD])->force : 0)
				<= 0)
				result = attack_color;
			else if (t_warrior[1 - attack_color]->kind != NINJA && t_warrior[attack_color]->hp_left
				- t_warrior[1 - attack_color]->cur_force * 5 / 10
				- (t_warrior[1 - attack_color]->wp[SWORD] ? dynamic_cast<sword*>(t_warrior[1 - attack_color]->wp[SWORD])->force : 0)
				<= 0)
				result = 1 - attack_color;

			if (t_warrior[RED]->wp[BOMB] && result == BLUE)
			{
				printf("%03d:38 red %s %d used a bomb and killed blue %s %d\n",
					time,
					t_warrior[RED]->getName().c_str(),
					t_warrior[RED]->number,
					t_warrior[BLUE]->getName().c_str(),
					t_warrior[BLUE]->number);
				city::citys[i].warriors[RED].clear();
				city::citys[i].warriors[BLUE].clear();
			}
			if (t_warrior[BLUE]->wp[BOMB] && result == RED)
			{
				printf("%03d:38 blue %s %d used a bomb and killed red %s %d\n",
					time,
					t_warrior[BLUE]->getName().c_str(),
					t_warrior[BLUE]->number,
					t_warrior[RED]->getName().c_str(),
					t_warrior[RED]->number);
				city::citys[i].warriors[RED].clear();
				city::citys[i].warriors[BLUE].clear();
			}
		}
	}
}
void warrior::fight(int time)
{
	int add_hp[2] = { 0, 0 };
	for (int i = 1; i <= city::number; ++i)
	{
		if (city::citys[i].warriors[RED].size() && city::citys[i].warriors[BLUE].size())
		{
			warrior *t_warrior[2] = { city::citys[i].warriors[RED][0] , city::citys[i].warriors[BLUE][0] };
			int result = WHITE;
			int attack_color = (city::citys[i].color != WHITE) ? city::citys[i].color : (i % 2 ? RED : BLUE);
			if (t_warrior[RED]->hp_left <= 0 && t_warrior[BLUE]->hp_left <= 0) // 都被箭射死
			{
				//city::citys[i].last_winner = WHITE; // 不算做战斗
				city::citys[i].warriors[RED].clear();
				city::citys[i].warriors[BLUE].clear();
			}
			else if (t_warrior[RED]->hp_left <= 0 || t_warrior[BLUE]->hp_left <= 0)
			{
				result = t_warrior[RED]->hp_left <= 0 ? BLUE : RED;
				if (attack_color == result)
				{
					dragon *t_dragon = dynamic_cast<dragon*>(t_warrior[result]);
					if (t_dragon)
					{
						t_dragon->morale += 0.2f;
						if (t_dragon->morale > 0.8)
							t_dragon->yell(time);
					}
				}
				if (t_warrior[result]->parmy->hp >= 8)
				{
					t_warrior[result]->parmy->hp -= 8;
					t_warrior[result]->hp_left += 8;
				}
				add_hp[result] += city::citys[i].elements;
				printf("%03d:40 %s %s %d earned %d elements for his headquarter\n",
					time,
					color_name[result].c_str(),
					t_warrior[result]->getName().c_str(),
					t_warrior[result]->number,
					city::citys[i].elements);
				city::citys[i].elements = 0;
				if (city::citys[i].color != result)
				{
					if (city::citys[i].last_winner == result)
					{
						printf("%03d:40 %s flag raised in city %d\n",
							time,
							color_name[result].c_str(),
							i);
						city::citys[i].color = result;
					}
					else
						city::citys[i].last_winner = result;
				}
				else
					city::citys[i].last_winner = result;
				if (t_warrior[result]->kind == WOLF)
				{
					for (int k = 0; k < 3; ++k)
					{
						if (t_warrior[result]->wp[k] == NULL && t_warrior[1 - result]->wp[k] != NULL)
						{
							t_warrior[result]->wp[k] = t_warrior[1 - result]->wp[k];
							t_warrior[1 - result]->wp[k] = NULL;
						}
					}
				}
				city::citys[i].warriors[1 - result].clear();
			}
			else // 真正开打
			{
				int hp_before[2] = { t_warrior[RED]->hp_left, t_warrior[BLUE]->hp_left };
				t_warrior[1 - attack_color]->hp_left -=
					(t_warrior[attack_color]->cur_force
						+ (t_warrior[attack_color]->wp[SWORD] ? dynamic_cast<sword*>(t_warrior[attack_color]->wp[SWORD])->force : 0));

				printf("%03d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",
					time,
					color_name[attack_color].c_str(),
					t_warrior[attack_color]->getName().c_str(),
					t_warrior[attack_color]->number,
					color_name[1 - attack_color].c_str(),
					t_warrior[1 - attack_color]->getName().c_str(),
					t_warrior[1 - attack_color]->number,
					i,
					t_warrior[attack_color]->hp_left,
					t_warrior[attack_color]->cur_force);
				if (t_warrior[attack_color]->wp[SWORD])
				{
					int &t_force = dynamic_cast<sword*>(t_warrior[attack_color]->wp[SWORD])->force;
					t_force = t_force * 8 / 10;
					if (t_force == 0)
					{
						delete t_warrior[attack_color]->wp[SWORD];
						t_warrior[attack_color]->wp[SWORD] = NULL;
					}
				}
				if (t_warrior[1 - attack_color]->hp_left <= 0)
				{
					result = attack_color;
					printf("%03d:40 %s %s %d was killed in city %d\n",
						time,
						color_name[1 - attack_color].c_str(),
						t_warrior[1 - attack_color]->getName().c_str(),
						t_warrior[1 - attack_color]->number,
						i);
					if (t_warrior[1 - attack_color]->kind == LION)
						t_warrior[attack_color]->hp_left += hp_before[1 - attack_color];
				}
				else
				{
					if (t_warrior[1 - attack_color]->kind != NINJA)
					{
						t_warrior[attack_color]->hp_left -=
							(t_warrior[1 - attack_color]->cur_force * 5 / 10
								+ (t_warrior[1 - attack_color]->wp[SWORD] ? dynamic_cast<sword*>(t_warrior[1 - attack_color]->wp[SWORD])->force : 0));
						printf("%03d:40 %s %s %d fought back against %s %s %d in city %d\n",
							time,
							color_name[1 - attack_color].c_str(),
							t_warrior[1 - attack_color]->getName().c_str(),
							t_warrior[1 - attack_color]->number,
							color_name[attack_color].c_str(),
							t_warrior[attack_color]->getName().c_str(),
							t_warrior[attack_color]->number,
							i);
						if (t_warrior[1 - attack_color]->wp[SWORD])
						{
							int &t_force = dynamic_cast<sword*>(t_warrior[1 - attack_color]->wp[SWORD])->force;
							t_force = t_force * 8 / 10;
							if (t_force == 0)
							{
								delete t_warrior[1 - attack_color]->wp[SWORD];
								t_warrior[1 - attack_color]->wp[SWORD] = NULL;
							}
						}
						if (t_warrior[attack_color]->hp_left <= 0)
						{
							result = 1 - attack_color;
							printf("%03d:40 %s %s %d was killed in city %d\n",
								time,
								color_name[attack_color].c_str(),
								t_warrior[attack_color]->getName().c_str(),
								t_warrior[attack_color]->number,
								i);
							if (t_warrior[attack_color]->kind == LION)
								t_warrior[1 - attack_color]->hp_left += hp_before[attack_color];
						}
					}
				}
				if (result == WHITE)
				{
					city::citys[i].last_winner = WHITE;
					for (int kk = 0; kk < 2; ++kk)
					{
						dragon *t_dragon = dynamic_cast<dragon*>(t_warrior[kk]);
						lion *t_lion = dynamic_cast<lion*>(t_warrior[kk]);
						if (t_dragon)
						{
							t_dragon->morale -= 0.2f;
							if (t_dragon->morale > 0.8 && kk == attack_color)
								t_dragon->yell(time);
						}
						if (t_lion)
						{
							t_lion->loyalty -= lion::k;
						}
					}
				}
				else
				{
					dragon *t_dragon = dynamic_cast<dragon*>(t_warrior[result]);
					if (attack_color == result && t_dragon)
					{
						t_dragon->morale += 0.2f;
						if (t_dragon->morale > 0.8)
							t_dragon->yell(time);
					}

					if (t_warrior[result]->parmy->hp >= 8)
					{
						t_warrior[result]->parmy->hp -= 8;
						t_warrior[result]->hp_left += 8;
					}
					add_hp[result] += city::citys[i].elements;
					printf("%03d:40 %s %s %d earned %d elements for his headquarter\n",
						time,
						color_name[result].c_str(),
						t_warrior[result]->getName().c_str(),
						t_warrior[result]->number,
						city::citys[i].elements);
					city::citys[i].elements = 0;
					if (city::citys[i].color != result)
					{
						if (city::citys[i].last_winner == result)
						{
							printf("%03d:40 %s flag raised in city %d\n",
								time,
								color_name[result].c_str(),
								i);
							city::citys[i].color = result;
						}
						else
							city::citys[i].last_winner = result;
					}
					else
						city::citys[i].last_winner = result;
					if (t_warrior[result]->kind == WOLF)
					{
						for (int k = 0; k < 3; ++k)
						{
							if (t_warrior[result]->wp[k] == NULL && t_warrior[1 - result]->wp[k] != NULL)
							{
								t_warrior[result]->wp[k] = t_warrior[1 - result]->wp[k];
								t_warrior[1 - result]->wp[k] = NULL;
							}
						}
					}
					city::citys[i].warriors[1 - result].clear();
				}
			}
		}
		else if (city::citys[i].warriors[RED].size() || city::citys[i].warriors[BLUE].size())
		{
			int dead = city::citys[i].warriors[RED].size() ? RED : BLUE;
			if (city::citys[i].warriors[dead][0]->hp_left <= 0)
				city::citys[i].warriors[dead].clear();
		}
	}
	army::armys[RED]->hp += add_hp[RED];
	army::armys[BLUE]->hp += add_hp[BLUE];
}
void warrior::report(int time)
{
	printf("%03d:55 %s %s %d has ",
		time,
		color_name[color].c_str(),
		warrior::name[kind].c_str(),
		number);
	bool flag = true;
	if (wp[ARROW])
	{
		printf("arrow(%d)", dynamic_cast<arrow*>(wp[ARROW])->use_left);
		flag = false;
	}
	if (wp[BOMB])
	{
		if (flag)
			flag = false;
		else
			printf(",");
		printf("bomb");

	}
	if (wp[SWORD])
	{
		if (flag)
			flag = false;
		else
			printf(",");
		printf("sword(%d)", dynamic_cast<sword*>(wp[SWORD])->force);
	}
	if (flag)
		printf("no weapon");
	printf("\n");
}
void wolf::take(int time)
{
	;
}
void lion::ran(int time)
{
	for (int city_num = 0; city_num <= city::number + 1; ++city_num)
	{
		for (int color = 0; color <= 1; ++color)
		{
			vector<warrior *> &warriors = city::citys[city_num].warriors[color];
			vector<warrior *>::iterator it = warriors.begin();
			for (; it != warriors.end(); )
			{
				if ((*it)->kind == LION)
				{
					lion *temp = dynamic_cast<lion *>(*it);
					if (temp->is_ran())
					{
						printf("%03d:05 %s lion %d ran away\n", time, color_name[temp->color].c_str(), temp->number);
						it = warriors.erase(it);
					}
					else
					{
						++it;
					}
				}
				else
					++it;
			}
		}
	}
}
sword::sword(warrior *host) :weapon(SWORD, host), force(host->cur_force * 2 / 10) { ; }