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
class weapon
{
public:
	bool used;
	int kind;
	int force;
	static string name[WEAPON_NUM];
	weapon(int kind) : kind(kind), used(false) { ; }
};
class warrior // 战士基类
{
protected:
	army *parmy;                     // 阵营
	int color;
	int hp_left;                     // 剩余生命值
	int city_num;                    // 所在城市
	bool alive;
	int weapon_num[3];               // 不同武器的数量
public:
	int number;                      // 编号
	friend class wolf;
	weapon *wp[3][10];               // 武器
	int kind;                        // 种类
	warrior(int num, army &_army);
	static int hp[WARRIORS_NUM];
	static int force[WARRIORS_NUM];
	static string name[5];
	virtual string getName() = 0;
	virtual ~warrior()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 10; ++j)
				if (wp[i][j])
					delete wp[i][j];
		};
	}
	virtual void born(int time, int kind);
	friend class army;
	virtual void reach(int time);
	virtual void report(int time)
	{
		printf("%03d:55 %s %s %d has %d sword %d bomb %d arrow and %d elements\n",
			time,
			color_name[color].c_str(),
			warrior::name[kind].c_str(),
			number,
			weapon_num[SWORD],
			weapon_num[BOMB],
			weapon_num[ARROW],
			hp_left);
	}
	virtual void march(int time);
	static void fight(int time);
};

class army
{
public:
	int number;                   // 编号
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
	
public:
	~city() { ; }
	vector<warrior* > warriors[2];
	void setindex(int idx)
	{
		index = idx;
	}
	static int number;
	static city *citys;
	city() :color(WHITE)
	{
		;
	}
	city(int idx) :color(WHITE), index(idx) { ; }
	void change_color(int col)
	{
		color = col;
	}
	static void move(int time)
	{
		vector<warrior *>::iterator it;
		for (int j = 0; j <= city::number; ++j) // 蓝色移动
		{
			for (it = citys[j + 1].warriors[BLUE].begin(); it != citys[j + 1].warriors[BLUE].end(); ++it)
			{
				citys[j].warriors[BLUE].push_back(*it);
			}
			citys[j + 1].warriors[BLUE].clear();
		}
		for (int j = city::number + 1; j > 0; --j) // 红色移动
		{
			for (it = citys[j - 1].warriors[RED].begin(); it != citys[j - 1].warriors[RED].end(); ++it)
			{
				citys[j].warriors[RED].push_back(*it);
			}
			citys[j - 1].warriors[RED].clear();
		}
		for (it = citys[0].warriors[BLUE].begin(); it != citys[0].warriors[BLUE].end(); ++it) // 蓝色占领红色
		{
			(*it)->reach(time);
		}
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
		for (it = citys[city::number + 1].warriors[RED].begin(); it != citys[city::number + 1].warriors[RED].end(); ++it) // 红色占领蓝色
		{
			(*it)->reach(time);
		}
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
	dragon(int num, army &_army) :warrior(num, _army)
	{
		kind = DRAGON;
		hp_left = warrior::hp[DRAGON];
		wp[num % 3][0] = new weapon(num % 3);
		++weapon_num[num % 3];
	}
	string getName()
	{
		return "dragon";
	}
	void yell(int time)
	{
		printf("%03d:40 %s dragon %d yelled in city %d\n", time, color_name[parmy->color].c_str(), number, city_num);
	}
	~dragon()
	{
		;
	}
	void born(int time, int kind)
	{
		warrior::born(time, kind);
	}
};

class ninja : public warrior
{
public:
	ninja(int num, army &_army) :warrior(num, _army)
	{
		wp[num % 3][0] = new weapon(num % 3);
		wp[(num + 1) % 3][0] = new weapon((num + 1) % 3);
		kind = NINJA;
		hp_left = warrior::hp[NINJA];
		++weapon_num[num % 3];
		++weapon_num[(num + 1) % 3];
		
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
public:
	iceman(int num, army &_army) :warrior(num, _army)
	{
		wp[num % 3][0] = new weapon(num % 3);
		kind = ICEMAN;
		hp_left = warrior::hp[ICEMAN];
		++weapon_num[num % 3];

	}
	void reach(int time)
	{
		hp_left -= hp_left / 10;
		warrior::reach(time);
	}
	void march(int time)
	{
		hp_left -= hp_left / 10;
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
	static void ran(int time)
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
	bool is_ran()
	{
		return loyalty <= 0;
	}
	lion(int num, army &_army) :warrior(num, _army)
	{
		wp[num % 3][0] = new weapon(num % 3);
		++weapon_num[num % 3];
		loyalty = _army.hp;
		kind = LION;
		hp_left = warrior::hp[LION];
	}
	string getName()
	{
		return "lion";
	}
	void born(int time, int kind)
	{
		warrior::born(time, kind);
		printf("Its loyalty is %d\n", loyalty);
	}
	virtual void march(int time)
	{
		warrior::march(time);
		loyalty -= k;
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
	wolf(int num, army &_army) :warrior(num, _army)
	{
		kind = WOLF;
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


int main(int argc, const char *argv[])
{
	freopen("C:\\Users\\pkuzh\\Desktop\\in", "r", stdin);
	freopen("C:\\Users\\pkuzh\\Desktop\\out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int T;
		int hp_total;
		cin >> hp_total >> city::number >> lion::k >> T;
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
			T -= 25;
			if (T < 0)
				break;
			wolf::take(time); // 35分
			T -= 5;
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

army::army(int _color, int _hp) : color(_color), hp(_hp), stop(false), tick(0), num_total(0), taken(false)
{
	number = color == RED ? 0 : city::number + 1;
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
	if (is_stop())
		return;
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

	stop = true;
}

warrior::warrior(int num, army &_army) :number(num), parmy(&_army), city_num(_army.number), alive(true), color(_army.color)
{
	weapon_num[SWORD] = 0;
	weapon_num[BOMB] = 0;
	weapon_num[ARROW] = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 10; ++j)
			wp[i][j] = NULL;
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
		force[kind]
	);
	printf("%03d:10 %s headquarter was taken\n", time, color_name[1 - color].c_str());
	army::armys[1 - color]->taken = true;
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
		force[kind]
	);
}
void warrior::fight(int time)
{
	for (int city_num = 1; city_num <= city::number; ++city_num)
	{
		if (!city::citys[city_num].warriors[RED].size() || !city::citys[city_num].warriors[BLUE].size())
			continue;
		warrior *first, *second;
		// 在奇数编号城市，红武士先发起攻击
		// 在偶数编号城市，蓝武士先发起攻击
		int col = city_num % 2;
		first = city::citys[city_num].warriors[1 - col][0];
		second = city::citys[city_num].warriors[col][0];
		sort(first->wp[ARROW], first->wp[ARROW] + first->weapon_num[ARROW],
			[=](weapon *a, weapon*b) ->bool { return a != NULL && a->used; });
		sort(second->wp[ARROW], second->wp[ARROW] + second->weapon_num[ARROW],
			[=](weapon *a, weapon*b) ->bool { return a!= NULL && a->used; });

		queue<weapon **> qfirst, qsecond;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < first->weapon_num[i]; ++j)
			{
				qfirst.push(&(first->wp[i][j]));
			}
			for (int j = 0; j < second->weapon_num[i]; ++j)
			{
				qsecond.push(&(second->wp[i][j]));
			}
		}
		while (true)
		{
			int flag = 0;
			int temp;
			weapon **t;
			if (qfirst.empty())
				++flag;
			else
			{
				t = qfirst.front();
				qfirst.pop();
				switch ((*t)->kind)
				{
				case SWORD:
					second->hp_left -= force[first->kind] * 2 / 10;
					if (force[first->kind] * 2 / 10 == 0 && first->weapon_num[BOMB] + first->weapon_num[ARROW] == 0)
						++flag;
					qfirst.push(t);
					break;
				case BOMB:
					temp = force[first->kind] * 4 / 10;
					second->hp_left -= temp;
					if (first->kind != NINJA)
						first->hp_left -= temp / 2;
					delete *t;
					*t = NULL;
					--first->weapon_num[BOMB];
					break;
				case ARROW:
					second->hp_left -= force[first->kind] * 3 / 10;
					if ((*t)->used)
					{
						delete *t;
						*t = NULL;
						--first->weapon_num[ARROW];
					}
					else
					{
						(*t)->used = true;
						qfirst.push(t);
					}
					break;
				}
			}
			if (first->hp_left <= 0 || second->hp_left <= 0)
				break;

			if (qsecond.empty())
				++flag;
			else
			{
				t = qsecond.front();
				qsecond.pop();
				switch ((*t)->kind)
				{
				case SWORD:
					first->hp_left -= force[second->kind] * 2 / 10;
					if (force[second->kind] * 2 / 10 == 0 && second->weapon_num[BOMB] + second->weapon_num[ARROW] == 0)
						++flag;
					qsecond.push(t);
					break;
				case BOMB:
					temp = force[second->kind] * 4 / 10;
					first->hp_left -= temp;
					if (second->kind != NINJA)
						second->hp_left -= temp / 2;
					delete *t;
					*t = NULL;
					--second->weapon_num[BOMB];
					break;
				case ARROW:
					first->hp_left -= force[second->kind] * 3 / 10;
					if ((*t)->used)
					{
						delete *t;
						*t = NULL;
						--second->weapon_num[ARROW];
					}
					else
					{
						(*t)->used = true;
						qsecond.push(t);
					}
					break;
				}
			}
			if (first->hp_left <= 0 || second->hp_left <= 0)
				break;
			if (flag == 2)
				break;
		}

		sort(first->wp[BOMB], first->wp[BOMB] + 10,
			[=](weapon *a, weapon*b) ->bool { return a != NULL || b == NULL; });
		sort(second->wp[BOMB], second->wp[BOMB] + 10,
			[=](weapon *a, weapon*b) ->bool { return a != NULL || b == NULL; });
		int i;
		for (i = 0; first->wp[BOMB][i] != NULL && i < 10; ++i);
		first->weapon_num[BOMB] = i;
		for (i = 0; second->wp[BOMB][i] != NULL && i < 10; ++i);
		second->weapon_num[BOMB] = i;

		sort(first->wp[ARROW], first->wp[ARROW] + 10,
			[=](weapon *a, weapon*b) ->bool { return a != NULL && (b == NULL || !a->used); });
		sort(second->wp[ARROW], second->wp[ARROW] + 10,
			[=](weapon *a, weapon*b) ->bool { return a != NULL && (b == NULL || !a->used); });
		for (i = 0; first->wp[ARROW][i] != NULL && i < 10; ++i);
		first->weapon_num[ARROW] = i;
		for (i = 0; second->wp[ARROW][i] != NULL && i < 10; ++i);
		second->weapon_num[ARROW] = i;

		if (first->hp_left <= 0 && second->hp_left <= 0)
		{
			printf("%03d:40 both red %s %d and blue %s %d died in city %d\n",
				time,
				city::citys[city_num].warriors[RED][0]->getName().c_str(),
				city::citys[city_num].warriors[RED][0]->number,
				city::citys[city_num].warriors[BLUE][0]->getName().c_str(),
				city::citys[city_num].warriors[BLUE][0]->number,
				city_num);
			city::citys[city_num].warriors[RED].clear();
			city::citys[city_num].warriors[BLUE].clear();
		}
		else if (first->hp_left > 0 && second->hp_left > 0)
		{
			printf("%03d:40 both red %s %d and blue %s %d were alive in city %d\n",
				time,
				city::citys[city_num].warriors[RED][0]->getName().c_str(),
				city::citys[city_num].warriors[RED][0]->number,
				city::citys[city_num].warriors[BLUE][0]->getName().c_str(),
				city::citys[city_num].warriors[BLUE][0]->number,
				city_num);
			if (city::citys[city_num].warriors[RED][0]->kind == DRAGON)
				dynamic_cast<dragon *>(city::citys[city_num].warriors[RED][0])->yell(time);
			if (city::citys[city_num].warriors[BLUE][0]->kind == DRAGON)
				dynamic_cast<dragon *>(city::citys[city_num].warriors[BLUE][0])->yell(time);
		}
		else if (first->hp_left > 0)
		{
			printf("%03d:40 %s %s %d killed %s %s %d in city %d remaining %d elements\n",
				time,
				color_name[first->color].c_str(),
				first->getName().c_str(),
				first->number,
				color_name[second->color].c_str(),
				second->getName().c_str(),
				second->number,
				city_num,
				first->hp_left);
			if (first->kind == DRAGON)
				dynamic_cast<dragon *>(first)->yell(time);
			while (first->weapon_num[SWORD] + first->weapon_num[BOMB] + first->weapon_num[ARROW] < 10)
			{
				if (second->weapon_num[SWORD] > 0)
				{
					--(second->weapon_num[SWORD]);
					first->wp[SWORD][first->weapon_num[SWORD]] = second->wp[SWORD][second->weapon_num[SWORD]];
					second->wp[SWORD][second->weapon_num[SWORD]] = NULL;
					++first->weapon_num[SWORD];
				}
				else if (second->weapon_num[BOMB] > 0)
				{
					--(second->weapon_num[BOMB]);
					first->wp[BOMB][first->weapon_num[BOMB]] = second->wp[BOMB][second->weapon_num[BOMB]];
					second->wp[BOMB][second->weapon_num[BOMB]] = NULL;
					++first->weapon_num[BOMB];
				}
				else if (second->weapon_num[ARROW] > 0)
				{
					--(second->weapon_num[ARROW]);
					first->wp[ARROW][first->weapon_num[ARROW]] = second->wp[ARROW][second->weapon_num[ARROW]];
					second->wp[ARROW][second->weapon_num[ARROW]] = NULL;
					++first->weapon_num[ARROW];
				}
				else
					break;
			}
			city::citys[city_num].warriors[col].clear();
		}
		else
		{
			printf("%03d:40 %s %s %d killed %s %s %d in city %d remaining %d elements\n",
				time,
				color_name[second->color].c_str(),
				second->getName().c_str(),
				second->number,
				color_name[first->color].c_str(),
				first->getName().c_str(),
				first->number,
				city_num,
				second->hp_left);
			if (second->kind == DRAGON)
				dynamic_cast<dragon *>(second)->yell(time);
			while (second->weapon_num[SWORD] + second->weapon_num[BOMB] + second->weapon_num[ARROW] < 10)
			{
				if (first->weapon_num[SWORD] > 0)
				{
					--(first->weapon_num[SWORD]);
					second->wp[SWORD][second->weapon_num[SWORD]] = first->wp[SWORD][first->weapon_num[SWORD]];
					first->wp[SWORD][first->weapon_num[SWORD]] = NULL;
					++second->weapon_num[SWORD];
				}
				else if (first->weapon_num[BOMB] > 0)
				{
					--(first->weapon_num[BOMB]);
					second->wp[BOMB][second->weapon_num[BOMB]] = first->wp[BOMB][first->weapon_num[BOMB]];
					first->wp[BOMB][first->weapon_num[BOMB]] = NULL;
					++second->weapon_num[BOMB];
				}
				else if (first->weapon_num[ARROW] > 0)
				{
					--(first->weapon_num[ARROW]);
					second->wp[ARROW][second->weapon_num[ARROW]] = first->wp[ARROW][first->weapon_num[ARROW]];
					first->wp[ARROW][first->weapon_num[ARROW]] = NULL;
					++second->weapon_num[ARROW];
				}
				else
					break;
			}
			city::citys[city_num].warriors[1 - col].clear();
		}
	}
}

void wolf::take(int time)
{
	for (int city_num = 0; city_num <= city::number + 1; ++city_num)
	{
		for (int color = 0; color <= 1; ++color)
		{
			vector<warrior *> &warriors = city::citys[city_num].warriors[color];
			vector<warrior *> &op_warriors = city::citys[city_num].warriors[1 - color];
			if (warriors.size() && op_warriors.size() && warriors[0]->kind == WOLF && op_warriors[0]->kind != WOLF)
			{
				wolf *self = dynamic_cast<wolf *>(warriors[0]);
				warrior *op = op_warriors[0];
				if (op->weapon_num[SWORD])
				{
					int t = 0;
					while (self->weapon_num[SWORD] < 10 && op->weapon_num[SWORD] > 0)
					{
						++t;
						--(op->weapon_num[SWORD]);
						self->wp[SWORD][self->weapon_num[SWORD]] = op->wp[SWORD][op->weapon_num[SWORD]];
						op->wp[SWORD][op->weapon_num[SWORD]] = NULL;
						++(self->weapon_num[SWORD]);
					}
					if (t)
						printf("%03d:35 %s wolf %d took %d sword from %s %s %d in city %d\n",
							time,
							color_name[self->color].c_str(),
							self->number,
							t,
							color_name[op->color].c_str(),
							op->getName().c_str(),
							op->number,
							city_num);
				}
				else if (op->weapon_num[BOMB])
				{
					int t = 0;
					while (self->weapon_num[BOMB] < 10 && op->weapon_num[BOMB] > 0)
					{
						++t;
						--(op->weapon_num[BOMB]);
						self->wp[BOMB][self->weapon_num[BOMB]] = op->wp[BOMB][op->weapon_num[BOMB]];
						op->wp[BOMB][op->weapon_num[BOMB]] = NULL;
						++(self->weapon_num[BOMB]);
					}
					if (t)
						printf("%03d:35 %s wolf %d took %d bomb from %s %s %d in city %d\n",
							time,
							color_name[self->color].c_str(),
							self->number,
							t,
							color_name[op->color].c_str(),
							op->getName().c_str(),
							op->number,
							city_num);
				}
				else
				{
					int t = 0;
					sort(op->wp[ARROW], op->wp[ARROW] + op->weapon_num[ARROW],
						[=](weapon *a, weapon*b) ->bool { return !a->used; });
					while (self->weapon_num[ARROW] < 10 && op->weapon_num[ARROW] > 0)
					{
						++t;
						--(op->weapon_num[ARROW]);
						self->wp[ARROW][self->weapon_num[ARROW]] = op->wp[ARROW][op->weapon_num[ARROW]];
						op->wp[ARROW][op->weapon_num[ARROW]] = NULL;
						++(self->weapon_num[ARROW]);
					}
					if (t)
						printf("%03d:35 %s wolf %d took %d arrow from %s %s %d in city %d\n",
							time,
							color_name[self->color].c_str(),
							self->number,
							t,
							color_name[op->color].c_str(),
							op->getName().c_str(),
							op->number,
							city_num);
				}
			}
		}
	}
}
